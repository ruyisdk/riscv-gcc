#include <riscv_ztt.h>
void rounding (const float *in, float *out)
{
  __riscv_ztt_f32_rne_1x1_t a = __riscv_ztt_mls_rm_f32_rne_1x1 (in);
  __riscv_ztt_f32_rup_1x1_t b = __riscv_ztt_mabs_ew_f32_rup_1x1 (a);
  __riscv_ztt_mss_rm (out, __riscv_ztt_mabs_ew_f32_rne_1x1 (b));
}
void format (const float *in, float *out)
{
  __riscv_ztt_f32_rne_1x1_t a = __riscv_ztt_mls_rm_f32_rne_1x1 (in);
  __riscv_ztt_f16_rne_1x1_t b = __riscv_ztt_mabs_ew_f16_rne_1x1 (a);
  __riscv_ztt_mss_rm (out, __riscv_ztt_mabs_ew_f32_rne_1x1 (b));
}
