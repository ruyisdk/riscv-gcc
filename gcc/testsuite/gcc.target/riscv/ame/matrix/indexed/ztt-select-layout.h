#include <riscv_ztt.h>
#ifndef LG_TYPE
#define LG_TYPE i32_rnu
#define LG_ELEMENT __INT32_TYPE__
#endif
#define LG_T_(T) __riscv_ztt_##T##_1x1_t
#define LG_T(T) LG_T_(T)
#define LG_F_(F,T) __riscv_ztt_##F##_##T##_1x1
#define LG_EXPAND(F,T) LG_F_(F,T)
#define LG_F(F) LG_EXPAND(F,LG_TYPE)
#define LG_ARGS unsigned long k, const LG_ELEMENT *input, const LG_ELEMENT *other, \
  const LG_ELEMENT *old, const __INT32_TYPE__ *index, LG_ELEMENT *out, \
  LG_ELEMENT *extra, __INT32_TYPE__ *saved
#define LG_LOAD \
  __riscv_ztt_i32_rnu_1x1_t i=__riscv_ztt_mls_rm_i32_rnu_1x1(index); \
  LG_T(LG_TYPE) a=LG_F(mls_rm)(input), b=LG_F(mls_rm)(other), d=LG_F(mls_rm)(old)
#define LG_ROW(V) LG_F(mrowbcast_ew_x)(V,k)
#define LG_COL(V) LG_F(mcolbcast_ew_x)(V,k)
#define LG_STORE(V) __riscv_ztt_mss_rm(out,V)
#define LG_SAVE __riscv_ztt_mss_rm(saved,i)
#define LG_CASE(NAME,LEFT,RIGHT,PREV,EXPR,GAP,VALUE,SAVE,AFTER) \
void lg_##NAME(LG_ARGS) \
{ LG_LOAD; LG_T(LG_TYPE) l=LEFT, r=RIGHT, p=PREV, v=EXPR; \
  GAP; LG_STORE(VALUE); SAVE; AFTER; }
#define LG_BINARY(NAME,OP) \
LG_CASE(NAME,LG_ROW(a),LG_ROW(b),d,LG_F(OP)(l,r),,LG_F(mrowgather_ew)(v,i),LG_SAVE,)
#ifdef __cplusplus
extern "C" {
#endif
extern void lg_callee(void);
LG_BINARY(absdiff,mabsdiff_ew)
LG_BINARY(hdiff,mhdiff_ew)
LG_BINARY(mean,mmean_ew)
LG_BINARY(selge,mselge_ew)
LG_BINARY(sellt,msellt_ew)
#ifndef LG_FLOAT
LG_BINARY(cmpge,mcmpge_ew)
LG_BINARY(cmplt,mcmplt_ew)
#endif
LG_CASE(cmovge,LG_ROW(a),LG_ROW(b),LG_ROW(d),LG_F(mcmovge_ew)(p,l,r),,LG_F(mrowgather_ew)(v,i),LG_SAVE,)
LG_CASE(cmovlt,LG_COL(a),LG_COL(b),LG_COL(d),LG_F(mcmovlt_ew)(p,l,r),,LG_F(mcolgather_ew)(v,i),LG_SAVE,)
LG_CASE(bcast,LG_ROW(a),LG_ROW(b),d,LG_F(mselge_ew)(l,r),,LG_F(mrowbcast_ew_x)(v,0),LG_SAVE,)
LG_CASE(live,LG_ROW(a),LG_ROW(b),LG_ROW(d),LG_F(mcmovge_ew)(p,l,r),,LG_F(mrowgather_ew)(v,i),LG_SAVE,__riscv_ztt_mss_rm(extra,v))
LG_CASE(predicate,a,LG_ROW(b),LG_ROW(d),LG_F(mcmovge_ew)(p,l,r),,LG_F(mrowgather_ew)(v,i),LG_SAVE,)
LG_CASE(data,LG_ROW(a),b,LG_ROW(d),LG_F(mcmovge_ew)(p,l,r),,LG_F(mrowgather_ew)(v,i),LG_SAVE,)
LG_CASE(old,LG_ROW(a),LG_ROW(b),d,LG_F(mcmovge_ew)(p,l,r),,LG_F(mrowgather_ew)(v,i),LG_SAVE,)
LG_CASE(wrong,LG_ROW(a),LG_ROW(b),d,LG_F(mmean_ew)(l,r),,LG_F(mcolgather_ew)(v,i),LG_SAVE,)
LG_CASE(call,LG_ROW(a),LG_ROW(b),d,LG_F(mselge_ew)(l,r),lg_callee(),LG_F(mrowgather_ew)(v,i),LG_SAVE,)
LG_CASE(flags,LG_ROW(a),LG_ROW(b),d,LG_F(mmean_ew)(l,r),__asm__ volatile("csrw amefflags,zero":::"memory"),LG_F(mrowgather_ew)(v,i),LG_SAVE,)
LG_CASE(dynamic,LG_ROW(a),LG_ROW(b),d,LG_F(mselge_ew)(l,r),,LG_F(mrowbcast_ew_x)(v,k),LG_SAVE,)
LG_CASE(unstored,LG_ROW(a),LG_ROW(b),d,LG_F(mmean_ew)(l,r),,LG_F(mrowgather_ew)(v,i),,)
LG_CASE(nested,LG_ROW(a),LG_ROW(b),LG_ROW(d),LG_F(mmean_ew)(LG_F(mselge_ew)(l,r),p),,LG_F(mrowgather_ew)(v,i),LG_SAVE,)
LG_CASE(volatile,LG_ROW(a),LG_ROW(b),d,LG_F(mmean_ew)(l,r),*(volatile LG_ELEMENT *)extra=0,LG_F(mrowgather_ew)(v,i),LG_SAVE,)
LG_CASE(reference,LG_ROW(a),LG_ROW(b),d,LG_F(mmean_ew)(l,r),,v,LG_SAVE,)
#ifdef __cplusplus
}
#endif
