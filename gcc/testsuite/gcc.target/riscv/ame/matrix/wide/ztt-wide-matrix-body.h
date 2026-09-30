/* Compile/assemble checks, not numerical execution evidence.  */
#include <stddef.h>
#include <riscv_ztt.h>
#if __riscv_ztt_wide_matrix_int != 1
#error Missing wide matrix integer capability
#endif
#ifdef __cplusplus
extern "C" {
#endif
#define TYPE_(T, S) __riscv_ztt_##T##_##S##_t
#define TYPE(T, S) TYPE_(T, S)
#define OP_(F, T, S) __riscv_ztt_##F##_##T##_##S
#define OP(F, T, S) OP_(F, T, S)
#define KEEP(X) __asm__ volatile ("" : : "Wmr" (X))
#define BINARY(F, T, S) \
void F##_##T##_##S (void) \
{ \
  TYPE(T, S) a = OP(mzero_m, T, S) (); \
  TYPE(T, S) b = OP(mclear_m, T, S) (); \
  TYPE(T, S) d = OP(F, T, S) (a, b); \
  KEEP(d); KEEP(a); KEEP(b); \
}
#define TERNARY(F, T, S) \
void F##_##T##_##S (void) \
{ \
  TYPE(T, S) a = OP(mzero_m, T, S) (); \
  TYPE(T, S) b = OP(mclear_m, T, S) (); \
  TYPE(T, S) old = OP(mzero_m, T, S) (); \
  TYPE(T, S) d = OP(F, T, S) (old, a, b); \
  KEEP(d); KEEP(old); KEEP(a); KEEP(b); \
}
#define UNARY(F, T, S) \
void F##_##T##_##S (void) \
{ \
  TYPE(T, S) a = OP(mzero_m, T, S) (); \
  TYPE(T, S) d = OP(F, T, S) (a); \
  KEEP(d); KEEP(a); \
}
#define CONTROL(F, T, S) \
void F##_##T##_##S (size_t n) \
{ \
  TYPE(T, S) a = OP(mzero_m, T, S) (); \
  TYPE(T, S) d = OP(F, T, S) (a, n); \
  KEEP(d); KEEP(a); \
}
#define OFFSET(F, T, S) \
void F##_##T##_##S (int n) \
{ \
  TYPE(T, S) a = OP(mzero_m, T, S) (); \
  TYPE(T, S) d = OP(F, T, S) (a, n); \
  KEEP(d); KEEP(a); \
}
#define ZIP(F, T, S) \
void F##_##T##_##S (void) \
{ \
  TYPE(T, S) a = OP(mzero_m, T, S) (); \
  TYPE(T, S) b = OP(mclear_m, T, S) (); \
  TYPE(T, 1x2) pair = OP(mconcat_m, T, 1x2) (a, b); \
  pair = OP(F, T, 1x2) (pair); \
  a = OP(mextract, T, S) (pair, 0); \
  b = OP(mextract, T, S) (pair, 1); \
  KEEP(a); KEEP(b); \
}
#define CONSTRUCT(F, T, S) \
void F##_##T##_##S (void) \
{ \
  TYPE(T, S) a = OP(F, T, S) (); \
  KEEP(a); \
}
#define RM(APPLY, F, T, S) \
  APPLY(F, T##_rnu, S) APPLY(F, T##_rne, S) \
  APPLY(F, T##_rdn, S) APPLY(F, T##_rod, S)
#define SIGNED(APPLY, F, S, W) RM(APPLY, F, i##W, S)
#define BOTH(APPLY, F, S, W) \
  RM(APPLY, F, i##W, S) RM(APPLY, F, u##W, S)

#define GENERAL(S, W) \
  BOTH(BINARY, madd_ew, S, W) \
  BOTH(BINARY, msub_ew, S, W) \
  BOTH(BINARY, mmul_ew, S, W) \
  BOTH(BINARY, mmulneg_ew, S, W) \
  BOTH(BINARY, mabsdiff_ew, S, W) \
  BOTH(BINARY, mhdiff_ew, S, W) \
  BOTH(BINARY, mmean_ew, S, W) \
  BOTH(BINARY, mcmpge_ew, S, W) \
  BOTH(BINARY, mcmplt_ew, S, W) \
  BOTH(BINARY, mselge_ew, S, W) \
  BOTH(BINARY, msellt_ew, S, W) \
  BOTH(BINARY, msll_ew, S, W) \
  BOTH(CONTROL, msll_ew_x, S, W) \
  BOTH(BINARY, msrl_ew, S, W) \
  BOTH(CONTROL, msrl_ew_x, S, W) \
  SIGNED(BINARY, msra_ew, S, W) \
  SIGNED(CONTROL, msra_ew_x, S, W) \
  BOTH(UNARY, mconv_ew, S, W) \
  BOTH(UNARY, mabs_ew, S, W) \
  BOTH(UNARY, mreduceadd_col, S, W) \
  BOTH(UNARY, mreduceadd_row, S, W) \
  BOTH(UNARY, mreducemax_col, S, W) \
  BOTH(UNARY, mreducemax_row, S, W) \
  BOTH(UNARY, mreducemin_col, S, W) \
  BOTH(UNARY, mreducemin_row, S, W) \
  BOTH(UNARY, mprefixadd_col, S, W) \
  BOTH(UNARY, mprefixadd_row, S, W) \
  BOTH(UNARY, mprefixmax_col, S, W) \
  BOTH(UNARY, mprefixmax_row, S, W) \
  BOTH(TERNARY, mmulacc_ew, S, W) \
  BOTH(TERNARY, mmulaccneg_ew, S, W) \
  BOTH(TERNARY, mmuladd_ew, S, W) \
  BOTH(TERNARY, mmulsub_ew, S, W) \
  BOTH(TERNARY, mcmovge_ew, S, W) \
  BOTH(TERNARY, mcmovlt_ew, S, W) \
  BOTH(BINARY, mmin_ew, S, W) \
  BOTH(BINARY, mmax_ew, S, W) \
  BOTH(BINARY, mand_ew, S, W) \
  BOTH(BINARY, mandnot_ew, S, W) \
  BOTH(BINARY, mor_ew, S, W) \
  BOTH(BINARY, mornot_ew, S, W) \
  BOTH(BINARY, mxor_ew, S, W)

#define BASIC(S, W) \
  BOTH(BINARY, mcolgather_ew, S, W) \
  BOTH(BINARY, mrowgather_ew, S, W) \
  BOTH(TERNARY, mcolscatadd_ew, S, W) \
  BOTH(TERNARY, mrowscatadd_ew, S, W) \
  BOTH(TERNARY, mcolscatmax_ew, S, W) \
  BOTH(TERNARY, mrowscatmax_ew, S, W) \
  BOTH(CONTROL, mcolbcast_ew_x, S, W) \
  BOTH(CONTROL, mrowbcast_ew_x, S, W) \
  BOTH(OFFSET, mcolshift_ew_x, S, W) \
  BOTH(OFFSET, mrowshift_ew_x, S, W) \
  BOTH(ZIP, mcolzip_ew, S, W) \
  BOTH(ZIP, mrowzip_ew, S, W) \
  BOTH(ZIP, mcolunzip_ew, S, W) \
  BOTH(ZIP, mrowunzip_ew, S, W) \
  BOTH(CONSTRUCT, mrowid_ew, S, W) \
  BOTH(CONSTRUCT, mcolid_ew, S, W)

#if TEST_UDS == 16
GENERAL(1x1, 64)
BASIC(1x1, 64)
#elif TEST_UDS == 32
GENERAL(1x2, 64)
GENERAL(1x1, 128)
BASIC(1x1, 64)
BASIC(1x1, 128)
#elif TEST_UDS == 64
GENERAL(4x1, 64)
GENERAL(2x1, 128)
BASIC(1x1, 64)
BASIC(1x1, 128)
#else
GENERAL(1x8, 64)
GENERAL(1x4, 128)
BASIC(1x1, 128)
#endif
#ifdef __cplusplus
}
#endif
