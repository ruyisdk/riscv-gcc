#include <riscv_ztt.h>
#ifndef UP_TYPE
#define UP_TYPE i32_rnu
#define UP_ALT i32_rod
#define UP_CARRIER __INT32_TYPE__
#endif
#ifndef UP_UNIT
#define UP_UNIT 1x1
#define UP_WHOLE 1x2
#endif
#define T_(D,S) __riscv_ztt_##D##_##S##_t
#define T(D,S) T_ (D,S)
#define F_(OP,D,S) __riscv_ztt_##OP##_##D##_##S
#define F(OP,D,S) F_ (OP,D,S)
#define STORE(P,V) __riscv_ztt_mss_rm (P,V)
#define CASE(OP,D,N,GAP,KEEP) \
__attribute__((noipa)) void up_##OP##_##N \
  (const UP_CARRIER *ia, const UP_CARRIER *ib, \
   UP_CARRIER *out, UP_CARRIER *old_a, UP_CARRIER *old_b) \
{ \
  T (UP_TYPE,UP_UNIT) a = F (mls_rm,UP_TYPE,UP_UNIT) (ia); \
  T (UP_TYPE,UP_UNIT) b = F (mls_rm,UP_TYPE,UP_UNIT) (ib); \
  T (UP_TYPE,UP_WHOLE) p = F (mconcat_m,UP_TYPE,UP_WHOLE) (a,b); \
  GAP; \
  T (D,UP_WHOLE) result = F (OP,D,UP_WHOLE) (p); \
  STORE (out,result); \
  KEEP; \
}
#define GROUP(OP,D) \
  CASE (OP,D,left,(void)0,STORE (old_a,a)) \
  CASE (OP,D,right,(void)0,STORE (old_b,b)) \
  CASE (OP,D,neither,(void)0,(void)0) \
  CASE (OP,D,both,(void)0,STORE (old_a,a); STORE (old_b,b)) \
  CASE (OP,D,call,up_callee (),(void)0) \
  CASE (OP,D,barrier,__asm__ volatile ("# AME boundary" ::: "memory"),(void)0) \
  CASE (OP,D,shared,(void)0,STORE (old_a,p)) \
  CASE (OP,D,memory,STORE (old_a,a),(void)0)
#ifdef __cplusplus
extern "C" {
#endif
extern void up_callee (void);
GROUP (mabs_ew,UP_TYPE)
GROUP (mreduceadd_col,UP_TYPE)
GROUP (mconv_ew,UP_ALT)
#ifdef __cplusplus
}
#endif
