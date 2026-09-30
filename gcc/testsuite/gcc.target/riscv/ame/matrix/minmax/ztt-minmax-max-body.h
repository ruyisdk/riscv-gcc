/* integer maximum.  */
#include <stdint.h>
#include <riscv_ztt.h>
#if __riscv_ztt_mmax_ew_int_same != 1
#error "same-type maximum capability missing"
#endif
#ifdef __cplusplus
extern "C" {
#endif

#define MAX_CASE(T, S, C, RM, OP) \
void max_##T##_##RM##_##S (const C *a, const C *b, \
                          C *out, C *save_a, C *save_b) \
{ \
  __riscv_ztt_##T##_##RM##_##S##_t x = __riscv_ztt_mls_rm_##T##_##RM##_##S (a); \
  __riscv_ztt_##T##_##RM##_##S##_t y = __riscv_ztt_mls_rm_##T##_##RM##_##S (b); \
  __riscv_ztt_##T##_##RM##_##S##_t z = OP (x, y); \
  __riscv_ztt_mss_rm (out, z); \
  __riscv_ztt_mss_rm (save_a, x); \
  __riscv_ztt_mss_rm (save_b, y); \
}
#define MAX_TYPE(T, S, C) \
  MAX_CASE (T, S, C, rnu, __riscv_ztt_mmax_ew_##T##_##S) \
  MAX_CASE (T, S, C, rne, __riscv_ztt_mmax_ew_##T##_rne_##S) \
  MAX_CASE (T, S, C, rdn, __riscv_ztt_mmax_ew_##T##_rdn_##S) \
  MAX_CASE (T, S, C, rod, __riscv_ztt_mmax_ew_##T##_rod_##S)

#if (8 * 1 % __riscv_ztt_uds == 0 \
     && 8 * 1 / __riscv_ztt_uds <= 4 \
     && (__riscv_ztt_profile == 2 || 1 == 1))
MAX_TYPE (i8, 1x1, int8_t)
#endif

#if (8 * 2 % __riscv_ztt_uds == 0 \
     && 8 * 2 / __riscv_ztt_uds <= 4 \
     && (__riscv_ztt_profile == 2 || 2 == 1))
MAX_TYPE (i8, 1x2, int8_t)
#endif

#if (8 * 2 % __riscv_ztt_uds == 0 \
     && 8 * 2 / __riscv_ztt_uds <= 4 \
     && (__riscv_ztt_profile == 2 || 2 == 1))
MAX_TYPE (i8, 2x1, int8_t)
#endif

#if (8 * 4 % __riscv_ztt_uds == 0 \
     && 8 * 4 / __riscv_ztt_uds <= 4 \
     && (__riscv_ztt_profile == 2 || 4 == 1))
MAX_TYPE (i8, 1x4, int8_t)
#endif

#if (8 * 4 % __riscv_ztt_uds == 0 \
     && 8 * 4 / __riscv_ztt_uds <= 4 \
     && (__riscv_ztt_profile == 2 || 4 == 1))
MAX_TYPE (i8, 4x1, int8_t)
#endif

#if (8 * 8 % __riscv_ztt_uds == 0 \
     && 8 * 8 / __riscv_ztt_uds <= 4 \
     && (__riscv_ztt_profile == 2 || 8 == 1))
MAX_TYPE (i8, 1x8, int8_t)
#endif

#if (8 * 8 % __riscv_ztt_uds == 0 \
     && 8 * 8 / __riscv_ztt_uds <= 4 \
     && (__riscv_ztt_profile == 2 || 8 == 1))
MAX_TYPE (i8, 8x1, int8_t)
#endif

#if (8 * 16 % __riscv_ztt_uds == 0 \
     && 8 * 16 / __riscv_ztt_uds <= 4 \
     && (__riscv_ztt_profile == 2 || 16 == 1))
MAX_TYPE (i8, 1x16, int8_t)
#endif

#if (8 * 16 % __riscv_ztt_uds == 0 \
     && 8 * 16 / __riscv_ztt_uds <= 4 \
     && (__riscv_ztt_profile == 2 || 16 == 1))
MAX_TYPE (i8, 16x1, int8_t)
#endif

