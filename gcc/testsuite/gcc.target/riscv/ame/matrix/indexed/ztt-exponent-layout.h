#include <riscv_ztt.h>
#ifndef EL_TYPE
#define EL_TYPE i32_rnu
#define EL_ELEMENT __INT32_TYPE__
#endif
#define EL_T_(T) __riscv_ztt_##T##_1x1_t
#define EL_T(T) EL_T_(T)
#define EL_F_(F,T) __riscv_ztt_##F##_##T##_1x1
#define EL_EXPAND(F,T) EL_F_(F,T)
#define EL_F(F) EL_EXPAND(F,EL_TYPE)
#define EL_ARGS unsigned long k, long e, const EL_ELEMENT *input, const EL_ELEMENT *other, \
  const __INT32_TYPE__ *index, EL_ELEMENT *out, EL_ELEMENT *extra, __INT32_TYPE__ *saved
#define EL_LOAD \
  __riscv_ztt_i32_rnu_1x1_t i=__riscv_ztt_mls_rm_i32_rnu_1x1(index); \
  EL_T(EL_TYPE) a=EL_F(mls_rm)(input), b=EL_F(mls_rm)(other)
#define EL_ROW(V) EL_F(mrowbcast_ew_x)(V,k)
#define EL_COL(V) EL_F(mcolbcast_ew_x)(V,k)
#define EL_STORE(V) __riscv_ztt_mss_rm(out,V)
#define EL_SAVE __riscv_ztt_mss_rm(saved,i)
#define EL_CASE(NAME,OLD,SRC,EXPR,GAP,VALUE,SAVE,AFTER) \
void el_##NAME(EL_ARGS) \
{ EL_LOAD; EL_T(EL_TYPE) d=OLD, s=SRC, v=EXPR; \
  GAP; EL_STORE(VALUE); SAVE; AFTER; }
#ifdef __cplusplus
extern "C" {
#endif
extern void el_callee(void);
extern volatile unsigned long el_observed;
EL_CASE(row,b,EL_ROW(a),EL_F(mldexp_ew_x)(s,e),,EL_F(mrowgather_ew)(v,i),EL_SAVE,)
EL_CASE(col,b,EL_COL(a),EL_F(mldexp_ew_x)(s,e),,EL_F(mcolgather_ew)(v,i),EL_SAVE,)
EL_CASE(acc,EL_ROW(b),EL_ROW(a),EL_F(mldexpacc_ew_x)(d,s,e),,EL_F(mrowgather_ew)(v,i),EL_SAVE,)
EL_CASE(acc_col,EL_COL(b),EL_COL(a),EL_F(mldexpacc_ew_x)(d,s,e),,EL_F(mcolgather_ew)(v,i),EL_SAVE,)
EL_CASE(live,b,EL_ROW(a),EL_F(mldexp_ew_x)(s,e),,EL_F(mrowgather_ew)(v,i),EL_SAVE,__riscv_ztt_mss_rm(extra,v))
EL_CASE(bcast,b,EL_ROW(a),EL_F(mldexp_ew_x)(s,e),,EL_F(mrowbcast_ew_x)(v,0),EL_SAVE,)
EL_CASE(old,b,EL_ROW(a),EL_F(mldexpacc_ew_x)(d,s,e),,EL_F(mrowgather_ew)(v,i),EL_SAVE,)
EL_CASE(source,EL_ROW(b),a,EL_F(mldexpacc_ew_x)(d,s,e),,EL_F(mrowgather_ew)(v,i),EL_SAVE,)
EL_CASE(wrong,b,EL_ROW(a),EL_F(mldexp_ew_x)(s,e),,EL_F(mcolgather_ew)(v,i),EL_SAVE,)
EL_CASE(call,b,EL_ROW(a),EL_F(mldexp_ew_x)(s,e),el_callee(),EL_F(mrowgather_ew)(v,i),EL_SAVE,)
EL_CASE(asm,b,EL_ROW(a),EL_F(mldexp_ew_x)(s,e),__asm__ volatile("":::"memory"),EL_F(mrowgather_ew)(v,i),EL_SAVE,)
EL_CASE(memory,b,EL_ROW(a),EL_F(mldexp_ew_x)(s,e),el_observed=k,EL_F(mrowgather_ew)(v,i),EL_SAVE,)
EL_CASE(dynamic,b,EL_ROW(a),EL_F(mldexp_ew_x)(s,e),,EL_F(mrowbcast_ew_x)(v,k),EL_SAVE,)
EL_CASE(unstored,b,EL_ROW(a),EL_F(mldexp_ew_x)(s,e),,EL_F(mrowgather_ew)(v,i),,)
EL_CASE(nested,b,EL_ROW(a),EL_F(mldexp_ew_x)(EL_F(mldexp_ew_x)(s,e),e),,EL_F(mrowgather_ew)(v,i),EL_SAVE,)
EL_CASE(reference,b,EL_ROW(a),EL_F(mldexp_ew_x)(s,e),,v,EL_SAVE,)
#ifdef __cplusplus
}
#endif
