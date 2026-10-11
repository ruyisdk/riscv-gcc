/* This file is part of GCC.

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
#define INCLUDE_MAP
#define INCLUDE_VECTOR
#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tm.h"
#include "rtl.h"
#include "tree.h"
#include "stringpool.h"
#include "function.h"
#include "memmodel.h"
#include "emit-rtl.h"
#include "tm_p.h"
#include "expr.h"
#include "selftest.h"
#include "selftest-rtl.h"
#include "insn-attr.h"
#include "target.h"
#include "optabs.h"

#if CHECKING_P
using namespace selftest;
class riscv_selftest_arch_abi_setter
{
private:
  std::string m_arch_backup;
  enum riscv_abi_type m_abi_backup;

public:
  riscv_selftest_arch_abi_setter (const char *arch, enum riscv_abi_type abi)
    : m_arch_backup (riscv_arch_str ()), m_abi_backup (riscv_abi)
  {
    riscv_parse_arch_string (arch, &global_options, UNKNOWN_LOCATION);
    riscv_abi = abi;
    riscv_reinit ();
  }
  ~riscv_selftest_arch_abi_setter ()
  {
    riscv_parse_arch_string (m_arch_backup.c_str (), &global_options,
			     UNKNOWN_LOCATION);
    riscv_abi = m_abi_backup;
    riscv_reinit ();
  }
};

static poly_int64
eval_value (rtx x, std::map<unsigned, rtx> &regno_to_rtx)
{
  if (!REG_P (x))
    {
      debug (x);
      gcc_unreachable ();
    }

  rtx expr = NULL_RTX;
  unsigned regno = REGNO (x);
  expr = regno_to_rtx[regno];

  poly_int64 op1_val = 0;
  poly_int64 op2_val = 0;
  if (UNARY_P (expr))
    {
      op1_val = eval_value (XEXP (expr, 0), regno_to_rtx);
    }
  if (BINARY_P (expr))
    {
      op1_val = eval_value (XEXP (expr, 0), regno_to_rtx);
      op2_val = eval_value (XEXP (expr, 1), regno_to_rtx);
    }

  switch (GET_CODE (expr))
    {
    case CONST_POLY_INT:
      return rtx_to_poly_int64 (expr);
    case CONST_INT:
      return INTVAL (expr);

    case MULT:
      if (op1_val.is_constant ())
	return op1_val.to_constant () * op2_val;
      else if (op2_val.is_constant ())
	return op1_val * op2_val.to_constant ();
      else
	gcc_unreachable ();
    case PLUS:
      return op1_val + op2_val;
    default:
      gcc_unreachable ();
    }
}

/* Calculate the value of x register in the sequence.  */
static poly_int64
calculate_x_in_sequence (rtx reg)
{
  std::map<unsigned, rtx> regno_to_rtx;
  rtx_insn *insn;
  for (insn = get_insns (); insn; insn = NEXT_INSN (insn))
    {
      rtx pat = PATTERN (insn);
      rtx dest = SET_DEST (pat);

      if (GET_CODE (pat) == CLOBBER)
	continue;

      if (SUBREG_P (dest))
	continue;

      gcc_assert (REG_P (dest));
      rtx note = find_reg_equal_equiv_note (insn);
      unsigned regno = REGNO (dest);
      if (note)
	regno_to_rtx[regno] = XEXP (note, 0);
      else
	regno_to_rtx[regno] = SET_SRC (pat);
    }

  return eval_value (reg, regno_to_rtx);
}

typedef enum
{
  POLY_TEST_DIMODE,
  POLY_TEST_PMODE
} poly_test_mode_t;

static void
simple_poly_selftest (const char *arch, enum riscv_abi_type abi,
		      const std::vector<machine_mode> &modes)
{
  riscv_selftest_arch_abi_setter rv (arch, abi);
  rtl_dump_test t (SELFTEST_LOCATION, locate_file ("riscv/empty-func.rtl"));
  set_new_first_and_last_insn (NULL, NULL);

  for (machine_mode mode : modes)
    emit_move_insn (gen_reg_rtx (mode),
		    gen_int_mode (BYTES_PER_RISCV_VECTOR, mode));
}

static void
run_poly_int_selftest (const char *arch, enum riscv_abi_type abi,
		       poly_test_mode_t test_mode,
		       const std::vector<poly_int64> &worklist)
{
  riscv_selftest_arch_abi_setter rv (arch, abi);
  rtl_dump_test t (SELFTEST_LOCATION, locate_file ("riscv/empty-func.rtl"));
  set_new_first_and_last_insn (NULL, NULL);
  machine_mode mode = VOIDmode;

  switch (test_mode)
    {
    case POLY_TEST_DIMODE:
      mode = DImode;
      break;
    case POLY_TEST_PMODE:
      mode = Pmode;
      break;
    default:
      gcc_unreachable ();
    }

  for (const poly_int64 &poly_val : worklist)
    {
      start_sequence ();
      rtx dest = gen_reg_rtx (mode);
      emit_move_insn (dest, gen_int_mode (poly_val, mode));
      ASSERT_TRUE (known_eq (calculate_x_in_sequence (dest), poly_val));
      end_sequence ();
    }
}

static void
run_poly_int_selftests (void)
{
  std::vector<poly_int64> worklist
    = {BYTES_PER_RISCV_VECTOR,	    BYTES_PER_RISCV_VECTOR * 8,
       BYTES_PER_RISCV_VECTOR * 32, -BYTES_PER_RISCV_VECTOR * 8,
       -BYTES_PER_RISCV_VECTOR * 32, BYTES_PER_RISCV_VECTOR * 7,
       BYTES_PER_RISCV_VECTOR * 31, -BYTES_PER_RISCV_VECTOR * 7,
       -BYTES_PER_RISCV_VECTOR * 31, BYTES_PER_RISCV_VECTOR * 9,
       BYTES_PER_RISCV_VECTOR * 33, -BYTES_PER_RISCV_VECTOR * 9,
       -BYTES_PER_RISCV_VECTOR * 33, poly_int64 (207, 0),
       poly_int64 (-207, 0),	    poly_int64 (0, 207),
       poly_int64 (0, -207),	    poly_int64 (5555, 0),
       poly_int64 (0, 5555),	    poly_int64 (4096, 4096),
       poly_int64 (17, 4088),	    poly_int64 (3889, 4104),
       poly_int64 (-4096, -4096),   poly_int64 (219, -4088),
       poly_int64 (-4309, -4104),   poly_int64 (-7337, 88),
       poly_int64 (9317, -88),	    poly_int64 (4, 4),
       poly_int64 (17, 4),	    poly_int64 (-7337, 4),
       poly_int64 (-4, -4),	    poly_int64 (-389, -4),
       poly_int64 (4789, -4),	    poly_int64 (-5977, 1508),
       poly_int64 (219, -1508),	    poly_int64 (2, 2),
       poly_int64 (33, 2),	    poly_int64 (-7337, 2),
       poly_int64 (-2, -2),	    poly_int64 (-389, -2),
       poly_int64 (4789, -2),	    poly_int64 (-3567, 954),
       poly_int64 (945, -954),	    poly_int64 (1, 1),
       poly_int64 (977, 1),	    poly_int64 (-339, 1),
       poly_int64 (-1, -1),	    poly_int64 (-12, -1),
       poly_int64 (44, -1),	    poly_int64 (9567, 77),
       poly_int64 (3467, -77)};

  simple_poly_selftest ("rv64imafdv", ABI_LP64D,
			{QImode, HImode, SImode, DImode});
  simple_poly_selftest ("rv32imafdv", ABI_ILP32D, {QImode, HImode, SImode});

  run_poly_int_selftest ("rv64imafdv", ABI_LP64D, POLY_TEST_PMODE, worklist);
  run_poly_int_selftest ("rv64imafd_zve32x1p0", ABI_LP64D, POLY_TEST_PMODE,
			 worklist);
  run_poly_int_selftest ("rv32imafdv", ABI_ILP32, POLY_TEST_PMODE, worklist);
  run_poly_int_selftest ("rv32imafdv", ABI_ILP32, POLY_TEST_DIMODE, worklist);
  run_poly_int_selftest ("rv32imafd_zve32x1p0", ABI_ILP32D, POLY_TEST_PMODE,
			 worklist);
  run_poly_int_selftest ("rv32imafd_zve32x1p0", ABI_ILP32D, POLY_TEST_DIMODE,
			 worklist);
  simple_poly_selftest ("rv64imafdv_zvl256b", ABI_LP64D,
			{QImode, HImode, SImode, DImode});
  simple_poly_selftest ("rv64imafdv_zvl512b", ABI_LP64D,
			{QImode, HImode, SImode, DImode});
  simple_poly_selftest ("rv64imafdv_zvl1024b", ABI_LP64D,
			{QImode, HImode, SImode, DImode});
  simple_poly_selftest ("rv64imafdv_zvl2048b", ABI_LP64D,
			{QImode, HImode, SImode, DImode});
  simple_poly_selftest ("rv64imafdv_zvl4096b", ABI_LP64D,
			{QImode, HImode, SImode, DImode});
}

