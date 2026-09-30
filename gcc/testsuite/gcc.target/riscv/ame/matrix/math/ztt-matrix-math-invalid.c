/* Matrix mathematics; compile contracts are not numerical execution.  */
/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u16-m32-a16" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u16-m32-a16" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>
void invalid (void)
{
  __riscv_ztt_f16_1x1_t f = __riscv_ztt_mzero_m_f16_1x1 ();
  __riscv_ztt_i16_1x1_t i = __riscv_ztt_mzero_m_i16_1x1 ();
  __riscv_ztt_f16_rno_1x1_t rm = __riscv_ztt_mzero_m_f16_rno_1x1 ();
  __riscv_ztt_f16_1x2_t wide = __riscv_ztt_mzero_m_f16_1x2 ();
  __riscv_ztt_mldexp_ew_f16_1x1 (f, f); /* { dg-error "exponents must be integer" } */
  __riscv_ztt_mrdexp_ew_i16_1x1 (i, f); /* { dg-error "exponents must be integer" } */
  __riscv_ztt_mldexpacc_ew_f16_1x1 (rm, f, i); /* { dg-error "requires old_d" } */
  __riscv_ztt_mrdexpacc_ew_f16_1x1 (f, f, f); /* { dg-error "exponents must be integer" } */
  __riscv_ztt_mlog2sub_ew_f16_1x1 (i, f); /* { dg-error "logarithm data and results must be floating-point" } */
  __riscv_ztt_msublog2_ew_f16_1x1 (i, i); /* { dg-error "logarithm data and results must be floating-point" } */
  __riscv_ztt_mldexp_ew_f16_1x1 (wide, i); /* { dg-error "compatible shapes" } */
}
