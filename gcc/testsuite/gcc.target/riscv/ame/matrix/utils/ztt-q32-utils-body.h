/* Q32.  */
#include <stdint.h>
#include <riscv_ztt.h>
#define Q32_UTIL(T, E, BIG, HALF) \
void utility_##T##_##BIG (E *out, E *first, E *last, const E *p, const E *q) \
{ \
  __riscv_ztt_##T##_##HALF##_t a = __riscv_ztt_mls_rm_##T##_##HALF (p); \
  __riscv_ztt_##T##_##HALF##_t b = __riscv_ztt_mls_rm_##T##_##HALF (q); \
  __riscv_ztt_##T##_##BIG##_t both = __riscv_ztt_mconcat_m_##T##_##BIG (a, b); \
  __riscv_ztt_##T##_##HALF##_t left = __riscv_ztt_mextract_##T##_##HALF (both, 0); \
  __riscv_ztt_##T##_##HALF##_t right = __riscv_ztt_mextract_##T##_##HALF (both, 1); \
  __riscv_ztt_mss_rm (out, both); \
  __riscv_ztt_mss_rm (first, left); \
  __riscv_ztt_mss_rm (last, right); \
}
Q32_UTIL (i8_rnu, int8_t, 1x32, 1x16)
Q32_UTIL (i8_rnu, int8_t, 32x1, 16x1)
Q32_UTIL (i8_rne, int8_t, 1x32, 1x16)
Q32_UTIL (i8_rne, int8_t, 32x1, 16x1)
Q32_UTIL (i8_rdn, int8_t, 1x32, 1x16)
Q32_UTIL (i8_rdn, int8_t, 32x1, 16x1)
Q32_UTIL (i8_rod, int8_t, 1x32, 1x16)
Q32_UTIL (i8_rod, int8_t, 32x1, 16x1)
Q32_UTIL (i8, int8_t, 1x32, 1x16)
Q32_UTIL (i8, int8_t, 32x1, 16x1)
Q32_UTIL (u8_rnu, uint8_t, 1x32, 1x16)
Q32_UTIL (u8_rnu, uint8_t, 32x1, 16x1)
Q32_UTIL (u8_rne, uint8_t, 1x32, 1x16)
Q32_UTIL (u8_rne, uint8_t, 32x1, 16x1)
Q32_UTIL (u8_rdn, uint8_t, 1x32, 1x16)
Q32_UTIL (u8_rdn, uint8_t, 32x1, 16x1)
Q32_UTIL (u8_rod, uint8_t, 1x32, 1x16)
Q32_UTIL (u8_rod, uint8_t, 32x1, 16x1)
Q32_UTIL (u8, uint8_t, 1x32, 1x16)
Q32_UTIL (u8, uint8_t, 32x1, 16x1)
#if __riscv_ztt_uds == 128
Q32_UTIL (i16_rnu, int16_t, 1x32, 1x16)
Q32_UTIL (i16_rnu, int16_t, 32x1, 16x1)
Q32_UTIL (i16_rne, int16_t, 1x32, 1x16)
Q32_UTIL (i16_rne, int16_t, 32x1, 16x1)
Q32_UTIL (i16_rdn, int16_t, 1x32, 1x16)
Q32_UTIL (i16_rdn, int16_t, 32x1, 16x1)
Q32_UTIL (i16_rod, int16_t, 1x32, 1x16)
Q32_UTIL (i16_rod, int16_t, 32x1, 16x1)
Q32_UTIL (i16, int16_t, 1x32, 1x16)
Q32_UTIL (i16, int16_t, 32x1, 16x1)
Q32_UTIL (u16_rnu, uint16_t, 1x32, 1x16)
Q32_UTIL (u16_rnu, uint16_t, 32x1, 16x1)
Q32_UTIL (u16_rne, uint16_t, 1x32, 1x16)
Q32_UTIL (u16_rne, uint16_t, 32x1, 16x1)
Q32_UTIL (u16_rdn, uint16_t, 1x32, 1x16)
Q32_UTIL (u16_rdn, uint16_t, 32x1, 16x1)
Q32_UTIL (u16_rod, uint16_t, 1x32, 1x16)
Q32_UTIL (u16_rod, uint16_t, 32x1, 16x1)
Q32_UTIL (u16, uint16_t, 1x32, 1x16)
Q32_UTIL (u16, uint16_t, 32x1, 16x1)
#endif
