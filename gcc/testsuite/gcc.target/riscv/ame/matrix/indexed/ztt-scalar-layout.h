#include <riscv_ztt.h>
#ifndef LS_TYPE
#define LS_TYPE i32_rnu_sat
#define LS_ELEMENT __INT32_TYPE__
#endif
#ifndef LS_SCALAR
#define LS_SCALAR LS_TYPE
#endif
#define LS_T_(T) __riscv_ztt_##T##_1x1_t
#define LS_T(T) LS_T_(T)
#define LS_F_(F,T) __riscv_ztt_##F##_##T##_1x1
#define LS_EXPAND(F,T) LS_F_(F,T)
#define LS_F(F) LS_EXPAND(F,LS_TYPE)
#define LS_BITS_(T,V) __riscv_ztt_scalar_from_bits_##T(V)
#define LS_BITS(T,V) LS_BITS_(T,V)
#define LS_ARGS unsigned long k, const LS_ELEMENT *input, __UINT32_TYPE__ scalar, \
  const __INT32_TYPE__ *index, LS_ELEMENT *out, LS_ELEMENT *extra, __INT32_TYPE__ *saved
#define LS_LOAD \
  __riscv_ztt_i32_rnu_1x1_t i=__riscv_ztt_mls_rm_i32_rnu_1x1(index); \
  LS_T(LS_TYPE) a=LS_F(mls_rm)(input)
#define LS_ROW(V) LS_F(mrowbcast_ew_x)(V,k)
#define LS_COL(V) LS_F(mcolbcast_ew_x)(V,k)
#define LS_STORE(V) __riscv_ztt_mss_rm(out,V)
#define LS_SAVE __riscv_ztt_mss_rm(saved,i)
#define LS_CASE(NAME,INPUT,OP,GAP,VALUE,SAVE,AFTER) \
void ls_##NAME(LS_ARGS) \
{ LS_LOAD; LS_T(LS_TYPE) l=INPUT, v=LS_F(OP)(l,LS_BITS(LS_SCALAR,scalar)); \
  GAP; LS_STORE(VALUE); SAVE; AFTER; }
#ifdef __cplusplus
extern "C" {
#endif
extern void ls_callee(void);
LS_CASE(row,LS_ROW(a),madd_ew_x,,LS_F(mrowgather_ew)(v,i),LS_SAVE,)
LS_CASE(col,LS_COL(a),mmul_ew_x,,LS_F(mcolgather_ew)(v,i),LS_SAVE,)
LS_CASE(sub,LS_ROW(a),msub_ew_x,,LS_F(mrowgather_ew)(v,i),LS_SAVE,)
LS_CASE(bcast,LS_ROW(a),madd_ew_x,,LS_F(mrowbcast_ew_x)(v,0),LS_SAVE,)
LS_CASE(live,LS_ROW(a),madd_ew_x,,LS_F(mrowgather_ew)(v,i),LS_SAVE,__riscv_ztt_mss_rm(extra,v))
LS_CASE(wrong,LS_ROW(a),madd_ew_x,,LS_F(mcolgather_ew)(v,i),LS_SAVE,)
LS_CASE(partial,a,madd_ew_x,,LS_F(mrowgather_ew)(v,i),LS_SAVE,)
LS_CASE(call,LS_ROW(a),madd_ew_x,ls_callee(),LS_F(mrowgather_ew)(v,i),LS_SAVE,)
LS_CASE(flags,LS_ROW(a),madd_ew_x,__asm__ volatile("csrw amefflags,zero":::"memory"),LS_F(mrowgather_ew)(v,i),LS_SAVE,)
LS_CASE(dynamic,LS_ROW(a),madd_ew_x,,LS_F(mrowbcast_ew_x)(v,k),LS_SAVE,)
LS_CASE(unstored,LS_ROW(a),madd_ew_x,,LS_F(mrowgather_ew)(v,i),,)
LS_CASE(reference,LS_ROW(a),madd_ew_x,,v,LS_SAVE,)
#ifdef __cplusplus
}
#endif
