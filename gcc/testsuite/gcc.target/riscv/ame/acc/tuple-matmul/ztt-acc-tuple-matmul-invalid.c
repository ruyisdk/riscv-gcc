/* Tuple matmul contracts.  */
/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>
void invalid (int8_t *p)
{
  __riscv_ztt_i8_rnu_1x1_t m = __riscv_ztt_mls_rm_i8_rnu_1x1 (p);
  __riscv_ztt_i8_rnu_1x2_t shape = __riscv_ztt_mls_rm_i8_rnu_1x2 (p);
  __riscv_ztt_i8_rne_1x1_t rm = __riscv_ztt_mls_rm_i8_rne_1x1 (p);
  __riscv_ztt_i16_rnu_1x1_t width = __riscv_ztt_mclear_m_i16_rnu_1x1 ();
  __riscv_ztt_i8_rnu_accx2_t a = __riscv_ztt_mclear_acc_i8_rnu_accx2 ();
  __riscv_ztt_i8_rnu_accx4_t b = __riscv_ztt_mclear_acc_i8_rnu_accx4 ();
  __riscv_ztt_u8_rnu_accx2_t u = __riscv_ztt_mclear_acc_u8_rnu_accx2 ();
  __riscv_ztt_i8_rne_accx2_t r = __riscv_ztt_mclear_acc_i8_rne_accx2 ();
  __riscv_ztt_mmulacc_2d_i8_rnu_accx2 (b, m, m); /* { dg-error "incompatible|cannot convert" } */
  __riscv_ztt_mmulaccneg_2d_i8_rnu_accx2 (u, m, m); /* { dg-error "incompatible|cannot convert" } */
  __riscv_ztt_mmulatacc_2d_i8_rnu_accx2 (r, m, m); /* { dg-error "incompatible|cannot convert" } */
  __riscv_ztt_mmulataccneg_2d_i8_rnu_accx2 (a, shape, m); /* { dg-error "incompatible|cannot convert" } */
  __riscv_ztt_mmulbtacc_2d_i8_rnu_accx2 (a, m, shape); /* { dg-error "incompatible|cannot convert" } */
  __riscv_ztt_mmulbtaccneg_2d_i8_rnu_accx2 (a, width, m); /* Mixed sources are now valid. */
  __riscv_ztt_mmulacc_2d_i8_rnu_accx2 (a, m, rm); /* Mixed sources are now valid. */
}
