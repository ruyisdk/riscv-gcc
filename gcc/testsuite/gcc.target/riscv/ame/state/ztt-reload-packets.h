#include <riscv_ztt.h>

#ifndef RP_SRC
#define RP_SRC i32_rnu
#define RP_DST i8_rnu
#define RP_INPUT __INT32_TYPE__
#define RP_OUTPUT signed char
#endif
#ifndef RP_SHAPE
#define RP_SHAPE 1x4
#endif
#define RP_T_(T,S) __riscv_ztt_##T##_##S##_t
#define RP_T_I(T,S) RP_T_(T,S)
#define RP_T(T) RP_T_I(T,RP_SHAPE)
#define RP_F_(F,T,S) __riscv_ztt_##F##_##T##_##S
#define RP_F_I(F,T,S) RP_F_(F,T,S)
#define RP_F(F,T) RP_F_I(F,T,RP_SHAPE)
#define RP_ARGS const RP_INPUT *in, const RP_OUTPUT *old, RP_OUTPUT *out, \
                RP_INPUT *saved, int flag

#ifdef __cplusplus
extern "C" {
#endif
extern void rp_callee (void);
extern volatile unsigned long rp_observed;

#define RP_CONVERT(NAME,BETWEEN,AFTER) \
__attribute__((noipa)) void rp_##NAME (RP_ARGS) \
{ \
  RP_T(RP_SRC) a = RP_F(mls_rm,RP_SRC) (in); \
  BETWEEN; \
  RP_T(RP_DST) b = RP_F(mconv_ew,RP_DST) (a); \
  __riscv_ztt_mss_rm (out, b); \
  AFTER; \
}
RP_CONVERT (convert, rp_callee (), (void) 0)
RP_CONVERT (live, rp_callee (), __riscv_ztt_mss_rm (saved, a))
RP_CONVERT (ready, (void) 0, (void) 0)
RP_CONVERT (barrier,
  rp_callee (); __asm__ volatile ("# AME observer" : "+Wmr" (a) : : "memory"),
  (void) 0)
RP_CONVERT (query,
  rp_callee (); __asm__ volatile ("csrr %0,ameown"
    : "=r" (rp_observed), "+Wmr" (a) : : "memory"), (void) 0)
RP_CONVERT (join, if (flag) rp_callee (), (void) 0)

__attribute__((noipa)) void rp_shared (RP_ARGS)
{
  RP_T(RP_SRC) a = RP_F(mls_rm,RP_SRC) (in);
  rp_callee ();
  RP_T(RP_DST) b = RP_F(mmul_ew,RP_DST) (a, a);
  __riscv_ztt_mss_rm (out, b);
}

__attribute__((noipa)) void rp_binary (RP_ARGS)
{
  RP_T(RP_SRC) a = RP_F(mls_rm,RP_SRC) (in);
  RP_T(RP_SRC) b = RP_F(mls_rm,RP_SRC) (saved);
  rp_callee ();
  RP_T(RP_DST) d = RP_F(mmul_ew,RP_DST) (a, b);
  __riscv_ztt_mss_rm (out, d);
}

__attribute__((noipa)) void rp_old (RP_ARGS)
{
  RP_T(RP_SRC) a = RP_F(mls_rm,RP_SRC) (in);
  RP_T(RP_DST) b = RP_F(mls_rm,RP_DST) (old);
  rp_callee ();
  b = RP_F(mmulacc_ew,RP_DST) (b, a, a);
  __riscv_ztt_mss_rm (out, b);
}
#ifdef __cplusplus
}
#endif
