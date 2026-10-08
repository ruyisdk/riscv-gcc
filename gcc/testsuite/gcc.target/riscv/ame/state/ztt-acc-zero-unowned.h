#include <riscv_ztt.h>
#include <stdint.h>
int zero_acc_after_release (unsigned long desc, int32_t *out)
{
  if (!(__riscv_ztt_ame_acquire (desc) & 1))
    return 0;
  __riscv_ztt_ame_release ();
  __riscv_ztt_i32_rnu_accx1_t value = __riscv_ztt_mzero_acc_i32_rnu_accx1 ();
  __riscv_ztt_mss_rm (out, __riscv_ztt_mcopy_a2m_i32_rnu_1x1 (value));
  return 1;
}
