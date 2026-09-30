/* Q32.  */
#include <stdint.h>
#include <riscv_ztt.h>

#define Q32_TYPE(T, S) __riscv_ztt_##T##_##S##_t
#define Q32_CALL(OP, T, S) __riscv_ztt_##OP##_##T##_##S
#define Q32_BINARY(OP, T, S, E) \
void test_##OP##_##T##_##S (E *out, const E *p, const E *q) \
{ \
  Q32_TYPE (T, S) a = Q32_CALL (mls_rm, T, S) (p); \
  Q32_TYPE (T, S) b = Q32_CALL (mls_rm, T, S) (q); \
  __riscv_ztt_mss_rm (out, Q32_CALL (OP, T, S) (a, b)); \
}
#define Q32_ZERO(OP, T, S, E) \
void test_##OP##_##T##_##S (E *out) \
{ \
  __riscv_ztt_mss_rm (out, Q32_CALL (OP, T, S) ()); \
}
#define Q32_COPY(T, S, E) \
void test_copy_##T##_##S (E *out, E *live, const E *p) \
{ \
  Q32_TYPE (T, S) a = Q32_CALL (mls_rm, T, S) (p); \
  Q32_TYPE (T, S) b = Q32_CALL (mcopy_m2m, T, S) (a); \
  __riscv_ztt_mss_rm (out, b); \
  __riscv_ztt_mss_rm (live, a); \
}
#define Q32_ALL(T, S, E) \
  Q32_ZERO (mclear_m, T, S, E) \
  Q32_ZERO (mzero_m, T, S, E) \
  Q32_COPY (T, S, E) \
  Q32_BINARY (madd_ew, T, S, E) \
  Q32_BINARY (msub_ew, T, S, E) \
  Q32_BINARY (mmin_ew, T, S, E) \
  Q32_BINARY (mmax_ew, T, S, E) \
  Q32_BINARY (mand_ew, T, S, E) \
  Q32_BINARY (mandnot_ew, T, S, E) \
  Q32_BINARY (mor_ew, T, S, E) \
  Q32_BINARY (mornot_ew, T, S, E) \
  Q32_BINARY (mxor_ew, T, S, E)
Q32_ALL (i8_rnu, 1x32, int8_t)
Q32_ALL (i8_rnu, 32x1, int8_t)
Q32_ALL (i8_rne, 1x32, int8_t)
Q32_ALL (i8_rne, 32x1, int8_t)
Q32_ALL (i8_rdn, 1x32, int8_t)
Q32_ALL (i8_rdn, 32x1, int8_t)
Q32_ALL (i8_rod, 1x32, int8_t)
Q32_ALL (i8_rod, 32x1, int8_t)
Q32_ALL (i8, 1x32, int8_t)
Q32_ALL (i8, 32x1, int8_t)
Q32_ALL (u8_rnu, 1x32, uint8_t)
Q32_ALL (u8_rnu, 32x1, uint8_t)
Q32_ALL (u8_rne, 1x32, uint8_t)
Q32_ALL (u8_rne, 32x1, uint8_t)
Q32_ALL (u8_rdn, 1x32, uint8_t)
Q32_ALL (u8_rdn, 32x1, uint8_t)
Q32_ALL (u8_rod, 1x32, uint8_t)
Q32_ALL (u8_rod, 32x1, uint8_t)
Q32_ALL (u8, 1x32, uint8_t)
Q32_ALL (u8, 32x1, uint8_t)
#if __riscv_ztt_uds == 128
Q32_ALL (i16_rnu, 1x32, int16_t)
Q32_ALL (i16_rnu, 32x1, int16_t)
Q32_ALL (i16_rne, 1x32, int16_t)
Q32_ALL (i16_rne, 32x1, int16_t)
Q32_ALL (i16_rdn, 1x32, int16_t)
Q32_ALL (i16_rdn, 32x1, int16_t)
Q32_ALL (i16_rod, 1x32, int16_t)
Q32_ALL (i16_rod, 32x1, int16_t)
Q32_ALL (i16, 1x32, int16_t)
Q32_ALL (i16, 32x1, int16_t)
Q32_ALL (u16_rnu, 1x32, uint16_t)
Q32_ALL (u16_rnu, 32x1, uint16_t)
Q32_ALL (u16_rne, 1x32, uint16_t)
Q32_ALL (u16_rne, 32x1, uint16_t)
Q32_ALL (u16_rdn, 1x32, uint16_t)
Q32_ALL (u16_rdn, 32x1, uint16_t)
Q32_ALL (u16_rod, 1x32, uint16_t)
Q32_ALL (u16_rod, 32x1, uint16_t)
Q32_ALL (u16, 1x32, uint16_t)
Q32_ALL (u16, 32x1, uint16_t)
#endif
