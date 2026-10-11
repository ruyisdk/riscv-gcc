#include <riscv_ztt.h>
void unowned_projections (__INT32_TYPE__ *out, const __INT32_TYPE__ *in)
{
  if (!(__riscv_ztt_ame_acquire (0) & 1))
    return;
  __riscv_ztt_i32_rnu_1x1_t a = __riscv_ztt_mls_rm_i32_rnu_1x1 (in);
  __riscv_ztt_i32_rnu_1x1_t b = __riscv_ztt_mls_rm_i32_rnu_1x1 (in);
  __riscv_ztt_ame_release ();
  __riscv_ztt_i32_rnu_1x2_t p = __riscv_ztt_mconcat_m_i32_rnu_1x2 (a, b);
  __riscv_ztt_i32_rnu_1x1_t x = __riscv_ztt_mextract_i32_rnu_1x1 (p, 0);
  __riscv_ztt_i32_rnu_1x1_t y = __riscv_ztt_mextract_i32_rnu_1x1 (p, 1);
  if (!(__riscv_ztt_ame_acquire (0) & 1))
    return;
  __riscv_ztt_mss_rm (out, x);
  __riscv_ztt_mss_rm (out, y);
  __riscv_ztt_ame_release ();
}
