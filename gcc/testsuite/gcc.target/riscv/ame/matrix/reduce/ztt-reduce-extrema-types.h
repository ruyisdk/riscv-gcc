#include <riscv_ztt.h>
void rounding (const float *in, float *out)
{
  __riscv_ztt_f32_rne_1x1_t a = __riscv_ztt_mls_rm_f32_rne_1x1 (in);
  a = __riscv_ztt_mreducemax_row_f32_rne_1x1 (a);
  __riscv_ztt_mss_rm (out, __riscv_ztt_mreducemin_row_f32_rup_1x1 (a));
}
void format (const float *in, float *out)
{
  __riscv_ztt_f32_rne_1x1_t a = __riscv_ztt_mls_rm_f32_rne_1x1 (in);
  __riscv_ztt_f16_rne_1x1_t b = __riscv_ztt_mreducemax_row_f16_rne_1x1 (a);
  __riscv_ztt_mss_rm (out, __riscv_ztt_mreducemin_row_f32_rne_1x1 (b));
}
void integer (const __INT32_TYPE__ *in, __INT32_TYPE__ *out)
{
  __riscv_ztt_i32_rnu_1x1_t a = __riscv_ztt_mls_rm_i32_rnu_1x1 (in);
  __riscv_ztt_i16_rnu_1x1_t b = __riscv_ztt_mreducemax_row_i16_rnu_1x1 (a);
  __riscv_ztt_mss_rm (out, __riscv_ztt_mreducemin_row_i32_rnu_1x1 (b));
}
