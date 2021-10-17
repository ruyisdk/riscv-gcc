
#include "opts.h"
#include "riscv-thead-tune.h"
#include "backend.h"
#include "pass_manager.h"
#include "context.h"
#include "cfgrtl.h"
#include "cfghooks.h"

void
riscv_xthead_option_override (const struct riscv_tune_param *tune_param,
			      struct gcc_options *opts,
			      struct gcc_options *opts_set)
{
  if (!optimize_size)
    {
      SET_OPTION_IF_UNSET (opts, opts_set,
			   param_max_inline_insns_single,
			   400);
      SET_OPTION_IF_UNSET (opts, opts_set,
			   param_max_inline_insns_auto,
			   30);
    }

  SET_OPTION_IF_UNSET (opts, opts_set,
		       g_switch_value,
		       0);

  if (optimize == 2)
    SET_OPTION_IF_UNSET (opts, opts_set,
			 flag_tree_loop_distribute_patterns,
			 0);

  if (optimize == 3)
    SET_OPTION_IF_UNSET (opts, opts_set,
			 riscv_ipa_unhot_inline,
			 1);

  /* If not optimizing for size, set the default
     alignment to what the target wants.  */
  if (!opts->x_optimize_size)
    {
      if (opts->x_flag_align_loops && !opts->x_str_align_loops)
	opts->x_str_align_loops = tune_param->loop_align;
      if (opts->x_flag_align_jumps && !opts->x_str_align_jumps)
	opts->x_str_align_jumps = tune_param->jump_align;
      if (opts->x_flag_align_functions && !opts->x_str_align_functions)
	opts->x_str_align_functions = tune_param->function_align;
    }

  /* Set the defualt max-rtl-if-conversion-unpredictable-cost to 100
     to generate more conditional move instructions.  */
  if (!opts->x_optimize_size
      && TARGET_XTHEAD_C)
    {
      SET_OPTION_IF_UNSET (opts, opts_set,
			   param_max_rtl_if_conversion_unpredictable_cost,
			   tune_param->ifcvt_unpred);
    }

  if (!opts_set->x_riscv_4k_optimize && riscv_microarchitecture == c910)
    opts->x_riscv_4k_optimize = 1;
}

bool
riscv_xthead_rtx_costs (rtx x, machine_mode mode, int outer_code,
			int opno ATTRIBUTE_UNUSED, int *total,
			bool speed ATTRIBUTE_UNUSED)
{
  switch (GET_CODE (x))
    {
    case IF_THEN_ELSE:
      if (!optimize_size && TARGET_XTHEAD_C
	  && GET_CODE (XEXP (x, 1)) == REG && GET_CODE (XEXP (x, 2)) == REG)
	{
	  *total = tune_param->if_then_else;
	  return true;
	}
      return false;
    case ZERO_EXTRACT:
      if (outer_code == SET && TARGET_XTHEAD_EXT)
	{
	  *total = COSTS_N_INSNS (SINGLE_SHIFT_COST);
	  return true;
	}
      return false;
    case IOR:
      if (TARGET_XTHEAD_SRRIW
	  && outer_code == SET
	  && GET_CODE (XEXP (x, 0)) == ASHIFT
	  && GET_CODE (XEXP (x, 1)) == ZERO_EXTRACT)
	{
	  rtx ashift_op0 = XEXP (XEXP (x, 0), 0);
	  rtx ashift_op1 = XEXP (XEXP (x, 0), 1);
	  rtx zeroext_op0 = XEXP (XEXP (x, 1), 0);
	  rtx zeroext_op1 = XEXP (XEXP (x, 1), 1);
	  rtx zeroext_op2 = XEXP (XEXP (x, 1), 2);
	  if (REG_P (ashift_op0) && REG_P (zeroext_op0)
	      && CONST_INT_P (ashift_op1)
	      && CONST_INT_P (zeroext_op1)
	      && CONST_INT_P (zeroext_op2)
	      && INTVAL (ashift_op1) == INTVAL (zeroext_op1)
	      && (INTVAL (zeroext_op1) + INTVAL (zeroext_op2)) == 32)
	    {
		  *total = COSTS_N_INSNS (SINGLE_SHIFT_COST);
		  return true;
	    }
	}
      return false;
    case SET:
      if (riscv_vector_mode_vext_except_pext_supported_p (mode)
	  && REG_P (XEXP (x, 0))
	  && REG_P (XEXP (x, 1)))
	{
	  *total = COSTS_N_INSNS (3);
	  return true;
	}
      else
	return false;
    default:
      return false;
    }
}

/* Return true if address offset is a valid index.  If it is, fill in INFO
   appropriately.  STRICT_P is true if REG_OK_STRICT is in effect.  */

