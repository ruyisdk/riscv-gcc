#include <riscv_ztt.h>

#define T_(S) __riscv_ztt_i32_rnu_##S##_t
#define T(S) T_ (S)
#define F_(OP,S) __riscv_ztt_##OP##_i32_rnu_##S
#define F(OP,S) F_ (OP,S)
#define STORE(P,V) __riscv_ztt_mss_rm (P,V)
#define SUB(A,B) F (msub_ew,1x4) (A,B)
#define CASE(NAME,PRE,GAP,POST,EXPR,KEEP) \
__attribute__((noipa)) void nc_##NAME \
  (const __INT32_TYPE__ *ia, const __INT32_TYPE__ *ib, \
   const __INT32_TYPE__ *ic, const __INT32_TYPE__ *id, \
   const __INT32_TYPE__ *iq, __INT32_TYPE__ *out, __INT32_TYPE__ *saved) \
{ \
  T (1x1) a = F (mls_rm,1x1) (ia); \
  T (1x1) b = F (mls_rm,1x1) (ib); \
  T (1x1) c = F (mls_rm,1x1) (ic); \
  T (1x1) d = F (mls_rm,1x1) (id); \
  PRE; \
  T (1x2) ab = F (mconcat_m,1x2) (a,b); \
  GAP; \
  T (1x2) cd = F (mconcat_m,1x2) (c,d); \
  T (1x4) p = F (mconcat_m,1x4) (ab,cd); \
  POST; \
  STORE (out,EXPR); \
  KEEP; \
}
#define Q T (1x4) q = F (mls_rm,1x4) (iq)

#ifdef __cplusplus
extern "C" {
#endif
extern void nc_callee (void);
CASE (left,(void)0,(void)0,Q,SUB (p,q),(void)0)
CASE (right,(void)0,(void)0,Q,SUB (q,p),(void)0)
CASE (before,Q,(void)0,(void)0,SUB (p,q),(void)0)
CASE (leaf,(void)0,(void)0,Q,SUB (p,q),STORE (saved,a))
CASE (inner,(void)0,(void)0,Q,SUB (p,q),STORE (saved,ab))
CASE (outer,(void)0,(void)0,Q,SUB (p,q),STORE (saved,p))
CASE (call,(void)0,(void)0,nc_callee (); Q,SUB (p,q),(void)0)
CASE (inner_call,Q,nc_callee (),(void)0,SUB (p,q),(void)0)
CASE (barrier,(void)0,(void)0,
      __asm__ volatile ("# AME boundary" ::: "memory"); Q,SUB (p,q),(void)0)
CASE (memory,(void)0,(void)0,STORE (saved,a); Q,SUB (p,q),(void)0)
CASE (store,(void)0,(void)0,(void)0,p,(void)0)
CASE (abs,(void)0,(void)0,(void)0,F (mabs_ew,1x4) (p),(void)0)
CASE (scalar,(void)0,(void)0,(void)0,
      __riscv_ztt_madd_ew_x_i32_rnu_1x4_i32_rnu
        (p,__riscv_ztt_scalar_from_bits_i32_rnu (7)),(void)0)
#ifdef __cplusplus
}
#endif
