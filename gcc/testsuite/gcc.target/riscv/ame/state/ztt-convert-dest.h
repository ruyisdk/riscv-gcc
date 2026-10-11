#include <riscv_ztt.h>
#ifndef CD_SRC
#define CD_SRC u32_rnu
#define CD_DST u16_rnu
#define CD_ALT u16_rod
#define CD_INPUT __UINT32_TYPE__
#define CD_OUTPUT __UINT16_TYPE__
#endif
#ifndef CD_SHAPE
#define CD_SHAPE 1x1
#endif
#define CD_T_(T,S) __riscv_ztt_##T##_##S##_t
#define CD_T_I(T,S) CD_T_(T,S)
#define CD_T(T) CD_T_I(T,CD_SHAPE)
#define CD_F_(F,T,S) __riscv_ztt_##F##_##T##_##S
#define CD_F_I(F,T,S) CD_F_(F,T,S)
#define CD_F(F,T) CD_F_I(F,T,CD_SHAPE)
#define CD_ARGS const CD_INPUT *in, const CD_INPUT *other, \
  CD_OUTPUT *previous, CD_OUTPUT *out, CD_INPUT *saved, CD_INPUT *saved_other, int control
#ifdef __cplusplus
extern "C" {
#endif
extern void cd_callee (void);
#define CD_CASE(NAME, FIRST, BETWEEN) \
__attribute__((noipa)) void cd_##NAME (CD_ARGS) \
{ \
  CD_T(CD_SRC) a = CD_F(mls_rm,CD_SRC) (in); \
  CD_T(CD_SRC) b = CD_F(mls_rm,CD_SRC) (other); \
  CD_T(FIRST) first = CD_F(mconv_ew,FIRST) (a); \
  __riscv_ztt_mss_rm (previous, first); \
  BETWEEN; \
  CD_T(CD_DST) second = CD_F(mconv_ew,CD_DST) (b); \
  __riscv_ztt_mss_rm (out, second); \
  __riscv_ztt_mss_rm (saved, a); \
  __riscv_ztt_mss_rm (saved_other, b); \
}
CD_CASE(repeat, CD_DST, )
CD_CASE(changed, CD_ALT, )
CD_CASE(call, CD_DST, cd_callee ())
CD_CASE(barrier, CD_DST, __asm__ volatile ("" ::: "memory"))
CD_CASE(join, CD_DST, if (control & 1) cd_callee ())
__attribute__((noipa)) void cd_unknown (CD_ARGS)
{
  CD_T(CD_SRC) a = CD_F(mls_rm,CD_SRC) (in);
  CD_T(CD_DST) b = CD_F(mconv_ew,CD_DST) (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (saved, a);
}
#ifdef __cplusplus
}
#endif