bool
riscv_classify_address_index (struct riscv_address_info *info, rtx x,
      machine_mode mode, bool strict_p)
{
  enum riscv_address_type type = ADDRESS_REG_REG;;
  rtx index;
  int shift = 0;

  if (!TARGET_XTHEAD_LDR)
    return false;

  if (!TARGET_64BIT && mode == DImode)
    return false;

  if (SCALAR_FLOAT_MODE_P (mode))
    {
      if (!TARGET_HARD_FLOAT)
	return false;
      if (!TARGET_XTHEAD_FLDR)
	return false;
      if (GET_MODE_SIZE (mode) == 2)
	return false;
    }

  /* (reg:P) */
  if ((REG_P (x) || GET_CODE (x) == SUBREG)
      && GET_MODE (x) == Pmode)
    {
      index = x;
      shift = 0;
    }
  /* (zero_extend:DI (reg:SI)) */
  else if (GET_CODE (x) == ZERO_EXTEND
	   && GET_MODE (x) == DImode
	   && GET_MODE (XEXP (x, 0)) == SImode)
    {
      type = ADDRESS_REG_UREG;
      index = XEXP (x, 0);
      shift = 0;
    }
  /* (mult:DI (zero_extend:DI (reg:SI)) (const_int scale)) */
  else if (GET_CODE (x) == MULT
	   && GET_CODE (XEXP (x, 0)) == ZERO_EXTEND
	   && GET_MODE (XEXP (x, 0)) == DImode
	   && GET_MODE (XEXP (XEXP (x, 0), 0)) == SImode
	   && CONST_INT_P (XEXP (x, 1)))
    {
      type = ADDRESS_REG_UREG;
      index = XEXP (XEXP (x, 0), 0);
      shift = exact_log2 (INTVAL (XEXP (x, 1)));
    }
  /* (ashift:DI (zero_extend:DI (reg:SI)) (const_int shift)) */
  else if (GET_CODE (x) == ASHIFT
	   && GET_CODE (XEXP (x, 0)) == ZERO_EXTEND
	   && GET_MODE (XEXP (x, 0)) == DImode
	   && GET_MODE (XEXP (XEXP (x, 0), 0)) == SImode
	   && CONST_INT_P (XEXP (x, 1)))
    {
      type = ADDRESS_REG_UREG;
      index = XEXP (XEXP (x, 0), 0);
      shift = INTVAL (XEXP (x, 1));
    }
  /* (mult:P (reg:P) (const_int scale)) */
  else if (GET_CODE (x) == MULT
	   && GET_MODE (x) == Pmode
	   && GET_MODE (XEXP (x, 0)) == Pmode
	   && CONST_INT_P (XEXP (x, 1)))
    {
      index = XEXP (x, 0);
      shift = exact_log2 (INTVAL (XEXP (x, 1)));
    }
  /* (ashift:P (reg:P) (const_int shift)) */
  else if (GET_CODE (x) == ASHIFT
	   && GET_MODE (x) == Pmode
	   && GET_MODE (XEXP (x, 0)) == Pmode
	   && CONST_INT_P (XEXP (x, 1)))
    {
      index = XEXP (x, 0);
      shift = INTVAL (XEXP (x, 1));
    }
  else
    return false;

  if (shift != 0 && !IN_RANGE (shift, 1, 3))
    return false;

  if (!strict_p
      && GET_CODE (index) == SUBREG
      && contains_reg_of_mode[GENERAL_REGS][GET_MODE (SUBREG_REG (index))])
    index = SUBREG_REG (index);

  if (riscv_valid_base_register_p (index, mode, strict_p))
    {
      info->type = type;
      info->offset = index;
      info->shift = shift;
      return true;
    }

  return false;
}

/* Return true if address is a valid modify.  If it is, fill in INFO
   appropriately.  STRICT_P is true if REG_OK_STRICT is in effect.  */

bool
riscv_classify_address_modify (struct riscv_address_info *info, rtx x,
      machine_mode mode, bool strict_p)
{

#define AM_IMM(BIT) (1LL << (5 + (BIT)))
#define AM_OFFSET(VALUE, SHIFT) (\
  ((unsigned HOST_WIDE_INT) (VALUE) + AM_IMM (SHIFT)/2 < AM_IMM (SHIFT)) \
  && !((unsigned HOST_WIDE_INT) (VALUE) & ((1 << (SHIFT)) - 1)) \
  ? (SHIFT) + 1 \
  : 0)

  if (!TARGET_XTHEAD_LDI)
    return false;

  if (!SCALAR_INT_MODE_P (mode) && !riscv_vector_mode_pext_supported_p (mode))
    return false;

  if (!TARGET_64BIT && mode == DImode)
    return false;

  if (GET_CODE (x) != POST_MODIFY
      && GET_CODE (x) != PRE_MODIFY)
    return false;

  info->type = ADDRESS_REG_WB;
  info->reg = XEXP (x, 0);

  if (GET_CODE (XEXP (x, 1)) == PLUS
      && CONST_INT_P (XEXP (XEXP (x, 1), 1))
      && rtx_equal_p (XEXP (XEXP (x, 1), 0), info->reg)
      && riscv_valid_base_register_p (info->reg, mode, strict_p))
    {
      info->offset = XEXP (XEXP (x, 1), 1);
      int shift = AM_OFFSET (INTVAL (info->offset), 0);
      if (!shift)
	shift = AM_OFFSET (INTVAL (info->offset), 1);
      if (!shift)
	shift = AM_OFFSET (INTVAL (info->offset), 2);
      if (!shift)
	shift = AM_OFFSET (INTVAL (info->offset), 3);
      if (shift)
	{
	  info->shift = shift - 1;
	  return true;
	}
    }

  return false;
}

/* Return TRUE if X is a legitimate address modify.  */

bool
riscv_legitimize_address_modify_p (rtx x, machine_mode mode, bool post)
{
  struct riscv_address_info addr;
  return riscv_classify_address_modify (&addr, x, mode, false)
	 && (!post || GET_CODE (x) == POST_MODIFY);
}

