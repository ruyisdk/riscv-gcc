#include <riscv_ztt.h>
void fu_unowned (const float *in, const __INT32_TYPE__ *index,
                 float *out, __INT32_TYPE__ *saved)
{
  if (!(__riscv_ztt_ame_acquire (0) & 1))
    return;
  __riscv_ztt_i32_rnu_1x1_t i = __riscv_ztt_mls_rm_i32_rnu_1x1 (index);
  __riscv_ztt_f32_rne_1x1_t a = __riscv_ztt_mls_rm_f32_rne_1x1 (in);
  a = __riscv_ztt_mrowbcast_ew_x_f32_rne_1x1 (a, 0);
  __riscv_ztt_f32_rne_1x1_t b = __riscv_ztt_msqrt_ew_f32_rne_1x1 (a);
  __riscv_ztt_ame_release ();
  b = __riscv_ztt_mrowgather_ew_f32_rne_1x1 (b, i);
  if (!(__riscv_ztt_ame_acquire (0) & 1))
    return;
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (saved, i);
  __riscv_ztt_ame_release ();
}
