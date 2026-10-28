#include <riscv_ztt.h>
void unowned (const __UINT32_TYPE__ *in, __UINT32_TYPE__ *out,
              __UINT32_TYPE__ *saved)
{
  if (!(__riscv_ztt_ame_acquire (0) & 1)) return;
  __riscv_ztt_u32_rod_sat_1x2_t a = __riscv_ztt_mls_rm_u32_rod_sat_1x2 (in);
  __riscv_ztt_ame_release ();
  __riscv_ztt_u32_rod_sat_1x2_t v = __riscv_ztt_msub_ew_u32_rod_sat_1x2 (a, a);
  if (!(__riscv_ztt_ame_acquire (0) & 1)) return;
  __riscv_ztt_mss_rm (saved, a);
  __riscv_ztt_mss_rm (out, v);
  __riscv_ztt_ame_release ();
}