static void
run_const_vector_selftests (void)
{
  /* We don't need to do the redundant tests in different march && mabi.
     Just pick up the march && mabi which fully support all RVV modes.  */
  riscv_selftest_arch_abi_setter rv ("rv64imafdcv", ABI_LP64D);
  rtl_dump_test t (SELFTEST_LOCATION, locate_file ("riscv/empty-func.rtl"));
  set_new_first_and_last_insn (NULL, NULL);

  machine_mode mode;
  std::vector<HOST_WIDE_INT> worklist = {-111, -17, -16, 7, 15, 16, 111};

  FOR_EACH_MODE_IN_CLASS (mode, MODE_VECTOR_INT)
    {
      if (riscv_vla_mode_p (mode))
	{
	  for (const HOST_WIDE_INT &val : worklist)
	    {
	      start_sequence ();
	      rtx dest = gen_reg_rtx (mode);
	      rtx dup = gen_const_vec_duplicate (mode, GEN_INT (val));
	      emit_move_insn (dest, dup);
	      rtx_insn *insn = get_last_insn ();
	      rtx src = SET_SRC (PATTERN (insn));
	      /* 1.  Should be vmv.v.i for in range of -16 ~ 15.
		 2.  Should be vmv.v.x for exceed -16 ~ 15.  */
	      if (IN_RANGE (val, -16, 15))
		ASSERT_TRUE (
		  rtx_equal_p (XEXP (SET_SRC (PATTERN (insn)), 1), dup));
	      else
		ASSERT_TRUE (GET_CODE (src) == VEC_DUPLICATE);
	      end_sequence ();
	    }
	}
    }

  FOR_EACH_MODE_IN_CLASS (mode, MODE_VECTOR_FLOAT)
    {
      if (riscv_vla_mode_p (mode))
	{
	  scalar_mode inner_mode = GET_MODE_INNER (mode);
	  REAL_VALUE_TYPE f = REAL_VALUE_ATOF ("0.2928932", inner_mode);
	  rtx ele = const_double_from_real_value (f, inner_mode);

	  start_sequence ();
	  rtx dest = gen_reg_rtx (mode);
	  rtx dup = gen_const_vec_duplicate (mode, ele);
	  emit_move_insn (dest, dup);
	  rtx_insn *insn = get_last_insn ();
	  rtx src = SET_SRC (PATTERN (insn));
	  /* Should always be vfmv.v.f.  */
	  ASSERT_TRUE (GET_CODE (src) == VEC_DUPLICATE);
	  end_sequence ();
	}
    }

  FOR_EACH_MODE_IN_CLASS (mode, MODE_VECTOR_BOOL)
    {
      /* Test vmset.m.  */
      if (riscv_vla_mode_p (mode))
	{
	  start_sequence ();
	  rtx dest = gen_reg_rtx (mode);
	  emit_move_insn (dest, CONSTM1_RTX (mode));
	  rtx_insn *insn = get_last_insn ();
	  rtx src = XEXP (SET_SRC (PATTERN (insn)), 1);
	  ASSERT_TRUE (rtx_equal_p (src, CONSTM1_RTX (mode)));
	  end_sequence ();
	}
    }
}

static void
run_broadcast_selftests (void)
{
  /* We don't need to do the redundant tests in different march && mabi.
     Just pick up the march && mabi which fully support all RVV modes.  */
  riscv_selftest_arch_abi_setter rv ("rv64imafdcv", ABI_LP64D);
  rtl_dump_test t (SELFTEST_LOCATION, locate_file ("riscv/empty-func.rtl"));
  set_new_first_and_last_insn (NULL, NULL);

  machine_mode mode;

#define BROADCAST_TEST(MODE_CLASS)                                             \
  FOR_EACH_MODE_IN_CLASS (mode, MODE_VECTOR_INT)                               \
    {                                                                          \
      if (riscv_vla_mode_p (mode))					       \
	{                                                                      \
	  rtx_insn *insn;                                                      \
	  rtx src;                                                             \
	  scalar_mode inner_mode = GET_MODE_INNER (mode);                      \
	  /* Test vlse.v with zero stride.  */                                 \
	  start_sequence ();                                                   \
	  rtx addr = gen_reg_rtx (Pmode);                                      \
	  rtx mem = gen_rtx_MEM (inner_mode, addr);                            \
	  expand_vector_broadcast (mode, mem);                                 \
	  insn = get_last_insn ();                                             \
	  src = SET_SRC (PATTERN (insn));                                      \
	  if (strided_load_broadcast_p ())                                     \
	    {                                                                  \
	      ASSERT_TRUE (MEM_P (XEXP (src, 0)));                             \
	      ASSERT_TRUE (                                                    \
		rtx_equal_p (src,                                              \
			     gen_rtx_VEC_DUPLICATE (mode, XEXP (src, 0))));    \
	    }                                                                  \
	  end_sequence ();                                                     \
	  /* Test vmv.v.x or vfmv.v.f.  */                                     \
	  start_sequence ();                                                   \
	  rtx reg = gen_reg_rtx (inner_mode);                                  \
	  expand_vector_broadcast (mode, reg);                                 \
	  insn = get_last_insn ();                                             \
	  src = SET_SRC (PATTERN (insn));                                      \
	  ASSERT_TRUE (REG_P (XEXP (src, 0)));                                 \
	  ASSERT_TRUE (                                                        \
	    rtx_equal_p (src, gen_rtx_VEC_DUPLICATE (mode, XEXP (src, 0))));   \
	  end_sequence ();                                                     \
	}                                                                      \
    }

  BROADCAST_TEST (MODE_VECTOR_INT)
  BROADCAST_TEST (MODE_VECTOR_FLOAT)
}

static void
test_vectorize_related_mode (machine_mode vec_mode, scalar_mode ele_mode,
			     machine_mode expected)
{
  opt_machine_mode result = riscv_vector::vectorize_related_mode (vec_mode,
								  ele_mode, 0);
  machine_mode result_mode = result.else_void ();
  ASSERT_TRUE (result_mode == expected);
}

static void
run_vectorize_related_mode_vla_selftests (void)
{
  riscv_selftest_arch_abi_setter rv ("rv64imafdcv", ABI_LP64D);
  enum rvv_max_lmul_enum backup_rvv_max_lmul = rvv_max_lmul;
  rvv_max_lmul = RVV_M1;

  test_vectorize_related_mode (RVVM1QImode, SImode, RVVM1SImode);
  test_vectorize_related_mode (RVVM2QImode, SImode, RVVM1SImode);
  test_vectorize_related_mode (RVVM4QImode, SImode, RVVM1SImode);
  test_vectorize_related_mode (RVVM8QImode, SImode, RVVM1SImode);
  test_vectorize_related_mode (RVVM8QImode, DImode, RVVM1DImode);
  test_vectorize_related_mode (RVVM8QImode, QImode, RVVM1QImode);
  test_vectorize_related_mode (RVVM8QImode, HImode, RVVM1HImode);

  rvv_max_lmul = RVV_M2;

  test_vectorize_related_mode (RVVM1QImode, SImode, RVVM2SImode);
  test_vectorize_related_mode (RVVM2QImode, SImode, RVVM2SImode);
  test_vectorize_related_mode (RVVM4QImode, SImode, RVVM2SImode);
  test_vectorize_related_mode (RVVM8QImode, SImode, RVVM2SImode);
  test_vectorize_related_mode (RVVM8QImode, DImode, RVVM2DImode);
  test_vectorize_related_mode (RVVM8QImode, QImode, RVVM2QImode);
  test_vectorize_related_mode (RVVM8QImode, HImode, RVVM2HImode);

  rvv_max_lmul = RVV_M4;

  test_vectorize_related_mode (RVVM1QImode, SImode, RVVM4SImode);
  test_vectorize_related_mode (RVVM2QImode, SImode, RVVM4SImode);
  test_vectorize_related_mode (RVVM4QImode, SImode, RVVM4SImode);
  test_vectorize_related_mode (RVVM8QImode, SImode, RVVM4SImode);
  test_vectorize_related_mode (RVVM8QImode, DImode, RVVM4DImode);
  test_vectorize_related_mode (RVVM8QImode, QImode, RVVM4QImode);
  test_vectorize_related_mode (RVVM8QImode, HImode, RVVM4HImode);

  rvv_max_lmul = RVV_M8;

  test_vectorize_related_mode (RVVM1QImode, SImode, RVVM4SImode);
  test_vectorize_related_mode (RVVM2QImode, SImode, RVVM8SImode);
  test_vectorize_related_mode (RVVM4QImode, SImode, RVVM8SImode);
  test_vectorize_related_mode (RVVM8QImode, SImode, RVVM8SImode);
  test_vectorize_related_mode (RVVM8QImode, DImode, RVVM8DImode);
  test_vectorize_related_mode (RVVM8QImode, QImode, RVVM8QImode);
  test_vectorize_related_mode (RVVM8QImode, HImode, RVVM8HImode);

  rvv_max_lmul = backup_rvv_max_lmul;
}

