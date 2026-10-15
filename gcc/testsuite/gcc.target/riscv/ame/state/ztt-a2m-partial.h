#include <riscv_ztt.h>
#ifndef DP_TYPE
#define DP_TYPE i32_rnu
#define DP_CARRIER __INT32_TYPE__
#define DP_UNIT 1x1
#define DP_WHOLE 1x2
#define DP_ACC accx2
#endif
#define NAME_(OP,T,S) __riscv_ztt_##OP##_##T##_##S
#define NAME(OP,T,S) NAME_ (OP,T,S)
#define TYPE_(T,S) __riscv_ztt_##T##_##S##_t
#define TYPE(T,S) TYPE_ (T,S)
#define CASE(N,PRE,GAP,POST) \
void __attribute__((noipa)) dp_##N \
  (const DP_CARRIER *in, DP_CARRIER *saved, DP_CARRIER *out) \
{ \
  PRE; \
  TYPE (DP_TYPE,DP_ACC) acc = NAME (mzero_acc,DP_TYPE,DP_ACC) (); \
  __asm__ volatile ("" ::: "memory"); \
  GAP; \
  __riscv_ztt_mss_rm (out,NAME (mcopy_a2m,DP_TYPE,DP_WHOLE) (acc)); \
  POST; \
}
#define LOAD TYPE (DP_TYPE,DP_UNIT) a = NAME (mls_rm,DP_TYPE,DP_UNIT) (in)
#define SAVE __riscv_ztt_mss_rm (saved,a)
#ifdef __cplusplus
extern "C" {
#endif
extern void dp_callee (void);
CASE (store,LOAD; SAVE,(void)0,(void)0)
CASE (live,LOAD,(void)0,SAVE)
CASE (unknown,(void)0,(void)0,(void)0)
CASE (call,LOAD; SAVE,dp_callee (),(void)0)
CASE (barrier,LOAD; SAVE,__asm__ volatile ("# AME boundary" ::: "memory"),(void)0)
#ifdef __cplusplus
}
#endif