#if (8 * 1 % __riscv_ztt_uds == 0 \
     && 8 * 1 / __riscv_ztt_uds <= 4 \
     && (__riscv_ztt_profile == 2 || 1 == 1))
MAX_TYPE (u8, 1x1, uint8_t)
#endif

#if (8 * 2 % __riscv_ztt_uds == 0 \
     && 8 * 2 / __riscv_ztt_uds <= 4 \
     && (__riscv_ztt_profile == 2 || 2 == 1))
MAX_TYPE (u8, 1x2, uint8_t)
#endif

#if (8 * 2 % __riscv_ztt_uds == 0 \
     && 8 * 2 / __riscv_ztt_uds <= 4 \
     && (__riscv_ztt_profile == 2 || 2 == 1))
MAX_TYPE (u8, 2x1, uint8_t)
#endif

#if (8 * 4 % __riscv_ztt_uds == 0 \
     && 8 * 4 / __riscv_ztt_uds <= 4 \
     && (__riscv_ztt_profile == 2 || 4 == 1))
MAX_TYPE (u8, 1x4, uint8_t)
#endif

#if (8 * 4 % __riscv_ztt_uds == 0 \
     && 8 * 4 / __riscv_ztt_uds <= 4 \
     && (__riscv_ztt_profile == 2 || 4 == 1))
MAX_TYPE (u8, 4x1, uint8_t)
#endif

#if (8 * 8 % __riscv_ztt_uds == 0 \
     && 8 * 8 / __riscv_ztt_uds <= 4 \
     && (__riscv_ztt_profile == 2 || 8 == 1))
MAX_TYPE (u8, 1x8, uint8_t)
#endif

#if (8 * 8 % __riscv_ztt_uds == 0 \
     && 8 * 8 / __riscv_ztt_uds <= 4 \
     && (__riscv_ztt_profile == 2 || 8 == 1))
MAX_TYPE (u8, 8x1, uint8_t)
#endif

#if (8 * 16 % __riscv_ztt_uds == 0 \
     && 8 * 16 / __riscv_ztt_uds <= 4 \
     && (__riscv_ztt_profile == 2 || 16 == 1))
MAX_TYPE (u8, 1x16, uint8_t)
#endif

#if (8 * 16 % __riscv_ztt_uds == 0 \
     && 8 * 16 / __riscv_ztt_uds <= 4 \
     && (__riscv_ztt_profile == 2 || 16 == 1))
MAX_TYPE (u8, 16x1, uint8_t)
#endif

#if (16 * 1 % __riscv_ztt_uds == 0 \
     && 16 * 1 / __riscv_ztt_uds <= 4 \
     && (__riscv_ztt_profile == 2 || 1 == 1))
MAX_TYPE (i16, 1x1, int16_t)
#endif

#if (16 * 2 % __riscv_ztt_uds == 0 \
     && 16 * 2 / __riscv_ztt_uds <= 4 \
     && (__riscv_ztt_profile == 2 || 2 == 1))
MAX_TYPE (i16, 1x2, int16_t)
#endif

#if (16 * 2 % __riscv_ztt_uds == 0 \
     && 16 * 2 / __riscv_ztt_uds <= 4 \
     && (__riscv_ztt_profile == 2 || 2 == 1))
MAX_TYPE (i16, 2x1, int16_t)
#endif

#if (16 * 4 % __riscv_ztt_uds == 0 \
     && 16 * 4 / __riscv_ztt_uds <= 4 \
     && (__riscv_ztt_profile == 2 || 4 == 1))
MAX_TYPE (i16, 1x4, int16_t)
#endif

#if (16 * 4 % __riscv_ztt_uds == 0 \
     && 16 * 4 / __riscv_ztt_uds <= 4 \
     && (__riscv_ztt_profile == 2 || 4 == 1))
MAX_TYPE (i16, 4x1, int16_t)
#endif

#if (16 * 8 % __riscv_ztt_uds == 0 \
     && 16 * 8 / __riscv_ztt_uds <= 4 \
     && (__riscv_ztt_profile == 2 || 8 == 1))
MAX_TYPE (i16, 1x8, int16_t)
#endif

