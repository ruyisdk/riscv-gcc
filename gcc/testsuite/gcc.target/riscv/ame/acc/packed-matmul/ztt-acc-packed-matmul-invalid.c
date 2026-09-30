/* Complete packed matmul.  */
/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m16-a16" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m16-a16" { target rv64 } } */
#include <riscv_ztt.h>
void invalid (void)
{
  __riscv_ztt_i8_rnu_accx4_t a = __riscv_ztt_mclear_acc_i8_rnu_accx4 ();
  __riscv_ztt_i8_rne_accx4_t rm = __riscv_ztt_mclear_acc_i8_rne_accx4 ();
  __riscv_ztt_u8_rnu_accx4_t sign = __riscv_ztt_mclear_acc_u8_rnu_accx4 ();
  __riscv_ztt_i8_rnu_accx8_t count = __riscv_ztt_mclear_acc_i8_rnu_accx8 ();
  __riscv_ztt_i16_rnu_accx4_t wide = __riscv_ztt_mclear_acc_i16_rnu_accx4 ();
  __riscv_ztt_i8_rne_1x4_t l = __riscv_ztt_mclear_m_i8_rne_1x4 ();
  __riscv_ztt_u16_rod_4x1_t r = __riscv_ztt_mclear_m_u16_rod_4x1 ();
  __riscv_ztt_i8_rne_4x1_t col = __riscv_ztt_mclear_m_i8_rne_4x1 ();
  __riscv_ztt_u16_rod_8x1_t otherq = __riscv_ztt_mclear_m_u16_rod_8x1 ();
  __riscv_ztt_mmulacc_2d_i8_rnu_accx4 (rm, l, r); /* { dg-error "incompatible|cannot convert" } */
  __riscv_ztt_mmulacc_2d_i8_rnu_accx4 (sign, l, r); /* { dg-error "incompatible|cannot convert" } */
  __riscv_ztt_mmulacc_2d_i8_rnu_accx4 (count, l, r); /* { dg-error "incompatible|cannot convert" } */
  __riscv_ztt_mmulacc_2d_i8_rnu_accx4 (wide, l, r); /* { dg-error "incompatible|cannot convert" } */
  __riscv_ztt_mmulacc_2d_i8_rnu_accx4 (a, col, r); /* { dg-error "incompatible|cannot convert" } */
  __riscv_ztt_mmulatacc_2d_i8_rnu_accx4 (a, l, r); /* { dg-error "incompatible|cannot convert" } */
  __riscv_ztt_mmulacc_2d_i8_rnu_accx4 (a, l, otherq); /* { dg-error "incompatible|cannot convert" } */
  __riscv_ztt_mmulacc_2d_i8_rnu_accx4 (a, a, r); /* { dg-error "incompatible|cannot convert" } */
  __riscv_ztt_mmulacc_2d_i8_rnu_accx4 (a); /* { dg-error "too few arguments" } */
}
