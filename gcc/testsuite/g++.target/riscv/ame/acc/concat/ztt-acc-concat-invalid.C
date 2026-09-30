/* Source-shape diagnostics.  */
/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv64 } } */
#include <riscv_ztt.h>
void invalid (void)
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
  __riscv_ztt_mmulacc_2d_i8_rnu_accx2 (a, r, r); /* { dg-error "incompatible|cannot convert" } */
  __riscv_ztt_mmulaccneg_2d_i8_rnu_accx2 (a, c, r); /* { dg-error "incompatible|cannot convert" } */
  __riscv_ztt_mmulacc_2d_i8_rnu_accx2 (a, r, c4); /* { dg-error "incompatible|cannot convert" } */
  __riscv_ztt_mmulatacc_2d_i8_rnu_accx2 (a, r, c); /* { dg-error "incompatible|cannot convert" } */
  __riscv_ztt_mmulataccneg_2d_i8_rnu_accx2 (a, c, r); /* { dg-error "incompatible|cannot convert" } */
  __riscv_ztt_mmulbtacc_2d_i8_rnu_accx2 (a, r, r4); /* { dg-error "incompatible|cannot convert" } */
  __riscv_ztt_mmulbtaccneg_2d_i8_rnu_accx2 (a, c4, c); /* { dg-error "incompatible|cannot convert" } */
  __riscv_ztt_mmulacc_2d_i8_rnu_accx2 (one, r, c); /* { dg-error "incompatible|cannot convert" } */
  __riscv_ztt_mmulatacc_2d_i8_rnu_accx2 (rm, r, r); /* { dg-error "incompatible|cannot convert" } */
  __riscv_ztt_mmulbtacc_2d_i8_rnu_accx2 (a, rrm, r); /* Mixed sources are now valid. */
  __riscv_ztt_mmulacc_2d_i8_rnu_accx2 (a, r, wide); /* Mixed sources are now valid. */
  __riscv_ztt_mmulataccneg_2d_i8_rnu_accx2 (a, ur, r); /* Mixed sources are now valid. */
  __riscv_ztt_mmulacc_2d_i8_rnu_accx2 (a); /* { dg-error "too few arguments" } */
}
