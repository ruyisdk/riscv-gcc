#include <riscv_ztt.h>
#ifdef __cplusplus
extern "C" {
#endif
extern void accprep_callee (void);
extern volatile int accprep_condition;
#define KERNEL(NAME, BARRIER) \
__attribute__((noinline,noclone)) \
void NAME (const __INT32_TYPE__ *in, __INT32_TYPE__ *out, \
           __INT32_TYPE__ *live) \
{ \
  __riscv_ztt_i32_1x1_t a = __riscv_ztt_mls_rm_i32_1x1 (in); \
  __riscv_ztt_i32_accx1_t d; \
  BARRIER; \
  d = __riscv_ztt_mcopy_m2a_i32_accx1 (a); \
  __riscv_ztt_mss_rm (out, __riscv_ztt_mcopy_a2m_i32_1x1 (d)); \
  __riscv_ztt_mss_rm (live, a); \
}
KERNEL (accprep_straight, (void) 0)
KERNEL (accprep_asm, __asm__ volatile ("" ::: "memory"))
KERNEL (accprep_call, accprep_callee ())
KERNEL (accprep_join, if (accprep_condition) __asm__ volatile ("" ::: "memory"))
#undef KERNEL
#ifdef __cplusplus
}
#endif
