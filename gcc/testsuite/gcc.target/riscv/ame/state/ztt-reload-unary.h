#include <riscv_ztt.h>
#ifndef RU_SRC
#define RU_SRC i32_rnu
#define RU_DST i16_rnu
#define RU_INPUT __INT32_TYPE__
#define RU_OUTPUT __INT16_TYPE__
#endif
#ifndef RU_SHAPE
#define RU_SHAPE 1x1
#endif
#define RU_T_(T,S) __riscv_ztt_##T##_##S##_t
#define RU_T_I(T,S) RU_T_(T,S)
#define RU_T(T) RU_T_I(T,RU_SHAPE)
#define RU_F_(F,T,S) __riscv_ztt_##F##_##T##_##S
#define RU_F_I(F,T,S) RU_F_(F,T,S)
#define RU_F(F,T) RU_F_I(F,T,RU_SHAPE)
#define RU_ARGS const RU_INPUT *in, RU_INPUT *out, RU_OUTPUT *converted, \
                RU_INPUT *saved, int flag
#define RU_CASE(NAME,OP,BETWEEN,AFTER) \
__attribute__((noipa)) void ru_##NAME (RU_ARGS) \
{ \
  RU_T(RU_SRC) a = RU_F(mls_rm,RU_SRC) (in); \
  BETWEEN; \
  RU_T(RU_SRC) b = RU_F(OP,RU_SRC) (a); \
  __riscv_ztt_mss_rm (out, b); \
  AFTER; \
}
#ifdef __cplusplus
extern "C" {
#endif
extern void ru_callee (void);
extern volatile unsigned long ru_observed;
RU_CASE(abs, mabs_ew, ru_callee (), )
RU_CASE(reduce, mreducemax_row, ru_callee (), )
RU_CASE(prefix, mprefixmax_col, ru_callee (), )
RU_CASE(live, mabs_ew, ru_callee (), __riscv_ztt_mss_rm (saved, a))
RU_CASE(ready, mabs_ew, , )
RU_CASE(barrier, mabs_ew, ru_callee (); __asm__ volatile ("# AME observer" : "+Wmr" (a) : : "memory"), )
RU_CASE(query, mabs_ew, ru_callee (); \
  __asm__ volatile ("csrr %0,ameown" : "=r" (ru_observed), "+Wmr" (a) : : "memory"), )
#define RU_CONVERT(NAME,BETWEEN) \
__attribute__((noipa)) void ru_##NAME (RU_ARGS) \
{ \
  RU_T(RU_SRC) a = RU_F(mls_rm,RU_SRC) (in); \
  BETWEEN; \
  RU_T(RU_DST) b = RU_F(mconv_ew,RU_DST) (a); \
  __riscv_ztt_mss_rm (converted, b); \
}
RU_CONVERT(convert, ru_callee ())
RU_CONVERT(join, if (flag) ru_callee ())
#ifdef __cplusplus
}
#endif
