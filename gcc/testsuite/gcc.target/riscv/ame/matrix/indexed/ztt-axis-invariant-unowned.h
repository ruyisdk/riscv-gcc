#include <riscv_ztt.h>
void ai_unowned (const __INT32_TYPE__ *in, __INT32_TYPE__ *out,
                 __INT32_TYPE__ *saved)
{
  if (!(__riscv_ztt_ame_acquire (0) & 1))
    return;
  __riscv_ztt_i32_rnu_1x1_t i = __riscv_ztt_mls_rm_i32_rnu_1x1 (in);
  __riscv_ztt_i32_rnu_1x1_t a = __riscv_ztt_mcolid_ew_i32_rnu_1x1 ();
  __riscv_ztt_ame_release ();
  __riscv_ztt_i32_rnu_1x1_t b = __riscv_ztt_mrowgather_ew_i32_rnu_1x1 (a, i);
  if (!(__riscv_ztt_ame_acquire (0) & 1))
    return;
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (saved, i);
  __riscv_ztt_ame_release ();
}
