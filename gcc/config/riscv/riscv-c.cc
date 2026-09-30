/* RISC-V-specific code for C family languages.
   Copyright (C) 2011-2026 Free Software Foundation, Inc.
   Contributed by Andrew Waterman (andrew@sifive.com).

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING3.  If not see
<http://www.gnu.org/licenses/>.  */

#define IN_TARGET_CODE 1

#define INCLUDE_STRING
#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tm.h"
#include "c-family/c-common.h"
#include "cpplib.h"
#include "c-family/c-pragma.h"
#include "target.h"
#include "tm_p.h"
#include "riscv-subset.h"

#define builtin_define(TXT) cpp_define (pfile, TXT)

static int
riscv_ext_version_value (unsigned major, unsigned minor)
{
  return (major * RISCV_MAJOR_VERSION_BASE)
    + (minor * RISCV_MINOR_VERSION_BASE);
}

/* Implement TARGET_CPU_CPP_BUILTINS.  */

void
riscv_cpu_cpp_builtins (cpp_reader *pfile)
{
  builtin_define ("__riscv");

  if (TARGET_RVC || TARGET_ZCA)
    builtin_define ("__riscv_compressed");

  if (TARGET_RVE)
    builtin_define (TARGET_64BIT ? "__riscv_64e" : "__riscv_32e");

  if (TARGET_ATOMIC)
    builtin_define ("__riscv_atomic");

  if (TARGET_MUL)
    builtin_define ("__riscv_mul");
  if (TARGET_DIV)
    builtin_define ("__riscv_div");
  if (TARGET_DIV && TARGET_MUL)
    builtin_define ("__riscv_muldiv");

  builtin_define_with_int_value ("__riscv_xlen", UNITS_PER_WORD * 8);
  if (TARGET_HARD_FLOAT)
    builtin_define_with_int_value ("__riscv_flen", UNITS_PER_FP_REG * 8);

  if ((TARGET_HARD_FLOAT || TARGET_ZFINX) && TARGET_FDIV)
    {
      builtin_define ("__riscv_fdiv");
      builtin_define ("__riscv_fsqrt");
    }

  switch (riscv_abi)
    {
    case ABI_ILP32E:
    case ABI_LP64E:
      builtin_define ("__riscv_abi_rve");
      gcc_fallthrough ();

    case ABI_ILP32:
    case ABI_LP64:
      builtin_define ("__riscv_float_abi_soft");
      break;

    case ABI_ILP32F:
    case ABI_LP64F:
      builtin_define ("__riscv_float_abi_single");
      break;

    case ABI_ILP32D:
    case ABI_LP64D:
      builtin_define ("__riscv_float_abi_double");
      break;
    }

  switch (riscv_cmodel)
    {
    case CM_MEDLOW:
      builtin_define ("__riscv_cmodel_medlow");
      break;

    case CM_LARGE:
      builtin_define ("__riscv_cmodel_large");
      break;

    case CM_PIC:
    case CM_MEDANY:
      builtin_define ("__riscv_cmodel_medany");
      break;
    }

  if (riscv_user_wants_strict_align)
    builtin_define_with_int_value ("__riscv_misaligned_avoid", 1);
  else if (riscv_slow_unaligned_access_p)
    builtin_define_with_int_value ("__riscv_misaligned_slow", 1);
  else
    builtin_define_with_int_value ("__riscv_misaligned_fast", 1);

  if (TARGET_MIN_VLEN != 0)
    builtin_define_with_int_value ("__riscv_v_min_vlen", TARGET_MIN_VLEN);

  if (TARGET_VECTOR_ELEN_64)
    builtin_define_with_int_value ("__riscv_v_elen", 64);
  else if (TARGET_VECTOR_ELEN_32)
    builtin_define_with_int_value ("__riscv_v_elen", 32);

  if (TARGET_VECTOR_ELEN_FP_64)
    builtin_define_with_int_value ("__riscv_v_elen_fp", 64);
  else if (TARGET_VECTOR_ELEN_FP_32)
    builtin_define_with_int_value ("__riscv_v_elen_fp", 32);
  else if (TARGET_MIN_VLEN != 0)
    builtin_define_with_int_value ("__riscv_v_elen_fp", 0);

  if (TARGET_MIN_VLEN)
    {
      builtin_define ("__riscv_vector");
      builtin_define_with_int_value ("__riscv_v_intrinsic",
				     riscv_ext_version_value (1, 0));

      if (rvv_vector_bits == RVV_VECTOR_BITS_ZVL)
	builtin_define_with_int_value ("__riscv_v_fixed_vlen", TARGET_MIN_VLEN);
    }

  if (TARGET_XTHEADVECTOR)
    builtin_define_with_int_value ("__riscv_th_v_intrinsic",
				   riscv_ext_version_value (0, 11));

  if (TARGET_ZTT && TARGET_ZICSR)
    builtin_define ("__riscv_ztt_runtime_queries");

  if (TARGET_ZTT && riscv_ztt::typed_profile_p ())
    {
      const riscv_ztt::profile_info *profile = riscv_ztt::active_profile ();
      gcc_assert (profile != nullptr);

      /* Experimental interface version 0.2.2: major * 1000000
	 + minor * 1000 + patch.  */
      builtin_define_with_int_value ("__riscv_ztt_intrinsic", 2002);
      /* Provisional v0.2.4 clear/zero names for the single-M i8_rne
	 subset, not a claim of complete v0.2.4 interface support.  */
      if (profile->uds == 8)
	{
	  builtin_define_with_int_value ("__riscv_ztt_i8_rne_1x1_clear_zero", 1);
	  builtin_define_with_int_value ("__riscv_ztt_i8_1x1_irm", 15);
	  builtin_define_with_int_value ("__riscv_ztt_u8_1x1_irm", 15);
	}
      if (profile->uds <= 16)
	builtin_define_with_int_value ("__riscv_ztt_i16_u16_1x1_irm", 15);
      if (profile->uds <= 32)
	builtin_define_with_int_value ("__riscv_ztt_i32_u32_1x1_irm", 15);
      /* Bits 0..10
	 describe 1x1, 1x2, 2x1, 1x4, 4x1, 1x8, 8x1, 1x16, 16x1,
	 1x32, 32x1 for all four integer RMs.  */
      const unsigned int squares[] = { 1, 2, 2, 4, 4, 8, 8, 16, 16, 32, 32 };
      for (unsigned int bits : { 8U, 16U, 32U })
	{
	  unsigned int mask = 0;
	  for (unsigned int i = 0; i < ARRAY_SIZE (squares); ++i)
	    if ((riscv_ztt::runtime_profile_p () || i == 0)
		&& riscv_ztt::m_shape_nregs
		     (bits, squares[i], profile->uds,
		      riscv_ztt::runtime_profile_p () ? profile->mregs : 4))
	      mask |= 1U << i;
	  char name[64];
	  snprintf (name, sizeof (name), "__riscv_ztt_i%u_u%u_shapes", bits, bits);
	  builtin_define_with_int_value (name, mask);
	}
      builtin_define_with_int_value ("__riscv_ztt_profile",
				     riscv_ztt::runtime_profile_p () ? 2 : 1);
      /* legal M types only.  */
      builtin_define_with_int_value ("__riscv_ztt_mcopy_m2m", 1);
      /* same integer T/RM/shape.  */
      builtin_define_with_int_value ("__riscv_ztt_msub_ew_int_same", 1);
      /* identical integer Md.  */
      builtin_define_with_int_value ("__riscv_ztt_mmin_ew_int_same", 1);
      builtin_define_with_int_value ("__riscv_ztt_mmax_ew_int_same", 1);
      /* identical integer Md.  */
      builtin_define_with_int_value ("__riscv_ztt_mand_ew_int_same", 1);
      builtin_define_with_int_value ("__riscv_ztt_mandnot_ew_int_same", 1);
      builtin_define_with_int_value ("__riscv_ztt_mor_ew_int_same", 1);
      builtin_define_with_int_value ("__riscv_ztt_mornot_ew_int_same", 1);
      builtin_define_with_int_value ("__riscv_ztt_mxor_ew_int_same", 1);
      /* independent integer
	 types, complete M shapes and size_t scalar shift controls.  */
      builtin_define_with_int_value ("__riscv_ztt_shift_int_mixed", 1);
      /* independent integer
	 M sources and destination, identical logical shape.  */
      builtin_define_with_int_value ("__riscv_ztt_mmul_ew_int_mixed", 1);
      /* independent integer
	 matrix datatypes, one final destination conversion.  */
      builtin_define_with_int_value ("__riscv_ztt_madd_ew_int_mixed", 1);
      builtin_define_with_int_value ("__riscv_ztt_msub_ew_int_mixed", 1);
      builtin_define_with_int_value ("__riscv_ztt_mabsdiff_ew_int_mixed", 1);
      builtin_define_with_int_value ("__riscv_ztt_mhdiff_ew_int_mixed", 1);
      builtin_define_with_int_value ("__riscv_ztt_mmean_ew_int_mixed", 1);
      builtin_define_with_int_value ("__riscv_ztt_mmulneg_ew_int_mixed", 1);
      /* explicit integer TC,
	 scalar conversion to TB, and compiler-managed amestype.  */
      builtin_define_with_int_value ("__riscv_ztt_madd_ew_x_int", 1);
      builtin_define_with_int_value ("__riscv_ztt_msub_ew_x_int", 1);
      builtin_define_with_int_value ("__riscv_ztt_mabsdiff_ew_x_int", 1);
      builtin_define_with_int_value ("__riscv_ztt_mhdiff_ew_x_int", 1);
      builtin_define_with_int_value ("__riscv_ztt_mmean_ew_x_int", 1);
      builtin_define_with_int_value ("__riscv_ztt_mmul_ew_x_int", 1);
      builtin_define_with_int_value ("__riscv_ztt_mmulneg_ew_x_int", 1);
      builtin_define_with_int_value ("__riscv_ztt_mmin_ew_x_int", 1);
      builtin_define_with_int_value ("__riscv_ztt_mmax_ew_x_int", 1);
      /* scalar TC converts
	 to the identical integer matrix source/result datatype.  */
      builtin_define_with_int_value ("__riscv_ztt_mand_ew_x_int_same", 1);
      builtin_define_with_int_value ("__riscv_ztt_mandnot_ew_x_int_same", 1);
      builtin_define_with_int_value ("__riscv_ztt_mor_ew_x_int_same", 1);
      builtin_define_with_int_value ("__riscv_ztt_mornot_ew_x_int_same", 1);
      builtin_define_with_int_value ("__riscv_ztt_mxor_ew_x_int_same", 1);
      /* source and result
	 have independent integer datatypes, but identical logical shape.  */
      builtin_define_with_int_value ("__riscv_ztt_mconv_ew_int", 1);
      /* magnitude before
	 destination conversion, with independently typed integer sources.  */
      builtin_define_with_int_value ("__riscv_ztt_mabs_ew_int", 1);
      /* old destination
	 is an exact-type input to each complete integer expression.  */
      builtin_define_with_int_value ("__riscv_ztt_mmulacc_ew_int", 1);
      builtin_define_with_int_value ("__riscv_ztt_mmulaccneg_ew_int", 1);
      builtin_define_with_int_value ("__riscv_ztt_mmuladd_ew_int", 1);
      builtin_define_with_int_value ("__riscv_ztt_mmulsub_ew_int", 1);
      /* scalar old-D forms.  */
      builtin_define_with_int_value ("__riscv_ztt_mmulacc_ew_x_int", 1);
      builtin_define_with_int_value ("__riscv_ztt_mmulaccneg_ew_x_int", 1);
      builtin_define_with_int_value ("__riscv_ztt_mmuladd_ew_x_int", 1);
      builtin_define_with_int_value ("__riscv_ztt_mmulsub_ew_x_int", 1);
      /* ordered comparison
	 and representation-preserving conditional selection.  */
      builtin_define_with_int_value ("__riscv_ztt_mcmovge_ew_int", 1);
      builtin_define_with_int_value ("__riscv_ztt_mcmovlt_ew_int", 1);
      builtin_define_with_int_value ("__riscv_ztt_mcmpge_ew_int", 1);
      builtin_define_with_int_value ("__riscv_ztt_mcmpge_ew_x_int", 1);
      builtin_define_with_int_value ("__riscv_ztt_mcmplt_ew_int", 1);
      builtin_define_with_int_value ("__riscv_ztt_mcmplt_ew_x_int", 1);
      builtin_define_with_int_value ("__riscv_ztt_mselge_ew_int", 1);
      builtin_define_with_int_value ("__riscv_ztt_msellt_ew_int", 1);
      /* These flags cover
	 value management, not wide arithmetic or every logical shape.  */
      if (riscv_ztt::active_profile ()->uds >= 16)
	builtin_define_with_int_value ("__riscv_ztt_wide64_values", 1);
      if (riscv_ztt::active_profile ()->uds >= 32)
	builtin_define_with_int_value ("__riscv_ztt_wide128_values", 1);
      /* Matrix arithmetic
	 only: data-scalar and matmul signatures have separate gates.  */
      if (riscv_ztt::active_profile ()->uds >= 16)
	builtin_define_with_int_value ("__riscv_ztt_wide_matrix_int", 1);
      /* Wide TC needs no
	 wide M value; destination/source formation is checked separately.  */
      builtin_define_with_int_value ("__riscv_ztt_wide_scalar_int", 1);
      /* Six matmul variants;
	 complete input and output values must each fit the active profile.  */
      if (riscv_ztt::runtime_profile_p ()
	  && riscv_ztt::active_profile ()->uds >= 16)
	builtin_define_with_int_value ("__riscv_ztt_wide_matmul_int", 63);
      /* Complete values and
	 unary and matrix operations; no i4 C scalar or memory interfaces.  */
      if (riscv_ztt::runtime_profile_p ())
	{
	  builtin_define_with_int_value ("__riscv_ztt_integer_kinds_values", 1);
	  builtin_define_with_int_value ("__riscv_ztt_integer_kinds_unary", 1);
	  builtin_define_with_int_value ("__riscv_ztt_integer_kinds_matrix", 1);
	  builtin_define_with_int_value ("__riscv_ztt_integer_kinds_matmul", 63);
	  builtin_define_with_int_value ("__riscv_ztt_integer_kinds_broadcast", 1);
	  builtin_define_with_int_value ("__riscv_ztt_integer_kinds_scalar", 1);
	  builtin_define_with_int_value ("__riscv_ztt_floating_unary", 1);
	  builtin_define_with_int_value ("__riscv_ztt_floating_matrix", 1);
	  builtin_define_with_int_value ("__riscv_ztt_matrix_math", 1);
	  builtin_define_with_int_value ("__riscv_ztt_exponent_scalar", 1);
	  builtin_define_with_int_value ("__riscv_ztt_floating_scalar", 1);
	  builtin_define_with_int_value ("__riscv_ztt_floating_memory", 1);
	  builtin_define_with_int_value ("__riscv_ztt_memory128", 1);
	  builtin_define_with_int_value ("__riscv_ztt_zip_value", 1);
	  builtin_define_with_int_value ("__riscv_ztt_floating_broadcast", 1);
	  builtin_define_with_int_value ("__riscv_ztt_floating_matmul", 63);
	}
      /* explicit integer
	 scalar datatype in the name, independent of the result type.  */
      builtin_define_with_int_value ("__riscv_ztt_mbcast_m_x_int", 1);
      /* integer basic 1x1
	 row/column controls, subject to each type's profile availability.  */
      builtin_define_with_int_value ("__riscv_ztt_mcolbcast_ew_x_int", 1);
      builtin_define_with_int_value ("__riscv_ztt_mrowbcast_ew_x_int", 1);
      builtin_define_with_int_value ("__riscv_ztt_mcolshift_ew_x_int", 1);
      builtin_define_with_int_value ("__riscv_ztt_mrowshift_ew_x_int", 1);
      /* Integer structural
	 unary operations on complete groups, independently per Square.  */
      builtin_define_with_int_value ("__riscv_ztt_mreduceadd_col_int", 1);
      builtin_define_with_int_value ("__riscv_ztt_mreduceadd_row_int", 1);
      builtin_define_with_int_value ("__riscv_ztt_mreducemax_col_int", 1);
      builtin_define_with_int_value ("__riscv_ztt_mreducemax_row_int", 1);
      builtin_define_with_int_value ("__riscv_ztt_mreducemin_col_int", 1);
      builtin_define_with_int_value ("__riscv_ztt_mreducemin_row_int", 1);
      builtin_define_with_int_value ("__riscv_ztt_mprefixadd_col_int", 1);
      builtin_define_with_int_value ("__riscv_ztt_mprefixadd_row_int", 1);
      builtin_define_with_int_value ("__riscv_ztt_mprefixmax_col_int", 1);
      builtin_define_with_int_value ("__riscv_ztt_mprefixmax_row_int", 1);
      /* Integer matrix-indexed
	 operations require complete basic 1x1 groups for every operand.  */
      builtin_define_with_int_value ("__riscv_ztt_mcolgather_ew_int", 1);
      builtin_define_with_int_value ("__riscv_ztt_mrowgather_ew_int", 1);
      builtin_define_with_int_value ("__riscv_ztt_mcolscatadd_ew_int", 1);
      builtin_define_with_int_value ("__riscv_ztt_mrowscatadd_ew_int", 1);
      builtin_define_with_int_value ("__riscv_ztt_mcolscatmax_ew_int", 1);
      builtin_define_with_int_value ("__riscv_ztt_mrowscatmax_ew_int", 1);
      /* Retired pointer zip APIs have no availability macros.  Runtime
	 profiles advertise the new interface with __riscv_ztt_zip_value.  */
      /* Integer index
	 constructors need complete basic Squares and representable N-1.  */
      if (profile->uds <= 32)
	{
	  builtin_define_with_int_value ("__riscv_ztt_mrowid_ew_int", 1);
	  builtin_define_with_int_value ("__riscv_ztt_mcolid_ew_int", 1);
	}
      if (riscv_ztt::runtime_profile_p ())
	{
	  builtin_define ("__riscv_ztt_runtime_n");
	  /* Both
	     source and result must have supported complete-group shapes.  */
	  builtin_define_with_int_value ("__riscv_ztt_mconcat_m", 1);
	  builtin_define_with_int_value ("__riscv_ztt_mextract", 1);
	}
      else
	{
	  builtin_define_with_int_value ("__riscv_ztt_nelem", profile->nelem);
	  builtin_define_with_int_value ("__riscv_ztt_n", profile->n);
	}

      if (riscv_ztt::acc_profile_p () && profile->uds <= 32)
	{
	  builtin_define_with_int_value ("__riscv_ztt_i32_rnu_accx1", 1);
	  builtin_define_with_int_value ("__riscv_ztt_i32_u32_accx1_irm", 15);
	  builtin_define_with_int_value ("__riscv_ztt_acc_matmul_variants", 63);
	  /* Same-type Q=2/4
	     inputs only when each complete M value occupies at most 4 regs.  */
	  builtin_define_with_int_value ("__riscv_ztt_acc_matmul_concat", 63);
	  /* Mixed integer inputs
	     require complete nonpacked Squares and independently legal spans.  */
	  builtin_define_with_int_value ("__riscv_ztt_acc_matmul_mixed", 63);
	  if (profile->uds <= 16)
	    builtin_define_with_int_value ("__riscv_ztt_i16_u16_accx1_irm", 15);
	  if (profile->uds == 8)
	    builtin_define_with_int_value ("__riscv_ztt_i8_u8_accx1_irm", 15);

	  if (profile->accregs >= 2)
	    {
	      builtin_define_with_int_value ("__riscv_ztt_acc_tuple_copy", 1);
	      /* Matching
		 1x1 inputs, with the rest of the old tuple preserved.  */
	      builtin_define_with_int_value ("__riscv_ztt_acc_tuple_matmul_1x1", 63);
	      for (unsigned int bits : { 8U, 16U, 32U })
		for (unsigned int count : { 2U, 4U })
		  if (bits >= profile->uds && count <= profile->accregs
		      && riscv_ztt::acc_shape_supported_p
			   (bits, count, profile->uds, profile->accregs))
		    {
		      char name[64];
		      snprintf (name, sizeof (name),
				"__riscv_ztt_i%u_u%u_accx%u_irm",
				bits, bits, count);
		      builtin_define_with_int_value (name, 15);
		    }
	    }
	}
      /* These capabilities
	 deliberately do not advertise the nonpacked matmul families.  */
      if (riscv_ztt::runtime_profile_p ())
	for (unsigned int bits : { 8U, 16U, 32U })
	  for (unsigned int count : { 2U, 4U, 8U, 16U })
	    if (bits < profile->uds
		&& riscv_ztt::acc_shape_supported_p (bits, count, profile->uds,
						  profile->accregs))
	      {
		char name[64];
		snprintf (name, sizeof (name),
			  "__riscv_ztt_i%u_u%u_accx%u_packed_irm",
			  bits, bits, count);
		builtin_define_with_int_value (name, 15);
		builtin_define_with_int_value ("__riscv_ztt_acc_packed_copy", 1);
	      }
      /* Input packing and
	 complete output availability are separate from the copy gate.  */
      if (riscv_ztt::acc_profile_p () && profile->uds > 8
	  && (profile->uds <= 32 || profile->accregs >= profile->uds / 32))
	builtin_define_with_int_value ("__riscv_ztt_acc_matmul_packed", 63);
      builtin_define_with_int_value ("__riscv_ztt_uds", profile->uds);
      builtin_define_with_int_value ("__riscv_ztt_mregs", profile->mregs);
      builtin_define_with_int_value ("__riscv_ztt_accregs",
				     profile->accregs);
    }

  /* Define architecture extension test macros.  */
  builtin_define_with_int_value ("__riscv_arch_test", 1);

  if (TARGET_ZICFISS && ((flag_cf_protection & CF_RETURN) == CF_RETURN))
    builtin_define ("__riscv_shadow_stack");

  if (TARGET_ZICFILP && ((flag_cf_protection & CF_BRANCH) == CF_BRANCH))
    {
      builtin_define ("__riscv_landing_pad");
      builtin_define ("__riscv_landing_pad_unlabeled");
    }

  const riscv_subset_list *subset_list = riscv_cmdline_subset_list ();
  if (!subset_list)
    return;

  size_t max_ext_len = 0;

  /* Figure out the max length of extension name for reserving buffer.   */
  for (auto &subset : *subset_list)
    max_ext_len = MAX (max_ext_len, subset.name.length ());

  char *buf = (char *)alloca (max_ext_len + 10 /* For __riscv_ and '\0'.  */);

  for (auto &subset : *subset_list)
    {
      int version_value = riscv_ext_version_value (subset.major_version,
						   subset.minor_version);
      /* Special rule for zicsr and zifencei, it's used for ISA spec 2.2 or
	 earlier.  */
      if ((subset.name == "zicsr" || subset.name == "zifencei")
	  && version_value == 0)
	version_value = riscv_ext_version_value (2, 0);

      sprintf (buf, "__riscv_%s", subset.name.c_str ());
      builtin_define_with_int_value (buf, version_value);
    }
}

