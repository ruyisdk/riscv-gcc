#include <riscv_ztt.h>

#ifndef MP_TYPE
#define MP_TYPE i32_rnu
#define MP_CARRIER __INT32_TYPE__
#endif
#define MP_NAME_(OP,T,S) __riscv_ztt_##OP##_##T##_##S
#define MP_NAME(OP,T,S) MP_NAME_ (OP,T,S)
#define MP_T_(T,S) __riscv_ztt_##T##_##S##_t
#define MP_T(T,S) MP_T_ (T,S)
#define LOAD(P) MP_NAME (mls_rm,MP_TYPE,1x1) (P)
#define STORE(P,V) __riscv_ztt_mss_rm (P,V)
/* The post-transfer barrier keeps the whole-group preparation path.  */
#define CASE(N,GAP,KEEP) \
void __attribute__((noipa)) mp_##N \
  (const MP_CARRIER *ia, const MP_CARRIER *ib, MP_CARRIER *out, \
   MP_CARRIER *old_a, MP_CARRIER *old_b) \
{ \
  MP_T (MP_TYPE,1x1) a = LOAD (ia), b = LOAD (ib); \
  MP_T (MP_TYPE,1x2) p = MP_NAME (mconcat_m,MP_TYPE,1x2) (a,b); \
  GAP; \
  MP_T (MP_TYPE,accx2) acc = MP_NAME (mcopy_m2a,MP_TYPE,accx2) (p); \
  __asm__ volatile ("" ::: "memory"); \
  STORE (out,MP_NAME (mcopy_a2m,MP_TYPE,1x2) (acc)); \
  KEEP; \
}
#ifdef __cplusplus
extern "C" {
#endif
extern void mp_callee (void);
CASE (left,(void)0,STORE (old_a,a))
CASE (right,(void)0,STORE (old_b,b))
CASE (neither,(void)0,(void)0)
CASE (both,(void)0,STORE (old_a,a); STORE (old_b,b))
CASE (call,mp_callee (),(void)0)
CASE (barrier,__asm__ volatile ("# AME boundary" ::: "memory"),(void)0)
#ifdef __cplusplus
}
#endif
