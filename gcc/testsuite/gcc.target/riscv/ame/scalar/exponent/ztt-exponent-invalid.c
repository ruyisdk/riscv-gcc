/* Matrix mathematics; compile contracts are not numerical execution.  */
/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u16-m32-a16" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u16-m32-a16" { target rv64 } } */
#include <riscv_ztt.h>
void invalid (long exponent)
{
  __riscv_ztt_i16_1x1_t a = __riscv_ztt_mzero_m_i16_1x1 ();
  __riscv_ztt_i16_1x2_t pair = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i16_rne_1x1_t rm = __riscv_ztt_mzero_m_i16_rne_1x1 ();
  __riscv_ztt_i16_accx1_t acc = __riscv_ztt_mzero_acc_i16_accx1 ();
  __riscv_ztt_mldexp_ew_x_i16_1x1 (a, 1.0); /* { dg-error "exponent control must be an integer" } */
  __riscv_ztt_mldexp_ew_x_i16_1x1 (a, &exponent); /* { dg-error "exponent control must be an integer" } */
  __riscv_ztt_mldexp_ew_x_i16_1x1 (pair, exponent); /* { dg-error "identical shapes and complete groups" } */
  __riscv_ztt_mldexp_ew_x_i16_1x1 (acc, exponent); /* { dg-error "numeric M operands" } */
  __riscv_ztt_mldexpacc_ew_x_i16_1x1 (rm, a, exponent); /* { dg-error "exact result datatype and shape" } */
  __riscv_ztt_mldexpacc_ew_x_i16_1x1 (a, a, ~0ULL); /* { dg-error "exponent control exceeds" } */
}
