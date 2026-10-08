#include <riscv_ztt.h>

#ifdef __cplusplus
extern "C" {
#endif

#define HOLD(V) __asm__ volatile ("" : : "Wmr" (V))
#define BCAST(NAME, DST, SHAPE, SRC, BITS) \
void NAME (void) \
{ \
  __riscv_ztt_##DST##_##SHAPE##_t v = \
    __riscv_ztt_mbcast_m_x_##DST##_##SHAPE##_##SRC \
      (__riscv_ztt_scalar_from_bits_##SRC (BITS)); \
  HOLD (v); \
}
#define FORMAT(T, P) \
BCAST(T##_rne, T##_rne, P, T##_rtz, 0UL) \
BCAST(T##_rtz, T##_rtz, P, T##_rdn, 0UL) \
BCAST(T##_rdn, T##_rdn, P, T##_rup, 0UL) \
BCAST(T##_rup, T##_rup, P, T##_rmm, 0UL) \
BCAST(T##_rmm, T##_rmm, P, T##_rno, 0UL) \
BCAST(T##_rno, T##_rno, P, T##_rne, 0UL)

FORMAT(f16, 1x2)
FORMAT(bf16, 1x2)
FORMAT(f32, 1x1)
FORMAT(f64, 1x1)
BCAST(row_group, f32_rne, 1x2, f32_rno, 0UL)
BCAST(col_group, f32_rdn, 2x1, f32_rmm, 0UL)
BCAST(negative_zero_f16, f16_rne, 1x2, f16_rne, 0x8000UL)
BCAST(negative_zero_f32, f32_rne, 1x1, f32_rne, 0x80000000UL)
BCAST(nonzero, f32_rne, 1x1, f32_rne, 0x3f800000UL)
BCAST(high_bits, f64_rne, 1x1, f64_rne, 0x10000UL)
BCAST(other_width, f32_rne, 1x1, f16_rne, 0UL)
BCAST(other_format, f16_rne, 1x2, bf16_rne, 0UL)
BCAST(integer_source, f32_rne, 1x1, i32_rne, 0UL)
BCAST(integer_destination, i32_rne, 1x1, f32_rne, 0UL)

void dynamic_value (unsigned long bits)
{
  __riscv_ztt_f32_rne_1x1_t v = __riscv_ztt_mbcast_m_x_f32_rne_1x1_f32_rne
    (__riscv_ztt_scalar_from_bits_f32_rne (bits));
  HOLD (v);
}

void volatile_zero (volatile unsigned *counter)
{
  __riscv_ztt_f32_rne_1x1_t v = __riscv_ztt_mbcast_m_x_f32_rne_1x1_f32_rne
    (__riscv_ztt_scalar_from_bits_f32_rne
      (((void) (*counter = *counter + 1), 0UL)));
  HOLD (v);
}

void raw_zero (void)
{
  __builtin_riscv_ztt_msettyp (0, 0x20300120UL);
  __builtin_riscv_ztt_mbcast_m_x (0, 0, 0x20300120UL);
}

#ifdef __cplusplus
}
#endif
