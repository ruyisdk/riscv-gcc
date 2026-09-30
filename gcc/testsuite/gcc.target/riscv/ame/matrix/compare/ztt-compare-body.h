#include <stdint.h>
#include <riscv_ztt.h>
#include "../../fixtures/ztt-scalar-construct.h"
#if __riscv_ztt_mcmovge_ew_int != 1 || __riscv_ztt_mcmovlt_ew_int != 1 \
    || __riscv_ztt_mcmpge_ew_int != 1 || __riscv_ztt_mcmplt_ew_int != 1 \
    || __riscv_ztt_mcmpge_ew_x_int != 1 || __riscv_ztt_mcmplt_ew_x_int != 1 \
    || __riscv_ztt_mselge_ew_int != 1 || __riscv_ztt_msellt_ew_int != 1
#error missing comparison or conditional selection support
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
#define OP_I(F, T, R, S) __riscv_ztt_##F##_ew_##T##_##R##_##S
#define OP(F, T, R, S) OP_I(F, T, R, S)
#define XOP_I(F, T, R, S, TC, CR) __riscv_ztt_##F##_ew_x_##T##_##R##_##S##_##TC##_##CR
#define XOP(F, T, R, S, TC, CR) XOP_I(F, T, R, S, TC, CR)
#ifdef TEST_Q32
#define ROW 1x32
#define COL 32x1
#elif __riscv_ztt_uds == 8
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

#define CMP(F, NAME, D, DR, A, AR, B, BR, S) \
void F##_##NAME (C(D) *out, const C(A) *pa, const C(B) *pb, C(A) *ac, C(B) *bc) \
{ \
  TYPE(A, AR, S) a = LOAD(A, AR, S) (pa); \
  TYPE(B, BR, S) b = LOAD(B, BR, S) (pb); \
  TYPE(D, DR, S) r = OP(F, D, DR, S) (a, b); \
  __riscv_ztt_mss_rm (out, r); \
  __riscv_ztt_mss_rm (ac, a); __riscv_ztt_mss_rm (bc, b); \
}
#define SEL(F, NAME, D, DR, P, PR, S) \
  CMP(F, NAME, D, DR, P, PR, D, DR, S)
