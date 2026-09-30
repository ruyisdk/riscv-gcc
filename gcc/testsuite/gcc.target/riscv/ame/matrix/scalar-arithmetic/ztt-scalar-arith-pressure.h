/* data-scalar arithmetic.  */
#include <stdint.h>
#include <stddef.h>
#include <riscv_ztt.h>
#include "../../fixtures/ztt-scalar-construct.h"

#define TYPE_(D, R) __riscv_ztt_##D##_##R##_1x4_t
#define TYPE(D, R) TYPE_(D, R)
#define OP_(F, D, R, T, TR) __riscv_ztt_##F##_ew_x_##D##_##R##_1x4_##T##_##TR
#define OP(F, D, R, T, TR) OP_(F, D, R, T, TR)
#define LOAD(I) TYPE(i32, rod) a##I = __riscv_ztt_mls_rm_i32_rod_1x4 (p + I * stride)
#define CALC(I, F, D, R, T, TR) TYPE(D, R) d##I = OP(F, D, R, T, TR) (a##I, ZTT_TEST_MAKE(T##_##TR, scalar))
#define STORE(I) \
  __riscv_ztt_mss_rm (out + I * stride, d##I); \
  __riscv_ztt_mss_rm (copy + I * stride, a##I)
#define FAMILY(F, D, R, C) \
  void pressure_##F (C *out, int32_t *copy, const int32_t *p, \
                      size_t stride, uint32_t scalar) \
  { \
    LOAD(0); LOAD(1); LOAD(2); LOAD(3); \
    LOAD(4); LOAD(5); LOAD(6); LOAD(7); \
    CALC(0, F, D, R, i8, rnu); CALC(1, F, D, R, u8, rne); \
    CALC(2, F, D, R, i16, rdn); CALC(3, F, D, R, u16, rod); \
    CALC(4, F, D, R, i32, rne); CALC(5, F, D, R, u32, rnu); \
    CALC(6, F, D, R, i8, rod); CALC(7, F, D, R, u32, rdn); \
    TYPE(i32, rod) saved = a0; \
    a0 = __riscv_ztt_mzero_m_i32_rod_1x4 (); \
    STORE(0); STORE(1); STORE(2); STORE(3); \
    STORE(4); STORE(5); STORE(6); STORE(7); \
    __riscv_ztt_mss_rm (copy + 8 * stride, saved); \
  }
FAMILY(madd, i8, rdn, int8_t)
FAMILY(msub, i8, rdn, int8_t)
FAMILY(mabsdiff, i8, rdn, int8_t)
FAMILY(mhdiff, i8, rdn, int8_t)
FAMILY(mmean, i8, rdn, int8_t)
FAMILY(mmul, i8, rdn, int8_t)
FAMILY(mmulneg, i8, rdn, int8_t)
FAMILY(mmin, i32, rod, int32_t)
FAMILY(mmax, i32, rod, int32_t)
