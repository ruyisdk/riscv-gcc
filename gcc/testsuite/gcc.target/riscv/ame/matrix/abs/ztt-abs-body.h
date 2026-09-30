/* mabs.ew.  */
#include <stdint.h>
#include <riscv_ztt.h>

#if __riscv_ztt_mabs_ew_int != 1
#error missing integer absolute value support
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
#define DEFAULT_(T, S) __riscv_ztt_mabs_ew_##T##_##S
#define DEFAULT(T, S) DEFAULT_(T, S)

#define ABSOLUTE(NAME, D, DR, A, AR, S) \
  void NAME (C(D) *out, const C(A) *input, C(A) *copy) \
  { \
    TYPE(A, AR, S) source = OP(mls_rm, A, AR, S) (input); \
    TYPE(D, DR, S) result = OP(mabs_ew, D, DR, S) (source); \
    __riscv_ztt_mss_rm (out, result); \
    __riscv_ztt_mss_rm (copy, source); \
  }

#ifdef TEST_Q32
#define ROW 1x32
#define COL 32x1
#if __riscv_ztt_uds == 64
ABSOLUTE (row_signed, i8, rnu, u8, rod, ROW)
ABSOLUTE (col_signed, i8, rnu, u8, rod, COL)
ABSOLUTE (row_unsigned, u8, rne, i8, rdn, ROW)
ABSOLUTE (col_unsigned, u8, rne, i8, rdn, COL)
#define ALIAS_SOURCE u8
#elif __riscv_ztt_uds == 128
ABSOLUTE (row_narrow, u8, rnu, i16, rod, ROW)
ABSOLUTE (col_narrow, u8, rnu, i16, rod, COL)
ABSOLUTE (row_widen, i16, rne, u8, rdn, ROW)
ABSOLUTE (col_widen, i16, rne, u8, rdn, COL)
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
ABSOLUTE (row_widen, i32, rod, i8, rne, ROW)
ABSOLUTE (col_widen, i32, rod, i8, rne, COL)
ABSOLUTE (row_narrow, i8, rnu, u32, rod, ROW)
ABSOLUTE (col_narrow, i8, rnu, u32, rod, COL)
ABSOLUTE (row_signed, i16, rdn, u16, rnu, ROW)
ABSOLUTE (col_signed, i16, rdn, u16, rnu, COL)
ABSOLUTE (row_unsigned, u32, rne, i32, rdn, ROW)
ABSOLUTE (col_unsigned, u32, rne, i32, rdn, COL)
ABSOLUTE (row_same, u8, rod, u8, rod, ROW)
ABSOLUTE (col_same, u8, rod, u8, rod, COL)
#define ALIAS_SOURCE u16
#endif

void
default_alias (int8_t *out, const C(ALIAS_SOURCE) *input)
{
  TYPE(ALIAS_SOURCE, rne, ROW) source
    = OP(mls_rm, ALIAS_SOURCE, rne, ROW) (input);
  TYPE(i8, rnu, ROW) result = DEFAULT(i8, ROW) (source);
  __riscv_ztt_mss_rm (out, result);
}
