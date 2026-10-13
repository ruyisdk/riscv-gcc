#include <riscv_ztt.h>
void distinct (const __riscv_ztt_i128_storage_t *in,
               __riscv_ztt_i128_storage_t *out)
{
#ifdef VOLATILE_INPUT
  volatile __riscv_ztt_i128_rnu_1x1_t a = __riscv_ztt_mls_rm_i128_rnu_1x1 (in);
  __riscv_ztt_i128_rnu_1x1_t b = __riscv_ztt_mcopy_m2m_i128_rnu_1x1 (a);
#else
  __riscv_ztt_i128_rnu_1x1_t a = __riscv_ztt_mls_rm_i128_rnu_1x1 (in);
  __riscv_ztt_i128_rnu_1x1_t b = __riscv_ztt_mcopy_m2m_i128_rnu_1x1 (a);
  a = __riscv_ztt_mls_rm_i128_rnu_1x1 (in + 1);
#endif
  __riscv_ztt_i128_rnu_1x1_t d = __riscv_ztt_mmulacc_ew_x_i128_rnu_1x1_i8_rnu
    (a, b, __riscv_ztt_scalar_make_i8_rnu (3));
  __riscv_ztt_mss_rm (out, d);
}
