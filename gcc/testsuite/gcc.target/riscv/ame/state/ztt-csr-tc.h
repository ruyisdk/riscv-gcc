#include <riscv_ztt.h>
#ifdef __cplusplus
extern "C" {
#endif
#define TC_OBSERVER(NAME, GAP) \
__attribute__((noipa)) unsigned long \
NAME (const __INT32_TYPE__ *in, __INT32_TYPE__ x, __INT32_TYPE__ *out) \
{ \
  __riscv_ztt_i32_1x1_t a = __riscv_ztt_mls_rm_i32_1x1 (in); \
  a = __riscv_ztt_madd_ew_x_i32_rnu_1x1_i32_rnu \
    (a, __riscv_ztt_scalar_from_bits_i32_rnu (x)); \
  GAP; \
  unsigned long value = __riscv_ztt_get_amestype (); \
  a = __riscv_ztt_mmul_ew_x_i32_rnu_1x1_i32_rnu \
    (a, __riscv_ztt_scalar_from_bits_i32_rnu (x)); \
  __riscv_ztt_mss_rm (out, a); \
  return value; \
}
TC_OBSERVER (observe_tc, (void) 0)
TC_OBSERVER (observe_tc_write, __asm__ volatile ("csrw amestype,zero" ::: "memory"))
#undef TC_OBSERVER
#ifdef __cplusplus
}
#endif
