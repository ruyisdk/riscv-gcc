/* Mixed integer matmul.  */
/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u16-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u16-m16-a4" { target rv64 } } */
#include <riscv_ztt.h>
void invalid (void)
{
  __riscv_ztt_i16_rnu_accx2_t a = __riscv_ztt_mclear_acc_i16_rnu_accx2 ();
  __riscv_ztt_u16_rnu_accx2_t wrong_old = __riscv_ztt_mclear_acc_u16_rnu_accx2 ();
  __riscv_ztt_i16_rnu_accx1_t one = __riscv_ztt_mclear_acc_i16_rnu_accx1 ();
  __riscv_ztt_u16_rod_1x2_t lr = __riscv_ztt_mclear_m_u16_rod_1x2 ();
  __riscv_ztt_i32_rne_2x1_t rc = __riscv_ztt_mclear_m_i32_rne_2x1 ();
  __riscv_ztt_i8_rnu_1x2_t packed = __riscv_ztt_mclear_m_i8_rnu_1x2 ();
  __riscv_ztt_i8_rnu_2x1_t packed_column = __riscv_ztt_mclear_m_i8_rnu_2x1 ();
  __riscv_ztt_u16_rod_1x4_t four = __riscv_ztt_mclear_m_u16_rod_1x4 ();
  a = __riscv_ztt_mmulacc_2d_i16_rnu_accx2 (a, packed, rc);
  __riscv_ztt_mmulaccneg_2d_i16_rnu_accx2 (a, lr, packed); /* { dg-error "incompatible|cannot convert" } */
  a = __riscv_ztt_mmulaccneg_2d_i16_rnu_accx2 (a, lr, packed_column);
  __riscv_ztt_mmulacc_2d_i16_rnu_accx2 (wrong_old, lr, rc); /* { dg-error "incompatible|cannot convert" } */
  __riscv_ztt_mmulacc_2d_i16_rnu_accx2 (one, lr, rc); /* { dg-error "incompatible|cannot convert" } */
  __riscv_ztt_mmulacc_2d_i16_rnu_accx2 (a, lr, lr); /* { dg-error "incompatible|cannot convert" } */
  __riscv_ztt_mmulatacc_2d_i16_rnu_accx2 (a, lr, rc); /* { dg-error "incompatible|cannot convert" } */
  __riscv_ztt_mmulbtacc_2d_i16_rnu_accx2 (a, four, lr); /* { dg-error "incompatible|cannot convert" } */
  __riscv_ztt_mmulbtaccneg_2d_i16_rnu_accx2 (a, a, rc); /* { dg-error "incompatible|cannot convert" } */
  __riscv_ztt_mmulacc_2d_i16_rnu_accx2 (a); /* { dg-error "too few arguments" } */
}
