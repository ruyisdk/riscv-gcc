#include <riscv_ztt.h>
#ifndef BL_TYPE
#define BL_TYPE i32_rnu
#define BL_ELEMENT __INT32_TYPE__
#endif
#define BL_T_(T) __riscv_ztt_##T##_1x1_t
#define BL_T(T) BL_T_(T)
#define BL_F_(F,T) __riscv_ztt_##F##_##T##_1x1
#define BL_F(F) BL_F_(F,BL_TYPE)
#define BL_EXPAND_(F,T) BL_F_(F,T)
#undef BL_F
#define BL_F(F) BL_EXPAND_(F,BL_TYPE)
#define BL_ARGS unsigned long k, const BL_ELEMENT *input, const BL_ELEMENT *other, \
  const __INT32_TYPE__ *index, BL_ELEMENT *out, BL_ELEMENT *extra, __INT32_TYPE__ *saved
#define BL_LOAD \
  __riscv_ztt_i32_rnu_1x1_t i=__riscv_ztt_mls_rm_i32_rnu_1x1(index); \
  BL_T(BL_TYPE) a=BL_F(mls_rm)(input), b=BL_F(mls_rm)(other)
#define BL_ROW(V) BL_F(mrowbcast_ew_x)(V,k)
#define BL_COL(V) BL_F(mcolbcast_ew_x)(V,k)
#define BL_STORE(V) __riscv_ztt_mss_rm(out,V)
#define BL_SAVE __riscv_ztt_mss_rm(saved,i)
#define BL_CASE(NAME,LEFT,RIGHT,OP,GAP,VALUE,SAVE,AFTER) \
void bl_##NAME(BL_ARGS) \
{ BL_LOAD; BL_T(BL_TYPE) l=LEFT, r=RIGHT, v=BL_F(OP)(l,r); \
  GAP; BL_STORE(VALUE); SAVE; AFTER; }
#ifdef __cplusplus
extern "C" {
#endif
extern void bl_callee(void);
extern volatile unsigned long bl_observed;
BL_CASE(row,BL_ROW(a),BL_ROW(b),madd_ew,,BL_F(mrowgather_ew)(v,i),BL_SAVE,)
BL_CASE(col,BL_COL(a),BL_COL(b),mxor_ew,,BL_F(mcolgather_ew)(v,i),BL_SAVE,)
BL_CASE(min,BL_ROW(a),BL_ROW(b),mmin_ew,,BL_F(mrowgather_ew)(v,i),BL_SAVE,)
BL_CASE(mul,BL_ROW(a),BL_ROW(b),mmul_ew,,BL_F(mrowgather_ew)(v,i),BL_SAVE,)
BL_CASE(sub,BL_ROW(a),BL_ROW(b),msub_ew,,BL_F(mrowgather_ew)(v,i),BL_SAVE,)
BL_CASE(bcast,BL_ROW(a),BL_ROW(b),madd_ew,,BL_F(mrowbcast_ew_x)(v,0),BL_SAVE,)
BL_CASE(extrema,BL_ROW(a),BL_ROW(b),madd_ew,,BL_F(mreducemax_col)(v),BL_SAVE,)
BL_CASE(live,BL_ROW(a),BL_ROW(b),madd_ew,,BL_F(mrowgather_ew)(v,i),BL_SAVE,__riscv_ztt_mss_rm(extra,v))
BL_CASE(wrong,BL_ROW(a),BL_ROW(b),madd_ew,,BL_F(mcolgather_ew)(v,i),BL_SAVE,)
BL_CASE(partial,BL_ROW(a),b,madd_ew,,BL_F(mrowgather_ew)(v,i),BL_SAVE,)
BL_CASE(call,BL_ROW(a),BL_ROW(b),madd_ew,bl_callee(),BL_F(mrowgather_ew)(v,i),BL_SAVE,)
BL_CASE(asm,BL_ROW(a),BL_ROW(b),madd_ew,__asm__ volatile("":::"memory"),BL_F(mrowgather_ew)(v,i),BL_SAVE,)
BL_CASE(memory,BL_ROW(a),BL_ROW(b),madd_ew,bl_observed=k,BL_F(mrowgather_ew)(v,i),BL_SAVE,)
BL_CASE(dynamic,BL_ROW(a),BL_ROW(b),madd_ew,,BL_F(mrowbcast_ew_x)(v,k),BL_SAVE,)
BL_CASE(unstored,BL_ROW(a),BL_ROW(b),madd_ew,,BL_F(mrowgather_ew)(v,i),,)
BL_CASE(reference,BL_ROW(a),BL_ROW(b),madd_ew,,v,BL_SAVE,)
#ifdef __cplusplus
}
#endif
