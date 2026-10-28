#include <riscv_ztt.h>
void unowned (float *out)
{
  if (!(__riscv_ztt_ame_acquire (0) & 1))
    return;
  __riscv_ztt_f32_rne_1x1_t a = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_ame_release ();
  a = __riscv_ztt_mabs_ew_f32_rne_1x1 (a);
  if (!(__riscv_ztt_ame_acquire (0) & 1))
    return;
  __riscv_ztt_mss_rm (out, a);
  __riscv_ztt_ame_release ();
}
