#include <riscv_ztt.h>
#ifdef __cplusplus
extern "C" {
#endif
extern void store_md_callee (void);
extern volatile int store_md_condition;
/* Forget the load's Md so only the typed store can establish it.  */
#define STORE_MD(NAME, STORE, BARRIER) \
__attribute__((noinline,noclone)) \
void NAME (const __INT32_TYPE__ *in, __INT32_TYPE__ *out, \
           __INT32_TYPE__ *live, __INT32_TYPE__ *stored, unsigned long stride) \
{ \
  __riscv_ztt_i32_1x1_t a = __riscv_ztt_mls_rm_i32_1x1 (in); \
  __asm__ volatile ("" ::: "memory"); \
  STORE; \
  BARRIER; \
  __riscv_ztt_i32_accx1_t d = __riscv_ztt_mcopy_m2a_i32_accx1 (a); \
  __riscv_ztt_mss_rm (out, __riscv_ztt_mcopy_a2m_i32_1x1 (d)); \
  __riscv_ztt_mss_rm (live, a); \
}
STORE_MD (store_md_rm, __riscv_ztt_mss_rm (stored, a), (void) 0)
STORE_MD (store_md_cm, __riscv_ztt_mss_cm (stored, a), (void) 0)
STORE_MD (store_md_st, __riscv_ztt_mss_st (stored, stride, a), (void) 0)
STORE_MD (store_md_tst, __riscv_ztt_mss_tst (stored, stride, a), (void) 0)
STORE_MD (store_md_asm, __riscv_ztt_mss_rm (stored, a),
          __asm__ volatile ("" ::: "memory"))
STORE_MD (store_md_call, __riscv_ztt_mss_rm (stored, a), store_md_callee ())
STORE_MD (store_md_join, __riscv_ztt_mss_rm (stored, a),
          if (store_md_condition) __asm__ volatile ("" ::: "memory"))
#undef STORE_MD
#ifdef __cplusplus
}
#endif
