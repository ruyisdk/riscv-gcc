#include <riscv_ztt.h>
#include <stdint.h>
int broadcast_after_release (unsigned long desc, int32_t *out)
{
  if (!(__riscv_ztt_ame_acquire (desc) & 1))
    return 0;
  __riscv_ztt_ame_release ();
  __riscv_ztt_i32_rnu_1x1_t value = __riscv_ztt_mbcast_m_x_i32_rnu_1x1_i8_rnu
    (__riscv_ztt_scalar_make_i8_rnu (0));
  __riscv_ztt_mss_rm (out, value);
  return 1;
}