static void
run_vectorize_related_mode_vls_rv64gcv_selftests ()
{
  enum rvv_vector_bits_enum backup_rvv_vector_bits = rvv_vector_bits;
  rvv_vector_bits = RVV_VECTOR_BITS_SCALABLE;
  riscv_selftest_arch_abi_setter rv ("rv64imafdcv", ABI_LP64D);
  enum rvv_max_lmul_enum backup_rvv_max_lmul = rvv_max_lmul;
  rvv_max_lmul = RVV_M1;

  test_vectorize_related_mode (  V16QImode, QImode,   V16QImode);
  test_vectorize_related_mode (  V16QImode, HImode,    V8HImode);
  test_vectorize_related_mode (  V16QImode, SImode,    V4SImode);
  test_vectorize_related_mode (  V16QImode, DImode,    V2DImode);

  rvv_max_lmul = RVV_M2;

  test_vectorize_related_mode (  V32QImode, QImode,   V32QImode);
  test_vectorize_related_mode (  V32QImode, HImode,   V16HImode);
  test_vectorize_related_mode (  V32QImode, SImode,    V8SImode);
  test_vectorize_related_mode (  V32QImode, DImode,    V4DImode);

  rvv_max_lmul = RVV_M4;

  test_vectorize_related_mode (  V64QImode, QImode,   V64QImode);
  test_vectorize_related_mode (  V64QImode, HImode,   V32HImode);
  test_vectorize_related_mode (  V64QImode, SImode,   V16SImode);
  test_vectorize_related_mode (  V64QImode, DImode,    V8DImode);

  rvv_max_lmul = RVV_M8;

  test_vectorize_related_mode ( V128QImode, QImode,  V128QImode);
  test_vectorize_related_mode ( V128QImode, HImode,   V64HImode);
  test_vectorize_related_mode ( V128QImode, SImode,   V32SImode);
  test_vectorize_related_mode ( V128QImode, DImode,   V16DImode);

  rvv_vector_bits = backup_rvv_vector_bits;
  rvv_max_lmul = backup_rvv_max_lmul;
}

static void
run_vectorize_related_mode_vls_rv32gc_zve32x_zvl256b_selftests ()
{
  enum rvv_vector_bits_enum backup_rvv_vector_bits = rvv_vector_bits;
  rvv_vector_bits = RVV_VECTOR_BITS_SCALABLE;
  riscv_selftest_arch_abi_setter rv ("rv32gc_zve32x_zvl256b", ABI_ILP32D);
  enum rvv_max_lmul_enum backup_rvv_max_lmul = rvv_max_lmul;
  rvv_max_lmul = RVV_M1;

  test_vectorize_related_mode (  V32QImode, QImode,   V32QImode);
  test_vectorize_related_mode (  V32QImode, HImode,   V16HImode);
  test_vectorize_related_mode (  V32QImode, SImode,    V8SImode);
  test_vectorize_related_mode (  V32QImode, DImode,    VOIDmode);

  test_vectorize_related_mode (  V16QImode, QImode,   V16QImode);
  test_vectorize_related_mode (  V16QImode, HImode,   V16HImode);
  test_vectorize_related_mode (  V16QImode, SImode,    V8SImode);
  test_vectorize_related_mode (  V16QImode, DImode,    VOIDmode);

  rvv_max_lmul = RVV_M2;

  test_vectorize_related_mode (  V32QImode, QImode,   V32QImode);
  test_vectorize_related_mode (  V32QImode, HImode,   V32HImode);
  test_vectorize_related_mode (  V32QImode, SImode,   V16SImode);
  test_vectorize_related_mode (  V32QImode, DImode,    VOIDmode);

  rvv_max_lmul = RVV_M4;

  test_vectorize_related_mode ( V128QImode, QImode,  V128QImode);
  test_vectorize_related_mode ( V128QImode, HImode,   V64HImode);
  test_vectorize_related_mode ( V128QImode, SImode,   V32SImode);
  test_vectorize_related_mode ( V128QImode, DImode,    VOIDmode);

  rvv_max_lmul = RVV_M8;

  test_vectorize_related_mode ( V128QImode, QImode,  V128QImode);
  test_vectorize_related_mode ( V128QImode, HImode,  V128HImode);
  test_vectorize_related_mode ( V128QImode, SImode,   V64SImode);
  test_vectorize_related_mode ( V128QImode, DImode,    VOIDmode);

  rvv_vector_bits = backup_rvv_vector_bits;
  rvv_max_lmul = backup_rvv_max_lmul;

}

static void
run_vectorize_related_mode_vls_selftests (void)
{
  run_vectorize_related_mode_vls_rv64gcv_selftests ();
  run_vectorize_related_mode_vls_rv32gc_zve32x_zvl256b_selftests ();
}

static void
run_vectorize_related_mode_selftests (void)
{
  run_vectorize_related_mode_vla_selftests ();
  run_vectorize_related_mode_vls_selftests ();
}

/* Check table and inline
   sizes, including the 64 KiB fixed mode that does not fit in uint16.  */
