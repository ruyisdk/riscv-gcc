#include <riscv_ztt.h>
#ifndef TL_TYPE
#define TL_TYPE i32_rnu
#define TL_ELEMENT __INT32_TYPE__
#endif
#define TL_T_(T) __riscv_ztt_##T##_1x1_t
#define TL_T(T) TL_T_(T)
#define TL_F_(F,T) __riscv_ztt_##F##_##T##_1x1
#define TL_EXPAND(F,T) TL_F_(F,T)
#define TL_F(F) TL_EXPAND(F,TL_TYPE)
#define TL_ARGS unsigned long k, const TL_ELEMENT *input, const TL_ELEMENT *other, \
  const TL_ELEMENT *third, const __INT32_TYPE__ *index, \
  TL_ELEMENT *out, TL_ELEMENT *extra, __INT32_TYPE__ *saved
#define TL_LOAD \
  __riscv_ztt_i32_rnu_1x1_t i=__riscv_ztt_mls_rm_i32_rnu_1x1(index); \
  TL_T(TL_TYPE) a=TL_F(mls_rm)(input), b=TL_F(mls_rm)(other), c=TL_F(mls_rm)(third)
#define TL_ROW(V) TL_F(mrowbcast_ew_x)(V,k)
#define TL_COL(V) TL_F(mcolbcast_ew_x)(V,k)
#define TL_STORE(V) __riscv_ztt_mss_rm(out,V)
#define TL_SAVE __riscv_ztt_mss_rm(saved,i)
#define TL_CASE(NAME,OLD,LEFT,RIGHT,OP,GAP,VALUE,SAVE,AFTER) \
void tl_##NAME(TL_ARGS) \
{ TL_LOAD; TL_T(TL_TYPE) d=OLD, l=LEFT, r=RIGHT, v=TL_F(OP)(d,l,r); \
  GAP; TL_STORE(VALUE); SAVE; AFTER; }
#ifdef __cplusplus
extern "C" {
#endif
extern void tl_callee(void);
extern volatile unsigned long tl_observed;
TL_CASE(row,TL_ROW(a),TL_ROW(b),TL_ROW(c),mmulacc_ew,,TL_F(mrowgather_ew)(v,i),TL_SAVE,)
TL_CASE(col,TL_COL(a),TL_COL(b),TL_COL(c),mmulaccneg_ew,,TL_F(mcolgather_ew)(v,i),TL_SAVE,)
TL_CASE(add,TL_ROW(a),TL_ROW(b),TL_ROW(c),mmuladd_ew,,TL_F(mrowgather_ew)(v,i),TL_SAVE,)
TL_CASE(sub,TL_ROW(a),TL_ROW(b),TL_ROW(c),mmulsub_ew,,TL_F(mrowgather_ew)(v,i),TL_SAVE,)
TL_CASE(bcast,TL_ROW(a),TL_ROW(b),TL_ROW(c),mmulacc_ew,,TL_F(mrowbcast_ew_x)(v,0),TL_SAVE,)
TL_CASE(live,TL_ROW(a),TL_ROW(b),TL_ROW(c),mmulacc_ew,,TL_F(mrowgather_ew)(v,i),TL_SAVE,__riscv_ztt_mss_rm(extra,v))
TL_CASE(old, a,TL_ROW(b),TL_ROW(c),mmulacc_ew,,TL_F(mrowgather_ew)(v,i),TL_SAVE,)
TL_CASE(left,TL_ROW(a),b,TL_ROW(c),mmulacc_ew,,TL_F(mrowgather_ew)(v,i),TL_SAVE,)
TL_CASE(right,TL_ROW(a),TL_ROW(b),c,mmulacc_ew,,TL_F(mrowgather_ew)(v,i),TL_SAVE,)
TL_CASE(wrong,TL_ROW(a),TL_ROW(b),TL_ROW(c),mmulacc_ew,,TL_F(mcolgather_ew)(v,i),TL_SAVE,)
TL_CASE(call,TL_ROW(a),TL_ROW(b),TL_ROW(c),mmulacc_ew,tl_callee(),TL_F(mrowgather_ew)(v,i),TL_SAVE,)
TL_CASE(asm,TL_ROW(a),TL_ROW(b),TL_ROW(c),mmulacc_ew,__asm__ volatile("":::"memory"),TL_F(mrowgather_ew)(v,i),TL_SAVE,)
TL_CASE(memory,TL_ROW(a),TL_ROW(b),TL_ROW(c),mmulacc_ew,tl_observed=k,TL_F(mrowgather_ew)(v,i),TL_SAVE,)
TL_CASE(dynamic,TL_ROW(a),TL_ROW(b),TL_ROW(c),mmulacc_ew,,TL_F(mrowbcast_ew_x)(v,k),TL_SAVE,)
TL_CASE(unstored,TL_ROW(a),TL_ROW(b),TL_ROW(c),mmulacc_ew,,TL_F(mrowgather_ew)(v,i),,)
TL_CASE(reference,TL_ROW(a),TL_ROW(b),TL_ROW(c),mmulacc_ew,,v,TL_SAVE,)
#ifdef __cplusplus
}
#endif
