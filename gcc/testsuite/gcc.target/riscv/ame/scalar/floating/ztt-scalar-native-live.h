#include <stdint.h>
#include <riscv_ztt.h>

float
native_live_f32 (uint32_t *out, const uint32_t *b, volatile float *in)
{
  float x = *in;
  __riscv_ztt_mss_rm (out, __riscv_ztt_madd_ew_x_u32_rnu_1x1_f32_rne
    (__riscv_ztt_mls_rm_u32_rnu_1x1 (b), __riscv_ztt_scalar_make_f32_rne (x)));
  return x;
}
