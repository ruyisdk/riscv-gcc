#include <riscv_ztt.h>
#ifndef ZR_TYPE
#define ZR_TYPE i32_rnu
#define ZR_ELEMENT __INT32_TYPE__
#endif
#define ZR_T_(T) __riscv_ztt_##T##_1x2_t
#define ZR_T(T) ZR_T_(T)
#define ZR_F_(F,T) __riscv_ztt_##F##_##T##_1x2
#define ZR_F(F,T) ZR_F_(F,T)
#define ZR_ARGS const ZR_ELEMENT *in, ZR_ELEMENT *out, ZR_ELEMENT *saved, int flag
#define ZR_CASE(OP,NAME,BEFORE,AFTER,SAVE) \
__attribute__((noipa)) void zr_##OP##_##NAME (ZR_ARGS) \
{ \
  ZR_T(ZR_TYPE) a = ZR_F(mls_rm,ZR_TYPE) (in); \
  BEFORE; \
  ZR_T(ZR_TYPE) b = ZR_F(OP,ZR_TYPE) (a); \
  AFTER; \
  __riscv_ztt_mss_rm (out, b); \
  SAVE; \
}
#define ZR_FAMILY(OP) \
ZR_CASE(OP, call, zr_callee (), , ) \
ZR_CASE(OP, live, zr_callee (), , __riscv_ztt_mss_rm (saved, a)) \
ZR_CASE(OP, after, zr_callee (), zr_callee (), ) \
ZR_CASE(OP, ready, , , ) \
ZR_CASE(OP, barrier, zr_callee (); __asm__ volatile ("# AME observer" : "+Wmr" (a) : : "memory"), , ) \
ZR_CASE(OP, query, zr_callee (); __asm__ volatile ("csrr %0,ameown" : "=r" (zr_observed), "+Wmr" (a) : : "memory"), , ) \
ZR_CASE(OP, join, if (flag) zr_callee (), , ) \
ZR_CASE(OP, store, zr_callee (); __riscv_ztt_mss_rm (saved, a), , )
#ifdef __cplusplus
extern "C" {
#endif
extern void zr_callee (void);
extern volatile unsigned long zr_observed;
ZR_FAMILY(mcolzip_ew)
ZR_FAMILY(mrowzip_ew)
ZR_FAMILY(mcolunzip_ew)
ZR_FAMILY(mrowunzip_ew)
#ifdef __cplusplus
}
#endif
