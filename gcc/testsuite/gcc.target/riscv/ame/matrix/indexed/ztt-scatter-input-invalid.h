#include <riscv_ztt.h>
void distinct (const __riscv_ztt_u128_storage_t *in,
               __riscv_ztt_u128_storage_t *out)
{
  __riscv_ztt_u128_rnu_1x1_t old = __riscv_ztt_mls_rm_u128_rnu_1x1 (in + 2);
#ifdef VOLATILE_INPUT
  volatile __riscv_ztt_u128_rnu_1x1_t a = __riscv_ztt_mls_rm_u128_rnu_1x1 (in);
  __riscv_ztt_u128_rnu_1x1_t b = __riscv_ztt_mcopy_m2m_u128_rnu_1x1 (a);
#else
  __riscv_ztt_u128_rnu_1x1_t a = __riscv_ztt_mls_rm_u128_rnu_1x1 (in);
  __riscv_ztt_u128_rnu_1x1_t b = __riscv_ztt_mcopy_m2m_u128_rnu_1x1 (a);
  a = __riscv_ztt_mls_rm_u128_rnu_1x1 (in + 1);
#endif
  __riscv_ztt_u128_rnu_1x1_t d = __riscv_ztt_mcolscatadd_ew_u128_rnu_1x1 (old, a, b);
  __riscv_ztt_mss_rm (out, d);
}