/* Return the LDIB/LDIA and STIB/STIA instructions.  Assume
   that X is MEM operand.  */

const char *
riscv_output_move_modify (rtx x, machine_mode mode, bool ldi)
{
  static char buf[128] = {0};

  int index = exact_log2 (GET_MODE_SIZE (mode));
  if (!IN_RANGE (index, 0, 3))
    return NULL;

  if (!riscv_legitimize_address_modify_p (x, mode, false))
    return NULL;

  bool post = riscv_legitimize_address_modify_p (x, mode, true);

  const char *const insn[][4] =
  {
    {
      "sbi%s\t%%z1,%%0",
      "shi%s\t%%z1,%%0",
      "swi%s\t%%z1,%%0",
      "sdi%s\t%%z1,%%0"
    },
    {
      "lbui%s\t%%0,%%1",
      "lhui%s\t%%0,%%1",
      "lwi%s\t%%0,%%1",
      "ldi%s\t%%0,%%1"
    }
  };

  snprintf (buf, sizeof (buf), insn[ldi][index], post ? "a" : "b");
  return buf;
}

/* Return TRUE if X is a legitimate address index.  */

bool
riscv_legitimize_address_index_p (rtx x, machine_mode mode, bool uindex)
{
  struct riscv_address_info addr;
  rtx op0, op1;

  if (GET_CODE (x) != PLUS)
    return false;

  op0 = XEXP (x, 0);
  op1 = XEXP (x, 1);

  return ((riscv_valid_base_register_p (op0, mode, false)
	   && riscv_classify_address_index (&addr, op1, mode, false))
	  || (riscv_valid_base_register_p (op1, mode, false)
	      && riscv_classify_address_index (&addr, op0, mode, false)))
	 && (!uindex || addr.type == ADDRESS_REG_UREG);
}

/* Return the LDR or STR instructions.  Assume
   that X is MEM operand.  */

const char *
riscv_output_move_index (rtx x, machine_mode mode, bool ldr)
{
  static char buf[128] = {0};

  int index = exact_log2 (GET_MODE_SIZE (mode));
  if (!IN_RANGE (index, 0, 3))
    return NULL;

  if (!riscv_legitimize_address_index_p (x, mode, false))
    return NULL;

  bool uindex = riscv_legitimize_address_index_p (x, mode, true);

  const char *const insn[][4] =
  {
    {
      "s%srb\t%%z1,%%0",
      "s%srh\t%%z1,%%0",
      "s%srw\t%%z1,%%0",
      "s%srd\t%%z1,%%0"
    },
    {
      "l%srbu\t%%0,%%1",
      "l%srhu\t%%0,%%1",
      "l%srw\t%%0,%%1",
      "l%srd\t%%0,%%1"
    }
  };

  snprintf (buf, sizeof (buf), insn[ldr][index], uindex ? "u" : "");

  return buf;
}

const char *
riscv_output_move_index_float (rtx x, machine_mode mode, bool ldr)
{
  static char buf[128] = {0};

  int index = exact_log2 (GET_MODE_SIZE (mode));
  if (!IN_RANGE (index, 0, 3))
    return NULL;

  if (!riscv_legitimize_address_index_p (x, mode, false))
    return NULL;

  bool uindex = riscv_legitimize_address_index_p (x, mode, true);

  const char *const insn[][4] =
  {
    {
      "fs%srb\t%%1,%%0",
      "fs%srh\t%%1,%%0",
      "fs%srw\t%%1,%%0",
      "fs%srd\t%%1,%%0"
    },
    {
      "fl%srb\t%%0,%%1",
      "fl%srh\t%%0,%%1",
      "fl%srw\t%%0,%%1",
      "fl%srd\t%%0,%%1"
    }
  };

  snprintf (buf, sizeof (buf), insn[ldr][index], uindex ? "u" : "");

  return buf;
}

/* Return true if address is a valid pair.  If it is, fill in INFO
   appropriately.  STRICT_P is true if REG_OK_STRICT is in effect.  */

static bool
riscv_classify_address_pair (struct riscv_address_info *info, rtx x,
      machine_mode mode, bool strict_p, bool ldd ATTRIBUTE_UNUSED)
{

#define AP_IMM (1LL << 7)
#define AP_OFFSET(VALUE) \
  ((unsigned HOST_WIDE_INT) (VALUE) + AP_IMM/2 < AP_IMM)

  if (GET_CODE (x) == PLUS)
    {
      info->reg = XEXP (x, 0);
      info->offset = XEXP (x, 1);
      if (INTVAL (info->offset) % (2 * GET_MODE_SIZE (mode)) != 0)
	return false;
      return (riscv_valid_base_register_p (info->reg, mode, strict_p)
	      && CONST_INT_P (info->offset)
	      && AP_OFFSET (INTVAL (info->offset)));
    }

  if (GET_CODE (x) == REG
      || GET_CODE (x) == SUBREG)
    {
      info->reg = x;
      info->offset = const0_rtx;
      return riscv_valid_base_register_p (info->reg, mode, strict_p);
    }

  return false;
}

/* Return TRUE if X is a legitimate address pair.  */

bool
riscv_legitimize_address_pair_p (rtx x, machine_mode mode, bool ldd)
{
  struct riscv_address_info addr;
  return riscv_classify_address_pair (&addr, x, mode, false, ldd);
}

