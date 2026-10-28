#include <riscv_ztt.h>
void floating (const float *in, float *out)
{
  __riscv_ztt_f32_rne_1x1_t a = __riscv_ztt_mls_rm_f32_rne_1x1 (in);
  a = __riscv_ztt_mabs_ew_f32_rne_1x1 (a);
  __riscv_ztt_mss_rm (out, __riscv_ztt_mabs_ew_f32_rne_1x1 (a));
}
void mixed (const __INT32_TYPE__ *in, __INT32_TYPE__ *out)
{
  __riscv_ztt_i32_rnu_1x1_t a = __riscv_ztt_mls_rm_i32_rnu_1x1 (in);
  __riscv_ztt_i16_rnu_1x1_t b = __riscv_ztt_mabs_ew_i16_rnu_1x1 (a);
  __riscv_ztt_mss_rm (out, __riscv_ztt_mabs_ew_i32_rnu_1x1 (b));
}
