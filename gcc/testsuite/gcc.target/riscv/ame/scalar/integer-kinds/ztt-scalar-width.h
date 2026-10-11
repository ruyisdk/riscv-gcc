#include <stdint.h>
#include <riscv_ztt.h>

#define TEST(TC, CTYPE) \
void add_##TC (uint32_t *out, const uint32_t *in, uintptr_t bits) \
{ \
  __riscv_ztt_mss_rm (out, __riscv_ztt_madd_ew_x_u32_rnu_1x1_##TC \
    (__riscv_ztt_mls_rm_u32_rnu_1x1 (in), \
     __riscv_ztt_scalar_from_bits_##TC ((CTYPE) (bits + 1u)))); \
}

TEST (i8_rnu, int8_t)
TEST (u8_rnu, uint8_t)
TEST (i16_rne, int16_t)
TEST (u16_rnu, uint16_t)
TEST (u32_rnu, uint32_t)
TEST (f16_rne, uint16_t)
TEST (bf16_rne, uint16_t)

void
fused_u16 (uint32_t *out, const uint32_t *in,
           const uint32_t *old, uintptr_t bits)
{
  __riscv_ztt_mss_rm (out, __riscv_ztt_mmulacc_ew_x_u32_rnu_1x1_u16_rnu
    (__riscv_ztt_mls_rm_u32_rnu_1x1 (old),
     __riscv_ztt_mls_rm_u32_rnu_1x1 (in),
     __riscv_ztt_scalar_from_bits_u16_rnu ((uint16_t) (bits + 1u))));
}

uintptr_t
live_u8 (uint32_t *out, const uint32_t *in, uintptr_t bits)
{
  uintptr_t value = bits + 1u;
  __riscv_ztt_mss_rm (out, __riscv_ztt_madd_ew_x_u32_rnu_1x1_u8_rnu
    (__riscv_ztt_mls_rm_u32_rnu_1x1 (in),
     __riscv_ztt_scalar_from_bits_u8_rnu (value)));
  return value;
}

void
volatile_u16 (uint32_t *out, const uint32_t *in, volatile uintptr_t *bits)
{
  uintptr_t value = *bits;
  *bits = value + 1u;
  __riscv_ztt_mss_rm (out, __riscv_ztt_madd_ew_x_u32_rnu_1x1_u16_rnu
    (__riscv_ztt_mls_rm_u32_rnu_1x1 (in),
     __riscv_ztt_scalar_from_bits_u16_rnu (value + 1u)));
}

void
unused_saturating (const uint32_t *in, uintptr_t bits)
{
  __riscv_ztt_madd_ew_x_u32_rnu_sat_1x1_i8_rnu
    (__riscv_ztt_mls_rm_u32_rnu_sat_1x1 (in),
     __riscv_ztt_scalar_from_bits_i8_rnu ((int8_t) (bits + 1u)));
}
