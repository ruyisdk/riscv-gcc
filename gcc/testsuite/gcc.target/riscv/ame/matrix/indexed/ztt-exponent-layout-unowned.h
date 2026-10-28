#include <riscv_ztt.h>
void el_unowned (long e, const __INT32_TYPE__ *in, const __INT32_TYPE__ *index,
                 __INT32_TYPE__ *out, __INT32_TYPE__ *saved)
{
  if (!(__riscv_ztt_ame_acquire (0) & 1))
    return;
  __riscv_ztt_i32_rnu_1x1_t i = __riscv_ztt_mls_rm_i32_rnu_1x1 (index);
  __riscv_ztt_i32_rnu_1x1_t a = __riscv_ztt_mls_rm_i32_rnu_1x1 (in);
  a = __riscv_ztt_mrowbcast_ew_x_i32_rnu_1x1 (a, 0);
  a = __riscv_ztt_mldexpacc_ew_x_i32_rnu_1x1 (a, a, e);
  __riscv_ztt_ame_release ();
  a = __riscv_ztt_mrowgather_ew_i32_rnu_1x1 (a, i);
  if (!(__riscv_ztt_ame_acquire (0) & 1))
    return;
  __riscv_ztt_mss_rm (out, a);
  __riscv_ztt_mss_rm (saved, i);
  __riscv_ztt_ame_release ();
}
