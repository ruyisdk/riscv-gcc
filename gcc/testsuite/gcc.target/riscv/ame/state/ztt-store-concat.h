#include <riscv_ztt.h>
#ifndef SC_TYPE
#define SC_TYPE i32_rnu
#define SC_CARRIER __INT32_TYPE__
#endif
#ifndef SC_HALF
#define SC_HALF 1
#define SC_WHOLE 2
#endif
#define ROW_(Q) 1x##Q
#define ROW(Q) ROW_ (Q)
#define T_(D,S) __riscv_ztt_##D##_##S##_t
#define T(D,S) T_ (D,S)
#define F_(OP,D,S) __riscv_ztt_##OP##_##D##_##S
#define F(OP,D,S) F_ (OP,D,S)
#define STORE(P,V) __riscv_ztt_mss_rm (P,V)
#define CASE(OP,N,TRANSFER,GAP,KEEP) \
__attribute__((noipa)) void sc_##OP##_##N \
  (const void *ia, const void *ib, void *output, \
   void *save_a, void *save_b, unsigned long stride) \
{ \
  SC_CARRIER *out = (SC_CARRIER *) output; \
  SC_CARRIER *saved_a = (SC_CARRIER *) save_a; \
  SC_CARRIER *saved_b = (SC_CARRIER *) save_b; \
  T (SC_TYPE,ROW(SC_HALF)) a = F (mls_rm,SC_TYPE,ROW(SC_HALF)) ((const SC_CARRIER *) ia); \
  T (SC_TYPE,ROW(SC_HALF)) b = F (mls_rm,SC_TYPE,ROW(SC_HALF)) ((const SC_CARRIER *) ib); \
  T (SC_TYPE,ROW(SC_WHOLE)) p = F (mconcat_m,SC_TYPE,ROW(SC_WHOLE)) (a,b); \
  GAP; \
  TRANSFER; \
  KEEP; \
}
#define GROUP(OP,TRANSFER) \
  CASE (OP,left,TRANSFER,(void)0,STORE (saved_a,a)) \
  CASE (OP,right,TRANSFER,(void)0,STORE (saved_b,b)) \
  CASE (OP,neither,TRANSFER,(void)0,(void)0) \
  CASE (OP,both,TRANSFER,(void)0,STORE (saved_a,a); STORE (saved_b,b)) \
  CASE (OP,call,TRANSFER,sc_callee (),(void)0) \
  CASE (OP,barrier,TRANSFER,__asm__ volatile ("# AME boundary" ::: "memory"),(void)0) \
  CASE (OP,shared,TRANSFER,(void)0,STORE (saved_a,p)) \
  CASE (OP,memory,TRANSFER,STORE (saved_a,a),(void)0)
#ifdef __cplusplus
extern "C" {
#endif
extern void sc_callee (void);
GROUP (rm,STORE (out,p))
GROUP (cm,__riscv_ztt_mss_cm (out,p))
GROUP (st,__riscv_ztt_mss_st (out,stride,p))
GROUP (tst,__riscv_ztt_mss_tst (out,stride,p))
#ifdef __cplusplus
}
#endif
