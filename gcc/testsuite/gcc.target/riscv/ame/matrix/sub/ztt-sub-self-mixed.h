#include <riscv_ztt.h>
void different_rounding (const __UINT32_TYPE__ *in, __UINT32_TYPE__ *out,
                         __UINT32_TYPE__ *saved)
{
  __riscv_ztt_u32_rnu_1x2_t a = __riscv_ztt_mls_rm_u32_rnu_1x2 (in);
  __riscv_ztt_u32_rod_sat_1x2_t v = __riscv_ztt_msub_ew_u32_rod_sat_1x2 (a, a);
  __riscv_ztt_mss_rm (saved, a);
  __riscv_ztt_mss_rm (out, v);
}
void different_sign (const __INT32_TYPE__ *in, __UINT32_TYPE__ *out,
                     __INT32_TYPE__ *saved)
{
  __riscv_ztt_i32_rod_sat_1x2_t a = __riscv_ztt_mls_rm_i32_rod_sat_1x2 (in);
  __riscv_ztt_u32_rod_sat_1x2_t v = __riscv_ztt_msub_ew_u32_rod_sat_1x2 (a, a);
  __riscv_ztt_mss_rm (saved, a);
  __riscv_ztt_mss_rm (out, v);
}
