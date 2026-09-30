/* Ownership effects for the RISC-V AME/Ztt extension.
   Copyright (C) 2026 Free Software Foundation, Inc.

   This file is part of GCC.

   GCC is free software; you can redistribute it and/or modify it under
   the terms of the GNU General Public License as published by the Free
   Software Foundation; either version 3, or (at your option) any later
   version.

   GCC is distributed in the hope that it will be useful, but WITHOUT ANY
   WARRANTY; without even the implied warranty of MERCHANTABILITY or
   FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
   for more details.

   You should have received a copy of the GNU General Public License
   along with GCC; see the file COPYING3.  If not see
   <http://www.gnu.org/licenses/>.  */

#define IN_TARGET_CODE 1

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tm.h"
#include "backend.h"
#include "target.h"
#include "rtl.h"
#include "insn-config.h"
#include "rtl-iter.h"
#include "tree.h"
#include "tm_p.h"
#include "regs.h"
#include "function.h"
#include "basic-block.h"
#include "tree-pass.h"
#include "recog.h"
#include "emit-rtl.h"
#include "df.h"
#include "cfgrtl.h"
#include "diagnostic-core.h"

/* The first element is checked by the MD pattern.  Reject an incomplete
   bank or an address-specific clobber: neither models a resource change.  */
bool
riscv_ztt_ownership_operation_p (rtx pattern)
{
  const riscv_ztt::profile_info *profile = riscv_ztt::active_profile ();
  if (!profile || GET_CODE (pattern) != PARALLEL
      || (unsigned int) XVECLEN (pattern, 0)
	 != 2 + profile->mregs + profile->accregs)
    return false;
  rtx memory = XVECEXP (pattern, 0, 1);
  if (GET_CODE (memory) != CLOBBER || !MEM_P (XEXP (memory, 0))
      || GET_MODE (XEXP (memory, 0)) != BLKmode
      || GET_CODE (XEXP (XEXP (memory, 0), 0)) != SCRATCH)
    return false;
  for (unsigned int i = 0; i < profile->mregs + profile->accregs; ++i)
    {
      unsigned int regno = i < profile->mregs ? M_REG_FIRST + i
	: ACC_REG_FIRST + i - profile->mregs;
      rtx clobber = XVECEXP (pattern, 0, i + 2);
      if (GET_CODE (clobber) != CLOBBER)
	return false;
      rtx reg = XEXP (clobber, 0);
      if (!REG_P (reg) || GET_MODE (reg) != SImode || REGNO (reg) != regno)
	return false;
    }
  return true;
}

namespace {

static bool
typed_values_p ()
{
  for (rtx_insn *insn = get_insns (); insn; insn = NEXT_INSN (insn))
    if (NONDEBUG_INSN_P (insn))
      {
	subrtx_iterator::array_type array;
	FOR_EACH_SUBRTX (iter, array, PATTERN (insn), NONCONST)
	  {
	    if (GET_CODE (*iter) == CLOBBER)
	      iter.skip_subrtxes ();
	    else if (riscv_ztt::value_mode_p (GET_MODE (*iter)))
	      return true;
	  }
      }
  return false;
}

static bool
abnormal_edges_p ()
{
  basic_block bb;
  FOR_EACH_BB_FN (bb, cfun)
    {
      edge e;
      edge_iterator ei;
      FOR_EACH_EDGE (e, ei, bb->succs)
	if (e->flags & (EDGE_ABNORMAL | EDGE_EH))
	  return true;
    }
  return false;
}

static bool
resource_operation_p (rtx pattern)
{
  if (GET_CODE (pattern) != PARALLEL || XVECLEN (pattern, 0) != 2)
    return false;
  pattern = XVECEXP (pattern, 0, 0);
  if (GET_CODE (pattern) == SET)
    pattern = SET_SRC (pattern);
  return GET_CODE (pattern) == UNSPEC_VOLATILE
    && (XINT (pattern, 1) == UNSPECV_ZTT_ACQUIRE
	|| XINT (pattern, 1) == UNSPECV_ZTT_RELEASE);
}

/* Model destructive grant/release before any RTL CSE or code motion.
   A failed or already-owned acquisition need not clobber the hardware,
   but treating it conservatively keeps live typed values out of the bank
   until the success path is established by the region analysis.  */
static rtx
resource_effects (rtx operation)
{
  const riscv_ztt::profile_info *profile = riscv_ztt::active_profile ();
  unsigned int count = profile->mregs + profile->accregs;
  rtvec effects = rtvec_alloc (count + 2);
  RTVEC_ELT (effects, 0) = XVECEXP (operation, 0, 0);
  RTVEC_ELT (effects, 1)
    = gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_MEM (BLKmode, gen_rtx_SCRATCH (VOIDmode)));
  for (unsigned int i = 0; i < count; ++i)
    {
      unsigned int regno = i < profile->mregs ? M_REG_FIRST + i
	: ACC_REG_FIRST + i - profile->mregs;
      RTVEC_ELT (effects, i + 2)
	= gen_rtx_CLOBBER (VOIDmode, gen_rtx_REG (SImode, regno));
    }
  return gen_rtx_PARALLEL (VOIDmode, effects);
}

