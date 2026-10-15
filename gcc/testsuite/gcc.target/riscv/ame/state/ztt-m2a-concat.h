#include <riscv_ztt.h>
#ifndef MC_TYPE
#define MC_TYPE i32_rnu
#define MC_CARRIER __INT32_TYPE__
#endif
#ifndef MC_HALF
#define MC_HALF 1
#define MC_WHOLE 2
#endif
#define ROW_(Q) 1x##Q
#define ROW(Q) ROW_ (Q)
#define COL_(Q) Q##x1
#define COL(Q) COL_ (Q)
#define ACC_(Q) accx##Q
#define ACC(Q) ACC_ (Q)
#define T_(D,S) __riscv_ztt_##D##_##S##_t
#define T(D,S) T_ (D,S)
#define F_(OP,D,S) __riscv_ztt_##OP##_##D##_##S
#define F(OP,D,S) F_ (OP,D,S)
#define STORE(P,V) __riscv_ztt_mss_rm (P,V)
#define CASE(AXIS,N,SHAPE,TO,FROM,GAP,AFTER,KEEP) \
__attribute__((noipa)) void mc_##AXIS##_##N \
  (const void *ia, const void *ib, void *output, void *save_a, void *save_b) \
{ \
  MC_CARRIER *out = (MC_CARRIER *) output; \
  MC_CARRIER *saved_a = (MC_CARRIER *) save_a; \
  MC_CARRIER *saved_b = (MC_CARRIER *) save_b; \
  T (MC_TYPE,SHAPE(MC_HALF)) a = F (mls_rm,MC_TYPE,SHAPE(MC_HALF)) ((const MC_CARRIER *) ia); \
  T (MC_TYPE,SHAPE(MC_HALF)) b = F (mls_rm,MC_TYPE,SHAPE(MC_HALF)) ((const MC_CARRIER *) ib); \
  T (MC_TYPE,SHAPE(MC_WHOLE)) p = F (mconcat_m,MC_TYPE,SHAPE(MC_WHOLE)) (a,b); \
  GAP; \
  T (MC_TYPE,ACC(MC_WHOLE)) v = F (mcopy_m2a,MC_TYPE,ACC(MC_WHOLE)) (p); \
  AFTER; \
  STORE (out,F (mcopy_a2m,MC_TYPE,SHAPE(MC_WHOLE)) (v)); \
  KEEP; \
}
#define GROUP(AXIS,SHAPE,TO,FROM) \
  CASE (AXIS,left,SHAPE,TO,FROM,(void)0,(void)0,STORE (saved_a,a)) \
  CASE (AXIS,right,SHAPE,TO,FROM,(void)0,(void)0,STORE (saved_b,b)) \
  CASE (AXIS,neither,SHAPE,TO,FROM,(void)0,(void)0,(void)0) \
  CASE (AXIS,both,SHAPE,TO,FROM,(void)0,(void)0,STORE (saved_a,a); STORE (saved_b,b)) \
  CASE (AXIS,call,SHAPE,TO,FROM,mc_callee (),(void)0,(void)0) \
  CASE (AXIS,barrier,SHAPE,TO,FROM,__asm__ volatile ("# AME boundary" ::: "memory"),(void)0,(void)0) \
  CASE (AXIS,shared,SHAPE,TO,FROM,(void)0,(void)0,STORE (saved_a,p)) \
  CASE (AXIS,memory,SHAPE,TO,FROM,STORE (saved_a,a),(void)0,(void)0) \
  CASE (AXIS,acc_call,SHAPE,TO,FROM,(void)0,mc_callee (),STORE (saved_a,a); STORE (saved_b,b)) \
  CASE (AXIS,acc_live,SHAPE,TO,FROM,(void)0,STORE (saved_b,F (mcopy_a2m,MC_TYPE,SHAPE(MC_WHOLE)) (v)); mc_callee (),(void)0)
#ifdef __cplusplus
extern "C" {
#endif
extern void mc_callee (void);
GROUP (row,ROW,mcopy_m2a,mcopy_a2m)
GROUP (col,COL,mcopy_m2a_col,mcopy_a2m_col)
#ifdef __cplusplus
}
#endif
