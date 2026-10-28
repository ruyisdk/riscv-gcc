#include <riscv_ztt.h>
typedef __INT64_TYPE__ element;
typedef __riscv_ztt_i64_rnu_1x1_t matrix;
#define LOAD(P) __riscv_ztt_mls_rm_i64_rnu_1x1(P)
#define STORE(P,V) __riscv_ztt_mss_rm(P,V)
#define SCALAR(V) __riscv_ztt_scalar_from_bits_i32_rnu((__UINT32_TYPE__)(V))
#define ITEMS(F) F(0) F(1) F(2) F(3) F(4) F(5) F(6) F(7) \
  F(8) F(9) F(10) F(11) F(12) F(13) F(14) F(15)
#define GET(I) double p##I = f[I];
#define SUM(I) sum += p##I / (delta + (I+1));
#define ARGS const element *in, const element *other, element *out, \
  element *saved, const volatile double *f, double *result
#define START matrix a=LOAD(in), b=LOAD(other)
#ifdef __cplusplus
extern "C" {
#endif
extern double fr_callee (void);
void fr_scalar (ARGS)
{
  START;
  double p=f[0];
  double delta=fr_callee ();
  matrix d=__riscv_ztt_mmulacc_ew_x_i64_rnu_1x1(a,b,SCALAR(p+delta));
  STORE(out,d); STORE(saved,a); *result=p*delta;
}
void fr_exponent (ARGS)
{
  START;
  double p=f[0];
  double delta=fr_callee ();
  matrix d=__riscv_ztt_mldexpacc_ew_x_i64_rnu_1x1(a,b,(long)(p+delta));
  STORE(out,d); STORE(saved,a); *result=p*delta;
}
void fr_pressure_scalar (ARGS)
{
  START;
  ITEMS(GET)
  double delta=fr_callee (), sum=0;
  ITEMS(SUM)
  matrix d=__riscv_ztt_mmulacc_ew_x_i64_rnu_1x1(a,b,SCALAR(sum));
  STORE(out,d); STORE(saved,a); *result=sum;
}
void fr_pressure_matrix (ARGS)
{
  START;
  ITEMS(GET)
  double delta=fr_callee (), sum=0;
  matrix d=__riscv_ztt_mmulacc_ew_i64_rnu_1x1(a,b,b);
  ITEMS(SUM)
  STORE(out,d); STORE(saved,a); *result=sum;
}
#ifdef __cplusplus
}
#endif
