#include <riscv_ztt.h>

#define T_(S) __riscv_ztt_i32_rnu_##S##_t
#define T(S) T_ (S)
#define F_(OP,S) __riscv_ztt_##OP##_i32_rnu_##S
#define F(OP,S) F_ (OP,S)
#define STORE(P,V) __riscv_ztt_mss_rm (P,V)
#define CASE(NAME,GAP,POST,KEEP) \
__attribute__((noipa)) void packed_##NAME \
  (const __INT32_TYPE__ *ia, const __INT32_TYPE__ *ib, \
   const __INT32_TYPE__ *ic, const __INT32_TYPE__ *id, \
   __INT8_TYPE__ *out, __INT32_TYPE__ *saved) \
{ \
  T (1x1) a = F (mls_rm,1x1) (ia); \
  T (1x1) b = F (mls_rm,1x1) (ib); \
  T (1x1) c = F (mls_rm,1x1) (ic); \
  T (1x1) d = F (mls_rm,1x1) (id); \
  T (1x2) ab = F (mconcat_m,1x2) (a,b); \
  GAP; \
  T (1x2) cd = F (mconcat_m,1x2) (c,d); \
  T (1x4) p = F (mconcat_m,1x4) (ab,cd); \
  POST; \
  __riscv_ztt_i8_rnu_1x4_t z = __riscv_ztt_mconv_ew_i8_rnu_1x4 (p); \
  STORE (out,z); \
  KEEP; \
}

#ifdef __cplusplus
extern "C" {
#endif
extern void packed_callee (void);
CASE (direct,(void)0,(void)0,(void)0)
CASE (leaf,(void)0,(void)0,STORE (saved,a))
CASE (inner,(void)0,(void)0,STORE (saved,ab))
CASE (outer,(void)0,(void)0,STORE (saved,p))
CASE (inner_call,packed_callee (),(void)0,(void)0)
CASE (call,(void)0,packed_callee (),(void)0)
CASE (barrier,(void)0,__asm__ volatile ("" ::: "memory"),(void)0)
CASE (memory,(void)0,STORE (saved,a),(void)0)
#ifdef __cplusplus
}
#endif
