#include <riscv_ztt.h>
void rounding (float *out)
{
  __riscv_ztt_f32_rne_1x1_t a = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_mss_rm (out, __riscv_ztt_mreducemin_row_f32_rup_1x1 (a));
}
void format (__INT16_TYPE__ *out, unsigned int x)
{
  __riscv_ztt_i32_rnu_1x1_t a = __riscv_ztt_mbcast_m_x_i32_rnu_1x1
    (__riscv_ztt_scalar_from_bits_i32_rnu (x));
  __riscv_ztt_mss_rm (out, __riscv_ztt_mreducemin_row_i16_rnu_1x1 (a));
}
