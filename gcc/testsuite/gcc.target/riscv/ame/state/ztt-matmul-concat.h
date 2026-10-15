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
#define BC_HALF 1
#define BC_WHOLE 2
#endif
#define ROW_(Q) 1x##Q
#define ROW(Q) ROW_ (Q)
#define COL_(Q) Q##x1
#define COL(Q) COL_ (Q)
#define T_(D,S) __riscv_ztt_##D##_##S##_t
#define T(D,S) T_ (D,S)
#define F_(OP,D,S) __riscv_ztt_##OP##_##D##_##S
#define F(OP,D,S) F_ (OP,D,S)
#define STORE(P,V) __riscv_ztt_mss_rm (P,V)
#define CASE(OP,N,AXIS,QAXIS,EXPR,GAP,KEEP) \
__attribute__((noipa)) void bc_##OP##_##N \
  (const BC_CARRIER *ia, const BC_CARRIER *ib, \
   const BC_OTHER_CARRIER *iq, const BC_CARRIER *initial, \
   BC_CARRIER *out, BC_CARRIER *saved_a, BC_CARRIER *saved_b) \
{ \
  T (BC_TYPE,accx4) old = F (mcopy_m2a,BC_TYPE,accx4) \
    (F (mls_rm,BC_TYPE,1x4) (initial)); \
  T (BC_TYPE,AXIS(BC_HALF)) a = F (mls_rm,BC_TYPE,AXIS(BC_HALF)) (ia); \
  T (BC_TYPE,AXIS(BC_HALF)) b = F (mls_rm,BC_TYPE,AXIS(BC_HALF)) (ib); \
  T (BC_OTHER,QAXIS(BC_WHOLE)) q = F (mls_rm,BC_OTHER,QAXIS(BC_WHOLE)) (iq); \
  T (BC_TYPE,AXIS(BC_WHOLE)) p = F (mconcat_m,BC_TYPE,AXIS(BC_WHOLE)) (a,b); \
  GAP; \
  T (BC_TYPE,accx4) result = EXPR; \
  STORE (out,F (mcopy_a2m,BC_TYPE,1x4) (result)); \
  KEEP; \
}
#define GROUP(OP,AXIS,QAXIS,EXPR) \
  CASE (OP,left,AXIS,QAXIS,EXPR,(void)0,STORE (saved_a,a)) \
  CASE (OP,right,AXIS,QAXIS,EXPR,(void)0,STORE (saved_b,b)) \
  CASE (OP,neither,AXIS,QAXIS,EXPR,(void)0,(void)0) \
  CASE (OP,both,AXIS,QAXIS,EXPR,(void)0,STORE (saved_a,a); STORE (saved_b,b)) \
  CASE (OP,call,AXIS,QAXIS,EXPR,bc_callee (),(void)0) \
  CASE (OP,barrier,AXIS,QAXIS,EXPR,__asm__ volatile ("# AME boundary" ::: "memory"),(void)0) \
  CASE (OP,shared,AXIS,QAXIS,EXPR,(void)0,STORE (saved_a,p)) \
  CASE (OP,memory,AXIS,QAXIS,EXPR,STORE (saved_a,a),(void)0)
#ifdef __cplusplus
extern "C" {
#endif
extern void bc_callee (void);
GROUP (normal_l,ROW,COL,F (mmulacc_2d,BC_TYPE,accx4) (old,p,q))
GROUP (normal_r,COL,ROW,F (mmulaccneg_2d,BC_TYPE,accx4) (old,q,p))
GROUP (at_l,ROW,ROW,F (mmulatacc_2d,BC_TYPE,accx4) (old,p,q))
GROUP (bt_r,ROW,ROW,F (mmulbtaccneg_2d,BC_TYPE,accx4) (old,q,p))
#ifdef __cplusplus
}
#endif
