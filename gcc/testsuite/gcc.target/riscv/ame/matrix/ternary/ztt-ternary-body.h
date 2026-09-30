/* old-destination arithmetic.  */
#include <stdint.h>
#include <riscv_ztt.h>

#if __riscv_ztt_mmulacc_ew_int != 1 || __riscv_ztt_mmulaccneg_ew_int != 1 \
    || __riscv_ztt_mmuladd_ew_int != 1 || __riscv_ztt_mmulsub_ew_int != 1
#error missing integer ternary arithmetic support
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
#define DEFAULT_(F, T, S) __riscv_ztt_##F##_##T##_##S
#define DEFAULT(F, T, S) DEFAULT_(F, T, S)

#define TERNARY(F, NAME, D, DR, A, AR, B, BR, S) \
  void F##_##NAME (C(D) *out, const C(D) *old, const C(A) *a, \
                  const C(B) *b, C(D) *dcopy, C(A) *acopy, C(B) *bcopy) \
  { \
    TYPE(D, DR, S) d = OP(mls_rm, D, DR, S) (old); \
    TYPE(A, AR, S) x = OP(mls_rm, A, AR, S) (a); \
    TYPE(B, BR, S) y = OP(mls_rm, B, BR, S) (b); \
    TYPE(D, DR, S) result = OP(F, D, DR, S) (d, x, y); \
    __riscv_ztt_mss_rm (out, result); \
    __riscv_ztt_mss_rm (dcopy, d); \
    __riscv_ztt_mss_rm (acopy, x); \
    __riscv_ztt_mss_rm (bcopy, y); \
  }

#ifdef TEST_Q32
#define ROW 1x32
#define COL 32x1
#if __riscv_ztt_uds == 64
#define CASES(F) \
  TERNARY(F, row, i8, rnu, u8, rne, i8, rod, ROW) \
  TERNARY(F, col, u8, rdn, i8, rod, u8, rne, COL)
#elif __riscv_ztt_uds == 128
#define CASES(F) \
  TERNARY(F, wide_row, i16, rnu, u8, rdn, i16, rod, ROW) \
  TERNARY(F, wide_col, u16, rne, i16, rnu, i8, rdn, COL) \
  TERNARY(F, narrow_row, u8, rod, i16, rne, u16, rdn, ROW) \
  TERNARY(F, narrow_col, i8, rdn, u16, rnu, i16, rod, COL)
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
#endif
#define CASES(F) \
  TERNARY(F, widen_row, i32, rod, i8, rne, u16, rdn, ROW) \
  TERNARY(F, widen_col, u32, rnu, u16, rod, i8, rne, COL) \
  TERNARY(F, narrow_row, i8, rnu, u32, rod, i16, rne, ROW) \
  TERNARY(F, narrow_col, u8, rdn, i16, rnu, i32, rod, COL) \
  TERNARY(F, signed_row, i16, rdn, u8, rnu, u16, rod, ROW) \
  TERNARY(F, unsigned_col, u16, rne, i32, rdn, i8, rod, COL)
#endif

#define SHARED(F) \
  void F##_shared (int8_t *out, const int8_t *in, int8_t *copy) \
  { \
    TYPE(i8, rnu, ROW) v = OP(mls_rm, i8, rnu, ROW) (in); \
    TYPE(i8, rnu, ROW) r = DEFAULT(F, i8, ROW) (v, v, v); \
    __riscv_ztt_mss_rm (out, r); \
    __riscv_ztt_mss_rm (copy, v); \
  }
CASES(mmulacc_ew)
CASES(mmulaccneg_ew)
CASES(mmuladd_ew)
CASES(mmulsub_ew)
SHARED(mmulacc_ew)
SHARED(mmulaccneg_ew)
SHARED(mmuladd_ew)
SHARED(mmulsub_ew)
