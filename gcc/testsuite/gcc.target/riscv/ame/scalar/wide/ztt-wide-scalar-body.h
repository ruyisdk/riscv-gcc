/* Compile/assemble checks, not numerical execution evidence.  */
#include <stdint.h>
#include <riscv_ztt.h>
#include "../../fixtures/ztt-scalar-construct.h"
#if __riscv_ztt_wide_scalar_int != 1
#error Missing wide scalar integer capability
#endif
#ifdef __cplusplus
extern "C" {
#endif
#define TYPE_(T, S) __riscv_ztt_##T##_##S##_t
#define TYPE(T, S) TYPE_(T, S)
#define ZERO_(T, S) __riscv_ztt_mzero_m_##T##_##S ()
#define ZERO(T, S) ZERO_(T, S)
#define OP_(F, T, S, C) __riscv_ztt_##F##_##T##_##S##_##C
#define OP(F, T, S, C) OP_(F, T, S, C)
#define KEEP(X) __asm__ volatile ("" : : "Wmr" (X))
#define SCALAR(F, T, S, C) \
  void F##_##T##_##S##_##C (uintptr_t c) \
  { \
    TYPE(T, S) b = ZERO(T, S); \
    TYPE(T, S) d = OP(F, T, S, C) (b, ZTT_TEST_BITS(C, c)); \
    KEEP(d); KEEP(b); \
  }
#define TERNARY_X(F, T, S, C) \
  void F##_##T##_##S##_##C (uintptr_t c) \
  { \
    TYPE(T, S) b = ZERO(T, S); \
    TYPE(T, S) old = ZERO(T, S); \
    TYPE(T, S) d = OP(F, T, S, C) (old, b, ZTT_TEST_BITS(C, c)); \
    KEEP(d); KEEP(old); KEEP(b); \
  }
#define BCAST(F, T, S, C) \
  void F##_##T##_##S##_##C (uintptr_t c) \
  { \
    TYPE(T, S) d = OP(F, T, S, C) (ZTT_TEST_BITS(C, c)); \
    KEEP(d); \
  }
#define SUITE(T, S, C) \
  SCALAR(madd_ew_x, T, S, C) \
  SCALAR(msub_ew_x, T, S, C) \
  SCALAR(mmul_ew_x, T, S, C) \
  SCALAR(mabsdiff_ew_x, T, S, C) \
  SCALAR(mhdiff_ew_x, T, S, C) \
  SCALAR(mmean_ew_x, T, S, C) \
  SCALAR(mmulneg_ew_x, T, S, C) \
  SCALAR(mmin_ew_x, T, S, C) \
  SCALAR(mmax_ew_x, T, S, C) \
  SCALAR(mand_ew_x, T, S, C) \
  SCALAR(mandnot_ew_x, T, S, C) \
  SCALAR(mor_ew_x, T, S, C) \
  SCALAR(mornot_ew_x, T, S, C) \
  SCALAR(mxor_ew_x, T, S, C) \
  TERNARY_X(mmulacc_ew_x, T, S, C) \
  TERNARY_X(mmulaccneg_ew_x, T, S, C) \
  TERNARY_X(mmuladd_ew_x, T, S, C) \
  TERNARY_X(mmulsub_ew_x, T, S, C) \
  SCALAR(mcmpge_ew_x, T, S, C) \
  SCALAR(mcmplt_ew_x, T, S, C) \
  BCAST(mbcast_m_x, T, S, C)
#define WIDTH(W, S) \
  SUITE(i##W##_rnu, S, i64_rnu) \
  SUITE(u##W##_rne, S, u64_rne) \
  SUITE(i##W##_rdn, S, i128_rdn) \
  SUITE(u##W##_rod, S, u128_rod) \
  SUITE(u##W##_rnu, S, i128_rne) \
  SUITE(i##W##_rne, S, u128_rdn) \
  SUITE(u##W##_rdn, S, i64_rod) \
  SUITE(i##W##_rod, S, u64_rnu)

#if TEST_UDS == 8
WIDTH(32, 1x1)
#elif TEST_UDS == 16
WIDTH(64, 1x1)
#elif TEST_UDS == 32
WIDTH(64, 1x1)
WIDTH(128, 1x1)
SUITE(i64_rne, 1x2, i16_rod)
SUITE(u64_rdn, 2x1, u32_rne)
#elif TEST_UDS == 64
WIDTH(64, 1x1)
WIDTH(128, 1x1)
SUITE(i64_rne, 1x4, i16_rod)
SUITE(u128_rdn, 2x1, u32_rne)
#elif TEST_UDS == 128
WIDTH(64, 1x2)
WIDTH(128, 1x1)
SUITE(i64_rne, 1x8, i16_rod)
SUITE(u128_rdn, 4x1, u32_rne)
#endif
#ifdef __cplusplus
}
#endif
