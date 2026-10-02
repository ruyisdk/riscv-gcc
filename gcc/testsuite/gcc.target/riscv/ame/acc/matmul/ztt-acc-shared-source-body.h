/* Keep the input live after matmul; the second operand is either the same
   value or an independently loaded group.  */
#include <riscv_ztt.h>
#ifdef __cplusplus
extern "C" {
#endif
#define CHECK(T, C, NAME, OP, RIGHT) \
__attribute__((noinline,noclone)) \
void NAME (const C *in, const C *rhs, const C *old, C *out, C *live) \
{ \
  __riscv_ztt_##T##_1x1_t x = __riscv_ztt_mls_rm_##T##_1x1 (in); \
  __riscv_ztt_##T##_1x1_t y = __riscv_ztt_mls_rm_##T##_1x1 (rhs); \
  __riscv_ztt_##T##_1x1_t c = __riscv_ztt_mls_rm_##T##_1x1 (old); \
  __riscv_ztt_##T##_accx1_t a = __riscv_ztt_mcopy_m2a_##T##_accx1 (c); \
  a = __riscv_ztt_##OP##_2d_##T##_accx1 (a, x, RIGHT); \
  __riscv_ztt_mss_rm (out, __riscv_ztt_mcopy_a2m_##T##_1x1 (a)); \
  __riscv_ztt_mss_rm (live, x); \
}
#define VARIANT(OP, N) \
  CHECK (i32_rnu, __INT32_TYPE__, same_i##N, OP, x) \
  CHECK (i32_rnu, __INT32_TYPE__, distinct_i##N, OP, y) \
  CHECK (f32_rne, float, same_f##N, OP, x) \
  CHECK (f32_rne, float, distinct_f##N, OP, y)
VARIANT (mmulacc, 0)
VARIANT (mmulaccneg, 1)
VARIANT (mmulatacc, 2)
VARIANT (mmulataccneg, 3)
VARIANT (mmulbtacc, 4)
VARIANT (mmulbtaccneg, 5)
#undef VARIANT
#undef CHECK
#ifdef __cplusplus
}
#endif