int
riscv_expand_movcc (rtx *operands)
{
  enum rtx_code code = GET_CODE (operands[1]);
  enum rtx_code new_code = code;
  machine_mode cmp0_mode = GET_MODE (XEXP (operands[1], 0));
  rtx cmp_op0 = XEXP (operands[1], 0);
  rtx cmp_op1 = XEXP (operands[1], 1);
  rtx tmp;

  if (GET_MODE_CLASS (cmp0_mode) != MODE_INT)
    return -1;
  else if ((GET_CODE (operands[1]) == EQ || GET_CODE (operands[1]) == NE)
	   && cmp_op1 == const0_rtx)
    {
      riscv_extend_comparands (code, &cmp_op0, &cmp_op1);
      cmp_op0 = force_reg (word_mode, cmp_op0);
      XEXP (operands[1], 0) = cmp_op0;
      /* If the operands[1] rtx is already (eq X 0) or (ne X 0),
	 we have gcc generate original template rtx.  */
      return 1;
    }
  else
    {
      bool reverse = false;

      tmp = gen_reg_rtx (TARGET_64BIT ? DImode : SImode);

      riscv_expand_int_scc (tmp, new_code,
			    cmp_op0, cmp_op1);

      operands[1] = gen_rtx_fmt_ee (reverse ? EQ : NE,
				    VOIDmode, tmp, const0_rtx);
    }
  return 1;
}

/* Return true if address is a valid vector.  If it is, fill in INFO
   appropriately.  STRICT_P is true if REG_OK_STRICT is in effect.  */

bool
riscv_classify_address_vector (struct riscv_address_info *info, rtx x,
  machine_mode mode, bool strict_p)
{
  if (reload_completed
      && (GET_CODE (x) == LABEL_REF
	  || (GET_CODE (x) == CONST
	      && GET_CODE (XEXP (x, 0)) == PLUS
	      && GET_CODE (XEXP (XEXP (x, 0), 0)) == LABEL_REF
	      && CONST_INT_P (XEXP (XEXP (x, 0), 1)))))
    return true;

  switch (GET_CODE (x))
    {
    case REG:
    case SUBREG:
      info->type = ADDRESS_REG;
      info->reg = x;
      info->offset = const0_rtx;
      return riscv_valid_base_register_p (x, mode, strict_p);

    case PLUS:
      info->type = ADDRESS_REG;
      info->reg = XEXP (x, 0);
      info->offset = XEXP (x, 1);
      return INTVAL (info->offset) == 0;

    default:
      return false;
    }
}

/* Return TRUE if X is a legitimate address vector.  */

bool
riscv_legitimize_address_vector_p (rtx x, machine_mode mode)
{
  struct riscv_address_info addr;
  return riscv_vector_mode_vext_supported_p (mode)
	 && riscv_classify_address_vector (&addr, x, mode, false);
}

bool
riscv_save_reg_ipush_p (int regno)
{
  int regs[] = {
    RETURN_ADDR_REGNUM,
    T0_REGNUM, T1_REGNUM, T2_REGNUM,
    A0_REGNUM, A1_REGNUM, A2_REGNUM, A3_REGNUM,
    A4_REGNUM, A5_REGNUM, A6_REGNUM, A7_REGNUM,
    T3_REGNUM, T4_REGNUM, T5_REGNUM, T6_REGNUM,
  };

  for (unsigned int i = 0; i < ARRAY_SIZE (regs); i++)
    {
      if (GP_REG_P (regno) && regno == regs[i] + GP_REG_FIRST)
	return true;
    }
  return false;
}

rtx
riscv_adjust_ipush_cfi_prologue ()
{
  rtx dwarf = NULL_RTX;
  rtx adjust_sp_rtx, reg, mem, insn;
  int saved_size = cfun->machine->frame.save_ipush_adjustment;
  int offset = saved_size - UNITS_PER_WORD * 2;

  for (int regno = GP_REG_FIRST; regno <= GP_REG_LAST; regno++)
    if (BITSET_P (cfun->machine->frame.imask, regno - GP_REG_FIRST))
      {
	offset -= UNITS_PER_WORD;
	reg = gen_rtx_REG (SImode, regno);
	mem = gen_frame_mem (SImode, plus_constant (Pmode,
						    stack_pointer_rtx,
						    offset));

	insn = gen_rtx_SET (mem, reg);
	dwarf = alloc_reg_note (REG_CFA_OFFSET, insn, dwarf);
      }

  /* Debug info for adjust sp.  */
  adjust_sp_rtx = gen_rtx_SET (stack_pointer_rtx,
	gen_rtx_PLUS (GET_MODE(stack_pointer_rtx), stack_pointer_rtx, GEN_INT (-saved_size)));
  dwarf = alloc_reg_note (REG_CFA_ADJUST_CFA, adjust_sp_rtx, dwarf);

  return dwarf;
}

/* Implement TARGET_MANGLE_TYPE.  */

extern const char *riscv_mangle_builtin_type (const_tree type);

static const char *
riscv_mangle_type (const_tree type)
{
  /* Mangle riscv-specific internal types.  TYPE_NAME is non-NULL_TREE for
    builtin types.  */
  if (TYPE_NAME (type) != NULL)
    return riscv_mangle_builtin_type (type);

  /* Use the default mangling.  */
  return NULL;
}

/* Implement TARGET_SCALAR_MODE_SUPPORTED_P - return TRUE
   if MODE is HFmode, and punt to the generic implementation otherwise.  */

