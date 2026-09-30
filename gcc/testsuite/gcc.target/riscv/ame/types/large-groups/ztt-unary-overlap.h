#include <riscv_ztt.h>
#define KEEP(X) __asm__ volatile ("" : : "Wmr" (X))
#define TYPE_(D, S) __riscv_ztt_##D##_##S##_t
#define TYPE(D, S) TYPE_(D, S)
#define BCAST_(D, S) __riscv_ztt_mbcast_m_x_##D##_##S##_i8_rnu
#define BCAST(D, S) BCAST_(D, S)
#define CALL_(OP, D, S) __riscv_ztt_##OP##_##D##_##S
#define CALL(OP, D, S) CALL_(OP, D, S)
#define UNARY(OP, D) \
void OP##_##D (signed char x) \
{ \
  TYPE(D, 1x1) a = BCAST(D, 1x1) ( __riscv_ztt_scalar_make_i8_rnu (x)); \
  TYPE(D, 1x1) b = CALL(OP, D, 1x1) (a); \
  KEEP(b); \
  KEEP(a); \
}
#define INTEGER(D) \
  UNARY(mconv_ew, D) \
  UNARY(mabs_ew, D) \
  UNARY(mprefixadd_col, D) \
  UNARY(mreduceadd_row, D)
INTEGER(i64_rnu)
INTEGER(u64_rne)
INTEGER(i128_rdn)
INTEGER(u128_rod)
INTEGER(i128_rnu_sat)
INTEGER(u64_rne_sat)

#define ROWCOL(OP, D, CONTROL) \
void OP##_##D (signed char x, unsigned long index, int offset) \
{ \
  TYPE(D, 1x1) a = BCAST(D, 1x1) ( __riscv_ztt_scalar_make_i8_rnu (x)); \
  TYPE(D, 1x1) b = CALL(OP, D, 1x1) (a, CONTROL); \
  KEEP(b); \
  KEEP(a); \
}
#define ROWCOL_TYPE(D) \
  ROWCOL(mcolbcast_ew_x, D, index) \
  ROWCOL(mrowbcast_ew_x, D, index) \
  ROWCOL(mcolshift_ew_x, D, offset) \
  ROWCOL(mrowshift_ew_x, D, offset)
ROWCOL_TYPE(u64_rne)
ROWCOL_TYPE(i128_rdn)
ROWCOL_TYPE(u128_rod)

#define FP(RM) UNARY(mconv_ew, f64_##RM) UNARY(mabs_ew, f64_##RM)
FP(rne)
FP(rtz)
FP(rdn)
FP(rup)
FP(rmm)
FP(rno)
UNARY(mfrintm_ew, f64_rne)
UNARY(mfrintn_ew, f64_rne)
UNARY(mfrintp_ew, f64_rne)
UNARY(mfrintz_ew, f64_rne)
UNARY(mexp2_ew, f64_rne)
UNARY(mlog2_ew, f64_rne)
UNARY(mcos_ew, f64_rne)
UNARY(msin_ew, f64_rne)
UNARY(mtanh_ew, f64_rne)
UNARY(mrec_ew, f64_rne)
UNARY(mrsqrt_ew, f64_rne)
UNARY(msqrt_ew, f64_rne)

#define DEAD(OP, D) \
void dead_##OP##_##D (signed char x) \
{ \
  TYPE(D, 1x1) a = BCAST(D, 1x1) ( __riscv_ztt_scalar_make_i8_rnu (x)); \
  CALL(OP, D, 1x1) (a); \
}
DEAD(mconv_ew, i128_rnu_sat)
DEAD(mabs_ew, i128_rnu_sat)
DEAD(msqrt_ew, f64_rne)
void dead_mcolbcast_ew_x_i128_rdn (signed char x, unsigned long index, int offset)
{
  TYPE(i128_rdn, 1x1) a = BCAST(i128_rdn, 1x1) ( __riscv_ztt_scalar_make_i8_rnu (x));
  CALL(mcolbcast_ew_x, i128_rdn, 1x1) (a, index);
}

#define MIXED(OP, D, S) \
void mixed_##OP##_##D##_##S (signed char x) \
{ \
  TYPE(S, 1x1) a = BCAST(S, 1x1) ( __riscv_ztt_scalar_make_i8_rnu (x)); \
  TYPE(D, 1x1) b = CALL(OP, D, 1x1) (a); \
  KEEP(b); \
  KEEP(a); \
}
MIXED(mconv_ew, f64_rne, f64_rdn)
MIXED(mabs_ew, f64_rne, f64_rdn)
#if TEST_UDS >= 16 || TEST_M >= 32
MIXED(mconv_ew, i128_rnu, i128_rdn)
MIXED(mabs_ew, i128_rnu, i128_rdn)
#define MULTI(OP) \
void multi_##OP##_i128_rdn (signed char x) \
{ \
  TYPE(i128_rdn, 1x2) a = BCAST(i128_rdn, 1x2) ( __riscv_ztt_scalar_make_i8_rnu (x)); \
  TYPE(i128_rdn, 1x2) b = CALL(OP, i128_rdn, 1x2) (a); \
  KEEP(b); \
  KEEP(a); \
}
MULTI(mconv_ew)
MULTI(mabs_ew)
#endif