/* A witness says that one low-bit value implies ownership.  It is not an
   ownership fact until control flow tests that bit.  In particular a failed
   acquire can return a nonzero status, so status != 0 is not sufficient.  */
enum witness { NO_WITNESS, LOW_ONE, LOW_ZERO, BIT_ONE, BIT_ZERO };
enum { OWNED = 1, UNOWNED = 2, UNKNOWN_OWNER = OWNED | UNOWNED };
struct binding { rtx location; witness value; int constant; };

static bool
same_location_p (rtx a, rtx b)
{
  return REG_P (a) && REG_P (b) ? REGNO (a) == REGNO (b)
    : rtx_equal_p (a, b);
}

/* A memory witness requires a whole, unescaped local scalar object.  Arbitrary
   pointer loads, volatile state and partial stores are not proofs.  */
static bool
local_slot_p (rtx x)
{
  if (!MEM_P (x) || MEM_VOLATILE_P (x) || !MEM_EXPR (x)
      || TREE_CODE (MEM_EXPR (x)) != VAR_DECL
      || DECL_CONTEXT (MEM_EXPR (x)) != cfun->decl
      || TREE_ADDRESSABLE (MEM_EXPR (x))
      || DECL_MODE (MEM_EXPR (x)) != GET_MODE (x)
      || !MEM_OFFSET_KNOWN_P (x) || !known_eq (MEM_OFFSET (x), 0))
    return false;
  return SCALAR_INT_MODE_P (GET_MODE (x));
}

struct proof_state
{
  unsigned int owners = 0;
  auto_vec<binding, 8> facts;

  witness lookup (rtx x) const
  {
    for (const binding &b : facts)
      if (same_location_p (x, b.location))
	{
	  if (b.value >= BIT_ONE
	      && maybe_gt (GET_MODE_PRECISION (GET_MODE (x)),
			   GET_MODE_PRECISION (GET_MODE (b.location))))
	    return b.value == BIT_ONE ? LOW_ONE : LOW_ZERO;
	  return b.value;
	}
    return NO_WITNESS;
  }

  int constant (rtx x) const
  {
    for (const binding &b : facts)
      if (same_location_p (x, b.location))
	return maybe_gt (GET_MODE_PRECISION (GET_MODE (x)),
			 GET_MODE_PRECISION (GET_MODE (b.location)))
	  ? -1 : b.constant;
    return -1;
  }

  void copy (const proof_state &other)
  {
    owners = other.owners;
    facts.truncate (0);
    facts.safe_splice (other.facts);
  }

  bool equal_p (const proof_state &other) const
  {
    if (owners != other.owners || facts.length () != other.facts.length ())
      return false;
    for (const binding &b : facts)
      if (other.lookup (b.location) != b.value
	  || other.constant (b.location) != b.constant)
	return false;
    return true;
  }

  void kill (rtx dest)
  {
    while (GET_CODE (dest) == SUBREG || GET_CODE (dest) == STRICT_LOW_PART
	   || GET_CODE (dest) == ZERO_EXTRACT)
      dest = XEXP (dest, 0);
    for (unsigned int i = facts.length (); i-- > 0;)
      if (same_location_p (dest, facts[i].location)
	  || (MEM_P (dest) && MEM_P (facts[i].location)))
	facts.unordered_remove (i);
  }

  void put (rtx dest, witness value, int constant = -1)
  {
    if ((value || constant >= 0) && (REG_P (dest) || local_slot_p (dest)))
      facts.safe_push ({dest, value, constant});
  }

