#include <riscv_ztt.h>
#ifndef CR_TYPE
#define CR_TYPE i64_rnu
#define CR_ELEMENT __INT64_TYPE__
#endif
#define CR_T_(T) __riscv_ztt_##T##_1x1_t
#define CR_T(T) CR_T_(T)
#define CR_F_(F,T) __riscv_ztt_##F##_##T##_1x1
#define CR_FT(F,T) CR_F_(F,T)
#define CR_F(F) CR_FT(F,CR_TYPE)
typedef CR_T(CR_TYPE) matrix;
#define CR_CLOBBERS "m0","m1","m2","m3","m4","m5","m6","m7", \
  "m8","m9","m10","m11","m12","m13","m14","m15", \
  "m16","m17","m18","m19","m20","m21","m22","m23", \
  "m24","m25","m26","m27","m28","m29","m30","m31"
#define CR_RESET __asm__ volatile ( \
  "csrr t0,ameudsz\n\tli t1,0x40000000\n\tor t0,t0,t1\n\t" \
  ".irp r,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15," \
  "16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31\n\t" \
  "msettyp m\\r,t0\n\tmzero.2d.m m\\r\n\t.endr" \
  ::: "t0","t1",CR_CLOBBERS,"memory")
#ifdef __cplusplus
extern "C" {
#endif
#define CR_ARGS const CR_ELEMENT *in, CR_ELEMENT *out, CR_ELEMENT *saved
#define CR_CASE(NAME,GAP,OP) \
void cr_##NAME (CR_ARGS) \
{ \
  matrix a=CR_F(mls_rm)(in); \
  GAP; \
  matrix b=CR_F(OP)(a,a,a); \
  CR_F(mss_rm)(out,b); \
  CR_F(mss_rm)(saved,a); \
}
CR_CASE(acc,CR_RESET,mmulacc_ew)
CR_CASE(add,CR_RESET,mmuladd_ew)
CR_CASE(sub,CR_RESET,mmulsub_ew)
CR_CASE(neg,CR_RESET,mmulaccneg_ew)
CR_CASE(ready,,mmulacc_ew)
CR_CASE(asm,__asm__ volatile("" ::: "memory"),mmulacc_ew)
extern void cr_callee (void);
CR_CASE(call,cr_callee(),mmulacc_ew)
void cr_observer (CR_ARGS)
{
  matrix a=CR_F(mls_rm)(in);
  CR_RESET;
  __asm__ volatile ("# observe %0" :: "Wmr" (a) : "memory");
  matrix b=CR_F(mmulacc_ew)(a,a,a);
  CR_F(mss_rm)(out,b);
  CR_F(mss_rm)(saved,a);
}
void cr_exponent (CR_ARGS)
{
  matrix a=CR_F(mls_rm)(in);
  CR_RESET;
  matrix b=CR_F(mldexpacc_ew_x)(a,a,1L);
  CR_F(mss_rm)(out,b);
  CR_F(mss_rm)(saved,a);
}
void cr_dead (CR_ARGS)
{
  matrix a=CR_F(mls_rm)(in);
  CR_RESET;
  CR_F(mss_rm)(out,CR_F(mmulacc_ew)(a,a,a));
}
#ifdef __cplusplus
}
#endif
