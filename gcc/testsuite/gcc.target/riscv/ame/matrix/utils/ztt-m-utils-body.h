/* M utilities.  */
#include <stdint.h>
#include <riscv_ztt.h>
#if __riscv_ztt_mconcat_m != 1 || __riscv_ztt_mextract != 1
#error "whole-M utilities required"
#endif
#define UT_TYPE_(T, S) __riscv_ztt_##T##_##S##_t
#define UT_TYPE(T, S) UT_TYPE_ (T, S)
#define UT_OP_(OP, T, S) __riscv_ztt_##OP##_##T##_##S
#define UT_OP(OP, T, S) UT_OP_ (OP, T, S)
#define UT_FUNCTION(F, T, C, BIG, HALF) \
void F (const void **in, void **out, int branch) \
{ \
  UT_TYPE (T, HALF) a = UT_OP (mls_rm, T, HALF) ((const C *) in[0]); \
  UT_TYPE (T, HALF) b = UT_OP (mls_rm, T, HALF) ((const C *) in[1]); \
  UT_TYPE (T, BIG) s = UT_OP (mls_rm, T, BIG) ((const C *) in[2]); \
  UT_TYPE (T, BIG) original = UT_OP (mconcat_m, T, BIG) (a, b); \
  UT_TYPE (T, HALF) left = UT_OP (mextract, T, HALF) (s, 0); \
  UT_TYPE (T, HALF) right = UT_OP (mextract, T, HALF) (s, 1); \
  UT_TYPE (T, BIG) rebuilt = UT_OP (mconcat_m, T, BIG) (left, right); \
  UT_TYPE (T, BIG) changed = branch \
    ? UT_OP (mconcat_m, T, BIG) (b, a) \
    : UT_OP (mconcat_m, T, BIG) (a, a); \
  if (branch) a = UT_OP (mzero_m, T, HALF) (); \
  __riscv_ztt_mss_rm ((C *) out[0], original); \
  __riscv_ztt_mss_rm ((C *) out[1], a); \
  __riscv_ztt_mss_rm ((C *) out[2], b); \
  __riscv_ztt_mss_rm ((C *) out[3], left); \
  __riscv_ztt_mss_rm ((C *) out[4], right); \
  __riscv_ztt_mss_rm ((C *) out[5], changed); \
  __riscv_ztt_mss_rm ((C *) out[6], rebuilt); \
  __riscv_ztt_mss_rm ((C *) out[7], UT_OP (mconcat_m, T, BIG) (a, a)); \
}
#define UT_TEST(T, C, BIG, HALF) UT_FUNCTION (utils_##T##_##BIG, T, C, BIG, HALF)
#define UT_RMS(D, C, BIG, HALF) \
  UT_TEST (D##_rnu, C, BIG, HALF) \
  UT_TEST (D##_rne, C, BIG, HALF) \
  UT_TEST (D##_rdn, C, BIG, HALF) \
  UT_TEST (D##_rod, C, BIG, HALF) \
  UT_TEST (D, C, BIG, HALF)
#ifdef __cplusplus
extern "C" {
#endif
#ifdef TEST_TYPE
UT_FUNCTION (m_utils_kernel, TEST_TYPE, TEST_CARRIER, TEST_BIG, TEST_HALF)
#else
#if (__riscv_ztt_i8_u8_shapes & 3) == 3
UT_RMS (i8, int8_t, 1x2, 1x1)
UT_RMS (u8, uint8_t, 1x2, 1x1)
#endif
#if (__riscv_ztt_i8_u8_shapes & 5) == 5
UT_RMS (i8, int8_t, 2x1, 1x1)
UT_RMS (u8, uint8_t, 2x1, 1x1)
#endif
#if (__riscv_ztt_i8_u8_shapes & 10) == 10
UT_RMS (i8, int8_t, 1x4, 1x2)
UT_RMS (u8, uint8_t, 1x4, 1x2)
#endif
#if (__riscv_ztt_i8_u8_shapes & 20) == 20
UT_RMS (i8, int8_t, 4x1, 2x1)
UT_RMS (u8, uint8_t, 4x1, 2x1)
#endif
#if (__riscv_ztt_i8_u8_shapes & 40) == 40
UT_RMS (i8, int8_t, 1x8, 1x4)
UT_RMS (u8, uint8_t, 1x8, 1x4)
#endif
#if (__riscv_ztt_i8_u8_shapes & 80) == 80
UT_RMS (i8, int8_t, 8x1, 4x1)
UT_RMS (u8, uint8_t, 8x1, 4x1)
#endif
#if (__riscv_ztt_i8_u8_shapes & 160) == 160
UT_RMS (i8, int8_t, 1x16, 1x8)
UT_RMS (u8, uint8_t, 1x16, 1x8)
#endif
#if (__riscv_ztt_i8_u8_shapes & 320) == 320
UT_RMS (i8, int8_t, 16x1, 8x1)
UT_RMS (u8, uint8_t, 16x1, 8x1)
#endif
#if (__riscv_ztt_i16_u16_shapes & 3) == 3
UT_RMS (i16, int16_t, 1x2, 1x1)
UT_RMS (u16, uint16_t, 1x2, 1x1)
#endif
#if (__riscv_ztt_i16_u16_shapes & 5) == 5
UT_RMS (i16, int16_t, 2x1, 1x1)
UT_RMS (u16, uint16_t, 2x1, 1x1)
#endif
#if (__riscv_ztt_i16_u16_shapes & 10) == 10
UT_RMS (i16, int16_t, 1x4, 1x2)
UT_RMS (u16, uint16_t, 1x4, 1x2)
#endif
#if (__riscv_ztt_i16_u16_shapes & 20) == 20
UT_RMS (i16, int16_t, 4x1, 2x1)
UT_RMS (u16, uint16_t, 4x1, 2x1)
#endif
#if (__riscv_ztt_i16_u16_shapes & 40) == 40
UT_RMS (i16, int16_t, 1x8, 1x4)
UT_RMS (u16, uint16_t, 1x8, 1x4)
#endif
#if (__riscv_ztt_i16_u16_shapes & 80) == 80
UT_RMS (i16, int16_t, 8x1, 4x1)
UT_RMS (u16, uint16_t, 8x1, 4x1)
#endif
#if (__riscv_ztt_i16_u16_shapes & 160) == 160
UT_RMS (i16, int16_t, 1x16, 1x8)
UT_RMS (u16, uint16_t, 1x16, 1x8)
#endif
#if (__riscv_ztt_i16_u16_shapes & 320) == 320
UT_RMS (i16, int16_t, 16x1, 8x1)
UT_RMS (u16, uint16_t, 16x1, 8x1)
#endif
#if (__riscv_ztt_i32_u32_shapes & 3) == 3
UT_RMS (i32, int32_t, 1x2, 1x1)
UT_RMS (u32, uint32_t, 1x2, 1x1)
#endif
#if (__riscv_ztt_i32_u32_shapes & 5) == 5
UT_RMS (i32, int32_t, 2x1, 1x1)
UT_RMS (u32, uint32_t, 2x1, 1x1)
#endif
#if (__riscv_ztt_i32_u32_shapes & 10) == 10
UT_RMS (i32, int32_t, 1x4, 1x2)
UT_RMS (u32, uint32_t, 1x4, 1x2)
#endif
#if (__riscv_ztt_i32_u32_shapes & 20) == 20
UT_RMS (i32, int32_t, 4x1, 2x1)
UT_RMS (u32, uint32_t, 4x1, 2x1)
#endif
#if (__riscv_ztt_i32_u32_shapes & 40) == 40
UT_RMS (i32, int32_t, 1x8, 1x4)
UT_RMS (u32, uint32_t, 1x8, 1x4)
#endif
#if (__riscv_ztt_i32_u32_shapes & 80) == 80
UT_RMS (i32, int32_t, 8x1, 4x1)
UT_RMS (u32, uint32_t, 8x1, 4x1)
#endif
#if (__riscv_ztt_i32_u32_shapes & 160) == 160
UT_RMS (i32, int32_t, 1x16, 1x8)
UT_RMS (u32, uint32_t, 1x16, 1x8)
#endif
#if (__riscv_ztt_i32_u32_shapes & 320) == 320
UT_RMS (i32, int32_t, 16x1, 8x1)
UT_RMS (u32, uint32_t, 16x1, 8x1)
#endif
#endif
#ifdef __cplusplus
}
#endif
#undef UT_RMS
#undef UT_TEST
#undef UT_FUNCTION
#undef UT_OP
#undef UT_OP_
#undef UT_TYPE
#undef UT_TYPE_
