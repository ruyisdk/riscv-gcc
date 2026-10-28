#include <riscv_ztt.h>
void unowned_zero_scatter (const __INT32_TYPE__ *in, __INT32_TYPE__ *out)
{
  if (!(__riscv_ztt_ame_acquire (0) & 1)) return;
  __riscv_ztt_i32_rnu_1x1_t a = __riscv_ztt_mls_rm_i32_rnu_1x1 (in);
  __riscv_ztt_ame_release ();
  __riscv_ztt_i32_rnu_1x1_t i = __riscv_ztt_mls_rm_i32_rnu_1x1 (in + 16);
  __riscv_ztt_i32_rnu_1x1_t z = __riscv_ztt_mzero_m_i32_rnu_1x1 ();
  __riscv_ztt_i32_rnu_1x1_t b = __riscv_ztt_mrowscatadd_ew_i32_rnu_1x1 (a, z, i);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (out + 16, i);
}