#if (16 * 8 % __riscv_ztt_uds == 0 \
     && 16 * 8 / __riscv_ztt_uds <= 4 \
     && (__riscv_ztt_profile == 2 || 8 == 1))
MAX_TYPE (i16, 8x1, int16_t)
#endif

#if (16 * 16 % __riscv_ztt_uds == 0 \
     && 16 * 16 / __riscv_ztt_uds <= 4 \
     && (__riscv_ztt_profile == 2 || 16 == 1))
MAX_TYPE (i16, 1x16, int16_t)
#endif

#if (16 * 16 % __riscv_ztt_uds == 0 \
     && 16 * 16 / __riscv_ztt_uds <= 4 \
     && (__riscv_ztt_profile == 2 || 16 == 1))
MAX_TYPE (i16, 16x1, int16_t)
#endif

#if (16 * 1 % __riscv_ztt_uds == 0 \
     && 16 * 1 / __riscv_ztt_uds <= 4 \
     && (__riscv_ztt_profile == 2 || 1 == 1))
MAX_TYPE (u16, 1x1, uint16_t)
#endif

#if (16 * 2 % __riscv_ztt_uds == 0 \
     && 16 * 2 / __riscv_ztt_uds <= 4 \
     && (__riscv_ztt_profile == 2 || 2 == 1))
MAX_TYPE (u16, 1x2, uint16_t)
#endif

#if (16 * 2 % __riscv_ztt_uds == 0 \
     && 16 * 2 / __riscv_ztt_uds <= 4 \
     && (__riscv_ztt_profile == 2 || 2 == 1))
MAX_TYPE (u16, 2x1, uint16_t)
#endif

#if (16 * 4 % __riscv_ztt_uds == 0 \
     && 16 * 4 / __riscv_ztt_uds <= 4 \
     && (__riscv_ztt_profile == 2 || 4 == 1))
MAX_TYPE (u16, 1x4, uint16_t)
#endif

#if (16 * 4 % __riscv_ztt_uds == 0 \
     && 16 * 4 / __riscv_ztt_uds <= 4 \
     && (__riscv_ztt_profile == 2 || 4 == 1))
MAX_TYPE (u16, 4x1, uint16_t)
#endif

#if (16 * 8 % __riscv_ztt_uds == 0 \
     && 16 * 8 / __riscv_ztt_uds <= 4 \
     && (__riscv_ztt_profile == 2 || 8 == 1))
MAX_TYPE (u16, 1x8, uint16_t)
#endif

#if (16 * 8 % __riscv_ztt_uds == 0 \
     && 16 * 8 / __riscv_ztt_uds <= 4 \
     && (__riscv_ztt_profile == 2 || 8 == 1))
MAX_TYPE (u16, 8x1, uint16_t)
#endif

#if (16 * 16 % __riscv_ztt_uds == 0 \
     && 16 * 16 / __riscv_ztt_uds <= 4 \
     && (__riscv_ztt_profile == 2 || 16 == 1))
MAX_TYPE (u16, 1x16, uint16_t)
#endif

#if (16 * 16 % __riscv_ztt_uds == 0 \
     && 16 * 16 / __riscv_ztt_uds <= 4 \
     && (__riscv_ztt_profile == 2 || 16 == 1))
MAX_TYPE (u16, 16x1, uint16_t)
#endif

#if (32 * 1 % __riscv_ztt_uds == 0 \
     && 32 * 1 / __riscv_ztt_uds <= 4 \
     && (__riscv_ztt_profile == 2 || 1 == 1))
MAX_TYPE (i32, 1x1, int32_t)
#endif

#if (32 * 2 % __riscv_ztt_uds == 0 \
     && 32 * 2 / __riscv_ztt_uds <= 4 \
     && (__riscv_ztt_profile == 2 || 2 == 1))
MAX_TYPE (i32, 1x2, int32_t)
#endif

#if (32 * 2 % __riscv_ztt_uds == 0 \
     && 32 * 2 / __riscv_ztt_uds <= 4 \
     && (__riscv_ztt_profile == 2 || 2 == 1))
MAX_TYPE (i32, 2x1, int32_t)
#endif