  void join (const proof_state &other)
  {
    if (!other.owners)
      return;
    if (!owners)
      return copy (other);
    owners |= other.owners;
    for (unsigned int i = facts.length (); i-- > 0;)
      {
	witness a = facts[i].value, b = other.lookup (facts[i].location);
	int ca = facts[i].constant, cb = other.constant (facts[i].location);
	/* A constant on the other path can exclude the guarded bit.
	   For example, owned->1 and unknown->0 retain a bit-one proof.
	   Two constants without an owned path never create a witness.  */
	if (!a && ca >= 0 && b && ca != (b == LOW_ONE || b == BIT_ONE))
	  a = b;
	if (!b && cb >= 0 && a && cb != (a == LOW_ONE || a == BIT_ONE))
	  b = a;
	facts[i].value = NO_WITNESS;
	if (a && b && ((a - 1) & 1) == ((b - 1) & 1))
	  {
	    if (a <= LOW_ZERO || b <= LOW_ZERO)
	      facts[i].value = ((a - 1) & 1) ? LOW_ZERO : LOW_ONE;
	    else
	      facts[i].value = a;
	  }
	facts[i].constant = ca == cb ? ca : -1;
	if (!facts[i].value && facts[i].constant < 0)
	  facts.unordered_remove (i);
      }
  }
};

static witness expression_witness (rtx, const proof_state &);

/* Track only exact 0/1 cleanup selectors, not arbitrary value ranges.  */
static int
expression_constant (rtx x, const proof_state &state)
{
  if (CONST_INT_P (x))
    return INTVAL (x) == 0 || INTVAL (x) == 1 ? INTVAL (x) : -1;
  if (REG_P (x) || local_slot_p (x))
    return state.constant (x);
  if (GET_CODE (x) == SUBREG && subreg_lowpart_p (x)
      && !paradoxical_subreg_p (x))
    return expression_constant (SUBREG_REG (x), state);
  if (GET_CODE (x) == ZERO_EXTEND || GET_CODE (x) == TRUNCATE)
    return expression_constant (XEXP (x, 0), state);
  if (GET_CODE (x) == SIGN_EXTEND
      && known_gt (GET_MODE_PRECISION (GET_MODE (XEXP (x, 0))), 1))
    return expression_constant (XEXP (x, 0), state);
  return -1;
}

/* Return the condition value which establishes ownership, or -1.  */
static int
condition_success (rtx cond, const proof_state &state)
{
  if (GET_CODE (cond) != EQ && GET_CODE (cond) != NE)
    return -1;
  rtx a = XEXP (cond, 0), b = XEXP (cond, 1);
  int ca = expression_constant (a, state);
  int cb = expression_constant (b, state);
  if (ca >= 0)
    a = GEN_INT (ca);
  if (cb >= 0)
    b = GEN_INT (cb);
  if (CONST_INT_P (a))
    std::swap (a, b);
  if (!CONST_INT_P (b))
    return -1;
  witness w = expression_witness (a, state);
  if (!w)
    return -1;
  bool wanted = !((w - 1) & 1);
  bool bit = INTVAL (b) & 1;
  if (bit == wanted)
    return GET_CODE (cond) == EQ;
  if (w >= BIT_ONE && (INTVAL (b) == 0 || INTVAL (b) == 1))
    return GET_CODE (cond) == NE;
  return -1;
}

static witness
expression_witness (rtx x, const proof_state &state)
{
  if (REG_P (x) || local_slot_p (x))
    return state.lookup (x);
  if (GET_CODE (x) == SUBREG)
    {
      if (!subreg_lowpart_p (x))
	return NO_WITNESS;
      witness w = expression_witness (SUBREG_REG (x), state);
      if (paradoxical_subreg_p (x) && w >= BIT_ONE)
	return w == BIT_ONE ? LOW_ONE : LOW_ZERO;
      return w;
    }
  if (GET_CODE (x) == ZERO_EXTEND || GET_CODE (x) == SIGN_EXTEND
      || GET_CODE (x) == TRUNCATE)
    return expression_witness (XEXP (x, 0), state);
  if (GET_CODE (x) == EQ || GET_CODE (x) == NE)
    {
      int success = condition_success (x, state);
      return success < 0 ? NO_WITNESS : success ? BIT_ONE : BIT_ZERO;
    }
  if (GET_CODE (x) == AND || GET_CODE (x) == XOR || GET_CODE (x) == IOR)
    {
      rtx a = XEXP (x, 0), b = XEXP (x, 1);
      if (CONST_INT_P (a))
	std::swap (a, b);
      if (!CONST_INT_P (b))
	return NO_WITNESS;
      witness w = expression_witness (a, state);
      if (!w)
	return w;
      bool wanted = !((w - 1) & 1);
      bool normalized = w >= BIT_ONE;
      HOST_WIDE_INT c = INTVAL (b);
      if (GET_CODE (x) == AND)
	{
	  if (!(c & 1))
	    return NO_WITNESS;
	  normalized |= c == 1;
	}
      else if (GET_CODE (x) == XOR)
	{
	  wanted ^= (c & 1) != 0;
	  normalized &= c == 0 || c == 1;
	}
      else
	{
	  if (c & 1)
	    return NO_WITNESS;
	  normalized &= c == 0;
	}
      return normalized ? (wanted ? BIT_ONE : BIT_ZERO)
	: (wanted ? LOW_ONE : LOW_ZERO);
    }
  return NO_WITNESS;
}

