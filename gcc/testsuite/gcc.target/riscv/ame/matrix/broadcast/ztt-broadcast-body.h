/* integer broadcast.  */
#include <stdint.h>
#include <riscv_ztt.h>
#include "../../fixtures/ztt-scalar-construct.h"

#if __riscv_ztt_mbcast_m_x_int != 1
#error missing integer scalar broadcast capability
#endif
#define C_i8 int8_t
#define C_u8 uint8_t
#define C_i16 int16_t
#define C_u16 uint16_t
#define C_i32 int32_t
#define C_u32 uint32_t
#define C_(T) C_##T
#define C(T) C_(T)
#define TYPE_(T, R, S) __riscv_ztt_##T##_##R##_##S##_t
#define TYPE(T, R, S) TYPE_(T, R, S)
#define OP_(D, DR, S, A, AR) __riscv_ztt_mbcast_m_x_##D##_##DR##_##S##_##A##_##AR
#define OP(D, DR, S, A, AR) OP_(D, DR, S, A, AR)
#define DEFAULT_(D, S, A) __riscv_ztt_mbcast_m_x_##D##_##S##_##A
#define DEFAULT(D, S, A) DEFAULT_(D, S, A)
#if __riscv_ztt_uds == 8
#define ROW 1x1
#define COL 1x1
#elif __riscv_ztt_uds == 16
#define ROW 1x2
#define COL 2x1
#elif __riscv_ztt_uds == 32
#define ROW 1x4
#define COL 4x1
#elif __riscv_ztt_uds == 64
#define ROW 1x8
#define COL 8x1
#elif __riscv_ztt_uds == 128
#define ROW 1x16
#define COL 16x1
#else
#error unsupported profile
#endif

#define BCAST(NAME, D, DR, S, A, AR) \
  void NAME (C(D) *out, C(A) scalar) \
  { \
    TYPE(D, DR, S) result = OP(D, DR, S, A, AR) ( ZTT_TEST_MAKE(A##_##AR, scalar)); \
    __riscv_ztt_mss_rm (out, result); \
  }

BCAST (row_i8_rnu, i8, rne, ROW, i8, rnu)
BCAST (col_i8_rnu, i8, rne, COL, i8, rnu)
BCAST (row_i8_rne, u8, rdn, ROW, i8, rne)
BCAST (col_i8_rne, u8, rdn, COL, i8, rne)
BCAST (row_i8_rdn, i16, rod, ROW, i8, rdn)
BCAST (col_i8_rdn, i16, rod, COL, i8, rdn)
BCAST (row_i8_rod, u16, rnu, ROW, i8, rod)
BCAST (col_i8_rod, u16, rnu, COL, i8, rod)
BCAST (row_u8_rnu, u8, rne, ROW, u8, rnu)
BCAST (col_u8_rnu, u8, rne, COL, u8, rnu)
BCAST (row_u8_rne, i16, rdn, ROW, u8, rne)
BCAST (col_u8_rne, i16, rdn, COL, u8, rne)
BCAST (row_u8_rdn, u16, rod, ROW, u8, rdn)
BCAST (col_u8_rdn, u16, rod, COL, u8, rdn)
BCAST (row_u8_rod, i32, rnu, ROW, u8, rod)
BCAST (col_u8_rod, i32, rnu, COL, u8, rod)
BCAST (row_i16_rnu, i16, rne, ROW, i16, rnu)
BCAST (col_i16_rnu, i16, rne, COL, i16, rnu)
BCAST (row_i16_rne, u16, rdn, ROW, i16, rne)
BCAST (col_i16_rne, u16, rdn, COL, i16, rne)
BCAST (row_i16_rdn, i32, rod, ROW, i16, rdn)
BCAST (col_i16_rdn, i32, rod, COL, i16, rdn)
BCAST (row_i16_rod, u32, rnu, ROW, i16, rod)
BCAST (col_i16_rod, u32, rnu, COL, i16, rod)
BCAST (row_u16_rnu, u16, rne, ROW, u16, rnu)
BCAST (col_u16_rnu, u16, rne, COL, u16, rnu)
BCAST (row_u16_rne, i32, rdn, ROW, u16, rne)
BCAST (col_u16_rne, i32, rdn, COL, u16, rne)
BCAST (row_u16_rdn, u32, rod, ROW, u16, rdn)
BCAST (col_u16_rdn, u32, rod, COL, u16, rdn)
BCAST (row_u16_rod, i8, rnu, ROW, u16, rod)
BCAST (col_u16_rod, i8, rnu, COL, u16, rod)
BCAST (row_i32_rnu, i32, rne, ROW, i32, rnu)
BCAST (col_i32_rnu, i32, rne, COL, i32, rnu)
BCAST (row_i32_rne, u32, rdn, ROW, i32, rne)
BCAST (col_i32_rne, u32, rdn, COL, i32, rne)
BCAST (row_i32_rdn, i8, rod, ROW, i32, rdn)
BCAST (col_i32_rdn, i8, rod, COL, i32, rdn)
BCAST (row_i32_rod, u8, rnu, ROW, i32, rod)
BCAST (col_i32_rod, u8, rnu, COL, i32, rod)
BCAST (row_u32_rnu, u32, rne, ROW, u32, rnu)
BCAST (col_u32_rnu, u32, rne, COL, u32, rnu)
BCAST (row_u32_rne, i8, rdn, ROW, u32, rne)
BCAST (col_u32_rne, i8, rdn, COL, u32, rne)
BCAST (row_u32_rdn, u8, rod, ROW, u32, rdn)
BCAST (col_u32_rdn, u8, rod, COL, u32, rdn)
BCAST (row_u32_rod, i16, rnu, ROW, u32, rod)
BCAST (col_u32_rod, i16, rnu, COL, u32, rod)

void default_alias (int8_t *out, uint32_t scalar)
{
  TYPE(i8, rnu, ROW) result = DEFAULT(i8, ROW, u32) ( __riscv_ztt_scalar_make_u32_rnu (scalar));
  __riscv_ztt_mss_rm (out, result);
}

void negative_constant (int8_t *out)
{
  TYPE(i8, rod, ROW) result = OP(i8, rod, ROW, i8, rne) ( __riscv_ztt_scalar_make_i8_rne (-1));
  __riscv_ztt_mss_rm (out, result);
}

void unsigned_high_bit (uint8_t *out)
{
  TYPE(u8, rne, ROW) result = OP(u8, rne, ROW, u32, rod) ( __riscv_ztt_scalar_make_u32_rod (UINT32_MAX));
  __riscv_ztt_mss_rm (out, result);
}

void signed_high_bit (int32_t *out)
{
  TYPE(i32, rdn, ROW) result = OP(i32, rdn, ROW, i32, rnu) ( __riscv_ztt_scalar_make_i32_rnu (INT32_MIN));
  __riscv_ztt_mss_rm (out, result);
}

static __inline__ __attribute__((__always_inline__)) uint32_t
next_scalar (volatile uint32_t *counter)
{
  uint32_t value = *counter;
  *counter = value + 1;
  return value;
}

void side_effect_once (uint32_t *out, volatile uint32_t *counter)
{
  TYPE(u32, rnu, ROW) result = OP(u32, rnu, ROW, u32, rne) ( __riscv_ztt_scalar_make_u32_rne (next_scalar (counter)));
  __riscv_ztt_mss_rm (out, result);
}
