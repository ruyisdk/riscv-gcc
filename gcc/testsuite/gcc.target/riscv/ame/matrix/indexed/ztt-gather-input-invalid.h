#include <riscv_ztt.h>
void distinct (const __riscv_ztt_u128_storage_t *in,
               __riscv_ztt_u128_storage_t *out)
{
#ifdef VOLATILE_INPUT
  volatile __riscv_ztt_u128_rnu_1x1_t a = __riscv_ztt_mls_rm_u128_rnu_1x1 (in);
  __riscv_ztt_u128_rnu_1x1_t b = __riscv_ztt_mcopy_m2m_u128_rnu_1x1 (a);
#else
  __riscv_ztt_u128_rnu_1x1_t a = __riscv_ztt_mls_rm_u128_rnu_1x1 (in);
  __riscv_ztt_u128_rnu_1x1_t b = __riscv_ztt_mcopy_m2m_u128_rnu_1x1 (a);
  a = __riscv_ztt_mls_rm_u128_rnu_1x1 (in);
#endif
  __riscv_ztt_u128_rnu_1x1_t d = __riscv_ztt_mcolgather_ew_u128_rnu_1x1 (a, b);
  __riscv_ztt_mss_rm (out, d);
}