static int
resource_code (rtx pattern)
{
  if (GET_CODE (pattern) == PARALLEL)
    pattern = XVECEXP (pattern, 0, 0);
  if (GET_CODE (pattern) == SET)
    pattern = SET_SRC (pattern);
  if (GET_CODE (pattern) == UNSPEC_VOLATILE
      && (XINT (pattern, 1) == UNSPECV_ZTT_ACQUIRE
	  || XINT (pattern, 1) == UNSPECV_ZTT_RELEASE
	  || XINT (pattern, 1) == UNSPECV_ZTT_OWNED))
    return XINT (pattern, 1);
  return -1;
}

static bool
owned_access_p (rtx pattern)
{
  if (resource_code (pattern) >= 0)
    return false;
  subrtx_iterator::array_type array;
  FOR_EACH_SUBRTX (iter, array, pattern, NONCONST)
    {
      rtx x = const_cast<rtx> (*iter);
      if (GET_CODE (x) == CLOBBER)
	iter.skip_subrtxes ();
      else if (riscv_ztt::value_mode_p (GET_MODE (x))
	       || (REG_P (x) && ((REGNO (x) >= M_REG_FIRST
				 && REGNO (x) <= M_REG_LAST)
				|| (REGNO (x) >= ACC_REG_FIRST
				    && REGNO (x) <= ACC_REG_LAST))))
	return true;
      else if (GET_CODE (x) == UNSPEC_VOLATILE
	       && XINT (x, 1) == UNSPECV_ZTT && XVECLEN (x, 0) == 1
	       && CONST_INT_P (XVECEXP (x, 0, 0)))
	{
	  HOST_WIDE_INT csr = INTVAL (XVECEXP (x, 0, 0));
	  if (csr == 2048 || csr == 2064 || csr == 2065 || csr == 2066)
	    return true;
	}
    }
  return false;
}

static void
kill_store (rtx dest, const_rtx, void *data)
{
  static_cast<proof_state *> (data)->kill (dest);
}

static void
transfer (rtx_insn *insn, proof_state &state, bool track_witnesses)
{
  int code = resource_code (PATTERN (insn));
  if (code == UNSPECV_ZTT_RELEASE)
    {
      state.owners = UNOWNED;
      state.facts.truncate (0);
      return;
    }
  if (code == UNSPECV_ZTT_OWNED)
    {
      state.owners = OWNED;
      return;
    }
  if (code == UNSPECV_ZTT_ACQUIRE)
    state.owners |= OWNED;
  if (!track_witnesses)
    return;
  rtx set = single_set (insn);
  witness value = set ? expression_witness (SET_SRC (set), state) : NO_WITNESS;
  int constant = set ? expression_constant (SET_SRC (set), state) : -1;
  if (constant >= 0)
    {
      /* A literal alone does not prove ownership.  Keep its exact value
	 for joins, and certify its bit only on an already owned path.  */
      value = state.owners == OWNED ? (constant ? BIT_ONE : BIT_ZERO)
	: NO_WITNESS;
    }
  if (code == UNSPECV_ZTT_ACQUIRE)
    value = LOW_ONE;
  else if (set && GET_CODE (SET_SRC (set)) == UNSPEC_VOLATILE
	   && XINT (SET_SRC (set), 1) == UNSPECV_ZTT
	   && XVECLEN (SET_SRC (set), 0) == 1
	   && XVECEXP (SET_SRC (set), 0, 0) == GEN_INT (3267))
    value = BIT_ONE;
  if (code == UNSPECV_ZTT_ACQUIRE)
    state.kill (SET_DEST (set));
  else
    note_stores (insn, kill_store, &state);
  if (CALL_P (insn))
    for (unsigned int i = state.facts.length (); i-- > 0;)
      {
	rtx loc = state.facts[i].location;
	if (MEM_P (loc) || (REG_P (loc) && REGNO (loc) < FIRST_PSEUDO_REGISTER
			   && call_used_regs[REGNO (loc)]))
	  state.facts.unordered_remove (i);
      }
  if (asm_noperands (PATTERN (insn)) >= 0)
    state.facts.truncate (0);
  if (set)
    state.put (SET_DEST (set), value, constant);
}