#if (32 * 4 % __riscv_ztt_uds == 0 \
     && 32 * 4 / __riscv_ztt_uds <= 4 \
     && (__riscv_ztt_profile == 2 || 4 == 1))
MAX_TYPE (i32, 1x4, int32_t)
#endif

#if (32 * 4 % __riscv_ztt_uds == 0 \
     && 32 * 4 / __riscv_ztt_uds <= 4 \
     && (__riscv_ztt_profile == 2 || 4 == 1))
MAX_TYPE (i32, 4x1, int32_t)
#endif

#if (32 * 8 % __riscv_ztt_uds == 0 \
     && 32 * 8 / __riscv_ztt_uds <= 4 \
     && (__riscv_ztt_profile == 2 || 8 == 1))
MAX_TYPE (i32, 1x8, int32_t)
#endif

#if (32 * 8 % __riscv_ztt_uds == 0 \
     && 32 * 8 / __riscv_ztt_uds <= 4 \
     && (__riscv_ztt_profile == 2 || 8 == 1))
MAX_TYPE (i32, 8x1, int32_t)
#endif

#if (32 * 16 % __riscv_ztt_uds == 0 \
     && 32 * 16 / __riscv_ztt_uds <= 4 \
     && (__riscv_ztt_profile == 2 || 16 == 1))
MAX_TYPE (i32, 1x16, int32_t)
#endif

#if (32 * 16 % __riscv_ztt_uds == 0 \
     && 32 * 16 / __riscv_ztt_uds <= 4 \
     && (__riscv_ztt_profile == 2 || 16 == 1))
MAX_TYPE (i32, 16x1, int32_t)
#endif

#if (32 * 1 % __riscv_ztt_uds == 0 \
     && 32 * 1 / __riscv_ztt_uds <= 4 \
     && (__riscv_ztt_profile == 2 || 1 == 1))
MAX_TYPE (u32, 1x1, uint32_t)
#endif

#if (32 * 2 % __riscv_ztt_uds == 0 \
     && 32 * 2 / __riscv_ztt_uds <= 4 \
     && (__riscv_ztt_profile == 2 || 2 == 1))
MAX_TYPE (u32, 1x2, uint32_t)
#endif

#if (32 * 2 % __riscv_ztt_uds == 0 \
     && 32 * 2 / __riscv_ztt_uds <= 4 \
     && (__riscv_ztt_profile == 2 || 2 == 1))
MAX_TYPE (u32, 2x1, uint32_t)
#endif

#if (32 * 4 % __riscv_ztt_uds == 0 \
     && 32 * 4 / __riscv_ztt_uds <= 4 \
     && (__riscv_ztt_profile == 2 || 4 == 1))
MAX_TYPE (u32, 1x4, uint32_t)
#endif

#if (32 * 4 % __riscv_ztt_uds == 0 \
     && 32 * 4 / __riscv_ztt_uds <= 4 \
     && (__riscv_ztt_profile == 2 || 4 == 1))
MAX_TYPE (u32, 4x1, uint32_t)
#endif

#if (32 * 8 % __riscv_ztt_uds == 0 \
     && 32 * 8 / __riscv_ztt_uds <= 4 \
     && (__riscv_ztt_profile == 2 || 8 == 1))
MAX_TYPE (u32, 1x8, uint32_t)
#endif

#if (32 * 8 % __riscv_ztt_uds == 0 \
     && 32 * 8 / __riscv_ztt_uds <= 4 \
     && (__riscv_ztt_profile == 2 || 8 == 1))
MAX_TYPE (u32, 8x1, uint32_t)
#endif

#if (32 * 16 % __riscv_ztt_uds == 0 \
     && 32 * 16 / __riscv_ztt_uds <= 4 \
     && (__riscv_ztt_profile == 2 || 16 == 1))
MAX_TYPE (u32, 1x16, uint32_t)
#endif

#if (32 * 16 % __riscv_ztt_uds == 0 \
     && 32 * 16 / __riscv_ztt_uds <= 4 \
     && (__riscv_ztt_profile == 2 || 16 == 1))
MAX_TYPE (u32, 16x1, uint32_t)
#endif

#undef MAX_TYPE
#undef MAX_CASE
#ifdef __cplusplus
}
#endif