static void
run_ztt_group_mode_selftests ()
{
  const machine_mode fixed[] = { ZTTM1mode, ZTTM2mode, ZTTM4mode };
  ASSERT_TRUE (riscv_ztt::acc_mode_p (ZTTAR1mode));
  ASSERT_FALSE (riscv_ztt::m_mode_p (ZTTAR1mode));
  ASSERT_EQ (riscv_hard_regno_nregs (ACC_REG_FIRST, ZTTAR1mode), 1U);
  ASSERT_TRUE (known_eq (GET_MODE_SIZE (ZTTAR1mode),
			GET_MODE_SIZE (ZTTMR1mode) + 16));
  ASSERT_TRUE (known_eq (riscv_regmode_natural_size (ZTTAR1mode),
			GET_MODE_SIZE (ZTTAR1mode)));
  const machine_mode acc[] = { ZTTAR1mode, ZTTAR2mode, ZTTAR4mode };
  for (unsigned int i = 0; i < 3; ++i)
    {
      ASSERT_EQ (riscv_ztt::acc_m_nregs (acc[i]), 1U << i);
      ASSERT_EQ (riscv_hard_regno_nregs (ACC_REG_FIRST, acc[i]), 1U);
      ASSERT_TRUE (known_eq (GET_MODE_SIZE (acc[i]),
			    GET_MODE_SIZE (ZTTMR1mode) * (1U << i) + 16));
      ASSERT_TRUE (known_eq (riscv_regmode_natural_size (acc[i]),
			    GET_MODE_SIZE (acc[i])));
    }
  const machine_mode runtime[] = { ZTTMR1mode, ZTTMR2mode, ZTTMR4mode,
				   ZTTMR8mode, ZTTMR16mode, ZTTMR32mode };
  const machine_mode packed[] = {
    ZTTAP2X2mode, ZTTAP4X4mode, ZTTAP2X4mode,
    ZTTAP2X8mode, ZTTAP4X8mode, ZTTAP4X16mode,
    ZTTAP8X8mode, ZTTAP8X16mode, ZTTAP16X16mode
  };
  const unsigned int packets[] = { 2, 4, 2, 2, 4, 4, 8, 8, 16 };
  const unsigned int packed_accs[] = { 2, 4, 4, 8, 8, 16, 8, 16, 16 };
  for (unsigned int i = 0; i < ARRAY_SIZE (packed); ++i)
    {
      machine_mode mode = packed[i];
      unsigned int k = packed_accs[i], m = k / packets[i];
      ASSERT_TRUE (riscv_ztt::acc_mode_p (mode));
      ASSERT_FALSE (riscv_ztt::m_mode_p (mode));
      ASSERT_EQ (riscv_ztt::acc_nregs (mode), k);
      ASSERT_EQ (riscv_ztt::acc_m_nregs (mode), 1U);
      ASSERT_EQ (riscv_ztt::acc_transfer_accs (mode), packets[i]);
      ASSERT_EQ (riscv_ztt::acc_full_m_nregs (mode), m);
      ASSERT_EQ (riscv_hard_regno_nregs (ACC_REG_FIRST, mode), k);
      ASSERT_TRUE (known_eq (GET_MODE_SIZE (mode),
			    GET_MODE_SIZE (ZTTMR1mode) * m + 16 * k));
      ASSERT_TRUE (known_eq (riscv_regmode_natural_size (mode), GET_MODE_SIZE (mode)));
      ASSERT_TRUE (known_eq (GET_MODE_PRECISION (mode), GET_MODE_BITSIZE (mode)));
      for (unsigned int uds : { 8U, 16U, 32U, 64U, 128U })
	for (unsigned int n : { 4U, 8U, 32U, 128U, 256U })
	  {
	    poly_uint32 size = GET_MODE_SIZE (mode);
	    unsigned int scale = n * n * uds / 128;
	    ASSERT_EQ (size.coeffs[1], 0U);
	    ASSERT_EQ (size.coeffs[0] + size.coeffs[2] * (scale - 1),
		       16 * k + m * n * n * uds / 8);
	  }
    }
  for (unsigned int uds : { 8U, 16U, 32U, 64U, 128U })
    for (unsigned int bits : { 4U, 8U, 16U, 32U, 64U, 128U })
      for (unsigned int k : { 1U, 2U, 4U, 8U, 16U })
	for (unsigned int a : { 1U, 2U, 4U, 8U, 16U })
	  {
	    unsigned int payload = bits * k;
	    bool valid = k <= a && payload >= uds && payload % uds == 0;
	    ASSERT_EQ (riscv_ztt::acc_shape_supported_p (bits, k, uds, a), valid);
	  }
  ASSERT_TRUE (riscv_ztt::acc_shape_supported_p (4, 4, 16, 4));
  ASSERT_FALSE (riscv_ztt::acc_shape_supported_p (4, 16, 128, 16));
  ASSERT_TRUE (riscv_ztt::acc_shape_supported_p (64, 2, 32, 4));
  ASSERT_TRUE (riscv_ztt::acc_shape_supported_p (128, 1, 32, 4));
  ASSERT_TRUE (riscv_ztt::acc_shape_supported_p (128, 2, 32, 4));
  ASSERT_FALSE (riscv_ztt::acc_shape_supported_p (256, 1, 128, 4));
  ASSERT_FALSE (riscv_ztt::acc_shape_supported_p (8, 3, 16, 4));
  ASSERT_FALSE (riscv_ztt::acc_shape_supported_p (8, 2, 24, 4));
  const machine_mode tuples[] = { ZTTAR1X2mode, ZTTAR1X4mode, ZTTAR2X2mode };
  const unsigned int tuple_accs[] = { 2, 4, 2 };
  const unsigned int tuple_m[] = { 1, 1, 2 };
  for (unsigned int i = 0; i < ARRAY_SIZE (tuples); ++i)
    {
      machine_mode mode = tuples[i];
      ASSERT_EQ (riscv_ztt::acc_nregs (mode), tuple_accs[i]);
      ASSERT_EQ (riscv_ztt::acc_m_nregs (mode), tuple_m[i]);
      ASSERT_FALSE (riscv_ztt::m_mode_p (mode));
      ASSERT_EQ (riscv_hard_regno_nregs (ACC_REG_FIRST, mode), tuple_accs[i]);
      ASSERT_TRUE (known_eq (riscv_regmode_natural_size (mode), GET_MODE_SIZE (mode)));
      ASSERT_TRUE (known_eq (GET_MODE_SIZE (mode),
			    (GET_MODE_SIZE (ZTTMR1mode) * tuple_m[i] + 16)
			    * tuple_accs[i]));
      ASSERT_TRUE (known_eq (GET_MODE_PRECISION (mode), GET_MODE_BITSIZE (mode)));
      for (unsigned int uds : { 8U, 16U, 32U })
	for (unsigned int n : { 4U, 8U, 32U, 128U, 256U })
	  {
	    poly_uint32 size = GET_MODE_SIZE (mode);
	    unsigned int scale = n * n * uds / 128;
	    ASSERT_EQ (size.coeffs[1], 0U);
	    ASSERT_EQ (size.coeffs[0] + size.coeffs[2] * (scale - 1),
		       tuple_accs[i] * (16 + tuple_m[i] * n * n * uds / 8));
	  }
    }
  for (unsigned int i = 0; i < 3; ++i)
    {
      unsigned int nregs = 1U << i;
      ASSERT_EQ (riscv_ztt::m_nregs (fixed[i]), nregs);
      ASSERT_EQ (riscv_ztt::m_nregs (runtime[i]), nregs);
      ASSERT_TRUE (known_eq (riscv_regmode_natural_size (runtime[i]),
			    GET_MODE_SIZE (ZTTMR1mode)));
      ASSERT_EQ (mode_size[fixed[i]].to_constant (), 16384U * nregs);
      ASSERT_EQ (GET_MODE_SIZE (fixed[i]).to_constant (), 16384U * nregs);
      ASSERT_EQ (GET_MODE_BITSIZE (fixed[i]).to_constant (), 131072U * nregs);
      ASSERT_EQ (GET_MODE_PRECISION (fixed[i]).to_constant (),
		 131072U * nregs);
      ASSERT_TRUE (known_eq (GET_MODE_SIZE (runtime[i]),
			    poly_uint32 (16 * nregs, 0, 16 * nregs)));
      ASSERT_TRUE (known_eq (GET_MODE_PRECISION (runtime[i]),
			    GET_MODE_BITSIZE (runtime[i])));
    }
  /* All runtime-N resource profiles share these modes.  Evaluate the
     independent coefficient at several legal N values; register spans
     must not grow with the memory footprint.  */
  const unsigned int dimensions[] = { 4, 8, 16, 32, 64, 128, 256 };
  for (unsigned int i = 0; i < ARRAY_SIZE (runtime); ++i)
    {
      machine_mode mode = runtime[i];
      unsigned int nregs = 1U << i;
      ASSERT_EQ (riscv_ztt::m_nregs (mode), nregs);
      ASSERT_EQ (riscv_hard_regno_nregs (M_REG_FIRST, mode), nregs);
      ASSERT_TRUE (known_eq (GET_MODE_SIZE (mode),
			    GET_MODE_SIZE (ZTTMR1mode) * nregs));
      ASSERT_TRUE (known_eq (GET_MODE_PRECISION (mode), GET_MODE_BITSIZE (mode)));
      ASSERT_TRUE (known_eq (riscv_regmode_natural_size (mode), GET_MODE_SIZE (ZTTMR1mode)));
    }
  const char *saved_profile = riscv_ztt_profile_string;
  for (const char *profile : { "gcc-runtime-u8-m16-a4", "gcc-runtime-u128-m32-a16" })
    {
      riscv_ztt_profile_string = profile;
      unsigned int available = riscv_ztt::active_profile ()->mregs;
      for (unsigned int i = 0; i < ARRAY_SIZE (runtime); ++i)
	for (unsigned int reg = 0; reg < 32; ++reg)
	  ASSERT_EQ (targetm.hard_regno_mode_ok (M_REG_FIRST + reg, runtime[i]),
		     reg % (1U << i) == 0 && reg + (1U << i) <= available);
    }
  riscv_ztt_profile_string = "gcc-p0-n128-u8-m16-a4";
  for (machine_mode mode : runtime)
    ASSERT_FALSE (targetm.hard_regno_mode_ok (M_REG_FIRST, mode));
  riscv_ztt_profile_string = saved_profile;
  for (unsigned int uds : { 8U, 16U, 32U, 64U, 128U })
    for (unsigned int n : dimensions)
      for (machine_mode mode : runtime)
	{
	  poly_uint32 size = GET_MODE_SIZE (mode);
	  unsigned int scale = n * n * uds / 128;
	  ASSERT_EQ (size.coeffs[1], 0U);
	  ASSERT_EQ (size.coeffs[0] + size.coeffs[2] * (scale - 1),
		     n * n * uds / 8 * riscv_ztt::m_nregs (mode));
	}

  ASSERT_EQ (mode_size_inline (ZTTM4mode).to_constant (), 65536U);
  ASSERT_EQ (GET_MODE_SIZE (ZTTM4mode).to_constant (), 65536U);
}

/* Check the largest accepted
   power-of-two N against the mathematical, untruncated frame size.  */
static void
run_ztt_runtime_n_bound_selftests ()
{
  for (unsigned int uds : { 8U, 16U, 32U, 64U, 128U })
    for (unsigned int xlen : { 32U, 64U })
      for (unsigned int groups : { 0U, 1U, 4U, 9U, 40U, 1024U })
	for (unsigned int fixed : { 0U, 16U, 4096U })
	  {
	    poly_int64 frame (fixed + groups * 16, 0, groups * 16);
	    unsigned int exponent
	      = riscv_ztt::runtime_n_max_log2 (xlen, frame, uds);
	    unsigned HOST_WIDE_INT n = HOST_WIDE_INT_1U << exponent;
	    unsigned HOST_WIDE_INT limit = (HOST_WIDE_INT_1U << (xlen - 1)) - 1;
	    unsigned HOST_WIDE_INT factor = MAX (4, groups) * (uds / 8);
	    ASSERT_TRUE (n >= 4);
	    ASSERT_TRUE (n * n <= (limit - fixed) / factor);
	    ASSERT_TRUE ((2 * n) * (2 * n) > (limit - fixed) / factor);
	  }
  ASSERT_EQ (riscv_ztt::runtime_n_max_log2
	     (32, poly_int64 (HOST_WIDE_INT_1U << 31)), 0U);
}