static bool
success_edge_p (edge e, const proof_state &out)
{
  rtx_insn *end = BB_END (e->src);
  if (!end || !JUMP_P (end))
    return false;
  rtx set = pc_set (end);
  if (!set || GET_CODE (SET_SRC (set)) != IF_THEN_ELSE)
    return false;
  rtx ite = SET_SRC (set);
  if (!((XEXP (ite, 1) == pc_rtx
	 && GET_CODE (XEXP (ite, 2)) == LABEL_REF)
	|| (XEXP (ite, 2) == pc_rtx
	    && GET_CODE (XEXP (ite, 1)) == LABEL_REF)))
    return false;
  int success = condition_success (XEXP (ite, 0), out);
  if (success < 0)
    return false;
  rtx arm = XEXP (ite, success ? 1 : 2);
  return arm == pc_rtx ? (e->flags & EDGE_FALLTHRU) != 0
    : GET_CODE (arm) == LABEL_REF && !(e->flags & EDGE_FALLTHRU);
}

/* Joins retain only witnesses common to all incoming paths.  A release
   invalidates every witness, even when its scalar value is still live.  */
class region_analysis
{
  auto_vec<proof_state *> outputs;
  bool early;
public:
  region_analysis (bool early_p, bool caller_owned = false) : early (early_p)
  {
    outputs.safe_grow (last_basic_block_for_fn (cfun), true);
    for (proof_state *&p : outputs)
      p = new proof_state;
    outputs[ENTRY_BLOCK_PTR_FOR_FN (cfun)->index]->owners
      = caller_owned ? OWNED : UNKNOWN_OWNER;
    if (dump_file && caller_owned)
      fprintf (dump_file, "Ztt caller-owned entry contract\n");
    bool changed;
    do
      {
	changed = false;
	basic_block bb;
	FOR_EACH_BB_FN (bb, cfun)
	  {
	    proof_state state;
	    input (bb, state);
	    if (state.owners)
	      {
		rtx_insn *insn;
		FOR_BB_INSNS (bb, insn)
		  if (NONDEBUG_INSN_P (insn))
		    transfer (insn, state, early);
	      }
	    if (!state.equal_p (*outputs[bb->index]))
	      {
		outputs[bb->index]->copy (state);
		changed = true;
	      }
	  }
      }
    while (changed);
  }

  ~region_analysis ()
  {
    for (proof_state *p : outputs)
      delete p;
  }

  void input (basic_block bb, proof_state &state)
  {
    edge e;
    edge_iterator ei;
    FOR_EACH_EDGE (e, ei, bb->preds)
      {
	proof_state incoming;
	incoming.copy (*outputs[e->src->index]);
	if (!incoming.owners)
	  continue;
	if (e->flags & (EDGE_ABNORMAL | EDGE_EH))
	  {
	    incoming.owners = UNKNOWN_OWNER;
	    incoming.facts.truncate (0);
	  }
	else if (early && success_edge_p (e, incoming))
	  incoming.owners = OWNED;
	state.join (incoming);
      }
  }

  bool verify ()
  {
    bool valid = true;
    basic_block bb;
    FOR_EACH_BB_FN (bb, cfun)
      {
	proof_state state;
	input (bb, state);
	if (!state.owners)
	  continue;
	rtx_insn *insn;
	FOR_BB_INSNS (bb, insn)
	  if (NONDEBUG_INSN_P (insn))
	    {
	      if (owned_access_p (PATTERN (insn)) && state.owners != OWNED)
		{
		  valid = false;
		  if (dump_file)
		    fprintf (dump_file, "Unproved Ztt access: insn %d, bb %d\n",
			     INSN_UID (insn), bb->index);
		  if (!early)
		    error_at (INSN_LOCATION (insn),
			      "AME/Ztt register or context access outside "
			      "a proven ownership region");
		}
	      transfer (insn, state, early);
	    }
      }
    return valid;
  }

