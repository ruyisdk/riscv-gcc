#include <riscv_ztt.h>
#ifdef __cplusplus
extern "C" {
#endif
extern void md_callee (void);
extern volatile int md_condition;
#define KERNEL(NAME, BARRIER) \
__attribute__((noinline,noclone)) \
void NAME (const __INT32_TYPE__ *left, const __INT32_TYPE__ *right, \
           const __INT32_TYPE__ *old, __INT32_TYPE__ *out) \
{ \
  __riscv_ztt_i32_1x1_t a = __riscv_ztt_mls_rm_i32_1x1 (left); \
  __riscv_ztt_i32_1x1_t b = __riscv_ztt_mls_rm_i32_1x1 (right); \
  __riscv_ztt_i32_1x1_t c = __riscv_ztt_mls_rm_i32_1x1 (old); \
  __riscv_ztt_i32_accx1_t d = __riscv_ztt_mcopy_m2a_i32_accx1 (c); \
  BARRIER; \
  d = __riscv_ztt_mmulacc_2d_i32_accx1 (d, a, b); \
  __riscv_ztt_mss_rm (out, __riscv_ztt_mcopy_a2m_i32_1x1 (d)); \
}
KERNEL (md_straight, (void) 0)
KERNEL (md_asm, __asm__ volatile ("" ::: "memory"))
KERNEL (md_call, md_callee ())
KERNEL (md_join, if (md_condition) __asm__ volatile ("" ::: "memory"))
#undef KERNEL
#ifdef __cplusplus
}
#endif