/* Compare formation with
   independent whole-value and paired-square arithmetic, not ACC width.  */
static void
run_ztt_matmul_formation_selftests ()
{
  for (unsigned int uds : { 8U, 16U, 32U, 64U, 128U })
    for (unsigned int lhs : { 4U, 8U, 16U, 32U, 64U, 128U })
      for (unsigned int rhs : { 4U, 8U, 16U, 32U, 64U, 128U })
	for (unsigned int q : { 1U, 2U, 4U, 8U, 16U, 32U })
	  {
	    unsigned int ltotal = q * lhs, rtotal = q * rhs;
	    bool valid = ltotal >= uds && rtotal >= uds
	      && ltotal <= 32 * uds && rtotal <= 32 * uds;
	    riscv_ztt::matmul_formation f;
	    ASSERT_EQ (riscv_ztt::form_matmul (lhs, rhs, q, uds, f), valid);
	    if (valid)
	      {
		unsigned int p = 1;
		while (p * lhs < uds || p * rhs < uds)
		  p *= 2;
		ASSERT_EQ (f.squares_per_insn, p);
		ASSERT_EQ (f.insns * p, q);
		ASSERT_EQ (f.lhs_nregs * uds, ltotal);
		ASSERT_EQ (f.rhs_nregs * uds, rtotal);
		ASSERT_EQ (f.lhs_step * uds, p * lhs);
		ASSERT_EQ (f.rhs_step * uds, p * rhs);
		ASSERT_EQ (f.insns * f.lhs_step, f.lhs_nregs);
		ASSERT_EQ (f.insns * f.rhs_step, f.rhs_nregs);
	      }
	  }
  riscv_ztt::matmul_formation f;
  ASSERT_TRUE (riscv_ztt::form_matmul (4, 8, 2, 8, f));
  ASSERT_FALSE (riscv_ztt::form_matmul (2, 8, 2, 8, f));
  ASSERT_FALSE (riscv_ztt::form_matmul (8, 256, 2, 8, f));
  ASSERT_FALSE (riscv_ztt::form_matmul (8, 8, 3, 8, f));
  ASSERT_FALSE (riscv_ztt::form_matmul (8, 8, 0, 8, f));
  ASSERT_FALSE (riscv_ztt::form_matmul (8, 8, 64, 128, f));
  ASSERT_FALSE (riscv_ztt::form_matmul (8, 8, 1, 0, f));
  ASSERT_FALSE (riscv_ztt::form_matmul (8, 8, 4, 24, f));
}

/* Check every supported
   integer-width geometry, including destination-driven packing.  */
static void
run_ztt_elementwise_formation_selftests ()
{
  for (unsigned int uds : { 8U, 16U, 32U, 64U, 128U })
    for (unsigned int dst : { 4U, 8U, 16U, 32U, 64U, 128U })
      for (unsigned int data : { 4U, 8U, 16U, 32U, 64U, 128U })
	for (unsigned int count : { 0U, 4U, 8U, 16U, 32U, 64U, 128U })
	  for (unsigned int q : { 1U, 2U, 4U, 8U, 16U, 32U })
	    {
	      unsigned int bits[] = { dst, data, count };
	      unsigned int operands = count ? 3 : 2;
	      bool valid = true;
	      unsigned int squares = 1;
	      for (unsigned int i = 0; i < operands; ++i)
		{
		  valid &= q * bits[i] >= uds && q * bits[i] <= 32 * uds;
		  while (squares * bits[i] < uds)
		    squares *= 2;
		}
	      riscv_ztt::elementwise_formation f;
	      ASSERT_EQ (riscv_ztt::form_elementwise (dst, data, count, q, uds, f), valid);
	      if (!valid)
		continue;
	      ASSERT_EQ (f.squares_per_insn, squares);
	      ASSERT_EQ (f.insns * squares, q);
	      for (unsigned int i = 0; i < operands; ++i)
		{
		  ASSERT_EQ (f.nregs[i] * uds, q * bits[i]);
		  ASSERT_EQ (f.step[i] * uds, squares * bits[i]);
		  ASSERT_EQ (f.step[i] * f.insns, f.nregs[i]);
		}
	      if (!count)
		{
		  ASSERT_EQ (f.nregs[2], 0U);
		  ASSERT_EQ (f.step[2], 0U);
		}
	    }
  riscv_ztt::elementwise_formation f;
  ASSERT_TRUE (riscv_ztt::form_elementwise (128, 32, 64, 1, 32, f));
  ASSERT_FALSE (riscv_ztt::form_elementwise (256, 64, 64, 1, 64, f));
  ASSERT_TRUE (riscv_ztt::form_elementwise (4, 8, 8, 2, 8, f));
  ASSERT_FALSE (riscv_ztt::form_elementwise (2, 8, 8, 4, 8, f));
  ASSERT_TRUE (riscv_ztt::form_elementwise (8, 64, 8, 1, 8, f));
  ASSERT_FALSE (riscv_ztt::form_elementwise (8, 8, 4, 1, 8, f));
  ASSERT_FALSE (riscv_ztt::form_elementwise (8, 8, 0, 0, 8, f));
  ASSERT_FALSE (riscv_ztt::form_elementwise (8, 8, 0, 3, 8, f));
  ASSERT_FALSE (riscv_ztt::form_elementwise (8, 8, 0, 64, 128, f));
  ASSERT_FALSE (riscv_ztt::form_elementwise (8, 8, 0, 1, 0, f));
  ASSERT_FALSE (riscv_ztt::form_elementwise (8, 8, 0, 1, 24, f));
}

/* Duplicate preparation is
   removable only for identical post-reload physical groups and descriptors.
   The public length helper exercises the predicate also used by final output.  */
static void
run_ztt_elementwise_shared_source_selftests ()
{
  int saved_reload = reload_completed;
  const machine_mode fixed[] = { ZTTM1mode, ZTTM2mode, ZTTM4mode };
  const machine_mode runtime[] = { ZTTMR1mode, ZTTMR2mode, ZTTMR4mode };
  const machine_mode integer[] = { SImode, DImode };
  for (unsigned int i = 0; i < 3; ++i)
    for (machine_mode mode : { fixed[i], runtime[i] })
      for (machine_mode gmode : integer)
	for (unsigned int step = 1; step <= (1U << i); step *= 2)
	  {
	    unsigned int nregs = 1U << i;
	    rtx ops[13] = {};
	    ops[11] = ops[12] = const0_rtx;
	    ops[0] = gen_rtx_REG (ZTTMR1mode, M_REG_FIRST + 12);
	    ops[1] = gen_rtx_REG (mode, M_REG_FIRST);
	    ops[2] = gen_rtx_REG (mode, M_REG_FIRST);
	    ops[4] = gen_rtx_REG (gmode, 11);
	    ops[5] = gen_rtx_REG (gmode, 11);
	    ops[8] = GEN_INT (6);
	    ops[9] = GEN_INT (riscv_ztt::pack_datatype_steps (1, step, step));
	    unsigned int prepare = nregs / step + (nregs == 1 ? 2 : 4 * nregs);
	    unsigned int full = 4 * (2 + 2 * prepare);
	    unsigned int reduced = 4 * (2 + prepare);
	    reload_completed = 0;
	    ASSERT_EQ (riscv_ztt::elementwise_length (ops, false), full);
	    reload_completed = 1;
	    ASSERT_EQ (riscv_ztt::elementwise_length (ops, false), reduced);
	    /* Comparison/select do not write amestype; cmov also preserves D.  */
	    for (unsigned int variant : { 27U, 28U, 31U, 32U })
	      {
		ops[8] = GEN_INT (variant);
		ASSERT_EQ (riscv_ztt::elementwise_length (ops, false), reduced);
	      }
	    for (unsigned int variant : { 4U, 5U })
	      {
		ops[8] = GEN_INT (variant);
		ASSERT_EQ (riscv_ztt::ternary_length (ops), reduced + 8);
	      }
	    ops[8] = GEN_INT (6);
	    ops[2] = gen_rtx_REG (mode, M_REG_FIRST + 8);
	    ASSERT_EQ (riscv_ztt::elementwise_length (ops, false), full);
	    if (nregs > 1)
	      {
		ops[2] = gen_rtx_REG (mode, M_REG_FIRST + 1);
		ASSERT_EQ (riscv_ztt::elementwise_length (ops, false), full);
	      }
	    machine_mode other = mode == fixed[i] ? runtime[i] : fixed[i];
	    ops[2] = gen_rtx_REG (other, M_REG_FIRST);
	    ASSERT_EQ (riscv_ztt::elementwise_length (ops, false), full);
	    ops[2] = ops[1];
	    ops[5] = gen_rtx_REG (gmode, 12);
	    ASSERT_EQ (riscv_ztt::elementwise_length (ops, false), full);
	    ops[5] = gen_rtx_REG (gmode == SImode ? DImode : SImode, 11);
	    ASSERT_EQ (riscv_ztt::elementwise_length (ops, false), full);
	    ops[4] = ops[5] = gen_rtx_REG (gmode, FIRST_PSEUDO_REGISTER);
	    ASSERT_EQ (riscv_ztt::elementwise_length (ops, false), full);
	    ops[4] = ops[5] = gen_rtx_REG (gmode, 11);
	    ops[1] = ops[2] = gen_rtx_REG (mode, FIRST_PSEUDO_REGISTER);
	    ASSERT_EQ (riscv_ztt::elementwise_length (ops, false), full);
	    ops[1] = ops[2] = gen_rtx_REG (mode, M_REG_FIRST);
	    if (step > 1)
	      {
		ops[9] = GEN_INT (riscv_ztt::pack_datatype_steps (1, step, step / 2));
		ASSERT_EQ (riscv_ztt::elementwise_length (ops, false),
			   full + 4 * nregs / step);
	      }
	    ops[9] = GEN_INT (riscv_ztt::pack_datatype_steps (1, step));
	    ops[2] = gen_rtx_REG (gmode, 10);
	    ops[5] = const0_rtx;
	    ops[8] = GEN_INT (1);
	    ASSERT_EQ (riscv_ztt::elementwise_length (ops, true), reduced);
	    /* Data-scalar arithmetic prepares amestype; control shifts do not.  */
	    ops[5] = gen_rtx_REG (gmode, 12);
	    for (unsigned int variant = 13; variant <= 26; ++variant)
	      {
		ops[8] = GEN_INT (variant);
		ASSERT_EQ (riscv_ztt::elementwise_length (ops, true), reduced + 4);
	      }
	    for (unsigned int variant : { 29U, 30U })
	      {
		ops[8] = GEN_INT (variant);
		ASSERT_EQ (riscv_ztt::elementwise_length (ops, true), reduced + 4);
	      }
	    /* Scalar ternary also saves/restores the old one-M destination.  */
	    for (unsigned int variant = 0; variant < 4; ++variant)
	      {
		ops[8] = GEN_INT (variant);
		ASSERT_EQ (riscv_ztt::scalar_ternary_length (ops), reduced + 12);
	      }
	  }
  reload_completed = saved_reload;
}

