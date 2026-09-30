/* Former mixed-only rejections.  */
#include <stdint.h>
#include <riscv_ztt.h>
void ztt_acc_matmul_invalid_now_valid (void)
{
  __riscv_ztt_i32_rnu_accx1_t a = __riscv_ztt_mzero_acc_i32_rnu_accx1 ();
  __riscv_ztt_i32_rnu_1x1_t m = __riscv_ztt_mzero_m_i32_rnu_1x1 ();
  __riscv_ztt_u32_rnu_1x1_t u = __riscv_ztt_mzero_m_u32_rnu_1x1 ();
  __riscv_ztt_i32_rne_1x1_t r = __riscv_ztt_mzero_m_i32_rne_1x1 ();
  __riscv_ztt_i32_rnu_1x2_t wide = __riscv_ztt_mzero_m_i32_rnu_1x2 ();
  __riscv_ztt_mmulaccneg_2d_i32_rnu_accx1 (a, m, u);
  __riscv_ztt_mmulatacc_2d_i32_rnu_accx1 (a, m, u);
  __riscv_ztt_mmulataccneg_2d_i32_rnu_accx1 (a, m, u);
  __riscv_ztt_mmulbtacc_2d_i32_rnu_accx1 (a, m, u);
  __riscv_ztt_mmulbtaccneg_2d_i32_rnu_accx1 (a, m, u);
  __riscv_ztt_mmulatacc_2d_i32_rnu_accx1 (a, r, m);
}

void ztt_acc_types_now_valid (void)
{
  __riscv_ztt_i32_rnu_1x1_t m = __riscv_ztt_mclear_m_i32_rnu_1x1 ();
  __riscv_ztt_i32_rne_1x1_t r = __riscv_ztt_mclear_m_i32_rne_1x1 ();
  __riscv_ztt_u32_rnu_1x1_t u = __riscv_ztt_mclear_m_u32_rnu_1x1 ();
  __riscv_ztt_i32_accx1_t a = __riscv_ztt_mclear_acc_i32_accx1 ();
  __riscv_ztt_mmulacc_2d_i32_accx1 (a, r, m);
}
