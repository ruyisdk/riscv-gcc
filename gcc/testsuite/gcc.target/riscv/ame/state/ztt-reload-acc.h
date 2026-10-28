#include <riscv_ztt.h>
#ifndef AR_TYPE
#define AR_TYPE i32_rnu
#define AR_ELEMENT __INT32_TYPE__
#define AR_K 2
#endif
#define AR_T_(T,K) __riscv_ztt_##T##_1x##K##_t
#define AR_T(T,K) AR_T_(T,K)
#define AR_A_(T,K) __riscv_ztt_##T##_accx##K##_t
#define AR_A(T,K) AR_A_(T,K)
#define AR_F_(F,T,K) __riscv_ztt_##F##_##T##_1x##K
#define AR_F(F,T,K) AR_F_(F,T,K)
#define AR_FROM_(T,K) __riscv_ztt_mcopy_m2a_##T##_accx##K
#define AR_FROM(T,K) AR_FROM_(T,K)
#define AR_ARGS const AR_ELEMENT *in, AR_ELEMENT *out, AR_ELEMENT *saved, int flag
#define AR_CASE(NAME,BEFORE,AFTER,SAVE) \
__attribute__((noipa)) void ar_##NAME (AR_ARGS) \
{ \
  AR_T(AR_TYPE,AR_K) a = AR_F(mls_rm,AR_TYPE,AR_K) (in); \
  BEFORE; \
  AR_A(AR_TYPE,AR_K) b = AR_FROM(AR_TYPE,AR_K) (a); \
  AFTER; \
  __riscv_ztt_mss_rm (out, AR_F(mcopy_a2m,AR_TYPE,AR_K) (b)); \
  SAVE; \
}
#ifdef __cplusplus
extern "C" {
#endif
extern void ar_callee (void);
extern volatile unsigned long ar_observed;
AR_CASE(transfer, ar_callee (), , )
AR_CASE(live, ar_callee (), , __riscv_ztt_mss_rm (saved, a))
AR_CASE(after, ar_callee (), ar_callee (), )
AR_CASE(ready, , , )
AR_CASE(barrier, ar_callee (); __asm__ volatile ("# AME observer" : "+Wmr" (a) : : "memory"), , )
AR_CASE(query, ar_callee (); __asm__ volatile ("csrr %0,ameown" : "=r" (ar_observed), "+Wmr" (a) : : "memory"), , )
AR_CASE(join, if (flag) ar_callee (), , )
AR_CASE(store, ar_callee (); __riscv_ztt_mss_rm (saved, a), , )
#ifdef __cplusplus
}
#endif