/* Destination reuse must not
   shorten envelopes that preserve an old destination, or accept partial
   mode/descriptor/step matches.  */
static void
run_ztt_elementwise_destination_selftests ()
{
  int saved_reload = reload_completed;
  const machine_mode modes[] = { ZTTMR1mode, ZTTMR2mode, ZTTMR4mode,
				 ZTTMR8mode, ZTTMR16mode, ZTTMR32mode };
  for (machine_mode mode : modes)
    for (machine_mode gmode : { SImode, DImode })
      for (unsigned int step = 1; step <= riscv_ztt::m_nregs (mode); step *= 2)
	{
	  unsigned int n = riscv_ztt::m_nregs (mode);
	  unsigned int setup = 4 * n / step;
	  unsigned int transfer = 4 * (n == 1 ? 2 : 4 * n);
	  rtx ops[13] = {};
	  ops[11] = ops[12] = const0_rtx;
	  ops[0] = ops[1] = ops[2] = gen_rtx_REG (mode, M_REG_FIRST);
	  ops[3] = ops[4] = ops[5] = gen_rtx_REG (gmode, 11);
	  ops[8] = GEN_INT (6);
	  ops[9] = GEN_INT (riscv_ztt::pack_datatype_steps (step, step, step));
	  reload_completed = 0;
	  ASSERT_EQ (riscv_ztt::elementwise_length (ops, false),
		     4 + 3 * setup + 2 * transfer);
	  reload_completed = 1;
	  unsigned int reduced = 4 + setup + transfer;
	  ASSERT_EQ (riscv_ztt::elementwise_length (ops, false), reduced);
	  rtx prepared_ops[] = { ops[0], ops[1], ops[2], ops[3], ops[4],
				 ops[5], ops[8], ops[9] };
	  ASSERT_TRUE (riscv_ztt::common_prepared_operands_p (prepared_ops, false));
	  prepared_ops[3] = gen_rtx_REG (gmode, 12);
	  ASSERT_FALSE (riscv_ztt::common_prepared_operands_p (prepared_ops, false));
	  if (n <= 16)
	    {
	      prepared_ops[0] = gen_rtx_REG (mode, M_REG_FIRST + 16);
	      ASSERT_TRUE (riscv_ztt::common_prepared_operands_p (prepared_ops, false));
	    }
	  prepared_ops[3] = ops[3];
	  if (n > 1)
	    {
	      prepared_ops[0] = gen_rtx_REG (ZTTMR1mode, M_REG_FIRST);
	      ASSERT_FALSE (riscv_ztt::common_prepared_operands_p (prepared_ops, false));
	    }
	  prepared_ops[0] = ops[0];
	  reload_completed = 0;
	  ASSERT_FALSE (riscv_ztt::common_prepared_operands_p (prepared_ops, false));
	  reload_completed = 1;
	  ASSERT_EQ (riscv_ztt::ternary_length (ops), reduced + setup + transfer);
	  ops[11] = GEN_INT (6);
	  ASSERT_EQ (riscv_ztt::elementwise_length (ops, false), 4U);
	  ops[11] = const0_rtx;
	  for (unsigned int mask = 0; mask < 8; ++mask)
	    {
	      ops[12] = GEN_INT (mask);
	      unsigned int expected = 4
		+ ((mask & 1) ? 0 : setup + transfer)
		+ ((mask & 2) ? 0 : setup + transfer);
	      ASSERT_EQ (riscv_ztt::ternary_length (ops), expected);
	      ops[8] = GEN_INT (2);
	      ASSERT_EQ (riscv_ztt::indexed_length (ops), expected);
	      ops[8] = GEN_INT (6);
	    }
	  ops[12] = const0_rtx;
	  ops[8] = GEN_INT (2);
	  ASSERT_EQ (riscv_ztt::indexed_length (ops), reduced + setup + transfer);
	  ops[8] = GEN_INT (0);
	  ASSERT_EQ (riscv_ztt::indexed_length (ops), reduced);
	  ops[3] = gen_rtx_REG (gmode, 12);
	  ASSERT_EQ (riscv_ztt::elementwise_length (ops, false), reduced + setup);
	  ops[3] = gen_rtx_REG (gmode == SImode ? DImode : SImode, 11);
	  ASSERT_EQ (riscv_ztt::elementwise_length (ops, false), reduced + setup);
	  ops[3] = ops[4];
	  ops[0] = gen_rtx_REG (mode, FIRST_PSEUDO_REGISTER);
	  ASSERT_EQ (riscv_ztt::elementwise_length (ops, false), reduced + setup);
	  ops[0] = gen_rtx_REG (mode == ZTTMR1mode ? ZTTM1mode : ZTTMR1mode,
			      M_REG_FIRST);
	  ops[9] = GEN_INT (riscv_ztt::pack_datatype_steps (1, step, step));
	  ASSERT_EQ (riscv_ztt::elementwise_length (ops, false), reduced + 4);
	  ops[0] = ops[1];
	  ops[9] = GEN_INT (riscv_ztt::pack_datatype_steps (step, step, step));
	  if (n <= 16)
	    for (unsigned int source : { 1U, 2U })
	      {
		ops[source] = gen_rtx_REG (mode, M_REG_FIRST + 16);
		ASSERT_EQ (riscv_ztt::elementwise_length (ops, false),
			   reduced + setup + transfer);
		ops[source] = ops[0];
	      }
	  ops[2] = gen_rtx_REG (gmode, 10);
	  ops[5] = const0_rtx;
	  ops[9] = GEN_INT (riscv_ztt::pack_datatype_steps (step, step));
	  ops[8] = GEN_INT (1);
	  ASSERT_EQ (riscv_ztt::elementwise_length (ops, true), reduced);
	  ASSERT_EQ (riscv_ztt::scalar_ternary_length (ops),
		     reduced + setup + transfer + 4);
	  for (unsigned int mask = 0; mask < 4; ++mask)
	    {
	      ops[12] = GEN_INT (mask);
	      ASSERT_EQ (riscv_ztt::scalar_ternary_length (ops),
			 8U + ((mask & 1) ? 0 : setup + transfer)
			 + ((mask & 2) ? 0 : setup + transfer));
	    }
	  ops[12] = const0_rtx;
	  ops[11] = GEN_INT (2);
	  ASSERT_EQ (riscv_ztt::elementwise_length (ops, true), 4U);
	  ops[11] = const0_rtx;
	  ops[8] = GEN_INT (18);
	  ASSERT_EQ (riscv_ztt::elementwise_length (ops, true), reduced + 4);
	  if (step > 1)
	    {
	      ops[9] = GEN_INT (riscv_ztt::pack_datatype_steps (step / 2, step));
	      ASSERT_EQ (riscv_ztt::elementwise_length (ops, true),
			 reduced + 4 + 2 * setup);
	    }
	}
  reload_completed = saved_reload;
}

