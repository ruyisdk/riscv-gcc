#include <riscv_ztt.h>
void unowned (const float *in, float *out)
{
  if (!(__riscv_ztt_ame_acquire (0) & 1))
    return;
  __riscv_ztt_f32_rne_1x1_t a = __riscv_ztt_mls_rm_f32_rne_1x1 (in);
  a = __riscv_ztt_mreducemax_row_f32_rne_1x1 (a);
  __riscv_ztt_ame_release ();
  a = __riscv_ztt_mreducemin_row_f32_rne_1x1 (a);
  if (!(__riscv_ztt_ame_acquire (0) & 1))
    return;
  __riscv_ztt_mss_rm (out, a);
  __riscv_ztt_ame_release ();
}
