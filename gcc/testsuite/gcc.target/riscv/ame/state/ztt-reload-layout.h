#include <riscv_ztt.h>
#ifndef RL_TYPE
#define RL_TYPE i32_rnu
#define RL_ELEMENT __INT32_TYPE__
#endif
#define RL_T_(T) __riscv_ztt_##T##_1x1_t
#define RL_T(T) RL_T_(T)
#define RL_F_(F,T) __riscv_ztt_##F##_##T##_1x1
#define RL_FN(F,T) RL_F_(F,T)
#define RL_F(F) RL_FN(F,RL_TYPE)
#define RL_ARGS const RL_ELEMENT *in, RL_ELEMENT *out, RL_ELEMENT *saved, \
                __INT32_TYPE__ control, int flag
#define RL_CASE(NAME,EXPR,BETWEEN,AFTER) \
__attribute__((noipa)) void rl_##NAME (RL_ARGS) \
{ \
  RL_T(RL_TYPE) a = RL_F(mls_rm) (in); \
  BETWEEN; \
  RL_T(RL_TYPE) b = EXPR; \
  __riscv_ztt_mss_rm (out, b); \
  AFTER; \
}
#ifdef __cplusplus
extern "C" {
#endif
extern void rl_callee (void);
extern volatile unsigned long rl_observed;
__attribute__((noipa)) void rl_copy (RL_ARGS)
{
  RL_T(RL_TYPE) a = RL_F(mls_rm) (in);
  rl_callee ();
  RL_T(RL_TYPE) b = RL_F(mcopy_m2m) (a);
  __asm__ volatile ("# AME copy output" : "+Wmr" (b));
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (saved, a);
}
RL_CASE(rowbcast, RL_F(mrowbcast_ew_x) (a, control), rl_callee (), )
RL_CASE(colbcast, RL_F(mcolbcast_ew_x) (a, control), rl_callee (), )
RL_CASE(rowshift, RL_F(mrowshift_ew_x) (a, control), rl_callee (), )
RL_CASE(colshift, RL_F(mcolshift_ew_x) (a, control), rl_callee (), )
RL_CASE(live, RL_F(mrowshift_ew_x) (a, control), rl_callee (), __riscv_ztt_mss_rm (saved, a))
RL_CASE(ready, RL_F(mrowshift_ew_x) (a, control), , )
RL_CASE(barrier, RL_F(mrowshift_ew_x) (a, control), rl_callee (); \
  __asm__ volatile ("# AME observer" : "+Wmr" (a) : : "memory"), )
RL_CASE(query, RL_F(mrowshift_ew_x) (a, control), rl_callee (); \
  __asm__ volatile ("csrr %0,ameown" : "=r" (rl_observed), "+Wmr" (a) : : "memory"), )
RL_CASE(join, RL_F(mcolshift_ew_x) (a, control), if (flag) rl_callee (), )
#ifdef __cplusplus
}
#endif
