#include <riscv_ztt.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define HOLD(V) __asm__ volatile ("" : : "Wmr" (V))
#define BCAST(NAME, DEST, SHAPE, SRC, FACTORY, VALUE) \
void NAME (void) \
{ \
  __riscv_ztt_##DEST##_##SHAPE##_t v = \
    __riscv_ztt_mbcast_m_x_##DEST##_##SHAPE##_##SRC \
      (__riscv_ztt_scalar_##FACTORY##_##SRC (VALUE)); \
  HOLD (v); \
}

BCAST(zero_i32, i32_rnu, 1x1, i8_rnu, make, 0)
BCAST(zero_sat, u32_rne_sat, 1x1, i16_rod, make, 0)
BCAST(zero_wide, i128_rnu, 1x1, i128_rnu, from_bits, 0UL)
BCAST(zero_packed, u8_rnu, 1x4, u32_rnu, make, 0)
BCAST(zero_concat, i32_rne, 1x2, i8_rdn, make, 0)
BCAST(zero_narrow, i4_rne_sat, 1x8, u128_rod, from_bits, 0UL)
BCAST(zero_wide_source, u32_rdn, 1x1, u128_rne, from_bits, 0UL)
BCAST(nonzero, i32_rnu, 1x1, i8_rnu, make, 1)
BCAST(high_bits, i128_rnu, 1x1, i128_rnu, from_bits, 0x100UL)
BCAST(float_source, i32_rnu, 1x1, f32_rne, make, 0.0f)
BCAST(float_destination, f32_rne, 1x1, i8_rnu, make, 0)

void dynamic_value (unsigned long x)
{
  __riscv_ztt_u32_rnu_1x1_t v = __riscv_ztt_mbcast_m_x_u32_rnu_1x1_u128_rnu
    (__riscv_ztt_scalar_from_bits_u128_rnu (x));
  HOLD (v);
}

void volatile_zero (volatile unsigned *counter)
{
  __riscv_ztt_i32_rnu_1x1_t v = __riscv_ztt_mbcast_m_x_i32_rnu_1x1_i8_rnu
    (__riscv_ztt_scalar_make_i8_rnu (((void) (*counter = *counter + 1), 0)));
  HOLD (v);
}

void raw_zero (void)
{
  __builtin_riscv_ztt_msettyp (0, 0x40000020UL);
  __builtin_riscv_ztt_mbcast_m_x (0, 0, 0x40000008UL);
}

#ifdef __cplusplus
}
#endif
