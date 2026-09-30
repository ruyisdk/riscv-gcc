/* Large packed RNU aliases, ordinary pointer ABI.  */
#include <stdint.h>
#include <riscv_ztt.h>
#define OP_(O, T, S) __riscv_ztt_##O##_##T##_##S
#define OP(O, T, S) OP_ (O, T, S)
#define NAME_(T, K, X) packed_##T##_##K##_##X
#define NAME(T, K, X) NAME_ (T, K, X)
#ifdef OTHER
#define SIDE other
#else
#define SIDE first
#endif
#ifdef __cplusplus
extern "C" {
#endif
#define FUNC(T, C, K, R, Q)                                      \
__attribute__((noinline))                                        \
void NAME(T, K, SIDE) (const void *in, void *out)                  \
{                                                               \
  __typeof__ (OP(mls_rm, T, R) ((const C *) in)) m                 \
    = OP(mls_rm, T, R) ((const C *) in);                          \
  __typeof__ (OP(mcopy_m2a, T, K) (m)) a = OP(mcopy_m2a, T, K) (m); \
  __riscv_ztt_mss_rm ((C *) out, OP(mcopy_a2m, T, R) (a));         \
  __riscv_ztt_mss_rm ((C *) out, OP(mcopy_a2m, T, Q) (a));         \
  a = OP(mclear_acc, T, K) ();                                    \
  __riscv_ztt_mss_rm ((C *) out, OP(mcopy_a2m, T, R) (a));         \
  a = OP(mzero_acc, T, K) ();                                     \
  __riscv_ztt_mss_rm ((C *) out, OP(mcopy_a2m, T, R) (a));         \
}                                                               \
extern void NAME(T, K, other) (const void *, void *);
#if TEST_K == 8 && defined (__riscv_ztt_i8_u8_accx8_packed_irm)
FUNC(i8, int8_t, accx8, 1x8, 8x1)
FUNC(u8, uint8_t, accx8, 1x8, 8x1)
#endif
#if TEST_K == 8 && defined (__riscv_ztt_i16_u16_accx8_packed_irm)
FUNC(i16, int16_t, accx8, 1x8, 8x1)
FUNC(u16, uint16_t, accx8, 1x8, 8x1)
#endif
#if TEST_K == 8 && defined (__riscv_ztt_i32_u32_accx8_packed_irm)
FUNC(i32, int32_t, accx8, 1x8, 8x1)
FUNC(u32, uint32_t, accx8, 1x8, 8x1)
#endif
#if TEST_K == 16 && defined (__riscv_ztt_i8_u8_accx16_packed_irm)
FUNC(i8, int8_t, accx16, 1x16, 16x1)
FUNC(u8, uint8_t, accx16, 1x16, 16x1)
#endif
#if TEST_K == 16 && defined (__riscv_ztt_i16_u16_accx16_packed_irm)
FUNC(i16, int16_t, accx16, 1x16, 16x1)
FUNC(u16, uint16_t, accx16, 1x16, 16x1)
#endif
#if TEST_K == 16 && defined (__riscv_ztt_i32_u32_accx16_packed_irm)
FUNC(i32, int32_t, accx16, 1x16, 16x1)
FUNC(u32, uint32_t, accx16, 1x16, 16x1)
#endif
#ifndef OTHER
void packed_entry (const void *in, void *out)
{
#if TEST_K == 8 && defined (__riscv_ztt_i8_u8_accx8_packed_irm)
  NAME(i8, accx8, first) (in, out);
  NAME(i8, accx8, other) (in, out);
  NAME(u8, accx8, first) (in, out);
  NAME(u8, accx8, other) (in, out);
#endif
#if TEST_K == 8 && defined (__riscv_ztt_i16_u16_accx8_packed_irm)
  NAME(i16, accx8, first) (in, out);
  NAME(i16, accx8, other) (in, out);
  NAME(u16, accx8, first) (in, out);
  NAME(u16, accx8, other) (in, out);
#endif
#if TEST_K == 8 && defined (__riscv_ztt_i32_u32_accx8_packed_irm)
  NAME(i32, accx8, first) (in, out);
  NAME(i32, accx8, other) (in, out);
  NAME(u32, accx8, first) (in, out);
  NAME(u32, accx8, other) (in, out);
#endif
#if TEST_K == 16 && defined (__riscv_ztt_i8_u8_accx16_packed_irm)
  NAME(i8, accx16, first) (in, out);
  NAME(i8, accx16, other) (in, out);
  NAME(u8, accx16, first) (in, out);
  NAME(u8, accx16, other) (in, out);
#endif
#if TEST_K == 16 && defined (__riscv_ztt_i16_u16_accx16_packed_irm)
  NAME(i16, accx16, first) (in, out);
  NAME(i16, accx16, other) (in, out);
  NAME(u16, accx16, first) (in, out);
  NAME(u16, accx16, other) (in, out);
#endif
#if TEST_K == 16 && defined (__riscv_ztt_i32_u32_accx16_packed_irm)
  NAME(i32, accx16, first) (in, out);
  NAME(i32, accx16, other) (in, out);
  NAME(u32, accx16, first) (in, out);
  NAME(u32, accx16, other) (in, out);
#endif
}
#endif
#ifdef __cplusplus
}
#endif
