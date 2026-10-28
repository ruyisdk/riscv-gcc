#include <riscv_ztt.h>
void ub_unowned (__INT32_TYPE__ value, __INT32_TYPE__ *out)
{
  if (!(__riscv_ztt_ame_acquire (0) & 1))
    return;
  __riscv_ztt_i32_1x1_t a = __riscv_ztt_mbcast_m_x_i32_1x1
    (__riscv_ztt_scalar_make_i32_rnu (value));
  __riscv_ztt_ame_release ();
  __riscv_ztt_i32_1x1_t b = __riscv_ztt_mrowbcast_ew_x_i32_1x1 (a, 0);
  if (!(__riscv_ztt_ame_acquire (0) & 1))
    return;
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_ame_release ();
}
