#include <riscv_ztt.h>
extern void observe (void);

void after_call (float *out, const float *in, int control)
{
  __riscv_ztt_f32_1x1_t a = __riscv_ztt_mls_rm_f32_1x1 (in);
  observe ();
  __riscv_ztt_mss_rm (out, __riscv_ztt_mrowshift_ew_x_f32_1x1 (a, control));
}

void after_asm (float *out, const float *in, int control)
{
  __riscv_ztt_f32_1x1_t a = __riscv_ztt_mls_rm_f32_1x1 (in);
  __asm__ volatile ("" ::: "memory");
  __riscv_ztt_mss_rm (out, __riscv_ztt_mcolshift_ew_x_f32_1x1 (a, control));
}

void after_join (float *out, const float *in, int control, int branch)
{
  __riscv_ztt_f32_1x1_t a = __riscv_ztt_mls_rm_f32_1x1 (in);
  if (branch)
    __asm__ volatile ("" ::: "memory");
  __riscv_ztt_mss_rm (out, __riscv_ztt_mcolbcast_ew_x_f32_1x1 (a, control));
}
