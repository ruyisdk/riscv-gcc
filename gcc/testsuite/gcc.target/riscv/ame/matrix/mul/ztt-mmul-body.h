/* mmul.ew.  */
#include <stdint.h>
#include <riscv_ztt.h>

#if __riscv_ztt_mmul_ew_int_mixed != 1
#error missing integer matrix multiply support
#endif

#define C_i8 int8_t
#define C_u8 uint8_t
#define C_i16 int16_t
#define C_u16 uint16_t
#define C_i32 int32_t
#define C_u32 uint32_t
#define C_(T) C_##T
#define C(T) C_(T)
#define TYPE_(T, RM, S) __riscv_ztt_##T##_##RM##_##S##_t
#define TYPE(T, RM, S) TYPE_(T, RM, S)
#define OP_(F, T, RM, S) __riscv_ztt_##F##_##T##_##RM##_##S
#define OP(F, T, RM, S) OP_(F, T, RM, S)
#define DEFAULT_(T, S) __riscv_ztt_mmul_ew_##T##_##S
#define DEFAULT(T, S) DEFAULT_(T, S)

#define PRODUCT(NAME, D, DR, L, LR, R, RR, S) \
  void NAME (C(D) *out, const C(L) *lp, const C(R) *rp, \
             C(L) *lcopy, C(R) *rcopy) \
  { \
    TYPE(L, LR, S) lhs = OP(mls_rm, L, LR, S) (lp); \
    TYPE(R, RR, S) rhs = OP(mls_rm, R, RR, S) (rp); \
    TYPE(D, DR, S) dst = OP(mmul_ew, D, DR, S) (lhs, rhs); \
    __riscv_ztt_mss_rm (out, dst); \
    __riscv_ztt_mss_rm (lcopy, lhs); \
    __riscv_ztt_mss_rm (rcopy, rhs); \
  }

#define SQUARE(NAME, D, T, S) \
  void NAME (C(D) *out, const C(T) *input, C(T) *copy) \
  { \
    TYPE(T, rod, S) value = OP(mls_rm, T, rod, S) (input); \
    TYPE(D, rne, S) result = OP(mmul_ew, D, rne, S) (value, value); \
    __riscv_ztt_mss_rm (out, result); \
    __riscv_ztt_mss_rm (copy, value); \
  }

#ifdef TEST_Q32
#define ROW 1x32
#define COL 32x1
#if __riscv_ztt_uds == 64
PRODUCT (row_mixed, u8, rne, i8, rod, u8, rdn, ROW)
PRODUCT (col_mixed, u8, rne, i8, rod, u8, rdn, COL)
SQUARE (row_square, u8, i8, ROW)
SQUARE (col_square, u8, i8, COL)
#define ALIAS_SOURCE u8
#elif __riscv_ztt_uds == 128
PRODUCT (row_mixed, u8, rne, i8, rod, u16, rdn, ROW)
PRODUCT (col_mixed, u8, rne, i8, rod, u16, rdn, COL)
PRODUCT (row_wide, i16, rnu, u16, rne, i16, rod, ROW)
PRODUCT (col_wide, i16, rnu, u16, rne, i16, rod, COL)
SQUARE (row_square, u8, i16, ROW)
SQUARE (col_square, u8, i16, COL)
#define ALIAS_SOURCE u16
#else
#error unsupported Q32 profile
#endif
#else
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
PRODUCT (row_widen, i32, rod, i8, rne, u16, rdn, ROW)
PRODUCT (col_widen, i32, rod, i8, rne, u16, rdn, COL)
PRODUCT (row_narrow, i8, rnu, u32, rod, i16, rne, ROW)
PRODUCT (col_narrow, i8, rnu, u32, rod, i16, rne, COL)
PRODUCT (row_mixed, u16, rdn, u8, rnu, i32, rod, ROW)
PRODUCT (col_mixed, u16, rdn, u8, rnu, i32, rod, COL)
PRODUCT (row_wide, u32, rne, i32, rdn, u32, rnu, ROW)
PRODUCT (col_wide, u32, rne, i32, rdn, u32, rnu, COL)
SQUARE (row_square, u16, i32, ROW)
SQUARE (col_square, u16, i32, COL)
#define ALIAS_SOURCE u16
#endif

void
default_alias (int8_t *out, const C(ALIAS_SOURCE) *p)
{
  TYPE(ALIAS_SOURCE, rne, ROW) value
    = OP(mls_rm, ALIAS_SOURCE, rne, ROW) (p);
  TYPE(i8, rnu, ROW) product = DEFAULT(i8, ROW) (value, value);
  __riscv_ztt_mss_rm (out, product);
}
