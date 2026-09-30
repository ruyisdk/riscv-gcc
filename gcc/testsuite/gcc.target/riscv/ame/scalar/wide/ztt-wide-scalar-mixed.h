/* Compile/assemble checks, not numerical execution evidence.  */
#include <stdint.h>
#include <riscv_ztt.h>
#include "../../fixtures/ztt-scalar-construct.h"
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
#define SCALAR(F, D, B, S, C) \
  void F##_##D##_##B##_##S##_##C (uintptr_t c) \
  { \
    TYPE(B, S) b = ZERO(B, S); \
    TYPE(D, S) d = OP(F, D, S, C) (b, ZTT_TEST_BITS(C, c)); \
    KEEP(d); KEEP(b); \
  }
#define TERNARY_X(F, D, B, S, C) \
  void F##_##D##_##B##_##S##_##C (uintptr_t c) \
  { \
    TYPE(B, S) b = ZERO(B, S); \
    TYPE(D, S) old = ZERO(D, S); \
    TYPE(D, S) d = OP(F, D, S, C) (old, b, ZTT_TEST_BITS(C, c)); \
    KEEP(d); KEEP(old); KEEP(b); \
  }
#define MIXED(D, B, S, C) \
  SCALAR(madd_ew_x, D, B, S, C) \
  SCALAR(msub_ew_x, D, B, S, C) \
  SCALAR(mmul_ew_x, D, B, S, C) \
  SCALAR(mabsdiff_ew_x, D, B, S, C) \
  SCALAR(mhdiff_ew_x, D, B, S, C) \
  SCALAR(mmean_ew_x, D, B, S, C) \
  SCALAR(mmulneg_ew_x, D, B, S, C) \
  TERNARY_X(mmulacc_ew_x, D, B, S, C) \
  TERNARY_X(mmulaccneg_ew_x, D, B, S, C) \
  TERNARY_X(mmuladd_ew_x, D, B, S, C) \
  TERNARY_X(mmulsub_ew_x, D, B, S, C) \
  SCALAR(mcmpge_ew_x, D, B, S, C) \
  SCALAR(mcmplt_ew_x, D, B, S, C)

#if TEST_UDS == 8
MIXED(i32_rne, u16_rod, 1x1, i128_rdn)
MIXED(u16_rdn, i32_rnu, 1x1, u64_rne)
#elif TEST_UDS == 16
MIXED(i64_rne, u32_rod, 1x1, i128_rdn)
MIXED(u32_rdn, i64_rnu, 1x1, u64_rne)
#elif TEST_UDS == 32
MIXED(i128_rne, u64_rod, 1x1, i128_rdn)
MIXED(u32_rdn, i128_rnu, 1x1, u16_rne)
MIXED(i32_rnu, u128_rod, 1x1, i32_rnu)
#elif TEST_UDS == 64
MIXED(i128_rne, u32_rod, 1x2, i128_rdn)
MIXED(u32_rdn, i128_rnu, 2x1, u64_rne)
#elif TEST_UDS == 128
MIXED(i128_rne, u64_rod, 1x2, i128_rdn)
MIXED(u64_rdn, i128_rnu, 2x1, u64_rne)
#endif
#ifdef __cplusplus
}
#endif
