#include <riscv_ztt.h>
#ifndef LD_TYPE
#define LD_TYPE u32_rnu
#define LD_ALT u32_rod
#define LD_CARRIER __UINT32_TYPE__
#endif
#ifndef LD_SHAPE
#define LD_SHAPE 1x1
#endif
#define ML_T_(T,S) __riscv_ztt_##T##_##S##_t
#define ML_T_I(T,S) ML_T_(T,S)
#define ML_T(T) ML_T_I(T,LD_SHAPE)
#define ML_F_(F,T,S) __riscv_ztt_##F##_##T##_##S
#define ML_F_I(F,T,S) ML_F_(F,T,S)
#define ML_F(F,T) ML_F_I(F,T,LD_SHAPE)
#define ML_ARGS const LD_CARRIER *in, const LD_CARRIER *other, \
  LD_CARRIER *previous, LD_CARRIER *out, LD_CARRIER *saved, \
  __SIZE_TYPE__ stride, int control
#define ML_CM ML_F(mls_cm,LD_TYPE) (other)
#define ML_ST ML_F(mls_st,LD_TYPE) (other,stride)
#define ML_TST ML_F(mls_tst,LD_TYPE) (other,stride)
#ifdef __cplusplus
extern "C" {
#endif
extern void ml_callee (void);
#define ML_CASE(LAYOUT,NAME,FIRST,LOAD,BETWEEN,AFTER) \
__attribute__((noipa)) void ml_##LAYOUT##_##NAME (ML_ARGS) \
{ \
  ML_T(FIRST) a = ML_F(mls_rm,FIRST) (in); \
  __riscv_ztt_mss_rm (previous,a); \
  BETWEEN; \
  ML_T(LD_TYPE) b = LOAD; \
  __riscv_ztt_mss_rm (out,b); \
  AFTER; \
}
#define ML_LAYOUT(LAYOUT,LOAD) \
ML_CASE(LAYOUT,repeat,LD_TYPE,LOAD, , ) \
ML_CASE(LAYOUT,changed,LD_ALT,LOAD, , ) \
ML_CASE(LAYOUT,call,LD_TYPE,LOAD,ml_callee (), ) \
ML_CASE(LAYOUT,barrier,LD_TYPE,LOAD,__asm__ volatile ("# AME state boundary" ::: "memory"), ) \
ML_CASE(LAYOUT,join,LD_TYPE,LOAD,if (control) ml_callee (), ) \
ML_CASE(LAYOUT,live,LD_TYPE,LOAD, ,__riscv_ztt_mss_rm (saved,a)) \
__attribute__((noipa)) void ml_##LAYOUT##_unknown (ML_ARGS) \
{ \
  ML_T(LD_TYPE) b = LOAD; \
  __riscv_ztt_mss_rm (out,b); \
}
ML_LAYOUT(cm,ML_CM)
ML_LAYOUT(st,ML_ST)
ML_LAYOUT(tst,ML_TST)
#ifdef __cplusplus
}
#endif
