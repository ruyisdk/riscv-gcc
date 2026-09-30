#include <stdint.h>
#include <riscv_ztt.h>
#include "../../fixtures/ztt-scalar-construct.h"

#if __riscv_ztt_mmulacc_ew_x_int != 1 || __riscv_ztt_mmulaccneg_ew_x_int != 1 \
    || __riscv_ztt_mmuladd_ew_x_int != 1 || __riscv_ztt_mmulsub_ew_x_int != 1
#error missing scalar old-D integer support
#endif

#define C_i8 int8_t
#define C_u8 uint8_t
#define C_i16 int16_t
#define C_u16 uint16_t
#define C_i32 int32_t
#define C_u32 uint32_t
#define C_I(T) C_##T
#define C(T) C_I(T)
#define TYPE_I(T, R, S) __riscv_ztt_##T##_##R##_##S##_t
#define TYPE(T, R, S) TYPE_I(T, R, S)
#define LOAD_I(T, R, S) __riscv_ztt_mls_rm_##T##_##R##_##S
#define LOAD(T, R, S) LOAD_I(T, R, S)
#define OP_I(F, T, R, S, TC, RC) __riscv_ztt_##F##_ew_x_##T##_##R##_##S##_##TC##_##RC
#define OP(F, T, R, S, TC, RC) OP_I(F, T, R, S, TC, RC)
#define DEFAULT_I(F, T, S, TC) __riscv_ztt_##F##_ew_x_##T##_##S##_##TC
#define DEFAULT(F, T, S, TC) DEFAULT_I(F, T, S, TC)

#ifdef TEST_Q32
#define ROW 1x32
#define COL 32x1
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
#else
#define ROW 1x16
#define COL 16x1
#endif
#endif

#define CASE(F, NAME, D, DR, B, BR, TC, CR, S) \
void F##_##NAME (C(D) *out, const C(D) *in_d, const C(B) *in_b, \
                C(D) *copy_d, C(B) *copy_b, C(TC) c) \
{ \
  TYPE(D, DR, S) d = LOAD(D, DR, S) (in_d); \
  TYPE(B, BR, S) b = LOAD(B, BR, S) (in_b); \
  TYPE(D, DR, S) r = OP(F, D, DR, S, TC, CR) (d, b, ZTT_TEST_MAKE(TC##_##CR, c)); \
  __riscv_ztt_mss_rm (out, r); \
  __riscv_ztt_mss_rm (copy_d, d); \
  __riscv_ztt_mss_rm (copy_b, b); \
}

#if defined(TEST_Q32) && __riscv_ztt_uds == 64
#define MATRIX_CASES(F) \
  CASE(F, signed_row, i8, rnu, u8, rne, i32, rod, ROW) \
  CASE(F, unsigned_col, u8, rdn, i8, rod, u32, rne, COL)
#elif defined(TEST_Q32)
#define MATRIX_CASES(F) \
  CASE(F, wide_row, i16, rdn, u8, rod, i32, rne, ROW) \
  CASE(F, wide_col, u16, rod, i8, rnu, u32, rdn, COL) \
  CASE(F, narrow_row, i8, rne, u16, rnu, i16, rod, ROW) \
  CASE(F, narrow_col, u8, rnu, i16, rne, u16, rnu, COL)
#else
#define MATRIX_CASES(F) \
  CASE(F, i8_row, i8, rnu, u32, rod, i16, rne, ROW) \
  CASE(F, u8_col, u8, rne, i32, rdn, u16, rnu, COL) \
  CASE(F, i16_row, i16, rdn, u8, rne, i32, rod, ROW) \
  CASE(F, u16_col, u16, rod, i8, rnu, u32, rdn, COL) \
  CASE(F, i32_row, i32, rnu, u16, rod, i8, rne, ROW) \
  CASE(F, u32_col, u32, rne, i16, rdn, u8, rod, COL)
#endif

#define TC_CASES(F, TC) \
  CASE(F, TC##_rnu, i8, rnu, u8, rne, TC, rnu, ROW) \
  CASE(F, TC##_rne, i8, rne, u8, rdn, TC, rne, ROW) \
  CASE(F, TC##_rdn, i8, rdn, u8, rod, TC, rdn, COL) \
  CASE(F, TC##_rod, i8, rod, u8, rnu, TC, rod, COL)

#define SHARED(F) \
void F##_shared (int8_t *out, const int8_t *in, int8_t *old_copy, uint32_t c) \
{ \
  TYPE(i8, rnu, ROW) d = LOAD(i8, rnu, ROW) (in); \
  TYPE(i8, rnu, ROW) r = DEFAULT(F, i8, ROW, u32) (d, d, __riscv_ztt_scalar_make_u32_rnu (c)); \
  __riscv_ztt_mss_rm (out, r); \
  __riscv_ztt_mss_rm (old_copy, d); \
}
#define ALL(F) \
  MATRIX_CASES(F) \
  TC_CASES(F, i8) TC_CASES(F, u8) \
  TC_CASES(F, i16) TC_CASES(F, u16) \
  TC_CASES(F, i32) TC_CASES(F, u32) \
  SHARED(F)

ALL(mmulacc)
ALL(mmulaccneg)
ALL(mmuladd)
ALL(mmulsub)
