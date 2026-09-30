/* Supported counterparts to profile/resource absence tests.  */
#include <riscv_ztt.h>
#define KEEP_M(X) __asm__ volatile ("" : : "Wmr" (X))

void clear_supported (void)
{
  __riscv_ztt_i64_1x1_t m = __riscv_ztt_mclear_m_i64_1x1 ();
  __riscv_ztt_i8_rne_1x8_t group = __riscv_ztt_mclear_m_i8_rne_1x8 ();
  __riscv_ztt_i64_rne_accx1_t acc = __riscv_ztt_mzero_acc_i64_rne_accx1 ();
  KEEP_M (m);
  KEEP_M (group);
  __asm__ volatile ("" : : "War" (acc));
}

void utils_supported (void)
{
  __riscv_ztt_i32_rnu_1x1_t m = __riscv_ztt_mzero_m_i32_rnu_1x1 ();
  __riscv_ztt_i32_rnu_1x2_t pair
    = __riscv_ztt_mconcat_m_i32_rnu_1x2 (m, m);
  __riscv_ztt_i32_rnu_1x1_t part
    = __riscv_ztt_mextract_i32_rnu_1x1 (pair, 1);
  KEEP_M (pair);
  KEEP_M (part);
}

void scalar_supported (long x)
{
  __riscv_ztt_i64_sat_1x1_t m = __riscv_ztt_mbcast_m_x_i64_sat_1x1_i8
    (__riscv_ztt_scalar_make_i8_rnu (x));
  __riscv_ztt_i64_sat_1x1_t result = __riscv_ztt_mmuladd_ew_x_i64_sat_1x1_i8
    (m, m, __riscv_ztt_scalar_make_i8_rnu (x));
  KEEP_M (result);
}
