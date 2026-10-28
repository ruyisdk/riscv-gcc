#include <riscv_ztt.h>
void unowned (const float *in, float *out)
{
  if (!(__riscv_ztt_ame_acquire (0) & 1)) return;
  __riscv_ztt_f32_rne_1x1_t a = __riscv_ztt_mls_rm_f32_rne_1x1 (in);
  __riscv_ztt_f32_rne_1x1_t b = __riscv_ztt_mabs_ew_f32_rne_1x1 (a);
  __riscv_ztt_ame_release ();
  __riscv_ztt_f32_rne_1x1_t v = __riscv_ztt_mabs_ew_f32_rne_1x1 (b);
  if (!(__riscv_ztt_ame_acquire (0) & 1)) return;
  __riscv_ztt_mss_rm (out, v);
  __riscv_ztt_ame_release ();
}