static bool
riscv_scalar_mode_supported_p (scalar_mode mode)
{
  return (TARGET_XTHEAD_FP16 && mode == HFmode)
	 || default_scalar_mode_supported_p (mode);
}

/* Implement TARGET_LIBGCC_FLOATING_POINT_MODE_SUPPORTED_P - return TRUE
   if MODE is HFmode, and punt to the generic implementation otherwise.  */

static bool
riscv_libgcc_floating_mode_supported_p (scalar_float_mode mode)
{
  return (TARGET_XTHEAD_FP16 && mode == HFmode
    ? true
    : default_libgcc_floating_mode_supported_p (mode));
}

/* Set the value of FLT_EVAL_METHOD.
   ISO/IEC TS 18661-3 defines two values that we'd like to make use of:

    0: evaluate all operations and constants, whose semantic type has at
       most the range and precision of type float, to the range and
       precision of float; evaluate all other operations and constants to
       the range and precision of the semantic type;

    N, where _FloatN is a supported interchange floating type
       evaluate all operations and constants, whose semantic type has at
       most the range and precision of _FloatN type, to the range and
       precision of the _FloatN type; evaluate all other operations and
       constants to the range and precision of the semantic type;
*/

static enum flt_eval_method
riscv_c_excess_precision (enum excess_precision_type type)
{
  switch (type)
    {
    case EXCESS_PRECISION_TYPE_FAST:
    case EXCESS_PRECISION_TYPE_STANDARD:
      /* We can calculate either in 16-bit range and precision or
	  32-bit range and precision. */
      return (TARGET_XTHEAD_FP16
	      ? FLT_EVAL_METHOD_PROMOTE_TO_FLOAT16
	      : FLT_EVAL_METHOD_PROMOTE_TO_FLOAT);
    case EXCESS_PRECISION_TYPE_IMPLICIT:
      return FLT_EVAL_METHOD_PROMOTE_TO_FLOAT16;
    default:
      gcc_unreachable ();
    }
  return FLT_EVAL_METHOD_UNPREDICTABLE;
}

#undef TARGET_C_EXCESS_PRECISION
#define TARGET_C_EXCESS_PRECISION riscv_c_excess_precision

#undef TARGET_LIBGCC_FLOATING_MODE_SUPPORTED_P
#define TARGET_LIBGCC_FLOATING_MODE_SUPPORTED_P \
  riscv_libgcc_floating_mode_supported_p

#undef TARGET_SCALAR_MODE_SUPPORTED_P
#define TARGET_SCALAR_MODE_SUPPORTED_P riscv_scalar_mode_supported_p

#undef TARGET_MANGLE_TYPE
#define TARGET_MANGLE_TYPE riscv_mangle_type

static unsigned
riscv_pass_mode_in_vr_p (machine_mode mode)
{
  if (GET_MODE_SIZE (mode) <= UNITS_PER_VR_ARG
      && riscv_vector_mode_vext_supported_p (mode))
    {
      return (GET_MODE_SIZE (mode) + UNITS_PER_VR_REG - 1) / UNITS_PER_VR_REG;
    }

  return 0;
}

/* Helper function for riscv_get_arg_info(); deal with v-ext arg.  */

rtx
riscv_get_varg_info (struct riscv_arg_info *info,
		     machine_mode mode, const_tree type,
		     bool return_p)
{
  rtx ret = NULL_RTX;

  /* Don't mess wih P-ext's rules. */
  if (riscv_vector_mode_pext_supported_p (mode))
    return ret;

  unsigned vr_base = return_p ? VR_RETURN : VR_ARG_FIRST;
  unsigned vregno = vr_base + info->vr_offset;

  info->num_vrs = riscv_pass_mode_in_vr_p (mode);
  if (!info->num_vrs)
    return ret;

  if (info->vr_offset + info->num_vrs > MAX_ARGS_IN_VREGISTERS)
    {
      info->num_vrs = 0;
      return ret;
    }

  ret = gen_rtx_REG (mode, vregno);
  return ret;
}

void
riscv_save_vreg (rtx reg, rtx mem)
{
  if (GET_CODE (XEXP (mem, 0)) == PLUS)
    {
      rtx tmp = RISCV_PROLOGUE_TEMP (word_mode), insn, dest;
      riscv_emit_move (tmp, XEXP (XEXP (mem, 0), 1));
      insn = emit_insn (gen_add3_insn (tmp, stack_pointer_rtx, tmp));
      dest = gen_rtx_MEM (GET_MODE (reg), tmp);
      riscv_emit_move (dest, reg);
      add_reg_note (insn, REG_FRAME_RELATED_EXPR, gen_rtx_SET (mem, reg));
      RTX_FRAME_RELATED_P (insn) = 1;
    }
  else
    {
      rtx tmp = gen_rtx_REG (SImode, 0);
      if (TARGET_XTHEAD_VLEN (128))
	{
	  riscv_emit_vsetvli (V4SImode, tmp, tmp);
	  emit_insn (gen_riscv_vsev_v4si_internal (mem, reg, tmp));
	}
      riscv_set_frame_expr (riscv_frame_set (mem, reg));
    }
}

