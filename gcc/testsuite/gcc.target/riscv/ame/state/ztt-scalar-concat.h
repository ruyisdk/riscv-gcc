#include <riscv_ztt.h>
#ifndef SC_TYPE
#define SC_TYPE i32_rnu
#define SC_CARRIER __INT32_TYPE__
#endif
#ifndef SC_HALF
#define SC_HALF 1x1
#define SC_WHOLE 1x2
#endif
#define T_(D,S) __riscv_ztt_##D##_##S##_t
#define T(D,S) T_ (D,S)
#define F_(OP,D,S) __riscv_ztt_##OP##_##D##_##S
#define F(OP,D,S) F_ (OP,D,S)
#define X_(OP,D,S) __riscv_ztt_##OP##_##D##_##S##_##D
#define X(OP,D,S) X_ (OP,D,S)
#define SCALAR_(D) __riscv_ztt_scalar_from_bits_##D
#define SCALAR(D) SCALAR_ (D)
#define STORE(P,V) __riscv_ztt_mss_rm (P,V)
#define CASE(OP,N,INIT,EXPR,GAP,KEEP) \
__attribute__((noipa)) void sc_##OP##_##N \
  (const SC_CARRIER *ia, const SC_CARRIER *ib, SC_CARRIER *out, \
   SC_CARRIER *old_a, SC_CARRIER *old_b, const SC_CARRIER *initial, \
   __UINTPTR_TYPE__ bits, long exponent) \
{ \
  __typeof__ (SCALAR (SC_TYPE) (bits)) scalar = SCALAR (SC_TYPE) (bits); \
  T (SC_TYPE,SC_HALF) a = F (mls_rm,SC_TYPE,SC_HALF) (ia); \
  T (SC_TYPE,SC_HALF) b = F (mls_rm,SC_TYPE,SC_HALF) (ib); \
  INIT; \
  T (SC_TYPE,SC_WHOLE) p = F (mconcat_m,SC_TYPE,SC_WHOLE) (a,b); \
  GAP; \
  T (SC_TYPE,SC_WHOLE) result = EXPR; \
  STORE (out,result); \
  KEEP; \
}
#define GROUP(OP,INIT,EXPR) \
  CASE (OP,left,INIT,EXPR,(void)0,STORE (old_a,a)) \
  CASE (OP,right,INIT,EXPR,(void)0,STORE (old_b,b)) \
  CASE (OP,neither,INIT,EXPR,(void)0,(void)0) \
  CASE (OP,both,INIT,EXPR,(void)0,STORE (old_a,a); STORE (old_b,b)) \
  CASE (OP,call,INIT,EXPR,sc_callee (),(void)0) \
  CASE (OP,barrier,INIT,EXPR,__asm__ volatile ("# AME boundary" ::: "memory"),(void)0) \
  CASE (OP,shared,INIT,EXPR,(void)0,STORE (old_a,p)) \
  CASE (OP,memory,INIT,EXPR,STORE (old_a,a),(void)0)
#ifdef __cplusplus
extern "C" {
#endif
extern void sc_callee (void);
GROUP (madd_ew_x,(void)0,X (madd_ew_x,SC_TYPE,SC_WHOLE) (p,scalar))
GROUP (mmul_ew_x,(void)0,X (mmul_ew_x,SC_TYPE,SC_WHOLE) (p,scalar))
GROUP (mmulacc_ew_x,T (SC_TYPE,SC_WHOLE) old = F (mls_rm,SC_TYPE,SC_WHOLE) (initial),
       X (mmulacc_ew_x,SC_TYPE,SC_WHOLE) (old,p,scalar))
GROUP (mldexp_ew_x,(void)0,F (mldexp_ew_x,SC_TYPE,SC_WHOLE) (p,exponent))
#ifdef __cplusplus
}
#endif
