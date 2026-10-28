#include <riscv_ztt.h>
#ifndef UL_SOURCE
#define UL_SOURCE i64_rnu
#define UL_INPUT __INT64_TYPE__
#define UL_DEST i32_rnu
#define UL_OUTPUT __INT32_TYPE__
#endif
#define UL_TYPE_(T) __riscv_ztt_##T##_1x1_t
#define UL_T(T) UL_TYPE_(T)
#define UL_NAME_(F,T) __riscv_ztt_##F##_##T##_1x1
#define UL_NAME(F,T) UL_NAME_(F,T)
#define UL_ARGS unsigned long k, const UL_INPUT *input, const __INT32_TYPE__ *index, \
  UL_OUTPUT *out, UL_OUTPUT *extra, __INT32_TYPE__ *saved
#define UL_INDEX __riscv_ztt_i32_rnu_1x1_t i = __riscv_ztt_mls_rm_i32_rnu_1x1(index)
#define UL_LOAD UL_T(UL_SOURCE) a = UL_NAME(mls_rm,UL_SOURCE)(input)
#define UL_ROW UL_NAME(mrowbcast_ew_x,UL_SOURCE)(a,k)
#define UL_COL UL_NAME(mcolbcast_ew_x,UL_SOURCE)(a,k)
#define UL_CONV(F,V) UL_T(UL_DEST) b = UL_NAME(F,UL_DEST)(V)
#define UL_STORE(V) __riscv_ztt_mss_rm(out,V)
#define UL_SAVE __riscv_ztt_mss_rm(saved,i)
#define UL_CASE(NAME,ROOT,OP,GAP,CONSUMER,AFTER) \
void ul_##NAME(UL_ARGS) \
{ UL_INDEX; UL_LOAD; UL_T(UL_SOURCE) root=ROOT; UL_CONV(OP,root); GAP; \
  UL_STORE(UL_NAME(CONSUMER,UL_DEST)(b,i)); UL_SAVE; AFTER; }
#ifdef __cplusplus
extern "C" {
#endif
extern void ul_callee(void);
extern volatile unsigned long ul_observed;
UL_CASE(row,UL_ROW,mconv_ew,,mrowgather_ew,)
UL_CASE(col,UL_COL,mconv_ew,,mcolgather_ew,)
UL_CASE(abs,UL_ROW,mabs_ew,,mrowgather_ew,)
UL_CASE(reduce,UL_NAME(mreducemax_col,UL_SOURCE)(a),mconv_ew,,mrowgather_ew,)
UL_CASE(live,UL_ROW,mconv_ew,,mrowgather_ew,__riscv_ztt_mss_rm(extra,b))
UL_CASE(after_call,UL_COL,mconv_ew,,mcolgather_ew,ul_callee();__riscv_ztt_mss_rm(extra,b))
UL_CASE(wrong,UL_ROW,mconv_ew,,mcolgather_ew,)
UL_CASE(call,UL_ROW,mconv_ew,ul_callee(),mrowgather_ew,)
UL_CASE(asm,UL_COL,mconv_ew,__asm__ volatile("":::"memory"),mcolgather_ew,)
UL_CASE(memory,UL_ROW,mconv_ew,ul_observed=k,mrowgather_ew,)
UL_CASE(plain,a,mconv_ew,,mrowgather_ew,)
void ul_bcast(UL_ARGS)
{ UL_INDEX; UL_LOAD; UL_CONV(mconv_ew,UL_ROW);
  UL_STORE(UL_NAME(mrowbcast_ew_x,UL_DEST)(b,0)); UL_SAVE; }
void ul_dynamic(UL_ARGS)
{ UL_INDEX; UL_LOAD; UL_CONV(mconv_ew,UL_ROW);
  UL_STORE(UL_NAME(mrowbcast_ew_x,UL_DEST)(b,k)); UL_SAVE; }
void ul_unstored(UL_ARGS)
{ UL_INDEX; UL_LOAD; UL_CONV(mconv_ew,UL_ROW);
  UL_STORE(UL_NAME(mrowgather_ew,UL_DEST)(b,i)); }
void ul_reference(UL_ARGS)
{ UL_INDEX; UL_LOAD; UL_CONV(mconv_ew,UL_ROW); UL_STORE(b); UL_SAVE; }
#ifdef __cplusplus
}
#endif
