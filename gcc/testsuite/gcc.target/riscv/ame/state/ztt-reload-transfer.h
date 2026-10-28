#include <riscv_ztt.h>

typedef __INT32_TYPE__ i32;
typedef __INT8_TYPE__ i8;
typedef __SIZE_TYPE__ usize;
#define OP(F,S) __riscv_ztt_##F##_i32_rnu_##S
#define T(S) __riscv_ztt_i32_rnu_##S##_t
#define LOAD(I) T(1x1) a##I = OP(mls_rm,1x1) (a + I * tile)
#define ADD(I,Q) a##I = OP(madd_ew,1x1) (a##I, Q)

#ifdef __cplusplus
extern "C" {
#endif
void reload_transfer (i8 *out, const i32 *a, const i32 *b, usize tile)
{
  LOAD(0); LOAD(1); LOAD(2); LOAD(3);
  T(1x4) q = OP(mls_rm,1x4) (b);
  T(1x2) lo = OP(mextract,1x2) (q, 0);
  T(1x2) hi = OP(mextract,1x2) (q, 1);
  ADD(0, OP(mextract,1x1) (lo, 0));
  ADD(1, OP(mextract,1x1) (lo, 1));
  ADD(2, OP(mextract,1x1) (hi, 0));
  ADD(3, OP(mextract,1x1) (hi, 1));
  T(1x4) value = OP(mconcat_m,1x4)
    (OP(mconcat_m,1x2) (a0, a1), OP(mconcat_m,1x2) (a2, a3));
  __riscv_ztt_mss_rm (out, __riscv_ztt_mconv_ew_i8_rnu_sat_1x4 (value));
}
#ifdef __cplusplus
}
#endif
