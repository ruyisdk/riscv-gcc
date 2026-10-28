#include <riscv_ztt.h>
#define load __riscv_ztt_mls_rm_f32_rne_1x1
#define store __riscv_ztt_mss_rm
#define madd __riscv_ztt_mmuladd_ew_f32_rne_1x1
#ifdef __cplusplus
extern "C" {
#endif
extern void callee (void);
typedef int any_int __attribute__((may_alias));
#define CASE(NAME, TAIL) \
void NAME (float *out, const float *in, const float *scale, const float *bias, \
           int flag, int *status, const int *unknown) \
{ \
  store (out, madd (load (in), load (bias), load (scale))); \
  TAIL; \
}
CASE (conditional_save, if (flag) *status = 7)
CASE (diamond_save, if (flag) *status = 7; else status[1] = 9)
CASE (unknown_read, if (flag) *status = *(const any_int *) unknown)
CASE (call_tail, if (flag) callee ())
CASE (asm_tail, if (flag) asm volatile ("# boundary" ::: "memory", "m0"))
CASE (volatile_read, if (flag) *status = *(volatile const int *) unknown)
#ifdef __cplusplus
}
#endif
