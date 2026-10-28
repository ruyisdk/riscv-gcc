#include <riscv_ztt.h>
void unowned (__INT32_TYPE__ *input, __INT32_TYPE__ *out, unsigned long row)
{
  if (!(__riscv_ztt_ame_acquire (0) & 1))
    return;
  __riscv_ztt_i32_rnu_1x1_t a = __riscv_ztt_mls_rm_i32_rnu_1x1 (input);
  a = __riscv_ztt_mrowbcast_ew_x_i32_rnu_1x1 (a, row);
  __riscv_ztt_ame_release ();
  a = __riscv_ztt_mreducemax_col_i32_rnu_1x1 (a);
  if (!(__riscv_ztt_ame_acquire (0) & 1))
    return;
  __riscv_ztt_mss_rm (out, a);
  __riscv_ztt_ame_release ();
}
