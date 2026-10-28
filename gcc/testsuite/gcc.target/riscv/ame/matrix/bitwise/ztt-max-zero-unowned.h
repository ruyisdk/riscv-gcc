#include <riscv_ztt.h>
void unowned (const __UINT32_TYPE__ *in, __UINT32_TYPE__ *out)
{
  if (!(__riscv_ztt_ame_acquire (0) & 1)) return;
  __riscv_ztt_u32_rnu_1x1_t a = __riscv_ztt_mls_rm_u32_rnu_1x1 (in);
  __riscv_ztt_u32_rnu_1x1_t z = __riscv_ztt_mzero_m_u32_rnu_1x1 ();
  __riscv_ztt_ame_release ();
  __riscv_ztt_u32_rnu_1x1_t v = __riscv_ztt_mmax_ew_u32_rnu_1x1 (a, z);
  if (!(__riscv_ztt_ame_acquire (0) & 1)) return;
  __riscv_ztt_mss_rm (out, v);
  __riscv_ztt_ame_release ();
}
