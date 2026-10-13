#include <riscv_ztt.h>
void different_inputs (const __riscv_ztt_i128_storage_t *in,
                       const __riscv_ztt_i128_storage_t *other,
                       __riscv_ztt_i128_storage_t *out, long e)
{
#ifdef WC_VOLATILE
  volatile __riscv_ztt_i128_rnu_1x1_t a=__riscv_ztt_mls_rm_i128_rnu_1x1(in);
#else
  __riscv_ztt_i128_rnu_1x1_t a=__riscv_ztt_mls_rm_i128_rnu_1x1(in);
#endif
  __riscv_ztt_i128_rnu_1x1_t b=__riscv_ztt_mcopy_m2m_i128_rnu_1x1(a);
#ifndef WC_VOLATILE
  a=__riscv_ztt_mls_rm_i128_rnu_1x1(other);
#endif
  __riscv_ztt_mss_rm(out,__riscv_ztt_mldexpacc_ew_x_i128_rnu_1x1(b,a,e));
}
