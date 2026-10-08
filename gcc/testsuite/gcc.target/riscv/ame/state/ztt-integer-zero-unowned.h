#include <riscv_ztt.h>
#include <stdint.h>

int zero_after_release (unsigned long desc, int32_t *out)
{
  if (!(__riscv_ztt_ame_acquire (desc) & 1))
    return 0;
  __riscv_ztt_ame_release ();
  __riscv_ztt_i32_rnu_1x1_t value = __riscv_ztt_mzero_m_i32_rnu_1x1 ();
  __riscv_ztt_mss_rm (out, value);
  return 1;
}
