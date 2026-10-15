#include <riscv_ztt.h>
#ifndef LD_TYPE
#define LD_TYPE u32_rnu
#define LD_ALT u32_rod
#define LD_CARRIER __UINT32_TYPE__
#endif
#ifndef LD_SHAPE
#define LD_SHAPE 1x1
#endif
#define LD_T_(T,S) __riscv_ztt_##T##_##S##_t
#define LD_T_I(T,S) LD_T_(T,S)
#define LD_T(T) LD_T_I(T,LD_SHAPE)
#define LD_F_(T,S) __riscv_ztt_mls_rm_##T##_##S
#define LD_F_I(T,S) LD_F_(T,S)
#define LD_F(T) LD_F_I(T,LD_SHAPE)
#define LD_ARGS const LD_CARRIER *in, const LD_CARRIER *other, \
  LD_CARRIER *previous, LD_CARRIER *out, LD_CARRIER *saved, int control
#ifdef __cplusplus
extern "C" {
#endif
extern void ld_callee (void);
#define LD_CASE(NAME,FIRST,BETWEEN) \
__attribute__((noipa)) void ld_##NAME (LD_ARGS) \
{ \
  LD_T(FIRST) a = LD_F(FIRST) (in); \
  __riscv_ztt_mss_rm (previous,a); \
  BETWEEN; \
  LD_T(LD_TYPE) b = LD_F(LD_TYPE) (other); \
  __riscv_ztt_mss_rm (out,b); \
}
LD_CASE(repeat,LD_TYPE, )
LD_CASE(changed,LD_ALT, )
LD_CASE(call,LD_TYPE,ld_callee ())
LD_CASE(barrier,LD_TYPE,__asm__ volatile ("# AME state boundary" ::: "memory"))
LD_CASE(join,LD_TYPE,if (control) ld_callee ())
__attribute__((noipa)) void ld_live (LD_ARGS)
{
  LD_T(LD_TYPE) a = LD_F(LD_TYPE) (in);
  __riscv_ztt_mss_rm (previous,a);
  LD_T(LD_TYPE) b = LD_F(LD_TYPE) (other);
  __riscv_ztt_mss_rm (out,b);
  __riscv_ztt_mss_rm (saved,a);
}
__attribute__((noipa)) void ld_unknown (LD_ARGS)
{
  LD_T(LD_TYPE) b = LD_F(LD_TYPE) (other);
  __riscv_ztt_mss_rm (out,b);
}
#ifdef __cplusplus
}
#endif
