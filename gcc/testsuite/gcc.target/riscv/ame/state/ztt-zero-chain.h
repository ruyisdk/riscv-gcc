#include <riscv_ztt.h>
#define ZC_T_(D,S) __riscv_ztt_##D##_##S##_t
#define ZC_T(D,S) ZC_T_ (D,S)
#define ZC_F_(OP,D,S) __riscv_ztt_##OP##_##D##_##S
#define ZC_F(OP,D,S) ZC_F_ (OP,D,S)
#define ZC_ROW_(Q) 1x##Q
#define ZC_ROW(Q) ZC_ROW_ (Q)
#define ZC_COL_(Q) Q##x1
#define ZC_COL(Q) ZC_COL_ (Q)
#define ZC_ACC_(Q) accx##Q
#define ZC_ACC(Q) ZC_ACC_ (Q)
#define ZC_M(S) ZC_T (ZC_TYPE,S(ZC_COUNT))
#define ZC_A ZC_T (ZC_TYPE,ZC_ACC(ZC_COUNT))
#define ZC_FROM(V) ZC_F (mcopy_m2a,ZC_TYPE,ZC_ACC(ZC_COUNT)) (V)
#define ZC_TO(S,V) ZC_F (mcopy_a2m,ZC_TYPE,S(ZC_COUNT)) (V)
extern void callee (void);

#define ZC_M_CASE(AX,S,NAME,GAP) \
void m_##AX##_##NAME (ZC_CARRIER *out, volatile int *flag) \
{ \
  ZC_M (S) m = ZC_F (mzero_m,ZC_TYPE,S(ZC_COUNT)) (); \
  ZC_A a = ZC_FROM (m); \
  GAP; \
  ZC_M (S) next = ZC_TO (S,a); \
  ZC_A last = ZC_FROM (next); \
  __riscv_ztt_mss_rm (out,ZC_TO (S,last)); \
}
#define ZC_A_CASE(AX,S,NAME,GAP) \
void a_##AX##_##NAME (ZC_CARRIER *out, volatile int *flag) \
{ \
  ZC_A a = ZC_F (mzero_acc,ZC_TYPE,ZC_ACC(ZC_COUNT)) (); \
  ZC_M (S) m = ZC_TO (S,a); \
  GAP; \
  ZC_A next = ZC_FROM (m); \
  __riscv_ztt_mss_rm (out,ZC_TO (S,next)); \
}
#define ZC_CASES(AX,S) \
  ZC_M_CASE (AX,S,zero,(void)0) \
  ZC_A_CASE (AX,S,zero,(void)0) \
  ZC_M_CASE (AX,S,call,callee ()) \
  ZC_A_CASE (AX,S,call,callee ()) \
  ZC_M_CASE (AX,S,asm,__asm__ volatile ("" ::: "memory")) \
  ZC_A_CASE (AX,S,asm,__asm__ volatile ("" ::: "memory")) \
  ZC_M_CASE (AX,S,memory,*flag = 1) \
  ZC_A_CASE (AX,S,memory,*flag = 1)
ZC_CASES (row,ZC_ROW)
ZC_CASES (col,ZC_COL)
