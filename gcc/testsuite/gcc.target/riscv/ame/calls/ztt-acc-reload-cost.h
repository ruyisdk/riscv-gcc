#include <riscv_ztt.h>

/* ACC copies require early-clobber scratches even within the same bank.
   Keep the old accumulator live while the tied matmul result is updated.  */
void acc_reload_cost (void)
{
  __riscv_ztt_i64_rnu_accx1_t old = __riscv_ztt_mzero_acc_i64_rnu_accx1 ();
  __riscv_ztt_i64_rnu_1x1_t m = __riscv_ztt_mzero_m_i64_rnu_1x1 ();
  __riscv_ztt_i64_rnu_accx1_t d =
    __riscv_ztt_mmulacc_2d_i64_rnu_accx1 (old, m, m);
  d = __riscv_ztt_mmulaccneg_2d_i64_rnu_accx1 (d, m, m);
  d = __riscv_ztt_mmulatacc_2d_i64_rnu_accx1 (d, m, m);
  d = __riscv_ztt_mmulataccneg_2d_i64_rnu_accx1 (d, m, m);
  d = __riscv_ztt_mmulbtacc_2d_i64_rnu_accx1 (d, m, m);
  d = __riscv_ztt_mmulbtaccneg_2d_i64_rnu_accx1 (d, m, m);
  asm volatile ("" : : "War" (d));
  asm volatile ("" : : "War" (old));
  asm volatile ("" : : "Wmr" (m));
}