/* Storage size is not
   physical register count or the width of a single transfer window.  */
static void
run_ztt_large_acc_mode_selftests ()
{
  const struct { machine_mode mode; unsigned int r, k, packet; } cases[] = {
    { ZTTAR1mode, 1, 1, 1 },
    { ZTTAR2mode, 2, 1, 1 },
    { ZTTAR4mode, 4, 1, 1 },
    { ZTTAR1X2mode, 1, 2, 1 },
    { ZTTAR1X4mode, 1, 4, 1 },
    { ZTTAR2X2mode, 2, 2, 1 },
    { ZTTAP2X2mode, 1, 2, 2 },
    { ZTTAP4X4mode, 1, 4, 4 },
    { ZTTAP2X4mode, 1, 4, 2 },
    { ZTTAP2X8mode, 1, 8, 2 },
    { ZTTAP4X8mode, 1, 8, 4 },
    { ZTTAP4X16mode, 1, 16, 4 },
    { ZTTAP8X8mode, 1, 8, 8 },
    { ZTTAP8X16mode, 1, 16, 8 },
    { ZTTAP16X16mode, 1, 16, 16 },
    { ZTTAR1X8mode, 1, 8, 1 },
    { ZTTAR1X16mode, 1, 16, 1 },
    { ZTTAR2X4mode, 2, 4, 1 },
    { ZTTAR2X8mode, 2, 8, 1 },
    { ZTTAR2X16mode, 2, 16, 1 },
    { ZTTAR4X2mode, 4, 2, 1 },
    { ZTTAR4X4mode, 4, 4, 1 },
    { ZTTAR4X8mode, 4, 8, 1 },
    { ZTTAR4X16mode, 4, 16, 1 },
    { ZTTAR8mode, 8, 1, 1 },
    { ZTTAR8X2mode, 8, 2, 1 },
    { ZTTAR8X4mode, 8, 4, 1 },
    { ZTTAR8X8mode, 8, 8, 1 },
    { ZTTAR8X16mode, 8, 16, 1 },
    { ZTTAR16mode, 16, 1, 1 },
    { ZTTAR16X2mode, 16, 2, 1 },
    { ZTTAR16X4mode, 16, 4, 1 },
    { ZTTAR16X8mode, 16, 8, 1 },
    { ZTTAR16X16mode, 16, 16, 1 },
    { ZTTAP2X16mode, 1, 16, 2 },
  };
  for (const auto &c : cases)
    {
      unsigned int payload = c.r * c.k / c.packet;
      ASSERT_TRUE (riscv_ztt::acc_mode_p (c.mode));
      ASSERT_FALSE (riscv_ztt::m_mode_p (c.mode));
      ASSERT_EQ (riscv_ztt::acc_nregs (c.mode), c.k);
      ASSERT_EQ (riscv_ztt::acc_m_nregs (c.mode), c.r);
      ASSERT_EQ (riscv_ztt::acc_transfer_accs (c.mode), c.packet);
      ASSERT_EQ (riscv_ztt::acc_full_m_nregs (c.mode), payload);
      ASSERT_EQ (riscv_hard_regno_nregs (ACC_REG_FIRST, c.mode), c.k);
      ASSERT_TRUE (known_eq (GET_MODE_SIZE (c.mode),
	GET_MODE_SIZE (ZTTMR1mode) * payload + 16 * c.k));
      ASSERT_TRUE (known_eq (GET_MODE_PRECISION (c.mode), GET_MODE_BITSIZE (c.mode)));
      ASSERT_TRUE (known_eq (riscv_regmode_natural_size (c.mode), GET_MODE_SIZE (c.mode)));
      for (unsigned int uds : { 8U, 16U, 32U, 64U, 128U })
	for (unsigned int n : { 4U, 8U, 32U, 128U, 256U })
	  {
	    poly_uint32 size = GET_MODE_SIZE (c.mode);
	    unsigned int scale = n * n * uds / 128;
	    ASSERT_EQ (size.coeffs[1], 0U);
	    ASSERT_EQ (size.coeffs[0] + size.coeffs[2] * (scale - 1),
		       16 * c.k + payload * n * n * uds / 8);
	  }
    }
  const char *saved = riscv_ztt_profile_string;
  for (unsigned int uds : { 8U, 16U, 32U, 64U, 128U })
    for (unsigned int m : { 16U, 32U })
      for (unsigned int a : { 1U, 2U, 4U, 8U, 16U })
	{
	  char profile[64];
	  snprintf (profile, sizeof profile, "gcc-runtime-u%u-m%u-a%u", uds, m, a);
	  riscv_ztt_profile_string = profile;
	  for (const auto &c : cases)
	    {
	      unsigned int bits = c.r * uds / c.packet;
	      bool supported = bits >= 4 && bits <= 128 && c.k <= a;
	      ASSERT_EQ (riscv_ztt::acc_mode_supported_p (c.mode), supported);
	      for (unsigned int reg = 0; reg < ACC_REG_NUM; ++reg)
		ASSERT_EQ (targetm.hard_regno_mode_ok (ACC_REG_FIRST + reg, c.mode),
			   supported && reg % c.k == 0 && reg + c.k <= a);
	    }
	}
  riscv_ztt_profile_string = saved;
}

/* Ordinary modes must be
   rejected before profile lookup in the hard-register initialization loop.  */
static void
run_ztt_nonvalue_mode_selftests ()
{
  const char *saved_profile = riscv_ztt_profile_string;
  const char *profiles[] = {
    nullptr,
#define ZTT_PROFILE(ID, NAME, NELEM, N, UDS, MREGS, ACCREGS) NAME,
#include "riscv-ztt-profile.def"
#undef ZTT_PROFILE
  };
  for (const char *profile : profiles)
    {
      riscv_ztt_profile_string = profile;
      for (unsigned int i = 0; i < NUM_MACHINE_MODES; ++i)
	{
	  machine_mode mode = (machine_mode) i;
	  if (riscv_ztt::value_mode_p (mode))
	    continue;
	  ASSERT_FALSE (riscv_ztt::acc_mode_supported_p (mode));
	  ASSERT_FALSE (targetm.hard_regno_mode_ok (M_REG_FIRST, mode));
	  ASSERT_FALSE (targetm.hard_regno_mode_ok (ACC_REG_FIRST, mode));
	}
    }
  riscv_ztt_profile_string = saved_profile;
}

/* Count each emitted
   setup, raw transfer and address step, independently of the length formula.  */
static void
run_ztt_conversion_length_selftests ()
{
  const machine_mode modes[] = { ZTTM1mode, ZTTM2mode, ZTTM4mode,
				 ZTTMR1mode, ZTTMR2mode, ZTTMR4mode,
				 ZTTMR8mode, ZTTMR16mode, ZTTMR32mode };
  for (unsigned int d = 0; d < ARRAY_SIZE (modes); ++d)
    for (unsigned int s = 0; s < ARRAY_SIZE (modes); ++s)
      for (unsigned int ds = 1; ds <= riscv_ztt::m_nregs (modes[d]); ds *= 2)
	for (unsigned int ss = 1; ss <= riscv_ztt::m_nregs (modes[s]); ss *= 2)
	  {
	    unsigned int dn = riscv_ztt::m_nregs (modes[d]);
	    unsigned int sn = riscv_ztt::m_nregs (modes[s]);
	    rtx ops[8] = {};
	    ops[0] = gen_rtx_REG (modes[d], M_REG_FIRST + (dn <= 16 ? 16 : 0));
	    ops[1] = gen_rtx_REG (modes[s], M_REG_FIRST);
	    ops[6] = GEN_INT (riscv_ztt::pack_datatype_steps (ds, ss));
	    unsigned int instructions = 1;
	    for (unsigned int i = 0; i < dn; i += ds)
	      ++instructions;
	    for (unsigned int i = 0; i < sn; i += ss)
	      ++instructions;
	    for (unsigned int pass = 0; pass < 2; ++pass)
	      {
		if (sn > 1)
		  ++instructions;
		for (unsigned int i = 0; i < sn; ++i)
		  {
		    ++instructions;
		    if (i + 1 < sn)
		      ++instructions;
		  }
	      }
	    ASSERT_EQ (riscv_ztt::conversion_length (ops), 4 * instructions);
	  }
}

/* Only a complete physical
   source with identical Md and step can eliminate destination preparation.  */
