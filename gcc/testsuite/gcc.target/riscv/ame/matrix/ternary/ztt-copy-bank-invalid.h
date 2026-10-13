#include <riscv_ztt.h>
#ifndef COPY_VOLATILE
void reloaded_source (const __INT64_TYPE__ *a, const __INT64_TYPE__ *other,
                      const __UINT64_TYPE__ *b, __INT64_TYPE__ *out)
{
  __riscv_ztt_i64_rnu_1x1_t x = __riscv_ztt_mls_rm_i64_rnu_1x1 (a);
  __riscv_ztt_u64_rnu_1x1_t y = __riscv_ztt_mls_rm_u64_rnu_1x1 (b);
  __riscv_ztt_i64_rnu_1x1_t d = __riscv_ztt_mcopy_m2m_i64_rnu_1x1 (x);
  x = __riscv_ztt_mls_rm_i64_rnu_1x1 (other);
  __riscv_ztt_mss_rm_i64_rnu_1x1
    (out, __riscv_ztt_mmulacc_ew_i64_rnu_1x1 (d, x, y));
}
#else
void volatile_source (const __INT64_TYPE__ *a, const __UINT64_TYPE__ *b,
                      __INT64_TYPE__ *out)
{
  volatile __riscv_ztt_i64_rnu_1x1_t x = __riscv_ztt_mls_rm_i64_rnu_1x1 (a);
  __riscv_ztt_u64_rnu_1x1_t y = __riscv_ztt_mls_rm_u64_rnu_1x1 (b);
  __riscv_ztt_i64_rnu_1x1_t d = __riscv_ztt_mcopy_m2m_i64_rnu_1x1 (x);
  __riscv_ztt_mss_rm_i64_rnu_1x1
    (out, __riscv_ztt_mmulacc_ew_i64_rnu_1x1 (d, x, y));
}
#endif
