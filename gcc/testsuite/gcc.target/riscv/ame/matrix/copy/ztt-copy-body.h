/* M copy.  */
#include <stdint.h>
#include <riscv_ztt.h>

#if __riscv_ztt_mcopy_m2m != 1
#error "missing M copy capability"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define COPY_TEST(T, C) \
void copy_##T (C *dst, C *changed, const C *src, int select) \
{ \
  __riscv_ztt_##T##_t a = __riscv_ztt_mls_rm_##T (src); \
  __riscv_ztt_##T##_t b = __riscv_ztt_mcopy_m2m_##T (a); \
  if (select) \
    a = __riscv_ztt_mzero_m_##T (); \
  else \
    a = __riscv_ztt_mcopy_m2m_##T (__riscv_ztt_mcopy_m2m_##T (a)); \
  __riscv_ztt_mss_rm (dst, b); \
  __riscv_ztt_mss_rm (changed, a); \
}

#define COPY_RMS(D, C, S) \
  COPY_TEST (D##_rnu_##S, C) \
  COPY_TEST (D##_rne_##S, C) \
  COPY_TEST (D##_rdn_##S, C) \
  COPY_TEST (D##_rod_##S, C) \
  COPY_TEST (D##_##S, C)

#if (__riscv_ztt_i8_u8_shapes & (1U << 0))
COPY_RMS (i8, int8_t, 1x1)
COPY_RMS (u8, uint8_t, 1x1)
#endif
#if (__riscv_ztt_i8_u8_shapes & (1U << 1))
COPY_RMS (i8, int8_t, 1x2)
COPY_RMS (u8, uint8_t, 1x2)
#endif
#if (__riscv_ztt_i8_u8_shapes & (1U << 2))
COPY_RMS (i8, int8_t, 2x1)
COPY_RMS (u8, uint8_t, 2x1)
#endif
#if (__riscv_ztt_i8_u8_shapes & (1U << 3))
COPY_RMS (i8, int8_t, 1x4)
COPY_RMS (u8, uint8_t, 1x4)
#endif
#if (__riscv_ztt_i8_u8_shapes & (1U << 4))
COPY_RMS (i8, int8_t, 4x1)
COPY_RMS (u8, uint8_t, 4x1)
#endif
#if (__riscv_ztt_i8_u8_shapes & (1U << 5))
COPY_RMS (i8, int8_t, 1x8)
COPY_RMS (u8, uint8_t, 1x8)
#endif
#if (__riscv_ztt_i8_u8_shapes & (1U << 6))
COPY_RMS (i8, int8_t, 8x1)
COPY_RMS (u8, uint8_t, 8x1)
#endif
#if (__riscv_ztt_i8_u8_shapes & (1U << 7))
COPY_RMS (i8, int8_t, 1x16)
COPY_RMS (u8, uint8_t, 1x16)
#endif
#if (__riscv_ztt_i8_u8_shapes & (1U << 8))
COPY_RMS (i8, int8_t, 16x1)
COPY_RMS (u8, uint8_t, 16x1)
#endif
#if (__riscv_ztt_i16_u16_shapes & (1U << 0))
COPY_RMS (i16, int16_t, 1x1)
COPY_RMS (u16, uint16_t, 1x1)
#endif
#if (__riscv_ztt_i16_u16_shapes & (1U << 1))
COPY_RMS (i16, int16_t, 1x2)
COPY_RMS (u16, uint16_t, 1x2)
#endif
#if (__riscv_ztt_i16_u16_shapes & (1U << 2))
COPY_RMS (i16, int16_t, 2x1)
COPY_RMS (u16, uint16_t, 2x1)
#endif
#if (__riscv_ztt_i16_u16_shapes & (1U << 3))
COPY_RMS (i16, int16_t, 1x4)
COPY_RMS (u16, uint16_t, 1x4)
#endif
#if (__riscv_ztt_i16_u16_shapes & (1U << 4))
COPY_RMS (i16, int16_t, 4x1)
COPY_RMS (u16, uint16_t, 4x1)
#endif
#if (__riscv_ztt_i16_u16_shapes & (1U << 5))
COPY_RMS (i16, int16_t, 1x8)
COPY_RMS (u16, uint16_t, 1x8)
#endif
#if (__riscv_ztt_i16_u16_shapes & (1U << 6))
COPY_RMS (i16, int16_t, 8x1)
COPY_RMS (u16, uint16_t, 8x1)
#endif
#if (__riscv_ztt_i16_u16_shapes & (1U << 7))
COPY_RMS (i16, int16_t, 1x16)
COPY_RMS (u16, uint16_t, 1x16)
#endif
#if (__riscv_ztt_i16_u16_shapes & (1U << 8))
COPY_RMS (i16, int16_t, 16x1)
COPY_RMS (u16, uint16_t, 16x1)
#endif
#if (__riscv_ztt_i32_u32_shapes & (1U << 0))
COPY_RMS (i32, int32_t, 1x1)
COPY_RMS (u32, uint32_t, 1x1)
#endif
#if (__riscv_ztt_i32_u32_shapes & (1U << 1))
COPY_RMS (i32, int32_t, 1x2)
COPY_RMS (u32, uint32_t, 1x2)
#endif
#if (__riscv_ztt_i32_u32_shapes & (1U << 2))
COPY_RMS (i32, int32_t, 2x1)
COPY_RMS (u32, uint32_t, 2x1)
#endif
#if (__riscv_ztt_i32_u32_shapes & (1U << 3))
COPY_RMS (i32, int32_t, 1x4)
COPY_RMS (u32, uint32_t, 1x4)
#endif
#if (__riscv_ztt_i32_u32_shapes & (1U << 4))
COPY_RMS (i32, int32_t, 4x1)
COPY_RMS (u32, uint32_t, 4x1)
#endif
#if (__riscv_ztt_i32_u32_shapes & (1U << 5))
COPY_RMS (i32, int32_t, 1x8)
COPY_RMS (u32, uint32_t, 1x8)
#endif
#if (__riscv_ztt_i32_u32_shapes & (1U << 6))
COPY_RMS (i32, int32_t, 8x1)
COPY_RMS (u32, uint32_t, 8x1)
#endif
#if (__riscv_ztt_i32_u32_shapes & (1U << 7))
COPY_RMS (i32, int32_t, 1x16)
COPY_RMS (u32, uint32_t, 1x16)
#endif
#if (__riscv_ztt_i32_u32_shapes & (1U << 8))
COPY_RMS (i32, int32_t, 16x1)
COPY_RMS (u32, uint32_t, 16x1)
#endif

#ifdef __cplusplus
}
#endif
