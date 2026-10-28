#include <riscv_ztt.h>
#ifndef FU_SOURCE
#define FU_SOURCE f32_rne
#define FU_INPUT float
#define FU_DEST f32_rne
#define FU_OUTPUT float
#endif
#define FU_T_(T) __riscv_ztt_##T##_1x1_t
#define FU_T(T) FU_T_(T)
#define FU_F_(F,T) __riscv_ztt_##F##_##T##_1x1
#define FU_EXPAND(F,T) FU_F_(F,T)
#define FU_S(F) FU_EXPAND(F,FU_SOURCE)
#define FU_D(F) FU_EXPAND(F,FU_DEST)
#define FU_ARGS unsigned long k, const FU_INPUT *input, const __INT32_TYPE__ *index, \
  FU_OUTPUT *out, FU_OUTPUT *extra, __INT32_TYPE__ *saved
#define FU_LOAD \
  __riscv_ztt_i32_rnu_1x1_t i=__riscv_ztt_mls_rm_i32_rnu_1x1(index); \
  FU_T(FU_SOURCE) a=FU_S(mls_rm)(input)
#define FU_ROW FU_S(mrowbcast_ew_x)(a,k)
#define FU_COL FU_S(mcolbcast_ew_x)(a,k)
#define FU_STORE(V) __riscv_ztt_mss_rm(out,V)
#define FU_SAVE __riscv_ztt_mss_rm(saved,i)
#define FU_CASE(NAME,SOURCE,OP,GAP,VALUE,SAVE,AFTER) \
void fu_##NAME(FU_ARGS) \
{ FU_LOAD; FU_T(FU_SOURCE) b=SOURCE; FU_T(FU_DEST) v=FU_D(OP)(b); \
  GAP; FU_STORE(VALUE); SAVE; AFTER; }
#ifdef __cplusplus
extern "C" {
#endif
extern void fu_callee(void);
extern volatile unsigned long fu_observed;
FU_CASE(frintm,FU_ROW,mfrintm_ew,,FU_D(mrowgather_ew)(v,i),FU_SAVE,)
FU_CASE(frintn,FU_COL,mfrintn_ew,,FU_D(mcolgather_ew)(v,i),FU_SAVE,)
FU_CASE(frintp,FU_ROW,mfrintp_ew,,FU_D(mrowgather_ew)(v,i),FU_SAVE,)
FU_CASE(frintz,FU_COL,mfrintz_ew,,FU_D(mcolgather_ew)(v,i),FU_SAVE,)
FU_CASE(exp2,FU_ROW,mexp2_ew,,FU_D(mrowgather_ew)(v,i),FU_SAVE,)
FU_CASE(log2,FU_COL,mlog2_ew,,FU_D(mcolgather_ew)(v,i),FU_SAVE,)
FU_CASE(cos,FU_ROW,mcos_ew,,FU_D(mrowgather_ew)(v,i),FU_SAVE,)
FU_CASE(sin,FU_COL,msin_ew,,FU_D(mcolgather_ew)(v,i),FU_SAVE,)
FU_CASE(tanh,FU_ROW,mtanh_ew,,FU_D(mrowgather_ew)(v,i),FU_SAVE,)
FU_CASE(rec,FU_COL,mrec_ew,,FU_D(mcolgather_ew)(v,i),FU_SAVE,)
FU_CASE(rsqrt,FU_ROW,mrsqrt_ew,,FU_D(mrowgather_ew)(v,i),FU_SAVE,)
FU_CASE(sqrt,FU_COL,msqrt_ew,,FU_D(mcolgather_ew)(v,i),FU_SAVE,)
FU_CASE(bcastrow,FU_ROW,msqrt_ew,,FU_D(mrowbcast_ew_x)(v,0),FU_SAVE,)
FU_CASE(bcastcol,FU_COL,mrec_ew,,FU_D(mcolbcast_ew_x)(v,0),FU_SAVE,)
FU_CASE(live,FU_ROW,msqrt_ew,,FU_D(mrowgather_ew)(v,i),FU_SAVE,__riscv_ztt_mss_rm(extra,v))
FU_CASE(raw,a,msqrt_ew,,FU_D(mrowgather_ew)(v,i),FU_SAVE,)
FU_CASE(wrong,FU_ROW,msqrt_ew,,FU_D(mcolgather_ew)(v,i),FU_SAVE,)
FU_CASE(call,FU_ROW,msqrt_ew,fu_callee(),FU_D(mrowgather_ew)(v,i),FU_SAVE,)
FU_CASE(asm,FU_ROW,msqrt_ew,__asm__ volatile("":::"memory"),FU_D(mrowgather_ew)(v,i),FU_SAVE,)
FU_CASE(memory,FU_ROW,msqrt_ew,fu_observed=k,FU_D(mrowgather_ew)(v,i),FU_SAVE,)
FU_CASE(dynamic,FU_ROW,msqrt_ew,,FU_D(mrowbcast_ew_x)(v,k),FU_SAVE,)
FU_CASE(unstored,FU_ROW,msqrt_ew,,FU_D(mrowgather_ew)(v,i),,)
FU_CASE(chain,FU_ROW,msqrt_ew,v=FU_D(mrec_ew)(v),FU_D(mrowgather_ew)(v,i),FU_SAVE,)
FU_CASE(reference,FU_ROW,msqrt_ew,,v,FU_SAVE,)
#ifdef __cplusplus
}
#endif
