#include <riscv_ztt.h>
#ifndef RS_TYPE
#define RS_TYPE i32_rnu
#define RS_ELEMENT __INT32_TYPE__
#endif
#define RS_NAME_(f, t) __riscv_ztt_##f##_##t##_1x1
#define RS_NAME(f, t) RS_NAME_(f, t)
#define RS_T_(t) __riscv_ztt_##t##_1x1_t
#define RS_T(t) RS_T_(t)
#ifdef __cplusplus
extern "C" {
#endif
extern void rs_callee (void);
extern volatile unsigned long rs_observed;
#define RS_CASE(name, gap, store) \
void name (const RS_ELEMENT *in, RS_ELEMENT *out, unsigned long stride, int flag) \
{ \
  RS_T(RS_TYPE) value = RS_NAME(mls_rm, RS_TYPE) (in); \
  gap; \
  store; \
}
RS_CASE (rs_rm, rs_callee (), __riscv_ztt_mss_rm (out, value))
RS_CASE (rs_cm, rs_callee (), __riscv_ztt_mss_cm (out, value))
RS_CASE (rs_st, rs_callee (), __riscv_ztt_mss_st (out, stride, value))
RS_CASE (rs_tst, rs_callee (), __riscv_ztt_mss_tst (out, stride, value))
RS_CASE (rs_ready, (void)0, __riscv_ztt_mss_rm (out, value))
RS_CASE (rs_asm, __asm__ volatile ("# state observer" ::: "memory"),
         __riscv_ztt_mss_rm (out, value))
RS_CASE (rs_query, rs_callee (); __asm__ volatile ("csrr %0,ameown" : "=r" (rs_observed) : "Wmr" (value)),
         __riscv_ztt_mss_rm (out, value))
RS_CASE (rs_join, if (flag) rs_callee (), __riscv_ztt_mss_rm (out, value))
#undef RS_CASE
#ifdef __cplusplus
}
#endif
