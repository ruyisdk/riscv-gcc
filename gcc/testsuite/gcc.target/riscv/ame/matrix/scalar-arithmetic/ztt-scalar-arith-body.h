/* data-scalar arithmetic.  */
#include <stdint.h>
#include <riscv_ztt.h>
#include "../../fixtures/ztt-scalar-construct.h"

#if __riscv_ztt_madd_ew_x_int != 1 || __riscv_ztt_msub_ew_x_int != 1 \
    || __riscv_ztt_mabsdiff_ew_x_int != 1 || __riscv_ztt_mhdiff_ew_x_int != 1 \
    || __riscv_ztt_mmean_ew_x_int != 1 || __riscv_ztt_mmul_ew_x_int != 1 \
    || __riscv_ztt_mmulneg_ew_x_int != 1 || __riscv_ztt_mmin_ew_x_int != 1 \
    || __riscv_ztt_mmax_ew_x_int != 1
#error missing integer data-scalar arithmetic support
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
#define LOAD_(T, R, S) __riscv_ztt_mls_rm_##T##_##R##_##S
#define LOAD(T, R, S) LOAD_(T, R, S)
#define OP_(F, D, DR, S, T, TR) __riscv_ztt_##F##_ew_x_##D##_##DR##_##S##_##T##_##TR
#define OP(F, D, DR, S, T, TR) OP_(F, D, DR, S, T, TR)
#define NAME_(F, D, DR, B, BR, T, TR, S) F##_##D##_##DR##_##B##_##BR##_##T##_##TR##_##S
#define NAME(F, D, DR, B, BR, T, TR, S) NAME_(F, D, DR, B, BR, T, TR, S)

#define SCALAR(F, D, DR, B, BR, T, TR, S) \
  void NAME(F, D, DR, B, BR, T, TR, S) \
    (C(D) *out, const C(B) *p, C(T) scalar, C(B) *copy) \
  { \
    TYPE(B, BR, S) b = LOAD(B, BR, S) (p); \
    TYPE(D, DR, S) d = OP(F, D, DR, S, T, TR) (b, ZTT_TEST_MAKE(T##_##TR, scalar)); \
    __riscv_ztt_mss_rm (out, d); \
    __riscv_ztt_mss_rm (copy, b); \
  }

#define RMS(F, D, B, T, S) \
  SCALAR(F, D, rnu, B, rne, T, rod, S) \
  SCALAR(F, D, rne, B, rdn, T, rnu, S) \
  SCALAR(F, D, rdn, B, rod, T, rne, S) \
  SCALAR(F, D, rod, B, rnu, T, rdn, S)
#define EXACT(F, D, T, S) \
  SCALAR(F, D, rnu, D, rnu, T, rod, S) \
  SCALAR(F, D, rne, D, rne, T, rnu, S) \
  SCALAR(F, D, rdn, D, rdn, T, rne, S) \
  SCALAR(F, D, rod, D, rod, T, rdn, S)

#ifdef TEST_Q32
#define ROW 1x32
#define COL 32x1
#if __riscv_ztt_uds == 64
#define MID i8
#define UMID u8
#elif __riscv_ztt_uds == 128
#define MID i16
#define UMID u16
#else
#error invalid Q32 profile
#endif
#define FAMILY(F) \
  RMS(F, i8, UMID, i8, ROW) \
  RMS(F, u8, MID, u8, COL) \
  RMS(F, MID, u8, i16, ROW) \
  RMS(F, UMID, i8, u16, COL) \
  RMS(F, i8, MID, i32, ROW) \
  RMS(F, u8, UMID, u32, COL)
#define MINMAX(F) \
  EXACT(F, i8, i8, ROW) \
  EXACT(F, u8, u8, COL) \
  EXACT(F, MID, i16, ROW) \
  EXACT(F, UMID, u16, COL) \
  EXACT(F, i8, i32, ROW) \
  EXACT(F, u8, u32, COL)
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
  RMS(F, i32, i8, i8, ROW) \
  RMS(F, i8, u32, u8, COL) \
  RMS(F, u16, u8, i16, ROW) \
  RMS(F, u8, i32, u16, COL) \
  RMS(F, i16, i8, i32, ROW) \
  RMS(F, u32, i32, u32, COL)
#define MINMAX(F) \
  EXACT(F, i8, u32, ROW) \
  EXACT(F, u8, i32, COL) \
  EXACT(F, i16, u16, ROW) \
  EXACT(F, u16, i16, COL) \
  EXACT(F, i32, u8, ROW) \
  EXACT(F, u32, i8, COL)
#endif

FAMILY(madd)
FAMILY(msub)
FAMILY(mabsdiff)
FAMILY(mhdiff)
FAMILY(mmean)
FAMILY(mmul)
FAMILY(mmulneg)
MINMAX(mmin)
MINMAX(mmax)
