/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a16" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a16" { target rv64 } } */
#include <riscv_ztt.h>
void invalid (void)
{
  __riscv_ztt_i8_rnu_sat_1x2_t a = __riscv_ztt_mzero_m_i8_sat_1x2 ();
  __riscv_ztt_u8_rnu_1x2_t b = __riscv_ztt_mzero_m_u8_1x2 ();
  __riscv_ztt_i16_rne_1x2_t c = __riscv_ztt_mzero_m_i16_rne_1x2 ();
  __riscv_ztt_i8_rnu_sat_2x1_t shape = __riscv_ztt_mzero_m_i8_sat_2x1 ();
  __riscv_ztt_madd_ew_i8_sat_1x2 (a, shape); /* { dg-error "compatible types, shapes and complete M groups" } */
  __riscv_ztt_mmul_ew_i8_sat_1x2 (a, 1); /* { dg-error "compatible types, shapes and complete M groups" } */
  __riscv_ztt_msra_ew_i8_sat_1x2 (b, a); /* { dg-error "compatible types, shapes and complete M groups" } */
  __riscv_ztt_msra_ew_x_i8_sat_1x2 (b, 1); /* { dg-error "compatible types, shapes and complete M groups" } */
  __riscv_ztt_msll_ew_x_i8_sat_1x2 (a, 1.5); /* { dg-error "count must be an integer" } */
  __riscv_ztt_mmulacc_ew_i8_sat_1x2 (c, a, b); /* { dg-error "requires old_d" } */
  __riscv_ztt_mselge_ew_i8_sat_1x2 (b, c); /* { dg-error "compatible types, shapes and complete M groups" } */
  __riscv_ztt_mcmovge_ew_i8_sat_1x2 (a, b, c); /* { dg-error "compatible types, shapes and complete M groups" } */
  __riscv_ztt_i8_rnu_sat_1x1_t x = __riscv_ztt_mzero_m_i8_sat_1x1 ();
  __riscv_ztt_u8_rnu_1x1_t index = __riscv_ztt_mzero_m_u8_1x1 ();
  __riscv_ztt_mcolgather_ew_i8_sat_1x1 (index, index); /* { dg-error "compatible types, shapes and complete M groups" } */
  __riscv_ztt_mrowscatadd_ew_i8_sat_1x1 (index, x, index); /* { dg-error "requires old_d" } */
}
