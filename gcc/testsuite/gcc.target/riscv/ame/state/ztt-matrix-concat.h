#include <riscv_ztt.h>
#ifndef BC_TYPE
#define BC_TYPE i32_rnu
#define BC_CARRIER __INT32_TYPE__
#endif
#ifndef BC_OTHER
#define BC_OTHER BC_TYPE
#define BC_OTHER_CARRIER BC_CARRIER
#endif
#ifndef BC_HALF
#define BC_HALF 1x1
#define BC_WHOLE 1x2
#endif
#define T_(D,S) __riscv_ztt_##D##_##S##_t
#define T(D,S) T_ (D,S)
#define F_(OP,D,S) __riscv_ztt_##OP##_##D##_##S
#define F(OP,D,S) F_ (OP,D,S)
#define STORE(P,V) __riscv_ztt_mss_rm (P,V)
#define CASE(OP,N,INIT,EXPR,GAP,KEEP) \
__attribute__((noipa)) void bc_##OP##_##N \
  (const BC_CARRIER *ia, const BC_CARRIER *ib, \
   const BC_OTHER_CARRIER *iq, const BC_CARRIER *initial, \
   BC_CARRIER *out, BC_CARRIER *saved_a, BC_CARRIER *saved_b) \
{ \
  T (BC_TYPE,BC_HALF) a = F (mls_rm,BC_TYPE,BC_HALF) (ia); \
  T (BC_TYPE,BC_HALF) b = F (mls_rm,BC_TYPE,BC_HALF) (ib); \
  T (BC_OTHER,BC_WHOLE) q = F (mls_rm,BC_OTHER,BC_WHOLE) (iq); \
  INIT; \
  T (BC_TYPE,BC_WHOLE) p = F (mconcat_m,BC_TYPE,BC_WHOLE) (a,b); \
  GAP; \
  T (BC_TYPE,BC_WHOLE) result = EXPR; \
  STORE (out,result); \
  KEEP; \
}
#define GROUP(OP,INIT,EXPR) \
  CASE (OP,left,INIT,EXPR,(void)0,STORE (saved_a,a)) \
  CASE (OP,right,INIT,EXPR,(void)0,STORE (saved_b,b)) \
  CASE (OP,neither,INIT,EXPR,(void)0,(void)0) \
  CASE (OP,both,INIT,EXPR,(void)0,STORE (saved_a,a); STORE (saved_b,b)) \
  CASE (OP,call,INIT,EXPR,bc_callee (),(void)0) \
  CASE (OP,barrier,INIT,EXPR,__asm__ volatile ("# AME boundary" ::: "memory"),(void)0) \
  CASE (OP,shared,INIT,EXPR,(void)0,STORE (saved_a,p)) \
  CASE (OP,memory,INIT,EXPR,STORE (saved_a,a),(void)0)
#ifdef __cplusplus
extern "C" {
#endif
extern void bc_callee (void);
GROUP (sub_l,(void)0,F (msub_ew,BC_TYPE,BC_WHOLE) (p,q))
GROUP (sub_r,(void)0,F (msub_ew,BC_TYPE,BC_WHOLE) (q,p))
GROUP (acc_l,T (BC_TYPE,BC_WHOLE) old = F (mls_rm,BC_TYPE,BC_WHOLE) (initial),
       F (mmulacc_ew,BC_TYPE,BC_WHOLE) (old,p,q))
GROUP (acc_r,T (BC_TYPE,BC_WHOLE) old = F (mls_rm,BC_TYPE,BC_WHOLE) (initial),
       F (mmulacc_ew,BC_TYPE,BC_WHOLE) (old,q,p))
#ifdef __cplusplus
}
#endif
