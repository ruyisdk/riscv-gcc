#include <riscv_ztt.h>
void unowned (const __UINT32_TYPE__ *in, __UINT32_TYPE__ *out)
{
  if (!(__riscv_ztt_ame_acquire (0)&1)) return;
  __riscv_ztt_u32_rod_sat_1x1_t a=__riscv_ztt_mls_rm_u32_rod_sat_1x1 (in);
  __riscv_ztt_ame_release ();
  __riscv_ztt_u32_rod_sat_1x1_t b=__riscv_ztt_mbcast_m_x_u32_rod_sat_1x1
    (__riscv_ztt_scalar_from_bits_u32_rod_sat ((__UINT32_TYPE__) -1));
  __riscv_ztt_u32_rod_sat_1x1_t v=__riscv_ztt_mand_ew_u32_rod_sat_1x1 (a,b);
  if (!(__riscv_ztt_ame_acquire (0)&1)) return;
  __riscv_ztt_mss_rm (out,v);
  __riscv_ztt_ame_release ();
}
