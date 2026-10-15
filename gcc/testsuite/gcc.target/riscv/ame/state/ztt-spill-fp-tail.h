#include <riscv_ztt.h>
typedef __UINT32_TYPE__ element_t;
typedef __riscv_ztt_u32_rnu_1x1_t matrix_t;
#ifdef __cplusplus
extern "C" {
#endif
extern void fp_tail_call (void);
#define CASE(NAME, EXPR, GAP) \
float __attribute__((noipa)) \
NAME (const element_t *in, element_t *out, element_t *saved, \
      const float *x, float y) \
{ \
  matrix_t d = __riscv_ztt_mls_rm_u32_rnu_1x1 (in); \
  matrix_t result = __riscv_ztt_mrowscatadd_ew_u32_rnu_1x1 (d, d, d); \
  __riscv_ztt_mss_rm (out, result); \
  GAP; \
  float a = *x; \
  __riscv_ztt_mss_rm (saved, d); \
  return EXPR; \
}
CASE (fp_tail_min, __builtin_fminf(a, y), (void) 0)
CASE (fp_tail_max, __builtin_fmaxf(a, y), (void) 0)
CASE (fp_tail_sign, __builtin_copysignf(a, y), (void) 0)
CASE (fp_tail_class, (float) __builtin_isnormal(a), (void) 0)
CASE (fp_tail_add, a + y, (void) 0)
CASE (fp_tail_asm, __builtin_fminf(a, y), __asm__ volatile ("# tail boundary" ::: "memory"))
CASE (fp_tail_external, __builtin_fminf(a, y), fp_tail_call())
#undef CASE
#ifdef __cplusplus
}
#endif
