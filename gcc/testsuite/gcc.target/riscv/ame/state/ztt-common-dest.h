#include <riscv_ztt.h>
#ifndef ED_SRC
#define ED_SRC u32_rnu
#define ED_DST u16_rnu
#define ED_ALT u16_rod
#define ED_INPUT __UINT32_TYPE__
#define ED_OUTPUT __UINT16_TYPE__
#endif
#ifndef ED_TC
#define ED_TC u32_rnu
#define ED_TC_ALT u32_rod
#define ED_SCALAR unsigned long
#endif
#ifndef ED_SHAPE
#define ED_SHAPE 1x1
#endif
#define ED_T_(T,S) __riscv_ztt_##T##_##S##_t
#define ED_T_I(T,S) ED_T_(T,S)
#define ED_T(T) ED_T_I(T,ED_SHAPE)
#define ED_F_(F,T,S) __riscv_ztt_##F##_##T##_##S
#define ED_F_I(F,T,S) ED_F_(F,T,S)
#define ED_F(F,T) ED_F_I(F,T,ED_SHAPE)
#define ED_X_(T,S,C) __riscv_ztt_mmul_ew_x_##T##_##S##_##C
#define ED_X_I(T,S,C) ED_X_(T,S,C)
#define ED_X(T,C) ED_X_I(T,ED_SHAPE,C)
#define ED_SC_(T) __riscv_ztt_scalar_make_##T
#define ED_SC(T) ED_SC_(T)
#define ED_ARGS const ED_INPUT *in, const ED_INPUT *other, \
  ED_OUTPUT *previous, ED_OUTPUT *out, ED_INPUT *saved, ED_INPUT *saved_other, \
  ED_SCALAR value, int control
#define ED_LOAD ED_T(ED_SRC) a = ED_F(mls_rm,ED_SRC) (in); \
  ED_T(ED_SRC) b = ED_F(mls_rm,ED_SRC) (other)
#define ED_SAVE __riscv_ztt_mss_rm (saved, a); \
  __riscv_ztt_mss_rm (saved_other, b)
#ifdef __cplusplus
extern "C" {
#endif
extern void ed_callee (void);
#define ED_CASE(NAME, FIRST, BETWEEN) \
__attribute__((noipa)) void ed_##NAME (ED_ARGS) \
{ \
  ED_LOAD; \
  ED_T(FIRST) first = ED_F(mmul_ew,FIRST) (a, b); \
  __riscv_ztt_mss_rm (previous, first); \
  BETWEEN; \
  ED_T(ED_DST) second = ED_F(mmul_ew,ED_DST) (b, a); \
  __riscv_ztt_mss_rm (out, second); \
  ED_SAVE; \
}
ED_CASE(matrix, ED_DST, )
ED_CASE(changed, ED_ALT, )
ED_CASE(call, ED_DST, ed_callee ())
ED_CASE(barrier, ED_DST, __asm__ volatile ("" ::: "memory"))
ED_CASE(join, ED_DST, if (control & 1) ed_callee ())
#define ED_SCALAR_CASE(NAME, TC, BETWEEN) \
__attribute__((noipa)) void ed_##NAME (ED_ARGS) \
{ \
  ED_LOAD; \
  ED_T(ED_DST) first = ED_X(ED_DST,ED_TC) (a, ED_SC(ED_TC) (value)); \
  __riscv_ztt_mss_rm (previous, first); \
  BETWEEN; \
  ED_T(ED_DST) second = ED_X(ED_DST,TC) (b, ED_SC(TC) (value)); \
  __riscv_ztt_mss_rm (out, second); \
  ED_SAVE; \
}
ED_SCALAR_CASE(scalar, ED_TC, )
ED_SCALAR_CASE(tc_changed, ED_TC_ALT, )
ED_SCALAR_CASE(scalar_call, ED_TC, ed_callee ())
__attribute__((noipa)) void ed_unknown (ED_ARGS)
{
  ED_LOAD;
  ED_T(ED_DST) d = ED_F(mmul_ew,ED_DST) (a, b);
  __riscv_ztt_mss_rm (out, d);
  ED_SAVE;
}
#ifdef __cplusplus
}
#endif
