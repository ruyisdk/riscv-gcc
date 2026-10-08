#include <riscv_ztt.h>

#ifndef TEST_ACC
int zero_m_after_release (unsigned long desc, float *out)
{
  if (!(__riscv_ztt_ame_acquire (desc) & 1))
    return 0;
  __riscv_ztt_ame_release ();
  __riscv_ztt_f32_rne_1x1_t value = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_mss_rm (out, value);
  return 1;
}
#else
int zero_acc_after_release (unsigned long desc, float *out)
{
  if (!(__riscv_ztt_ame_acquire (desc) & 1))
    return 0;
  __riscv_ztt_ame_release ();
  __riscv_ztt_f32_rne_accx1_t value = __riscv_ztt_mzero_acc_f32_rne_accx1 ();
  __riscv_ztt_mss_rm (out, __riscv_ztt_mcopy_a2m_f32_rne_1x1 (value));
  return 1;
}
#endif