void
riscv_restore_vreg (rtx reg, rtx mem)
{
  rtx insn;

  if (GET_CODE (XEXP (mem, 0)) == PLUS)
    {
      rtx tmp = RISCV_PROLOGUE_TEMP (word_mode), src;
      riscv_emit_move (tmp, XEXP (XEXP (mem, 0), 1));
      insn = emit_insn (gen_add3_insn (tmp, stack_pointer_rtx, tmp));
      src = gen_rtx_MEM (GET_MODE (reg), tmp);
      riscv_emit_move (reg, src);
      add_reg_note (insn, REG_CFA_RESTORE, reg);
      RTX_FRAME_RELATED_P (insn) = 1;
    }
  else
    {
      rtx tmp = gen_rtx_REG (SImode, 0);
      if (TARGET_XTHEAD_VLEN (128))
	{
	  riscv_emit_vsetvli (V4SImode, tmp, tmp);
	  insn = emit_insn (gen_riscv_vlev_v4si_internal (reg, mem, tmp));
	}
      add_reg_note (insn, REG_CFA_RESTORE, reg);
      RTX_FRAME_RELATED_P (insn) = 1;
    }
}

rtx
riscv_emit_vsetvli_base (machine_mode mode, rtx gvl, rtx avl, rtx nf)
{
  int isew = -1;
  riscv_classify_vext_mode (mode, &isew, NULL, false);
  gcc_assert (isew != -1);
  rtx sew = gen_rtx_CONST_INT (VOIDmode, isew);

  int mul = (GET_MODE_SIZE (mode) + UNITS_PER_VR_REG - 1) / UNITS_PER_VR_REG;

  if (nf)
    {
      int nf_value = INTVAL (nf);
      mul /= nf_value;
    }

  gcc_assert (exact_log2 (mul) != -1);
  rtx lmul = gen_rtx_CONST_INT (VOIDmode, exact_log2 (mul));

  if (avl == NULL_RTX
      || (REG_P (avl) && REGNO (avl) == 0))
    emit_insn (gen_riscv_vsetvli_max (gvl, sew, lmul));
  else
    emit_insn (gen_riscv_vsetvli (gvl, avl, sew, lmul));
  return gvl;
}

rtx
riscv_emit_vsetvli (machine_mode mode, rtx gvl, rtx avl)
{
  return riscv_emit_vsetvli_base (mode, gvl, avl, NULL);
}

rtx
riscv_emit_vsetvli_max (machine_mode mode)
{
  rtx gvl = gen_rtx_REG (SImode, 0);
  return riscv_emit_vsetvli (mode, gvl, NULL_RTX);
}

const char *
riscv_output_vector_sew (int index)
{
  const char *sew[] = {"e8", "e16", "e32", "e64"};
  return sew[index];
}

const char *
riscv_output_vector_lmul (int index)
{
  const char *lmul[] = {"m1", "m2", "m4", "m8"};
  return lmul[index];
}

const char *
riscv_output_vector_insn (machine_mode mode ATTRIBUTE_UNUSED, const char *insn)
{
  return insn;
  #if 0
  static char buf[128] = {0};
  const char *pattern = "vsetvli\tx0,x0,%s,%s\n\t%s";

  int sew = -1;
  riscv_classify_vext_mode (mode, &sew, NULL, false);
  gcc_assert (sew != -1);
  int lmul = exact_log2 ((GET_MODE_SIZE (mode) + UNITS_PER_VR_REG - 1) / UNITS_PER_VR_REG);

  snprintf (buf, sizeof (buf), pattern,
	    riscv_output_vector_sew (sew),
	    riscv_output_vector_lmul (lmul),
	    insn);
  return buf;
  #endif
}

rtx
riscv_legitimize_vector_address (rtx x, machine_mode mode)
{
  rtx addr;

  /* Handle BASE + OFFSET.  */
  if (GET_CODE (x) == PLUS && CONST_INT_P (XEXP (x, 1))
      && INTVAL (XEXP (x, 1)) != 0)
    {
      rtx base = XEXP (x, 0);
      HOST_WIDE_INT offset = INTVAL (XEXP (x, 1));

      if (!riscv_valid_base_register_p (base, mode, false))
	base = copy_to_mode_reg (Pmode, base);

	rtx base_reg = gen_reg_rtx (Pmode);
	rtx val = force_operand (plus_constant (Pmode, base, offset), NULL_RTX);
	emit_move_insn (base_reg, val);
	base = base_reg;
	offset = 0;

      addr = riscv_add_offset (NULL, base, offset);
      return riscv_force_address (addr, mode);
    }
  return x;
}

