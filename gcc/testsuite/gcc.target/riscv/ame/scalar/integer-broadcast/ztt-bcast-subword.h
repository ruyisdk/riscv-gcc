#include <stdint.h>
#include <riscv_ztt.h>

#define TEST(NAME, SOURCE, CARRIER) \
  void NAME (uint32_t *out, uintptr_t bits) \
  { \
    __riscv_ztt_mss_rm (out, \
      __riscv_ztt_mbcast_m_x_u32_rnu_1x1_##SOURCE \
        (__riscv_ztt_scalar_from_bits_##SOURCE ((CARRIER) (bits + 1u)))); \
  }

TEST (bcast_i8, i8_rnu, int8_t)
TEST (bcast_u8, u8_rnu, uint8_t)
TEST (bcast_i16, i16_rnu, int16_t)
TEST (bcast_u16, u16_rnu, uint16_t)
TEST (bcast_f16, f16_rne, uint16_t)
TEST (bcast_bf16, bf16_rne, uint16_t)

uintptr_t
bcast_live_subword (uint32_t *out, uintptr_t bits)
{
  uintptr_t result = bits + 1u;
  __riscv_ztt_mss_rm (out, __riscv_ztt_mbcast_m_x_u32_rnu_1x1_u8_rnu
    (__riscv_ztt_scalar_from_bits_u8_rnu (result)));
  return result;
}

void
bcast_volatile_subword (uint32_t *out, volatile uintptr_t *bits)
{
  uintptr_t old = *bits;
  *bits = old + 1u;
  __riscv_ztt_mss_rm (out, __riscv_ztt_mbcast_m_x_u32_rnu_1x1_u16_rnu
    (__riscv_ztt_scalar_from_bits_u16_rnu (old + 1u)));
}
