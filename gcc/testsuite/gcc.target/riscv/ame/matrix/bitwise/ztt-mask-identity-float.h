#include <riscv_ztt.h>
void nan_min (const float *in, float *out)
{
  __riscv_ztt_f32_rne_1x1_t a=__riscv_ztt_mls_rm_f32_rne_1x1 (in);
  __riscv_ztt_f32_rne_1x1_t b=__riscv_ztt_mbcast_m_x_f32_rne_1x1
    (__riscv_ztt_scalar_from_bits_f32_rne ((__UINT32_TYPE__) -1));
  __riscv_ztt_mss_rm (out,__riscv_ztt_mmin_ew_f32_rne_1x1 (a,b));
}
