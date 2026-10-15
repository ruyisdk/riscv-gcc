#include <riscv_ztt.h>

#ifndef ZP_TYPE
#define ZP_TYPE i32_rnu
#define ZP_CARRIER __INT32_TYPE__
#endif
#define ZP_NAME_(OP,T,S) __riscv_ztt_##OP##_##T##_##S
#define ZP_NAME(OP,T,S) ZP_NAME_ (OP,T,S)
#define ZP_TYPE_(T,S) __riscv_ztt_##T##_##S##_t
#define ZP_T(T,S) ZP_TYPE_ (T,S)
#define ZP_LOAD(P) ZP_NAME (mls_rm,ZP_TYPE,1x1) (P)
#define ZP_STORE(P,V) __riscv_ztt_mss_rm (P,V)
#define ZP_CASE(OP,N,GAP,KEEP) \
void __attribute__((noipa)) zp_##OP##_##N \
  (const ZP_CARRIER *ia, const ZP_CARRIER *ib, ZP_CARRIER *out, \
   ZP_CARRIER *old_a, ZP_CARRIER *old_b) \
{ \
  ZP_T (ZP_TYPE,1x1) a = ZP_LOAD (ia); \
  ZP_T (ZP_TYPE,1x1) b = ZP_LOAD (ib); \
  ZP_T (ZP_TYPE,1x2) p = ZP_NAME (mconcat_m,ZP_TYPE,1x2) (a,b); \
  GAP; \
  p = ZP_NAME (OP,ZP_TYPE,1x2) (p); \
  ZP_STORE (out,p); \
  KEEP; \
}
#define ZP_FAMILY(OP) \
  ZP_CASE (OP,left,(void)0,ZP_STORE (old_a,a)) \
  ZP_CASE (OP,right,(void)0,ZP_STORE (old_b,b)) \
  ZP_CASE (OP,neither,(void)0,(void)0) \
  ZP_CASE (OP,both,(void)0,ZP_STORE (old_a,a); ZP_STORE (old_b,b)) \
  ZP_CASE (OP,call,zp_callee (),(void)0) \
  ZP_CASE (OP,barrier,__asm__ volatile ("# AME boundary" ::: "memory"),(void)0)
#ifdef __cplusplus
extern "C" {
#endif
extern void zp_callee (void);
ZP_FAMILY (mcolzip_ew)
ZP_FAMILY (mrowzip_ew)
ZP_FAMILY (mcolunzip_ew)
ZP_FAMILY (mrowunzip_ew)
#ifdef __cplusplus
}
#endif
