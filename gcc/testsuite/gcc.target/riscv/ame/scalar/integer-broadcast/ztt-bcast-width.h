#include <stdint.h>
#include <riscv_ztt.h>

void
bcast_u32 (uint32_t *out, uint32_t bits)
{
  __riscv_ztt_mss_rm (out, __riscv_ztt_mbcast_m_x_u32_rnu_1x1_u32_rnu
    (__riscv_ztt_scalar_from_bits_u32_rnu (bits)));
}

void
bcast_f32 (float *out, uint32_t bits)
{
  __riscv_ztt_mss_rm (out, __riscv_ztt_mbcast_m_x_f32_rne_1x1_f32_rne
    (__riscv_ztt_scalar_from_bits_f32_rne (bits)));
}

void
bcast_native_f32 (float *out, float value)
{
  __riscv_ztt_mss_rm (out, __riscv_ztt_mbcast_m_x_f32_rne_1x1_f32_rne
    (__riscv_ztt_scalar_make_f32_rne (value)));
}

uintptr_t
bcast_live (uint32_t *out, uintptr_t bits)
{
  __riscv_ztt_mss_rm (out, __riscv_ztt_mbcast_m_x_u32_rnu_1x1_i32_rnu
    (__riscv_ztt_scalar_from_bits_i32_rnu (bits)));
  return bits;
}

void
bcast_wide (uint32_t *out, uintptr_t bits)
{
  __riscv_ztt_mss_rm (out, __riscv_ztt_mbcast_m_x_u32_rnu_1x1_u128_rnu
    (__riscv_ztt_scalar_from_bits_u128_rnu (bits)));
}

void
bcast_volatile (uint32_t *out, volatile uintptr_t *bits)
{
  bcast_u32 (out, *bits);
}

void
bcast_unused (volatile uintptr_t *bits)
{
  uintptr_t old = *bits;
  *bits = old + 1;
  (void) __riscv_ztt_mbcast_m_x_u32_rnu_1x1_u32_rnu
    (__riscv_ztt_scalar_from_bits_u32_rnu (old));
}
