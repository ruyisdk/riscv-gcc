#include <riscv_ztt.h>
#ifndef LC_TYPE
#define LC_TYPE i32_rnu_sat
#define LC_ELEMENT __INT32_TYPE__
#endif
#define LC_T_(T) __riscv_ztt_##T##_1x1_t
#define LC_T(T) LC_T_(T)
#define LC_F_(F,T) __riscv_ztt_##F##_##T##_1x1
#define LC_EXPAND(F,T) LC_F_(F,T)
#define LC_F(F) LC_EXPAND(F,LC_TYPE)
#define LC_ARGS unsigned long k, const LC_ELEMENT *input, const LC_ELEMENT *other, \
  const __INT32_TYPE__ *index, LC_ELEMENT *out, LC_ELEMENT *extra, __INT32_TYPE__ *saved
#define LC_LOAD \
  __riscv_ztt_i32_rnu_1x1_t i=__riscv_ztt_mls_rm_i32_rnu_1x1(index); \
  LC_T(LC_TYPE) a=LC_F(mls_rm)(input), b=LC_F(mls_rm)(other)
#define LC_ROW(V) LC_F(mrowbcast_ew_x)(V,k)
#define LC_COL(V) LC_F(mcolbcast_ew_x)(V,k)
#define LC_STORE(V) __riscv_ztt_mss_rm(out,V)
#define LC_SAVE __riscv_ztt_mss_rm(saved,i)
#define LC_CASE(NAME,LEFT,RIGHT,OP,GAP,VALUE,SAVE,AFTER) \
void lc_##NAME(LC_ARGS) \
{ LC_LOAD; LC_T(LC_TYPE) l=LEFT, r=RIGHT, v=LC_F(OP)(l,r); \
  GAP; LC_STORE(VALUE); SAVE; AFTER; }
#ifdef __cplusplus
extern "C" {
#endif
extern void lc_callee(void);
LC_CASE(row,LC_ROW(a),LC_ROW(b),madd_ew,,LC_F(mrowgather_ew)(v,i),LC_SAVE,)
LC_CASE(col,LC_COL(a),LC_COL(b),mmul_ew,,LC_F(mcolgather_ew)(v,i),LC_SAVE,)
LC_CASE(sub,LC_ROW(a),LC_ROW(b),msub_ew,,LC_F(mrowgather_ew)(v,i),LC_SAVE,)
LC_CASE(bcast,LC_ROW(a),LC_ROW(b),madd_ew,,LC_F(mrowbcast_ew_x)(v,0),LC_SAVE,)
LC_CASE(live,LC_ROW(a),LC_ROW(b),madd_ew,,LC_F(mrowgather_ew)(v,i),LC_SAVE,__riscv_ztt_mss_rm(extra,v))
LC_CASE(wrong,LC_ROW(a),LC_ROW(b),madd_ew,,LC_F(mcolgather_ew)(v,i),LC_SAVE,)
LC_CASE(partial,LC_ROW(a),b,madd_ew,,LC_F(mrowgather_ew)(v,i),LC_SAVE,)
LC_CASE(call,LC_ROW(a),LC_ROW(b),madd_ew,lc_callee(),LC_F(mrowgather_ew)(v,i),LC_SAVE,)
LC_CASE(flags,LC_ROW(a),LC_ROW(b),madd_ew,__asm__ volatile("csrw amefflags,zero":::"memory"),LC_F(mrowgather_ew)(v,i),LC_SAVE,)
LC_CASE(dynamic,LC_ROW(a),LC_ROW(b),madd_ew,,LC_F(mrowbcast_ew_x)(v,k),LC_SAVE,)
LC_CASE(unstored,LC_ROW(a),LC_ROW(b),madd_ew,,LC_F(mrowgather_ew)(v,i),,)
LC_CASE(reference,LC_ROW(a),LC_ROW(b),madd_ew,,v,LC_SAVE,)
#ifdef __cplusplus
}
#endif