/* Implement "#pragma riscv intrinsic".  */

static void
riscv_pragma_intrinsic (cpp_reader *)
{
  tree x;

  if (pragma_lex (&x) != CPP_STRING)
    {
      error ("%<#pragma riscv intrinsic%> requires a string parameter");
      return;
    }

  const char *name = TREE_STRING_POINTER (x);

  if (strcmp (name, "vector") == 0
      || strcmp (name, "xtheadvector") == 0
      || strcmp (name, "xsfvcp") == 0)
    {
      riscv_vector::handle_pragma_vector ();
    }
  else if (strcmp (name, "ztt") == 0)
    riscv_ztt::handle_pragma_ztt ();
  else
    error ("unknown %<#pragma riscv intrinsic%> option %qs", name);
}

/* Implement TARGETM.TARGET_OPTION.PRAGMA_PARSE.  */

static bool
riscv_pragma_target_parse (tree args, tree pop_target)
{
  /* If args is not NULL then process it and setup the target-specific
     information that it specifies.  */
  if (args)
    {
      if (!riscv_process_target_attr_for_pragma (args))
	return false;

      riscv_override_options_internal (&global_options);
    }
  /* args is NULL, restore to the state described in pop_target.  */
  else
    {
      pop_target = pop_target ? pop_target : target_option_default_node;
      cl_target_option_restore (&global_options, &global_options_set,
				TREE_TARGET_OPTION (pop_target));
    }

  target_option_current_node
    = build_target_option_node (&global_options, &global_options_set);

  riscv_reset_previous_fndecl ();

  /* For the definitions, ensure all newly defined macros are considered
     as used for -Wunused-macros.  There is no point warning about the
     compiler predefined macros.  */
  cpp_options *cpp_opts = cpp_get_options (parse_in);
  unsigned char saved_warn_unused_macros = cpp_opts->warn_unused_macros;
  cpp_opts->warn_unused_macros = 0;

  cpp_force_token_locations (parse_in, BUILTINS_LOCATION);
  riscv_cpu_cpp_builtins (parse_in);
  cpp_stop_forcing_token_locations (parse_in);

  cpp_opts->warn_unused_macros = saved_warn_unused_macros;

  return true;
}

