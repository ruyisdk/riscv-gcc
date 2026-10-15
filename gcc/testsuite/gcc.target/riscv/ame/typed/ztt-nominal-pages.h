#include "../types/ztt-nominal-repeat.h"

#ifdef __cplusplus
extern "C" {
#endif

__attribute__((noipa)) void
page_fp (float *out, __UINTPTR_TYPE__ bits)
{
  __riscv_ztt_bf16_rtz_scalar_t s = __riscv_ztt_scalar_from_bits_bf16_rtz (bits);
  __riscv_ztt_f32_1x1_t a = __riscv_ztt_mbcast_m_x_f32_1x1 (s);
  __riscv_ztt_mss_rm (out, a);
  a = __riscv_ztt_mbcast_m_x_f32_rne_1x1_bf16_rtz (s);
  __riscv_ztt_mss_rm (out, a);
}

__attribute__((noipa)) void
page_wide (__riscv_ztt_u128_storage_t *out, __UINTPTR_TYPE__ bits)
{
  __riscv_ztt_u128_rod_sat_scalar_t s
    = __riscv_ztt_scalar_from_bits_u128_rod_sat (bits);
  __riscv_ztt_u128_rod_1x1_t a = __riscv_ztt_mbcast_m_x_u128_rod_1x1 (s);
  __riscv_ztt_mss_rm (out, a);
  a = __riscv_ztt_mbcast_m_x_u128_rod_1x1_u128_rod_sat (s);
  __riscv_ztt_mss_rm (out, a);
}

#ifdef __cplusplus
}
#endif
