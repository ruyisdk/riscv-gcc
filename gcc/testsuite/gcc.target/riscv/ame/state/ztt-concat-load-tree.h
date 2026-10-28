#include <riscv_ztt.h>

#define T(S) __riscv_ztt_i32_rnu_##S##_t
#define F(OP,S) __riscv_ztt_##OP##_i32_rnu_##S
#define JOIN(A,B,C,D) F(mconcat_m,1x4) \
  (F(mconcat_m,1x2) (A,B),F(mconcat_m,1x2) (C,D))
#define STORE(P,V) __riscv_ztt_mss_rm (P,V)
#define LOAD4(P,S) \
  T(1x1) P##0 = F(mls_rm,1x1) (S); \
  T(1x1) P##1 = F(mls_rm,1x1) ((S)+tile); \
  T(1x1) P##2 = F(mls_rm,1x1) ((S)+2*tile); \
  T(1x1) P##3 = F(mls_rm,1x1) ((S)+3*tile)
#define CASE(NAME,GAP,RIGHT,KEEP) \
__attribute__((noipa)) void ct_##NAME \
  (__INT32_TYPE__ *out,__INT32_TYPE__ *saved,const __INT32_TYPE__ *a, \
   const __INT32_TYPE__ *b,__SIZE_TYPE__ tile) \
{ \
  LOAD4(v,a); \
  T(1x4) left = JOIN(v0,v1,v2,v3); \
  GAP; \
  LOAD4(q,b); \
  T(1x4) right = JOIN(q0,q1,q2,q3); \
  RIGHT; \
  STORE(out,F(msub_ew,1x4) (left,right)); \
  KEEP; \
}
#ifdef __cplusplus
extern "C" {
#endif
extern void ct_callee (void);
CASE (plain,(void)0,(void)0,(void)0)
CASE (leaf,(void)0,(void)0,STORE(saved,v0))
CASE (live,(void)0,(void)0,STORE(saved,left))
CASE (right_live,(void)0,(void)0,STORE(saved,right))
CASE (call,ct_callee (),(void)0,(void)0)
CASE (barrier,__asm__ volatile ("# boundary" ::: "memory"),(void)0,(void)0)
CASE (memory,STORE(saved,v0),(void)0,(void)0)
CASE (arithmetic,(void)0,right = F(madd_ew,1x4) (right,right),(void)0)
#ifdef __cplusplus
}
#endif
