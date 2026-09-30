#include <riscv_ztt.h>
#include <stddef.h>
#include <stdint.h>

#define MEMORY_CASE(T, C, RM, S) \
void mem_##T##_##RM##_##S (C *out, C *out_st, C *out_tst, \
                          C *from_st, C *from_tst, const C *in, size_t stride) \
{ \
  __riscv_ztt_##T##_##RM##_##S##_t v \
    = __riscv_ztt_mls_cm_##T##_##RM##_##S (in); \
  __riscv_ztt_mss_cm (out, v); \
  __riscv_ztt_mss_st (out_st, stride, v); \
  __riscv_ztt_mss_tst (out_tst, stride, v); \
  __riscv_ztt_mss_cm (from_st, __riscv_ztt_mls_st_##T##_##RM##_##S (in, stride)); \
  __riscv_ztt_mss_cm (from_tst, __riscv_ztt_mls_tst_##T##_##RM##_##S (in, stride)); \
}
#define MEMORY_RMS(T, C, S) \
  MEMORY_CASE (T, C, rnu, S) \
  MEMORY_CASE (T, C, rne, S) \
  MEMORY_CASE (T, C, rdn, S) \
  MEMORY_CASE (T, C, rod, S)

#if 8 >= MEMORY_UDS && 8 <= 4 * MEMORY_UDS
MEMORY_RMS (i8, int8_t, 1x1)
#endif

#if 16 >= MEMORY_UDS && 16 <= 4 * MEMORY_UDS && defined (__riscv_ztt_runtime_n)
MEMORY_RMS (i8, int8_t, 1x2)
MEMORY_RMS (i8, int8_t, 2x1)
#endif

#if 32 >= MEMORY_UDS && 32 <= 4 * MEMORY_UDS && defined (__riscv_ztt_runtime_n)
MEMORY_RMS (i8, int8_t, 1x4)
MEMORY_RMS (i8, int8_t, 4x1)
#endif

#if 64 >= MEMORY_UDS && 64 <= 4 * MEMORY_UDS && defined (__riscv_ztt_runtime_n)
MEMORY_RMS (i8, int8_t, 1x8)
MEMORY_RMS (i8, int8_t, 8x1)
#endif

#if 128 >= MEMORY_UDS && 128 <= 4 * MEMORY_UDS && defined (__riscv_ztt_runtime_n)
MEMORY_RMS (i8, int8_t, 1x16)
MEMORY_RMS (i8, int8_t, 16x1)
#endif

#if 256 >= MEMORY_UDS && 256 <= 4 * MEMORY_UDS && defined (__riscv_ztt_runtime_n)
MEMORY_RMS (i8, int8_t, 1x32)
MEMORY_RMS (i8, int8_t, 32x1)
#endif

#if 8 >= MEMORY_UDS && 8 <= 4 * MEMORY_UDS
MEMORY_RMS (u8, uint8_t, 1x1)
#endif

#if 16 >= MEMORY_UDS && 16 <= 4 * MEMORY_UDS && defined (__riscv_ztt_runtime_n)
MEMORY_RMS (u8, uint8_t, 1x2)
MEMORY_RMS (u8, uint8_t, 2x1)
#endif

#if 32 >= MEMORY_UDS && 32 <= 4 * MEMORY_UDS && defined (__riscv_ztt_runtime_n)
MEMORY_RMS (u8, uint8_t, 1x4)
MEMORY_RMS (u8, uint8_t, 4x1)
#endif

#if 64 >= MEMORY_UDS && 64 <= 4 * MEMORY_UDS && defined (__riscv_ztt_runtime_n)
MEMORY_RMS (u8, uint8_t, 1x8)
MEMORY_RMS (u8, uint8_t, 8x1)
#endif

#if 128 >= MEMORY_UDS && 128 <= 4 * MEMORY_UDS && defined (__riscv_ztt_runtime_n)
MEMORY_RMS (u8, uint8_t, 1x16)
MEMORY_RMS (u8, uint8_t, 16x1)
#endif

#if 256 >= MEMORY_UDS && 256 <= 4 * MEMORY_UDS && defined (__riscv_ztt_runtime_n)
MEMORY_RMS (u8, uint8_t, 1x32)
MEMORY_RMS (u8, uint8_t, 32x1)
#endif

#if 16 >= MEMORY_UDS && 16 <= 4 * MEMORY_UDS
MEMORY_RMS (i16, int16_t, 1x1)
#endif

#if 32 >= MEMORY_UDS && 32 <= 4 * MEMORY_UDS && defined (__riscv_ztt_runtime_n)
MEMORY_RMS (i16, int16_t, 1x2)
MEMORY_RMS (i16, int16_t, 2x1)
#endif

#if 64 >= MEMORY_UDS && 64 <= 4 * MEMORY_UDS && defined (__riscv_ztt_runtime_n)
MEMORY_RMS (i16, int16_t, 1x4)
MEMORY_RMS (i16, int16_t, 4x1)
#endif

#if 128 >= MEMORY_UDS && 128 <= 4 * MEMORY_UDS && defined (__riscv_ztt_runtime_n)
MEMORY_RMS (i16, int16_t, 1x8)
MEMORY_RMS (i16, int16_t, 8x1)
#endif

#if 256 >= MEMORY_UDS && 256 <= 4 * MEMORY_UDS && defined (__riscv_ztt_runtime_n)
MEMORY_RMS (i16, int16_t, 1x16)
MEMORY_RMS (i16, int16_t, 16x1)
#endif

#if 512 >= MEMORY_UDS && 512 <= 4 * MEMORY_UDS && defined (__riscv_ztt_runtime_n)
MEMORY_RMS (i16, int16_t, 1x32)
MEMORY_RMS (i16, int16_t, 32x1)
#endif

#if 16 >= MEMORY_UDS && 16 <= 4 * MEMORY_UDS
MEMORY_RMS (u16, uint16_t, 1x1)
#endif

#if 32 >= MEMORY_UDS && 32 <= 4 * MEMORY_UDS && defined (__riscv_ztt_runtime_n)
MEMORY_RMS (u16, uint16_t, 1x2)
MEMORY_RMS (u16, uint16_t, 2x1)
#endif

#if 64 >= MEMORY_UDS && 64 <= 4 * MEMORY_UDS && defined (__riscv_ztt_runtime_n)
MEMORY_RMS (u16, uint16_t, 1x4)
MEMORY_RMS (u16, uint16_t, 4x1)
#endif

#if 128 >= MEMORY_UDS && 128 <= 4 * MEMORY_UDS && defined (__riscv_ztt_runtime_n)
MEMORY_RMS (u16, uint16_t, 1x8)
MEMORY_RMS (u16, uint16_t, 8x1)
#endif

#if 256 >= MEMORY_UDS && 256 <= 4 * MEMORY_UDS && defined (__riscv_ztt_runtime_n)
MEMORY_RMS (u16, uint16_t, 1x16)
MEMORY_RMS (u16, uint16_t, 16x1)
#endif

#if 512 >= MEMORY_UDS && 512 <= 4 * MEMORY_UDS && defined (__riscv_ztt_runtime_n)
MEMORY_RMS (u16, uint16_t, 1x32)
MEMORY_RMS (u16, uint16_t, 32x1)
#endif

#if 32 >= MEMORY_UDS && 32 <= 4 * MEMORY_UDS
MEMORY_RMS (i32, int32_t, 1x1)
#endif

#if 64 >= MEMORY_UDS && 64 <= 4 * MEMORY_UDS && defined (__riscv_ztt_runtime_n)
MEMORY_RMS (i32, int32_t, 1x2)
MEMORY_RMS (i32, int32_t, 2x1)
#endif

#if 128 >= MEMORY_UDS && 128 <= 4 * MEMORY_UDS && defined (__riscv_ztt_runtime_n)
MEMORY_RMS (i32, int32_t, 1x4)
MEMORY_RMS (i32, int32_t, 4x1)
#endif

#if 256 >= MEMORY_UDS && 256 <= 4 * MEMORY_UDS && defined (__riscv_ztt_runtime_n)
MEMORY_RMS (i32, int32_t, 1x8)
MEMORY_RMS (i32, int32_t, 8x1)
#endif

#if 512 >= MEMORY_UDS && 512 <= 4 * MEMORY_UDS && defined (__riscv_ztt_runtime_n)
MEMORY_RMS (i32, int32_t, 1x16)
MEMORY_RMS (i32, int32_t, 16x1)
#endif

#if 1024 >= MEMORY_UDS && 1024 <= 4 * MEMORY_UDS && defined (__riscv_ztt_runtime_n)
MEMORY_RMS (i32, int32_t, 1x32)
MEMORY_RMS (i32, int32_t, 32x1)
#endif

#if 32 >= MEMORY_UDS && 32 <= 4 * MEMORY_UDS
MEMORY_RMS (u32, uint32_t, 1x1)
#endif

#if 64 >= MEMORY_UDS && 64 <= 4 * MEMORY_UDS && defined (__riscv_ztt_runtime_n)
MEMORY_RMS (u32, uint32_t, 1x2)
MEMORY_RMS (u32, uint32_t, 2x1)
#endif

#if 128 >= MEMORY_UDS && 128 <= 4 * MEMORY_UDS && defined (__riscv_ztt_runtime_n)
MEMORY_RMS (u32, uint32_t, 1x4)
MEMORY_RMS (u32, uint32_t, 4x1)
#endif

#if 256 >= MEMORY_UDS && 256 <= 4 * MEMORY_UDS && defined (__riscv_ztt_runtime_n)
MEMORY_RMS (u32, uint32_t, 1x8)
MEMORY_RMS (u32, uint32_t, 8x1)
#endif

#if 512 >= MEMORY_UDS && 512 <= 4 * MEMORY_UDS && defined (__riscv_ztt_runtime_n)
MEMORY_RMS (u32, uint32_t, 1x16)
MEMORY_RMS (u32, uint32_t, 16x1)
#endif

#if 1024 >= MEMORY_UDS && 1024 <= 4 * MEMORY_UDS && defined (__riscv_ztt_runtime_n)
MEMORY_RMS (u32, uint32_t, 1x32)
MEMORY_RMS (u32, uint32_t, 32x1)
#endif

#undef MEMORY_RMS
#undef MEMORY_CASE
