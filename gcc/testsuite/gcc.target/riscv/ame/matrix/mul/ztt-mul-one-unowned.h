#include <riscv_ztt.h>
void unowned (const __INT32_TYPE__ *in, __INT32_TYPE__ *out)
{
  if (!(__riscv_ztt_ame_acquire (0) & 1)) return;
  __riscv_ztt_i32_rnu_1x1_t a = __riscv_ztt_mls_rm_i32_rnu_1x1 (in);
  __riscv_ztt_ame_release ();
  __riscv_ztt_i32_rnu_1x1_t one = __riscv_ztt_mbcast_m_x_i32_rnu_1x1
    (__riscv_ztt_scalar_make_i32_rnu (1));
  __riscv_ztt_i32_rnu_1x1_t v = __riscv_ztt_mmul_ew_i32_rnu_1x1 (a,one);
  if (!(__riscv_ztt_ame_acquire (0) & 1)) return;
  __riscv_ztt_mss_rm (out,v);
  __riscv_ztt_ame_release ();
}
