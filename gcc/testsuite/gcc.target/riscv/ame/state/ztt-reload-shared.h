#include <riscv_ztt.h>
#ifndef RS_TYPE
#define RS_TYPE i32_rnu
#define RS_ELEMENT __INT32_TYPE__
#endif
#define RS_NAME_(F,T) __riscv_ztt_##F##_##T##_1x1
#define RS_NAME_T(F,T) RS_NAME_(F,T)
#define RS_NAME(F) RS_NAME_T(F,RS_TYPE)
#define RS_T_(T) __riscv_ztt_##T##_1x1_t
#define RS_T(T) RS_T_(T)
typedef RS_T(RS_TYPE) rs_matrix;
#define RS_LOAD(P) RS_NAME(mls_rm) (P)
#define RS_STORE(P,V) RS_NAME(mss_rm) (P,V)
#define RS_ARGS const RS_ELEMENT *in, const RS_ELEMENT *other, RS_ELEMENT *out, RS_ELEMENT *saved, int flag
#define RS_CASE(NAME,LOAD,BEFORE,OP,AFTER,SAVE) \
__attribute__((noipa)) void rs_##NAME (RS_ARGS) \
{ \
  rs_matrix a = RS_LOAD(in); LOAD; BEFORE; \
  rs_matrix z = OP; AFTER; RS_STORE(out,z); SAVE; \
}
#ifdef __cplusplus
extern "C" {
#endif
extern void rs_callee (void);
extern volatile unsigned long rs_observed;
RS_CASE(mul, , rs_callee (), RS_NAME(mmul_ew)(a,a), , )
#ifndef RS_ONLY_MUL
RS_CASE(live, , rs_callee (), RS_NAME(mmul_ew)(a,a), , RS_STORE(saved,a))
RS_CASE(after, , rs_callee (), RS_NAME(mmul_ew)(a,a), rs_callee (), )
RS_CASE(acc, rs_matrix b=RS_LOAD(other), rs_callee (), RS_NAME(mmulacc_ew)(b,a,a), , RS_STORE(saved,a); RS_STORE(saved+1024,b))
RS_CASE(all, , rs_callee (), RS_NAME(mmulacc_ew)(a,a,a), , RS_STORE(saved,a))
RS_CASE(ready, , , RS_NAME(mmul_ew)(a,a), , )
RS_CASE(distinct, rs_matrix b=RS_LOAD(other), rs_callee (), RS_NAME(mmul_ew)(a,b), , )
RS_CASE(barrier, , rs_callee (); __asm__ volatile ("# AME observer" : "+Wmr"(a) : : "memory"), RS_NAME(mmul_ew)(a,a), , )
RS_CASE(query, , rs_callee (); __asm__ volatile ("csrr %0,ameown" : "=r"(rs_observed), "+Wmr"(a) : : "memory"), RS_NAME(mmul_ew)(a,a), , )
RS_CASE(join, , if(flag) rs_callee (), RS_NAME(mmul_ew)(a,a), , )
#endif
#ifdef __cplusplus
}
#endif
