#include <riscv_ztt.h>
void zs_unowned (__INT32_TYPE__ *out, int offset)
{
  if (!(__riscv_ztt_ame_acquire (0) & 1))
    return;
  __riscv_ztt_i32_1x1_t a = __riscv_ztt_mzero_m_i32_1x1 ();
  __riscv_ztt_ame_release ();
  __riscv_ztt_i32_1x1_t b = __riscv_ztt_mrowshift_ew_x_i32_1x1 (a, offset);
  if (!(__riscv_ztt_ame_acquire (0) & 1))
    return;
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_ame_release ();
}
