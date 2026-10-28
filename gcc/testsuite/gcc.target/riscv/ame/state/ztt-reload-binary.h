#include <riscv_ztt.h>
#ifndef RB_TYPE
#define RB_TYPE i32_rnu
#define RB_ELEMENT __INT32_TYPE__
#endif
#ifndef RB_SHAPE
#define RB_SHAPE 1x1
#endif
#define RB_T_(T,S) __riscv_ztt_##T##_##S##_t
#define RB_T(T,S) RB_T_(T,S)
#define RB_F_(F,T,S) __riscv_ztt_##F##_##T##_##S
#define RB_F(F,T,S) RB_F_(F,T,S)
#define RB_ARGS const RB_ELEMENT *in, const RB_ELEMENT *right, RB_ELEMENT *out, RB_ELEMENT *saved, int flag
#define RB_CASE(OP,NAME,SAME,BEFORE,AFTER,SAVE) \
__attribute__((noipa)) void rb_##OP##_##NAME (RB_ARGS) \
{ \
  RB_T(RB_TYPE,RB_SHAPE) a = RB_F(mls_rm,RB_TYPE,RB_SHAPE) (in); \
  RB_T(RB_TYPE,RB_SHAPE) b = SAME ? a : RB_F(mls_rm,RB_TYPE,RB_SHAPE) (right); \
  BEFORE; \
  RB_T(RB_TYPE,RB_SHAPE) z = RB_F(OP,RB_TYPE,RB_SHAPE) (a,b); \
  AFTER; \
  __riscv_ztt_mss_rm (out,z); \
  SAVE; \
}
#define RB_FAMILY(OP) \
RB_CASE(OP,call,0,rb_callee (), , ) \
RB_CASE(OP,live,0,rb_callee (), , __riscv_ztt_mss_rm (saved,a); __riscv_ztt_mss_rm (saved+1024,b)) \
RB_CASE(OP,after,0,rb_callee (),rb_callee (), ) \
RB_CASE(OP,ready,0, , , ) \
RB_CASE(OP,barrier,0,rb_callee (); __asm__ volatile ("# AME observer" : "+Wmr" (a), "+Wmr" (b) : : "memory"), , ) \
RB_CASE(OP,query,0,rb_callee (); __asm__ volatile ("csrr %0,ameown" : "=r" (rb_observed), "+Wmr" (a), "+Wmr" (b) : : "memory"), , ) \
RB_CASE(OP,join,0,if (flag) rb_callee (), , ) \
RB_CASE(OP,same,1,rb_callee (), , __riscv_ztt_mss_rm (saved,a))
#ifdef __cplusplus
extern "C" {
#endif
extern void rb_callee (void);
extern volatile unsigned long rb_observed;
RB_FAMILY(madd_ew)
RB_FAMILY(msub_ew)
RB_FAMILY(mmin_ew)
RB_FAMILY(mmax_ew)
RB_FAMILY(mand_ew)
RB_FAMILY(mandnot_ew)
RB_FAMILY(mor_ew)
RB_FAMILY(mornot_ew)
RB_FAMILY(mxor_ew)
#ifdef __cplusplus
}
#endif
