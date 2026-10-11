#include <riscv_ztt.h>

#ifdef __cplusplus
extern "C" {
#endif
void pure_scale_store (const __INT32_TYPE__ *in, __INT32_TYPE__ *out)
{
  __riscv_ztt_i32_rnu_1x1_t x = __riscv_ztt_mls_rm_i32_rnu_1x1 (in);
  __asm__ volatile ("" : "+Wmr" (x));
  __riscv_ztt_mss_rm (out, x);
}
#ifdef __cplusplus
}
#endif
