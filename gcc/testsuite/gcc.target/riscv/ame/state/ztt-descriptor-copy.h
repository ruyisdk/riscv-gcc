#include <riscv_ztt.h>

void
acc_barrier (const float *a, const float *b, const float *old,
	     float *out, float *ca, float *cb, float *cd)
{
  __riscv_ztt_f32_1x1_t x = __riscv_ztt_mls_rm_f32_1x1 (a);
  __riscv_ztt_f32_1x1_t y = __riscv_ztt_mls_rm_f32_1x1 (b);
  __riscv_ztt_f32_1x1_t d = __riscv_ztt_mls_rm_f32_1x1 (old);
  __asm__ volatile ("" ::: "memory");
  __riscv_ztt_f32_1x1_t z = __riscv_ztt_mmulacc_ew_f32_1x1 (d, x, y);
  __riscv_ztt_mss_rm (out, z);
  __riscv_ztt_mss_rm (ca, x);
  __riscv_ztt_mss_rm (cb, y);
  __riscv_ztt_mss_rm (cd, d);
}