#define MOV(F, NAME, D, DR, P, PR, S) \
void F##_##NAME (C(D) *out, const C(D) *old, const C(P) *pa, const C(D) *pb, \
                C(D) *dc, C(P) *ac, C(D) *bc) \
{ \
  TYPE(D, DR, S) d = LOAD(D, DR, S) (old); \
  TYPE(P, PR, S) a = LOAD(P, PR, S) (pa); \
  TYPE(D, DR, S) b = LOAD(D, DR, S) (pb); \
  TYPE(D, DR, S) r = OP(F, D, DR, S) (d, a, b); \
  __riscv_ztt_mss_rm (out, r); __riscv_ztt_mss_rm (dc, d); \
  __riscv_ztt_mss_rm (ac, a); __riscv_ztt_mss_rm (bc, b); \
}
#define XCASE(F, NAME, D, DR, B, BR, TC, CR, S) \
void F##_x_##NAME (C(D) *out, const C(B) *in, C(B) *copy, C(TC) scalar) \
{ \
  TYPE(B, BR, S) b = LOAD(B, BR, S) (in); \
  TYPE(D, DR, S) r = XOP(F, D, DR, S, TC, CR) (b, ZTT_TEST_MAKE(TC##_##CR, scalar)); \
  __riscv_ztt_mss_rm (out, r); __riscv_ztt_mss_rm (copy, b); \
}

#if defined(TEST_Q32) && __riscv_ztt_uds == 64
#define CMP_CASES(F) \
  CMP(F, signed_row, i8, rod, u8, rne, i8, rdn, ROW) \
  CMP(F, unsigned_col, u8, rnu, i8, rod, u8, rne, COL)
#define SELECT_CASES(APPLY, F) \
  APPLY(F, signed_row, i8, rod, u8, rne, ROW) \
  APPLY(F, unsigned_col, u8, rnu, i8, rod, COL)
#elif defined(TEST_Q32)
#define CMP_CASES(F) \
  CMP(F, wide_row, i16, rdn, u8, rod, i16, rne, ROW) \
  CMP(F, wide_col, u16, rod, i16, rne, u8, rnu, COL) \
  CMP(F, narrow_row, i8, rne, u16, rdn, i8, rod, ROW) \
  CMP(F, narrow_col, u8, rnu, i8, rne, u16, rod, COL)
#define SELECT_CASES(APPLY, F) \
  APPLY(F, wide_row, i16, rdn, u8, rod, ROW) \
  APPLY(F, wide_col, u16, rod, i8, rne, COL) \
  APPLY(F, narrow_row, i8, rne, u16, rdn, ROW) \
  APPLY(F, narrow_col, u8, rnu, i16, rod, COL)
#else
#define CMP_CASES(F) \
  CMP(F, i8_row, i8, rnu, u16, rod, i32, rne, ROW) \
  CMP(F, u8_col, u8, rne, i32, rdn, u16, rnu, COL) \
  CMP(F, i16_row, i16, rdn, u8, rne, i16, rod, ROW) \
  CMP(F, u16_col, u16, rod, i16, rnu, u8, rdn, COL) \
  CMP(F, i32_row, i32, rnu, u16, rod, i8, rne, ROW) \
  CMP(F, u32_col, u32, rne, i8, rdn, u16, rod, COL)
#define SELECT_CASES(APPLY, F) \
  APPLY(F, i8_row, i8, rnu, u32, rod, ROW) \
  APPLY(F, u8_col, u8, rne, i32, rdn, COL) \
  APPLY(F, i16_row, i16, rdn, u8, rne, ROW) \
  APPLY(F, u16_col, u16, rod, i8, rnu, COL) \
  APPLY(F, i32_row, i32, rnu, u16, rod, ROW) \
  APPLY(F, u32_col, u32, rne, i16, rdn, COL)
#endif
#define TC_CASES(F, TC) \
  XCASE(F, TC##_rnu, i8, rnu, u8, rne, TC, rnu, ROW) \
  XCASE(F, TC##_rne, u8, rne, i8, rdn, TC, rne, ROW) \
  XCASE(F, TC##_rdn, i8, rdn, u8, rod, TC, rdn, COL) \
  XCASE(F, TC##_rod, u8, rod, i8, rnu, TC, rod, COL)
#define XCASES(F) \
  TC_CASES(F, i8) TC_CASES(F, u8) TC_CASES(F, i16) \
  TC_CASES(F, u16) TC_CASES(F, i32) TC_CASES(F, u32)
CMP_CASES(mcmpge)
CMP_CASES(mcmplt)
SELECT_CASES(MOV, mcmovge)
SELECT_CASES(MOV, mcmovlt)
SELECT_CASES(SEL, mselge)
SELECT_CASES(SEL, msellt)
XCASES(mcmpge)
XCASES(mcmplt)
#define X_MATRIX(F, NAME, D, DR, P, PR, S) \
  XCASE(F, mixed_##NAME, D, DR, P, PR, u32, rod, S)
SELECT_CASES(X_MATRIX, mcmpge)
SELECT_CASES(X_MATRIX, mcmplt)

/* The same value may supply both read-only inputs and old_d.  */
void shared (int8_t *out, const int8_t *in, int8_t *saved, uint32_t c)
{
  TYPE(i8, rnu, ROW) a = LOAD(i8, rnu, ROW) (in);
  TYPE(i8, rnu, ROW) x = OP(mcmovge, i8, rnu, ROW) (a, a, a);
  x = OP(mcmovlt, i8, rnu, ROW) (x, a, a);
  x = OP(mselge, i8, rnu, ROW) (x, x);
  x = OP(msellt, i8, rnu, ROW) (x, x);
  x = OP(mcmpge, i8, rnu, ROW) (x, x);
  x = OP(mcmplt, i8, rnu, ROW) (x, x);
  x = XOP(mcmpge, i8, rnu, ROW, u32, rdn) (x, __riscv_ztt_scalar_make_u32_rdn (c));
  x = XOP(mcmplt, i8, rnu, ROW, i16, rod) (x, __riscv_ztt_scalar_make_i16_rod (c));
  __riscv_ztt_mss_rm (out, x); __riscv_ztt_mss_rm (saved, a);
}
