#include <riscv_ztt.h>
#ifndef SL_TYPE
#define SL_TYPE i32_rnu
#define SL_ELEMENT __INT32_TYPE__
#endif
#define SL_T_(T) __riscv_ztt_##T##_1x1_t
#define SL_T(T) SL_T_(T)
#define SL_F_(F,T) __riscv_ztt_##F##_##T##_1x1
#define SL_EXPAND(F,T) SL_F_(F,T)
#define SL_F(F) SL_EXPAND(F,SL_TYPE)
#define SL_ARGS unsigned long k, const SL_ELEMENT *input, const SL_ELEMENT *other, \
  const SL_ELEMENT *initial, const __INT32_TYPE__ *index, \
  SL_ELEMENT *out, SL_ELEMENT *extra, __INT32_TYPE__ *saved
#define SL_LOAD \
  __riscv_ztt_i32_rnu_1x1_t i=__riscv_ztt_mls_rm_i32_rnu_1x1(index); \
  SL_T(SL_TYPE) a=SL_F(mls_rm)(input), b=SL_F(mls_rm)(other), d=SL_F(mls_rm)(initial)
#define SL_ROW(V) SL_F(mrowbcast_ew_x)(V,k)
#define SL_COL(V) SL_F(mcolbcast_ew_x)(V,k)
#define SL_STORE(V) __riscv_ztt_mss_rm(out,V)
#define SL_SAVE __riscv_ztt_mss_rm(saved,i)
#define SL_CASE(NAME,LEFT,RIGHT,OLD,EXPR,GAP,VALUE,SAVE,AFTER) \
void sl_##NAME(SL_ARGS) \
{ SL_LOAD; SL_T(SL_TYPE) l=LEFT, r=RIGHT, old=OLD, v=EXPR; \
  GAP; SL_STORE(VALUE); SAVE; AFTER; }
#ifdef __cplusplus
extern "C" {
#endif
extern void sl_callee(void);
extern volatile unsigned long sl_observed;
SL_CASE(row,SL_ROW(a),SL_ROW(b),d,SL_F(mldexp_ew)(l,r),,SL_F(mrowgather_ew)(v,i),SL_SAVE,)
SL_CASE(col,SL_COL(a),SL_COL(b),d,SL_F(mrdexp_ew)(l,r),,SL_F(mcolgather_ew)(v,i),SL_SAVE,)
SL_CASE(acc,SL_ROW(a),SL_ROW(b),SL_ROW(d),SL_F(mldexpacc_ew)(old,l,r),,SL_F(mrowgather_ew)(v,i),SL_SAVE,)
SL_CASE(acc_col,SL_COL(a),SL_COL(b),SL_COL(d),SL_F(mrdexpacc_ew)(old,l,r),,SL_F(mcolgather_ew)(v,i),SL_SAVE,)
SL_CASE(bcast,SL_ROW(a),SL_ROW(b),d,SL_F(mldexp_ew)(l,r),,SL_F(mrowbcast_ew_x)(v,0),SL_SAVE,)
SL_CASE(live,SL_ROW(a),SL_ROW(b),d,SL_F(mldexp_ew)(l,r),,SL_F(mrowgather_ew)(v,i),SL_SAVE,__riscv_ztt_mss_rm(extra,v))
SL_CASE(wrong,SL_ROW(a),SL_ROW(b),d,SL_F(mldexp_ew)(l,r),,SL_F(mcolgather_ew)(v,i),SL_SAVE,)
SL_CASE(partial,SL_ROW(a),b,d,SL_F(mldexp_ew)(l,r),,SL_F(mrowgather_ew)(v,i),SL_SAVE,)
SL_CASE(source,a,SL_ROW(b),d,SL_F(mldexp_ew)(l,r),,SL_F(mrowgather_ew)(v,i),SL_SAVE,)
SL_CASE(call,SL_ROW(a),SL_ROW(b),d,SL_F(mldexp_ew)(l,r),sl_callee(),SL_F(mrowgather_ew)(v,i),SL_SAVE,)
SL_CASE(asm,SL_ROW(a),SL_ROW(b),d,SL_F(mldexp_ew)(l,r),__asm__ volatile("":::"memory"),SL_F(mrowgather_ew)(v,i),SL_SAVE,)
SL_CASE(memory,SL_ROW(a),SL_ROW(b),d,SL_F(mldexp_ew)(l,r),sl_observed=k,SL_F(mrowgather_ew)(v,i),SL_SAVE,)
SL_CASE(dynamic,SL_ROW(a),SL_ROW(b),d,SL_F(mldexp_ew)(l,r),,SL_F(mrowbcast_ew_x)(v,k),SL_SAVE,)
SL_CASE(unstored,SL_ROW(a),SL_ROW(b),d,SL_F(mldexp_ew)(l,r),,SL_F(mrowgather_ew)(v,i),,)
SL_CASE(old,SL_ROW(a),SL_ROW(b),d,SL_F(mldexpacc_ew)(old,l,r),,SL_F(mrowgather_ew)(v,i),SL_SAVE,)
SL_CASE(reference,SL_ROW(a),SL_ROW(b),d,SL_F(mldexp_ew)(l,r),,v,SL_SAVE,)
#ifdef __cplusplus
}
#endif
