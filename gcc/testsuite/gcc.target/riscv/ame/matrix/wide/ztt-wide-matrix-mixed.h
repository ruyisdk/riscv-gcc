/* Compile/assemble checks, not numerical execution evidence.  */
#include <stddef.h>
#include <riscv_ztt.h>
#ifdef __cplusplus
extern "C" {
#endif
#define T_(D, S) __riscv_ztt_##D##_##S##_t
#define T(D, S) T_(D, S)
#define F_(OP, D, S) __riscv_ztt_##OP##_##D##_##S
#define F(OP, D, S) F_(OP, D, S)
#define LIVE(V) __asm__ volatile ("" : : "Wmr" (V))
#define CASE(OP, NAME, D, A, B, S, ARGS) \
void OP##_##NAME (size_t control) \
{ \
  T(D, S) old = F(mclear_m, D, S) (); \
  T(A, S) a = F(mclear_m, A, S) (); \
  T(B, S) b = F(mclear_m, B, S) (); \
  T(D, S) result = F(OP, D, S) ARGS; \
  LIVE(result); LIVE(old); LIVE(a); LIVE(b); \
}
#if TEST_UDS == 16
#define WIDE i64_rne
#define MID u32_rod
#define NARROW i16_rdn
#define SHAPE 1x1
#elif TEST_UDS == 32
#define WIDE i128_rne
#define MID u64_rod
#define NARROW i32_rdn
#define SHAPE 1x1
#elif TEST_UDS == 64
#define WIDE i128_rne
#define MID u64_rod
#define NARROW i32_rdn
#define SHAPE 2x1
#else
#define WIDE i128_rne
#define MID u64_rod
#define NARROW i32_rdn
#define SHAPE 1x4
#endif
#define MATRIX(OP, ARGS) \
  CASE(OP, wide, WIDE, NARROW, MID, SHAPE, ARGS) \
  CASE(OP, narrow, NARROW, WIDE, MID, SHAPE, ARGS)
#define SELECT(OP, ARGS) \
  CASE(OP, wide, WIDE, NARROW, WIDE, SHAPE, ARGS) \
  CASE(OP, narrow, NARROW, WIDE, NARROW, SHAPE, ARGS)
MATRIX(madd_ew, (a, b))
MATRIX(msub_ew, (a, b))
MATRIX(mmul_ew, (a, b))
MATRIX(mmulneg_ew, (a, b))
MATRIX(mabsdiff_ew, (a, b))
MATRIX(mhdiff_ew, (a, b))
MATRIX(mmean_ew, (a, b))
MATRIX(mcmpge_ew, (a, b))
MATRIX(mcmplt_ew, (a, b))
SELECT(mselge_ew, (a, b))
SELECT(msellt_ew, (a, b))
MATRIX(msll_ew, (a, b))
MATRIX(msll_ew_x, (a, control))
MATRIX(msrl_ew, (a, b))
MATRIX(msrl_ew_x, (a, control))
MATRIX(msra_ew, (a, b))
MATRIX(msra_ew_x, (a, control))
MATRIX(mconv_ew, (a))
MATRIX(mabs_ew, (a))
MATRIX(mreduceadd_col, (a))
MATRIX(mreduceadd_row, (a))
MATRIX(mreducemax_col, (a))
MATRIX(mreducemax_row, (a))
MATRIX(mreducemin_col, (a))
MATRIX(mreducemin_row, (a))
MATRIX(mprefixadd_col, (a))
MATRIX(mprefixadd_row, (a))
MATRIX(mprefixmax_col, (a))
MATRIX(mprefixmax_row, (a))
MATRIX(mmulacc_ew, (old, a, b))
MATRIX(mmulaccneg_ew, (old, a, b))
MATRIX(mmuladd_ew, (old, a, b))
MATRIX(mmulsub_ew, (old, a, b))
SELECT(mcmovge_ew, (old, a, b))
SELECT(mcmovlt_ew, (old, a, b))

#if TEST_UDS == 32
CASE(mcolgather_ew, mixed_index, u64_rod, u64_rod, i128_rne, 1x1, (a, b))
CASE(mrowgather_ew, mixed_index, i128_rdn, i128_rdn, u32_rnu, 1x1, (a, b))
CASE(mcolscatadd_ew, mixed, u64_rod, i128_rne, i32_rdn, 1x1, (old, a, b))
CASE(mrowscatadd_ew, mixed, i128_rdn, u32_rnu, i64_rne, 1x1, (old, a, b))
CASE(mcolscatmax_ew, mixed, u64_rod, i128_rne, i32_rdn, 1x1, (old, a, b))
CASE(mrowscatmax_ew, mixed, i128_rdn, u32_rnu, i64_rne, 1x1, (old, a, b))
#endif
#ifdef __cplusplus
}
#endif
