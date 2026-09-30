/* Former mixed-only rejections.  */
#include <stdint.h>
#include <riscv_ztt.h>
void ztt_acc_concat_invalid_now_valid (void)
{
  __riscv_ztt_i8_rnu_accx2_t a = __riscv_ztt_mclear_acc_i8_rnu_accx2 ();
  __riscv_ztt_i8_rnu_accx1_t one = __riscv_ztt_mclear_acc_i8_rnu_accx1 ();
  __riscv_ztt_i8_rne_accx2_t rm = __riscv_ztt_mclear_acc_i8_rne_accx2 ();
  __riscv_ztt_i8_rnu_1x2_t r = __riscv_ztt_mclear_m_i8_rnu_1x2 ();
  __riscv_ztt_i8_rnu_2x1_t c = __riscv_ztt_mclear_m_i8_rnu_2x1 ();
  __riscv_ztt_i8_rnu_1x4_t r4 = __riscv_ztt_mclear_m_i8_rnu_1x4 ();
  __riscv_ztt_i8_rnu_4x1_t c4 = __riscv_ztt_mclear_m_i8_rnu_4x1 ();
  __riscv_ztt_i8_rne_1x2_t rrm = __riscv_ztt_mclear_m_i8_rne_1x2 ();
  __riscv_ztt_u8_rnu_1x2_t ur = __riscv_ztt_mclear_m_u8_rnu_1x2 ();
  __riscv_ztt_i16_rnu_2x1_t wide = __riscv_ztt_mclear_m_i16_rnu_2x1 ();
  __riscv_ztt_mmulbtacc_2d_i8_rnu_accx2 (a, rrm, r);
  __riscv_ztt_mmulacc_2d_i8_rnu_accx2 (a, r, wide);
  __riscv_ztt_mmulataccneg_2d_i8_rnu_accx2 (a, ur, r);
}

void ztt_acc_tuple_matmul_invalid_now_valid (int8_t *p)
{
  __riscv_ztt_i8_rnu_1x1_t m = __riscv_ztt_mls_rm_i8_rnu_1x1 (p);
  __riscv_ztt_i8_rnu_1x2_t shape = __riscv_ztt_mls_rm_i8_rnu_1x2 (p);
  __riscv_ztt_i8_rne_1x1_t rm = __riscv_ztt_mls_rm_i8_rne_1x1 (p);
  __riscv_ztt_i16_rnu_1x1_t width = __riscv_ztt_mclear_m_i16_rnu_1x1 ();
  __riscv_ztt_i8_rnu_accx2_t a = __riscv_ztt_mclear_acc_i8_rnu_accx2 ();
  __riscv_ztt_i8_rnu_accx4_t b = __riscv_ztt_mclear_acc_i8_rnu_accx4 ();
  __riscv_ztt_u8_rnu_accx2_t u = __riscv_ztt_mclear_acc_u8_rnu_accx2 ();
  __riscv_ztt_i8_rne_accx2_t r = __riscv_ztt_mclear_acc_i8_rne_accx2 ();
  __riscv_ztt_mmulbtaccneg_2d_i8_rnu_accx2 (a, width, m);
  __riscv_ztt_mmulacc_2d_i8_rnu_accx2 (a, m, rm);
}

void ztt_acc_width_invalid_now_valid (int8_t *p)
{
  __riscv_ztt_i8_rnu_1x1_t m = __riscv_ztt_mls_rm_i8_rnu_1x1 (p);
  __riscv_ztt_i8_rnu_accx1_t a = __riscv_ztt_mcopy_m2a_i8_rnu_accx1 (m);
  __riscv_ztt_i16_rnu_accx1_t b = __riscv_ztt_mclear_acc_i16_rnu_accx1 ();
  __riscv_ztt_u8_rnu_accx1_t u = __riscv_ztt_mclear_acc_u8_rnu_accx1 ();
  __riscv_ztt_i8_rne_accx1_t r = __riscv_ztt_mclear_acc_i8_rne_accx1 ();
  __riscv_ztt_mmulacc_2d_i16_rnu_accx1 (b, m, m);
}
