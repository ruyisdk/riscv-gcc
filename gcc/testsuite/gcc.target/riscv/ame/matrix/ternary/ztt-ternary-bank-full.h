#include <riscv_ztt.h>
#ifdef __cplusplus
extern "C" {
#endif
void whole_bank (const __riscv_ztt_i128_storage_t *a,
                 __riscv_ztt_i128_storage_t *out,
                 __riscv_ztt_i128_storage_t *saved)
{
  __riscv_ztt_i128_rnu_1x1_t x = __riscv_ztt_mls_rm_i128_rnu_1x1 (a);
  __riscv_ztt_mss_rm_i128_rnu_1x1
    (out, __riscv_ztt_mmulacc_ew_i128_rnu_1x1 (x, x, x));
  __riscv_ztt_mss_rm_i128_rnu_1x1 (saved, x);
}
#ifdef __cplusplus
}
#endif
