/* matrix arithmetic.  */
#include <stdint.h>
#include <riscv_ztt.h>

#if __riscv_ztt_madd_ew_int_mixed != 1 \
    || __riscv_ztt_msub_ew_int_mixed != 1 \
    || __riscv_ztt_mabsdiff_ew_int_mixed != 1 \
    || __riscv_ztt_mhdiff_ew_int_mixed != 1 \
    || __riscv_ztt_mmean_ew_int_mixed != 1 \
    || __riscv_ztt_mmulneg_ew_int_mixed != 1
#error missing integer matrix arithmetic support
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
#define OP_(F, T, R, S) __riscv_ztt_##F##_##T##_##R##_##S
#define OP(F, T, R, S) OP_(F, T, R, S)
#define ALIAS_(F, T, S) __riscv_ztt_##F##_##T##_##S
#define ALIAS(F, T, S) ALIAS_(F, T, S)
#define NAME_(N, F, D, DR, A, AR, B, BR, S) N##_##F##_##D##_##DR##_##A##_##AR##_##B##_##BR##_##S
#define NAME(N, F, D, DR, A, AR, B, BR, S) NAME_(N, F, D, DR, A, AR, B, BR, S)

#define ARITH(N, F, D, DR, A, AR, B, BR, S) \
  void NAME(N, F, D, DR, A, AR, B, BR, S) \
    (C(D) *out, const C(A) *ap, const C(B) *bp, C(A) *ac, C(B) *bc) \
  { \
    TYPE(A, AR, S) a = OP(mls_rm, A, AR, S) (ap); \
    TYPE(B, BR, S) b = OP(mls_rm, B, BR, S) (bp); \
    TYPE(D, DR, S) value = OP(F, D, DR, S) (a, b); \
    __riscv_ztt_mss_rm (out, value); \
    __riscv_ztt_mss_rm (ac, a); \
    __riscv_ztt_mss_rm (bc, b); \
  }

#define SHARED(F, D, DR, A, AR, S) \
  void NAME(shared, F, D, DR, A, AR, A, AR, S) \
    (C(D) *out, const C(A) *p, C(A) *copy) \
  { \
    TYPE(A, AR, S) a = OP(mls_rm, A, AR, S) (p); \
    TYPE(D, DR, S) value = OP(F, D, DR, S) (a, a); \
    __riscv_ztt_mss_rm (out, value); \
    __riscv_ztt_mss_rm (copy, a); \
  }

#define DEFAULT(F, A, S) \
  void NAME(alias, F, i8, rnu, A, rne, A, rne, S) \
    (int8_t *out, const C(A) *p) \
  { \
    TYPE(A, rne, S) a = OP(mls_rm, A, rne, S) (p); \
    TYPE(i8, rnu, S) value = ALIAS(F, i8, S) (a, a); \
    __riscv_ztt_mss_rm (out, value); \
  }

#ifdef TEST_Q32
#define ROW 1x32
#define COL 32x1
#if __riscv_ztt_uds == 64
#define MID u8
#define SIGNEDMID i8
#elif __riscv_ztt_uds == 128
#define MID u16
#define SIGNEDMID i16
#else
#error invalid Q32 profile
#endif
#define FAMILY(F) \
  ARITH(row, F, i8, rnu, MID, rne, SIGNEDMID, rod, ROW) \
  ARITH(col, F, i8, rnu, MID, rne, SIGNEDMID, rod, COL) \
  ARITH(row, F, MID, rdn, i8, rod, MID, rne, ROW) \
  ARITH(col, F, MID, rdn, i8, rod, MID, rne, COL) \
  ARITH(row, F, SIGNEDMID, rod, MID, rdn, i8, rnu, ROW) \
  ARITH(col, F, SIGNEDMID, rod, MID, rdn, i8, rnu, COL) \
  SHARED(F, u8, rne, SIGNEDMID, rod, ROW) \
  DEFAULT(F, MID, ROW)
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
#define FAMILY(F) \
  ARITH(row, F, i32, rod, i8, rne, u16, rdn, ROW) \
  ARITH(col, F, i32, rod, i8, rne, u16, rdn, COL) \
  ARITH(row, F, i8, rnu, u32, rod, i16, rne, ROW) \
  ARITH(col, F, i8, rnu, u32, rod, i16, rne, COL) \
  ARITH(row, F, u16, rdn, u8, rnu, i32, rod, ROW) \
  ARITH(col, F, u16, rdn, u8, rnu, i32, rod, COL) \
  ARITH(row, F, u8, rne, i32, rod, u32, rdn, ROW) \
  ARITH(col, F, u8, rne, i32, rod, u32, rdn, COL) \
  ARITH(row, F, i16, rne, i8, rnu, u16, rod, ROW) \
  ARITH(col, F, i16, rne, i8, rnu, u16, rod, COL) \
  ARITH(row, F, u32, rnu, i32, rdn, u32, rne, ROW) \
  ARITH(col, F, u32, rnu, i32, rdn, u32, rne, COL) \
  ARITH(exact, F, i32, rnu, i32, rnu, i32, rnu, ROW) \
  SHARED(F, i32, rne, u32, rnu, ROW) \
  DEFAULT(F, u16, ROW)
#endif

FAMILY(madd_ew)
FAMILY(msub_ew)
FAMILY(mabsdiff_ew)
FAMILY(mhdiff_ew)
FAMILY(mmean_ew)
FAMILY(mmulneg_ew)