machine_mode
riscv_vector_register_mode (machine_mode mode)
{
  if ((GET_MODE_SIZE (mode) * BITS_PER_UNIT) < riscv_vlen
      || !(TARGET_XTHEAD_VLEN (128) || TARGET_XTHEAD_VLEN (64)))
      gcc_unreachable ();

  switch (mode)
  {
    case E_V1DImode:
    case E_V2DImode:
    case E_V4DImode:
    case E_V8DImode:
    case E_V16DImode:
      return (TARGET_XTHEAD_VLEN (128) ? E_V2DImode : V1DImode);
    case E_V2SImode:
    case E_V4SImode:
    case E_V8SImode:
    case E_V16SImode:
    case E_V32SImode:
      return (TARGET_XTHEAD_VLEN (128) ? E_V4SImode : E_V2SImode);
    case E_V4HImode:
    case E_V8HImode:
    case E_V16HImode:
    case E_V32HImode:
    case E_V64HImode:
      return (TARGET_XTHEAD_VLEN (128) ? E_V8HImode : E_V4HImode);
    case E_V8QImode:
    case E_V16QImode:
    case E_V32QImode:
    case E_V64QImode:
    case E_V128QImode:
      return (TARGET_XTHEAD_VLEN (128) ? E_V16QImode : E_V8QImode);
    case E_V1DFmode:
    case E_V2DFmode:
    case E_V4DFmode:
    case E_V8DFmode:
    case E_V16DFmode:
      return (TARGET_XTHEAD_VLEN (128) ? E_V2DFmode : E_V1DFmode);
    case E_V2SFmode:
    case E_V4SFmode:
    case E_V8SFmode:
    case E_V16SFmode:
    case E_V32SFmode:
      return (TARGET_XTHEAD_VLEN (128) ? E_V4SFmode : E_V2SFmode);
    case E_V4HFmode:
    case E_V8HFmode:
    case E_V16HFmode:
    case E_V32HFmode:
    case E_V64HFmode:
      return (TARGET_XTHEAD_VLEN (128) ? E_V8HFmode : E_V4HFmode);
    default:
      gcc_unreachable ();
  }
}

