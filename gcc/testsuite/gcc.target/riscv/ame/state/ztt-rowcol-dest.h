#include <riscv_ztt.h>
#ifndef RD_TYPE
#define RD_TYPE i32_rnu
#define RD_CARRIER __INT32_TYPE__
#endif
#define RD_T_(T) __riscv_ztt_##T##_1x1_t
#define RD_T(T) RD_T_(T)
#define RD_F_(F,T) __riscv_ztt_##F##_##T##_1x1
#define RD_F(F,T) RD_F_(F,T)
#define RD_ARGS const RD_CARRIER *in, RD_CARRIER *previous, \
  RD_CARRIER *out, RD_CARRIER *saved, int control
#ifdef __cplusplus
extern "C" {
#endif
extern void rd_callee (void);
#define RD_CASE(NAME, OP, BETWEEN) \
__attribute__((noipa)) void rd_##NAME (RD_ARGS) \
{ \
  RD_T(RD_TYPE) a = RD_F(mls_rm,RD_TYPE) (in); \
  RD_T(RD_TYPE) first = RD_F(mcolshift_ew_x,RD_TYPE) (a, 1); \
  __riscv_ztt_mss_rm (previous, first); \
  BETWEEN; \
  RD_T(RD_TYPE) b = RD_F(OP,RD_TYPE) (a, control); \
  __riscv_ztt_mss_rm (out, b); \
  __riscv_ztt_mss_rm (saved, a); \
}
RD_CASE(rowbcast, mrowbcast_ew_x, )
RD_CASE(colbcast, mcolbcast_ew_x, )
RD_CASE(rowshift, mrowshift_ew_x, )
RD_CASE(colshift, mcolshift_ew_x, )
RD_CASE(call, mrowshift_ew_x, rd_callee ())
RD_CASE(barrier, mrowshift_ew_x, __asm__ volatile ("# AME state boundary" ::: "memory"))
RD_CASE(join, mrowshift_ew_x, if (control & 1) rd_callee ())
__attribute__((noipa)) void rd_unknown (RD_ARGS)
{
  RD_T(RD_TYPE) a = RD_F(mls_rm,RD_TYPE) (in);
  RD_T(RD_TYPE) b = RD_F(mrowshift_ew_x,RD_TYPE) (a, control);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (saved, a);
}
#ifdef __cplusplus
}
#endif
