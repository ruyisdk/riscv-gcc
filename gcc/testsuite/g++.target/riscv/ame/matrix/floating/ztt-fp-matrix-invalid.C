/* Compile/assemble contracts, not AME numerical execution tests.  */
/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u16-m32-a16" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u16-m32-a16" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>
void invalid (void)
{
  __riscv_ztt_f16_1x1_t a = __riscv_ztt_mzero_m_f16_1x1 ();
  __riscv_ztt_f32_1x1_t b = __riscv_ztt_mzero_m_f32_1x1 ();
  __riscv_ztt_f16_rno_1x1_t rm = __riscv_ztt_mzero_m_f16_rno_1x1 ();
  __riscv_ztt_f16_1x2_t wide = __riscv_ztt_mzero_m_f16_1x2 ();
  __riscv_ztt_i16_1x1_t i = __riscv_ztt_mzero_m_i16_1x1 ();
  __riscv_ztt_mmin_ew_f16_1x1 (a, b); /* { dg-error "required exact types" } */
  __riscv_ztt_mmax_ew_f16_1x1 (a, rm); /* { dg-error "required exact types" } */
  __riscv_ztt_mselge_ew_f16_1x1 (i, b); /* { dg-error "required exact types" } */
  __riscv_ztt_mmulacc_ew_f16_1x1 (rm, a, b); /* { dg-error "requires old_d" } */
  __riscv_ztt_madd_ew_f16_1x1 (wide, b); /* { dg-error "compatible types, shapes" } */
  __riscv_ztt_mcolgather_ew_f16_1x1 (a, b); /* { dg-error "indices must be integer" } */
  __riscv_ztt_mrowscatmax_ew_f16_1x1 (a, b, rm); /* { dg-error "indices must be integer" } */
  __riscv_ztt_msll_ew_i16_1x1 (a, i); /* { dg-error "floating operands are not implemented" } */
}