static void
run_ztt_unary_destination_selftests ()
{
  int saved_reload = reload_completed;
  for (machine_mode mode : { ZTTMR1mode, ZTTMR2mode, ZTTMR4mode,
			    ZTTMR8mode, ZTTMR16mode, ZTTMR32mode })
    for (machine_mode gmode : { SImode, DImode })
      for (unsigned int step = 1; step <= riscv_ztt::m_nregs (mode); step *= 2)
	{
	  unsigned int n = riscv_ztt::m_nregs (mode);
	  unsigned int setup = 4 * n / step;
	  unsigned int transfer = 4 * (n == 1 ? 2 : 4 * n);
	  rtx ops[9] = {};
	  ops[0] = ops[1] = gen_rtx_REG (mode, M_REG_FIRST);
	  ops[2] = ops[3] = gen_rtx_REG (gmode, 11);
	  ops[6] = GEN_INT (riscv_ztt::pack_datatype_steps (step, step));
	  unsigned int reduced = 4 + setup + transfer;
	  reload_completed = 0;
	  ASSERT_EQ (riscv_ztt::conversion_length (ops), reduced + setup);
	  ASSERT_EQ (riscv_ztt::rowcol_length (ops), 12 + transfer);
	  reload_completed = 1;
	  ASSERT_EQ (riscv_ztt::conversion_length (ops), reduced);
	  ASSERT_EQ (riscv_ztt::rowcol_length (ops), 8 + transfer);
	  ops[2] = gen_rtx_REG (gmode, 12);
	  ASSERT_EQ (riscv_ztt::conversion_length (ops), reduced + setup);
	  ops[2] = gen_rtx_REG (gmode == SImode ? DImode : SImode, 11);
	  ASSERT_EQ (riscv_ztt::conversion_length (ops), reduced + setup);
	  ops[2] = NULL_RTX;
	  ASSERT_EQ (riscv_ztt::conversion_length (ops), reduced + setup);
	  ops[2] = ops[3];
	  ops[0] = gen_rtx_REG (mode, FIRST_PSEUDO_REGISTER);
	  ASSERT_EQ (riscv_ztt::conversion_length (ops), reduced + setup);
	  ASSERT_EQ (riscv_ztt::rowcol_length (ops), 12 + transfer);
	  ops[0] = gen_rtx_REG (mode == ZTTMR1mode ? ZTTM1mode : ZTTMR1mode,
			      M_REG_FIRST);
	  ops[6] = GEN_INT (riscv_ztt::pack_datatype_steps (1, step));
	  ASSERT_EQ (riscv_ztt::conversion_length (ops), reduced + 4);
	  ops[0] = ops[1];
	  ops[6] = GEN_INT (riscv_ztt::pack_datatype_steps (step, step));
	  if (step > 1)
	    {
	      ops[6] = GEN_INT (riscv_ztt::pack_datatype_steps (step / 2, step));
	      ASSERT_EQ (riscv_ztt::conversion_length (ops), reduced + 2 * setup);
	      ops[6] = GEN_INT (riscv_ztt::pack_datatype_steps (step, step));
	    }
	  if (n <= 16)
	    {
	      ops[0] = gen_rtx_REG (mode, M_REG_FIRST + 16);
	      ASSERT_EQ (riscv_ztt::conversion_length (ops), reduced + setup);
	      ASSERT_EQ (riscv_ztt::rowcol_length (ops), 12 + transfer);
	    }
	}
  reload_completed = saved_reload;
}

/* Profile geometry must not
   inherit the current four-M mode limit, nor accept fractional registers.
   Validate inputs before multiplying widths or dividing by UDS.  */
static void
run_ztt_complete_shape_selftests ()
{
  for (unsigned int limit : { 1U, 2U, 4U, 8U, 16U, 32U })
    for (unsigned int uds : { 8U, 16U, 32U, 64U, 128U })
      for (unsigned int bits : { 4U, 8U, 16U, 32U, 64U, 128U })
	for (unsigned int q : { 1U, 2U, 4U, 8U, 16U, 32U })
	  {
	    unsigned int total = bits * q;
	    unsigned int expected = total % uds || total / uds > limit
	      ? 0 : total / uds;
	    ASSERT_EQ (riscv_ztt::m_shape_nregs (bits, q, uds, limit), expected);
	  }
  for (unsigned int bad : { 0U, 1U, 2U, 3U, 5U, 24U, 256U, ~0U })
    ASSERT_EQ (riscv_ztt::m_shape_nregs (bad, 1, 8, 32), 0U);
  for (unsigned int bad : { 0U, 3U, 6U, 64U, ~0U })
    {
      ASSERT_EQ (riscv_ztt::m_shape_nregs (8, bad, 8, 32), 0U);
      ASSERT_EQ (riscv_ztt::m_shape_nregs (8, 1, 8, bad), 0U);
    }
  for (unsigned int bad : { 0U, 1U, 4U, 24U, 256U, ~0U })
    ASSERT_EQ (riscv_ztt::m_shape_nregs (8, 1, bad, 32), 0U);
  ASSERT_EQ (riscv_ztt::m_shape_nregs (4, 1, 8, 32), 0U);
  ASSERT_EQ (riscv_ztt::m_shape_nregs (4, 2, 8, 32), 1U);
  ASSERT_EQ (riscv_ztt::m_shape_nregs (128, 2, 8, 16), 0U);
  ASSERT_EQ (riscv_ztt::m_shape_nregs (128, 2, 8, 32), 32U);
  ASSERT_EQ (riscv_ztt::m_shape_nregs (128, 4, 8, 32), 0U);
  ASSERT_EQ (riscv_ztt::shape_nregs (64, 1, 8), 8U);
  ASSERT_EQ (riscv_ztt::shape_nregs (128, 2, 8), 32U);
  ASSERT_EQ (riscv_ztt::shape_nregs (32, 1, 8), 4U);
  ASSERT_EQ (riscv_ztt::shape_nregs (8, 1, 0), 0U);
}

static void
run_ztt_datatype_step_selftests ()
{
  for (unsigned int dst : { 1U, 2U, 4U, 8U, 16U, 32U })
    for (unsigned int src : { 1U, 2U, 4U, 8U, 16U, 32U })
      for (unsigned int other : { 0U, 1U, 2U, 4U, 8U, 16U, 32U })
	{
	  unsigned int packed = riscv_ztt::pack_datatype_steps (dst, src, other);
	  ASSERT_EQ (packed, dst + 64 * src + 4096 * other);
	  ASSERT_EQ (riscv_ztt::datatype_step (packed, 0), dst);
	  ASSERT_EQ (riscv_ztt::datatype_step (packed, 1), src);
	  ASSERT_EQ (riscv_ztt::datatype_step (packed, 2), other);
	}
  /* Decode constants independently, not only encoder/decoder round trips.  */
  ASSERT_EQ (riscv_ztt::datatype_step (2064, 0), 16U);
  ASSERT_EQ (riscv_ztt::datatype_step (2064, 1), 32U);
  ASSERT_EQ (riscv_ztt::datatype_step (2064, 2), 0U);
  ASSERT_EQ (riscv_ztt::datatype_step (33824, 0), 32U);
  ASSERT_EQ (riscv_ztt::datatype_step (33824, 1), 16U);
  ASSERT_EQ (riscv_ztt::datatype_step (33824, 2), 8U);
}

namespace selftest {
/* Run all target-specific selftests.  */
void
riscv_run_selftests (void)
{
  run_ztt_group_mode_selftests ();
  run_ztt_large_acc_mode_selftests ();
  run_ztt_complete_shape_selftests ();
  run_ztt_datatype_step_selftests ();
  run_ztt_runtime_n_bound_selftests ();
  run_ztt_matmul_formation_selftests ();
  run_ztt_elementwise_formation_selftests ();
  riscv_ztt::run_wide_signature_selftests ();
  run_ztt_elementwise_shared_source_selftests ();
  run_ztt_elementwise_destination_selftests ();
  run_ztt_conversion_length_selftests ();
  run_ztt_unary_destination_selftests ();
  run_ztt_nonvalue_mode_selftests ();
  for (unsigned int uds : { 8U, 16U, 32U, 64U, 128U })
    for (unsigned int bits : { 4U, 8U, 16U, 32U, 64U, 128U })
      for (unsigned int squares : { 1U, 2U, 4U, 8U, 16U, 32U })
	{
	  unsigned int total = bits * squares;
	  unsigned int expected = total < uds || total > 32 * uds ? 0 : total / uds;
	  ASSERT_EQ (riscv_ztt::shape_nregs (bits, squares, uds), expected);
	}
  if (!BYTES_PER_RISCV_VECTOR.is_constant ())
    /* We can know POLY value = [4, 4] when BYTES_PER_RISCV_VECTOR
       is !is_constant () since we can use csrr vlenb and scalar shift
       instruction to compute such POLY value and store it into a scalar
       register.  Whereas, we can't know [4, 4] on it is specified as
       FIXED-VLMAX since BYTES_PER_RISCV_VECTOR = 16 for -march=rv64gcv
       and csrr vlenb is 16 which is totally unrelated to any
       compile-time unknown POLY value.

       Since we never need to compute a compile-time unknown POLY value
       when -mrvv-vector-bits=zvl, disable poly
       selftests in such situation.  */
    run_poly_int_selftests ();
  run_const_vector_selftests ();
  run_broadcast_selftests ();
  run_vectorize_related_mode_selftests ();
}
} // namespace selftest
#endif /* #if CHECKING_P */
