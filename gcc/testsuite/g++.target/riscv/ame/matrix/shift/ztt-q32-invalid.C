/* Q32.  */
/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u128-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u128-m16-a4" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>
void invalid (unsigned index)
{
  __riscv_ztt_i8_1x32_t row = __riscv_ztt_mzero_m_i8_1x32 ();
  __riscv_ztt_i8_32x1_t col = __riscv_ztt_mzero_m_i8_32x1 ();
  __riscv_ztt_u8_1x32_t u = __riscv_ztt_mzero_m_u8_1x32 ();
  __riscv_ztt_i8_1x16_t half = __riscv_ztt_mzero_m_i8_1x16 ();
  __riscv_ztt_i8_16x1_t colhalf = __riscv_ztt_mzero_m_i8_16x1 ();
  (void) __riscv_ztt_msra_ew_i8_1x32 (u, u); /* { dg-error "signed data source" } */
  (void) __riscv_ztt_msll_ew_i8_1x32 (row, col); /* { dg-error "with the result shape" } */
  (void) __riscv_ztt_msll_ew_i8_1x32 (half, row); /* { dg-error "with the result shape" } */
  (void) __riscv_ztt_msrl_ew_x_i8_1x32 (row, &index); /* { dg-error "count must be an integer" } */
  (void) __riscv_ztt_mextract_i8_1x16 (row, 2); /* { dg-error "integer constant 0 or 1" } */
  (void) __riscv_ztt_mextract_i8_1x16 (row, index); /* { dg-error "integer constant 0 or 1" } */
  (void) __riscv_ztt_mconcat_m_i8_1x32 (half, colhalf); /* { dg-error "incompatible type|cannot convert|could not convert" } */
}