void *
riscv_classify_vext_mode (machine_mode mode, int *sew, int *lmul,
			  bool enabled)
{
  typedef struct {
    int lmul;
    int sew;
    machine_mode mode;
    int enabled;
  } vmode_t;

  static vmode_t vmode[] = {
    { -1, RVV_E8,  V8QImode  , TARGET_XTHEAD_VLEN (64) },
    { -1, RVV_E8,  V16QImode , TARGET_XTHEAD_VECTOR },
    { -1, RVV_E8,  V32QImode , TARGET_XTHEAD_VECTOR },
    { -1, RVV_E8,  V64QImode , TARGET_XTHEAD_VECTOR },
    { -1, RVV_E8,  V128QImode, TARGET_XTHEAD_VECTOR },

    { -1, RVV_E16, V4HImode  , TARGET_XTHEAD_VLEN (64) },
    { -1, RVV_E16, V8HImode  , TARGET_XTHEAD_VECTOR },
    { -1, RVV_E16, V16HImode , TARGET_XTHEAD_VECTOR },
    { -1, RVV_E16, V32HImode , TARGET_XTHEAD_VECTOR },
    { -1, RVV_E16, V64HImode , TARGET_XTHEAD_VECTOR },

    { -1, RVV_E32, V2SImode  , TARGET_XTHEAD_VLEN (64) },
    { -1, RVV_E32, V4SImode  , TARGET_XTHEAD_VECTOR },
    { -1, RVV_E32, V8SImode  , TARGET_XTHEAD_VECTOR },
    { -1, RVV_E32, V16SImode , TARGET_XTHEAD_VECTOR },
    { -1, RVV_E32, V32SImode , TARGET_XTHEAD_VECTOR },

    { -1, RVV_E64, V1DImode  , TARGET_XTHEAD_VLEN (64) },
    { -1, RVV_E64, V2DImode  , TARGET_XTHEAD_VECTOR },
    { -1, RVV_E64, V4DImode  , TARGET_XTHEAD_VECTOR },
    { -1, RVV_E64, V8DImode  , TARGET_XTHEAD_VECTOR },
    { -1, RVV_E64, V16DImode , TARGET_XTHEAD_VECTOR },

    { -1, -1, V1TImode , 0 },
    { -1, -1, V2TImode , 0 },
    { -1, -1, V4TImode , 0 },
    { -1, -1, V8TImode , 0 },

    { -1, RVV_E16, V4HFmode  , TARGET_XTHEAD_VLEN (64) },
    { -1, RVV_E16, V8HFmode  , TARGET_XTHEAD_VECTOR },
    { -1, RVV_E16, V16HFmode , TARGET_XTHEAD_VECTOR },
    { -1, RVV_E16, V32HFmode , TARGET_XTHEAD_VECTOR },
    { -1, RVV_E16, V64HFmode , TARGET_XTHEAD_VECTOR },

    { -1, RVV_E32, V2SFmode  , TARGET_XTHEAD_VLEN (64) },
    { -1, RVV_E32, V4SFmode  , TARGET_XTHEAD_VECTOR },
    { -1, RVV_E32, V8SFmode  , TARGET_XTHEAD_VECTOR },
    { -1, RVV_E32, V16SFmode , TARGET_XTHEAD_VECTOR },
    { -1, RVV_E32, V32SFmode , TARGET_XTHEAD_VECTOR },

    { -1, RVV_E64, V1DFmode  , TARGET_XTHEAD_VLEN (64) },
    { -1, RVV_E64, V2DFmode  , TARGET_XTHEAD_VECTOR },
    { -1, RVV_E64, V4DFmode  , TARGET_XTHEAD_VECTOR },
    { -1, RVV_E64, V8DFmode  , TARGET_XTHEAD_VECTOR },
    { -1, RVV_E64, V16DFmode , TARGET_XTHEAD_VECTOR },

#define RVV_VECTOR_SEG_TYPE_DEF(MODE, ELTYPE, LMUL, NF, AVAIL, SEW, VLEN, UNSIGNED) \
  { LMUL, RVV_E##SEW, MODE,  TARGET_XTHEAD_VLEN (VLEN)},
#include "config/riscv/riscv-vector-seg-type.def"
#undef RVV_VECTOR_SEG_TYPE_DEF

  };

  if (!(TARGET_XTHEAD_VECTOR || enabled))
    return NULL;

  for (unsigned int i = 0; i < ARRAY_SIZE (vmode); i++)
    {
      if (!(vmode[i].enabled || enabled))
	continue;
      if (vmode[i].mode != mode)
	continue;
      if (sew)
	*sew = vmode[i].sew;
      if (lmul)
	*lmul = vmode[i].lmul;
      return &vmode[i];
    }

  return NULL;
}

bool
riscv_vector_mode_vext_supported_p (machine_mode mode)
{
  return riscv_classify_vext_mode (mode, NULL, NULL, false) != NULL;
}

bool
riscv_vector_mode_pext_supported_p (machine_mode mode)
{
  if (TARGET_XTHEAD_DSP || TARGET_XTHEAD_ZPSFOPERAND)
    {
      switch (mode)
      {
	case E_V2HImode:
	case E_V4QImode:
	case E_V2SImode:
	case E_V4HImode:
	case E_V8QImode:
	  return true;
	default:
	  break;
      }
    }
  return false;
}

/* Implement TARGET_VECTOR_MODE_SUPPORTED_P.  */

bool
riscv_vector_mode_supported_p (machine_mode mode)
{
  return riscv_vector_mode_pext_supported_p (mode)
	 ||riscv_vector_mode_vext_supported_p (mode);
}

/* In many cases, the mode supported by P-ext shouldn't be treat as the mode
   supported by V-ext.  */

bool
riscv_vector_mode_vext_except_pext_supported_p (machine_mode mode)
{
  return riscv_vector_mode_vext_supported_p (mode)
	 && !riscv_vector_mode_pext_supported_p (mode);
}

/* Implement TARGET_VECTORIZE_PREFERRED_SIMD_MODE.  */

static machine_mode
riscv_preferred_simd_mode (scalar_mode mode)
{
  if (TARGET_XTHEAD_VECTOR)
    {
      if (TARGET_XTHEAD_VLEN (64))
	switch (mode)
	  {
	  case E_SFmode:
	    return V4SFmode;
	  case E_HFmode:
	    return V8HFmode;
	  case E_SImode:
	    return V4SImode;
	  case E_HImode:
	    return V8HImode;
	  case E_QImode:
	    return V16QImode;
	  default:
	    break;
	  }
      else if (TARGET_XTHEAD_VLEN (128))
	switch (mode)
	  {
	  case E_SFmode:
	    return V8SFmode;
	  case E_HFmode:
	    return V16HFmode;
	  case E_SImode:
	    return V8SImode;
	  case E_HImode:
	    return V16HImode;
	  case E_QImode:
	    return V32QImode;
	  default:
	    break;
	  }
    }

  if (TARGET_XTHEAD_DSP)
    {
      if (TARGET_64BIT)
	switch (mode)
	  {
	  case E_SImode:
	    return V2SImode;
	  case E_HImode:
	    return V4HImode;
	  case E_QImode:
	    return V8QImode;
	  default:
	    break;
	  }
      else
	switch (mode)
	  {
	  case E_HImode:
	    return V2HImode;
	  case E_QImode:
	    return V4QImode;
	  default:
	    break;
	  }
    }

  if (TARGET_XTHEAD_ZPSFOPERAND)
    if (mode == E_HImode) return E_V2HImode;

  return word_mode;
}

/* Implement TARGET_ARRAY_MODE_SUPPORTED_P.  */

static bool
riscv_array_mode_supported_p (machine_mode mode,
			      unsigned HOST_WIDE_INT nelems ATTRIBUTE_UNUSED)
{
  return riscv_vector_mode_supported_p (mode);
}

/* Implement TARGET_DWARF_REGISTER_SPAN.  */

static rtx
riscv_dwarf_register_span (rtx rtl)
{
  machine_mode mode = GET_MODE (rtl);
  unsigned regno = REGNO (rtl);
  rtx parts[16];

  if (riscv_vector_mode_vext_supported_p (mode)
      && UNITS_PER_VR_ARG
      && TARGET_XTHEAD_VLEN (128) && TARGET_64BIT
      && VR_RESERVE_REG_P (regno + 8))
    {
      int nregs = GET_MODE_SIZE (mode) / 8;
      for (int i = 0; i < nregs; i += 2)
	{
	  parts[i] = gen_rtx_REG (DImode, regno);
	  parts[i + 1] = gen_rtx_REG (DImode, regno + 8);
	  regno++;
	}
      return gen_rtx_PARALLEL (VOIDmode, gen_rtvec_v (nregs, parts));
    }

  return NULL_RTX;
}

#undef  TARGET_DWARF_REGISTER_SPAN
#define TARGET_DWARF_REGISTER_SPAN riscv_dwarf_register_span

#undef TARGET_ARRAY_MODE_SUPPORTED_P
#define TARGET_ARRAY_MODE_SUPPORTED_P riscv_array_mode_supported_p

#undef TARGET_VECTOR_MODE_SUPPORTED_P
#define TARGET_VECTOR_MODE_SUPPORTED_P riscv_vector_mode_supported_p

#undef TARGET_VECTORIZE_PREFERRED_SIMD_MODE
#define TARGET_VECTORIZE_PREFERRED_SIMD_MODE riscv_preferred_simd_mode

#include "riscv-thead-dfsrm.c"
#include "riscv-thead-dsext.c"