/* Implement TARGET_CHECK_BUILTIN_CALL.  */
static bool
riscv_check_builtin_call (location_t loc, vec<location_t> arg_loc, tree fndecl,
			  tree, unsigned int nargs, tree *args, bool)
{
  unsigned int code = DECL_MD_FUNCTION_CODE (fndecl);
  unsigned int subcode = code >> RISCV_BUILTIN_SHIFT;
  switch (code & RISCV_BUILTIN_CLASS)
    {
    case RISCV_BUILTIN_GENERAL:
      return true;

    case RISCV_BUILTIN_VECTOR:
      return riscv_vector::check_builtin_call (loc, arg_loc, subcode,
					       fndecl, nargs, args);

    case RISCV_BUILTIN_ZTT:
      return riscv_ztt::check_builtin_call (loc, subcode, fndecl, nargs,
					    args);
    }
  gcc_unreachable ();
}

/* Implement TARGET_RESOLVE_OVERLOADED_BUILTIN.  */
static tree
riscv_resolve_overloaded_builtin (location_t loc, tree fndecl,
				  void *uncast_arglist, bool)
{
  vec<tree, va_gc> empty = {};
  vec<tree, va_gc> *arglist = (vec<tree, va_gc> *) uncast_arglist;
  unsigned int code = DECL_MD_FUNCTION_CODE (fndecl);
  unsigned int subcode = code >> RISCV_BUILTIN_SHIFT;
  tree new_fndecl = NULL_TREE;

  if (!arglist)
    arglist = &empty;

  switch (code & RISCV_BUILTIN_CLASS)
    {
    case RISCV_BUILTIN_GENERAL:
      break;
    case RISCV_BUILTIN_VECTOR:
      new_fndecl = riscv_vector::resolve_overloaded_builtin (loc, subcode,
						     fndecl, arglist);
      break;
    case RISCV_BUILTIN_ZTT:
      /* A resolved Ztt expression can bypass normal call construction.
	 Fold C arguments first, before hiding language-specific nodes inside
	 a generated CALL_EXPR or TARGET_EXPR.  Leave C++ template trees to
	 their frontend; neither path performs scalar carrier conversions here.  */
      if (!c_dialect_cxx ())
	for (tree &arg : *arglist)
	  if (arg != error_mark_node)
	    arg = c_fully_fold (arg, false, NULL);
      if (!riscv_ztt::check_builtin_arguments (loc, subcode, arglist))
	return error_mark_node;
      new_fndecl = riscv_ztt::resolve_overloaded_builtin (loc, subcode, arglist);
      /* Ztt can retain type metadata in a fully formed internal call.  */
      if (new_fndecl && TREE_CODE (new_fndecl) != FUNCTION_DECL)
	return new_fndecl;
      break;
    default:
      gcc_unreachable ();
    }

  if (new_fndecl == NULL_TREE)
    return new_fndecl;

  return build_function_call_vec (loc, vNULL, new_fndecl, arglist, NULL,
				  fndecl);
}

/* Implement REGISTER_TARGET_PRAGMAS.  */

void
riscv_register_pragmas (void)
{
  targetm.resolve_overloaded_builtin = riscv_resolve_overloaded_builtin;
  targetm.check_builtin_call = riscv_check_builtin_call;
  targetm.target_option.pragma_parse = riscv_pragma_target_parse;
  c_register_pragma ("riscv", "intrinsic", riscv_pragma_intrinsic);
}