  void mark_success_edges ()
  {
    basic_block bb;
    FOR_EACH_BB_FN (bb, cfun)
      {
	const proof_state &out = *outputs[bb->index];
	if (!out.owners || out.owners == OWNED)
	  continue;
	edge e;
	edge_iterator ei;
	FOR_EACH_EDGE (e, ei, bb->succs)
	  if (!(e->flags & (EDGE_ABNORMAL | EDGE_EH))
	      && success_edge_p (e, out))
	    {
	      rtx head = gen_rtx_UNSPEC_VOLATILE
		(VOIDmode, gen_rtvec (1, const0_rtx), UNSPECV_ZTT_OWNED);
	      rtx effect = resource_effects
		(gen_rtx_PARALLEL (VOIDmode, gen_rtvec (1, head)));
	      insert_insn_on_edge (effect, e);
	      if (dump_file)
		fprintf (dump_file, "Ztt owned edge: bb %d -> %d\n",
			 e->src->index, e->dest->index);
	    }
      }
    commit_edge_insertions ();
  }
};

const pass_data pass_data_ztt_regions =
{
  RTL_PASS, "ztt_regions", OPTGROUP_NONE, TV_MACH_DEP,
  0, 0, 0, 0, 0
};

class pass_ztt_regions : public rtl_opt_pass
{
public:
  pass_ztt_regions (gcc::context *ctxt)
    : rtl_opt_pass (pass_data_ztt_regions, ctxt)
  {}

  bool gate (function *) final override
  {
    return TARGET_ZTT && riscv_ztt::typed_profile_p ()
      && (riscv_ztt_ownership_p () || riscv_ztt_ownership_query_p ()
	  || abnormal_edges_p ());
  }

  unsigned int execute (function *) final override
  {
    if (!typed_values_p ())
      return 0;
    for (rtx_insn *insn = get_insns (); insn; insn = NEXT_INSN (insn))
      if (NONDEBUG_INSN_P (insn) && resource_operation_p (PATTERN (insn)))
	{
	  PATTERN (insn) = resource_effects (PATTERN (insn));
	  INSN_CODE (insn) = -1;
	  if (df)
	    df_insn_rescan (insn);
	  if (dump_file)
	    fprintf (dump_file, "Ztt resource effect: insn %d, M%u, ACC%u\n",
		     INSN_UID (insn), riscv_ztt::active_profile ()->mregs,
		     riscv_ztt::active_profile ()->accregs);
	}
    region_analysis analysis (true);
    if (analysis.verify ())
      {
	analysis.mark_success_edges ();
	riscv_ztt_note_ownership_regions (false);
      }
    else if (!riscv_ztt_ownership_p ())
      {
	/* Neither observations nor their absence revoke the caller-owned
	   entry contract.  Exceptional edges invalidate that assumption;
	   no such fallback is permitted for explicit transitions.  */
	region_analysis caller_analysis (true, true);
	if (caller_analysis.verify ())
	  {
	    caller_analysis.mark_success_edges ();
	    riscv_ztt_note_ownership_regions (true);
	  }
	else if (riscv_ztt_ownership_query_p ())
	  error_at (DECL_SOURCE_LOCATION (cfun->decl),
		    "AME/Ztt query-only function cannot prove ownership "
		    "on all typed access paths");
	else
	  error_at (DECL_SOURCE_LOCATION (cfun->decl),
		    "AME/Ztt caller-owned function cannot prove ownership "
		    "on all typed access paths");
      }
    return 0;
  }
};

const pass_data pass_data_ztt_verify_regions =
{
  RTL_PASS, "ztt_verify_regions", OPTGROUP_NONE, TV_MACH_DEP,
  0, 0, 0, 0, 0
};

class pass_ztt_verify_regions : public rtl_opt_pass
{
public:
  pass_ztt_verify_regions (gcc::context *ctxt)
    : rtl_opt_pass (pass_data_ztt_verify_regions, ctxt)
  {}
  bool gate (function *) final override
  {
    return TARGET_ZTT && riscv_ztt_ownership_regions_p ();
  }
  unsigned int execute (function *) final override
  {
    region_analysis analysis (false, riscv_ztt_regions_caller_owned_p ());
    analysis.verify ();
    return 0;
  }
};

} // anonymous namespace

rtl_opt_pass *
make_pass_ztt_regions (gcc::context *ctxt)
{
  return new pass_ztt_regions (ctxt);
}

rtl_opt_pass *
make_pass_ztt_verify_regions (gcc::context *ctxt)
{
  return new pass_ztt_verify_regions (ctxt);
}
