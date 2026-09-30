/* integer arithmetic.  */
/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv64 } } */
#include <riscv_ztt.h>
void invalid (void)
{
  __riscv_ztt_i16_1x2_t row = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i16_2x1_t col = __riscv_ztt_mzero_m_i16_2x1 ();
  __riscv_ztt_i32_1x1_t sq = __riscv_ztt_mzero_m_i32_1x1 ();
  __riscv_ztt_i32_accx1_t acc = __riscv_ztt_mzero_acc_i32_accx1 ();
  (void) __riscv_ztt_mabsdiff_ew_i16_1x2 (col, row); /* { dg-error "with the result shape" } */
  (void) __riscv_ztt_mabsdiff_ew_i16_1x2 (row, col); /* { dg-error "with the result shape" } */
  (void) __riscv_ztt_mabsdiff_ew_i16_1x2 (sq, row); /* { dg-error "with the result shape" } */
  (void) __riscv_ztt_mabsdiff_ew_i32_1x1 (acc, sq); /* { dg-error "with the result shape" } */
  (void) __riscv_ztt_mabsdiff_ew_i32_1x1 (sq, acc); /* { dg-error "with the result shape" } */
  (void) __riscv_ztt_mabsdiff_ew_i32_1x1 (sq, 0); /* { dg-error "with the result shape" } */
  (void) __riscv_ztt_mabsdiff_ew_i32_1x1 (1.5, sq); /* { dg-error "with the result shape" } */
  (void) __riscv_ztt_mabsdiff_ew_i32_1x1 (sq); /* { dg-error "too few arguments" } */
  (void) __riscv_ztt_mabsdiff_ew_i32_1x1 (sq, sq, sq); /* { dg-error "too many arguments" } */
  (void) __riscv_ztt_mhdiff_ew_i16_1x2 (col, row); /* { dg-error "with the result shape" } */
  (void) __riscv_ztt_mhdiff_ew_i16_1x2 (row, col); /* { dg-error "with the result shape" } */
  (void) __riscv_ztt_mhdiff_ew_i16_1x2 (sq, row); /* { dg-error "with the result shape" } */
  (void) __riscv_ztt_mhdiff_ew_i32_1x1 (acc, sq); /* { dg-error "with the result shape" } */
  (void) __riscv_ztt_mhdiff_ew_i32_1x1 (sq, acc); /* { dg-error "with the result shape" } */
  (void) __riscv_ztt_mhdiff_ew_i32_1x1 (sq, 0); /* { dg-error "with the result shape" } */
  (void) __riscv_ztt_mhdiff_ew_i32_1x1 (1.5, sq); /* { dg-error "with the result shape" } */
  (void) __riscv_ztt_mhdiff_ew_i32_1x1 (sq); /* { dg-error "too few arguments" } */
  (void) __riscv_ztt_mhdiff_ew_i32_1x1 (sq, sq, sq); /* { dg-error "too many arguments" } */
  (void) __riscv_ztt_mmean_ew_i16_1x2 (col, row); /* { dg-error "with the result shape" } */
  (void) __riscv_ztt_mmean_ew_i16_1x2 (row, col); /* { dg-error "with the result shape" } */
  (void) __riscv_ztt_mmean_ew_i16_1x2 (sq, row); /* { dg-error "with the result shape" } */
  (void) __riscv_ztt_mmean_ew_i32_1x1 (acc, sq); /* { dg-error "with the result shape" } */
  (void) __riscv_ztt_mmean_ew_i32_1x1 (sq, acc); /* { dg-error "with the result shape" } */
  (void) __riscv_ztt_mmean_ew_i32_1x1 (sq, 0); /* { dg-error "with the result shape" } */
  (void) __riscv_ztt_mmean_ew_i32_1x1 (1.5, sq); /* { dg-error "with the result shape" } */
  (void) __riscv_ztt_mmean_ew_i32_1x1 (sq); /* { dg-error "too few arguments" } */
  (void) __riscv_ztt_mmean_ew_i32_1x1 (sq, sq, sq); /* { dg-error "too many arguments" } */
  (void) __riscv_ztt_mmulneg_ew_i16_1x2 (col, row); /* { dg-error "with the result shape" } */
  (void) __riscv_ztt_mmulneg_ew_i16_1x2 (row, col); /* { dg-error "with the result shape" } */
  (void) __riscv_ztt_mmulneg_ew_i16_1x2 (sq, row); /* { dg-error "with the result shape" } */
  (void) __riscv_ztt_mmulneg_ew_i32_1x1 (acc, sq); /* { dg-error "with the result shape" } */
  (void) __riscv_ztt_mmulneg_ew_i32_1x1 (sq, acc); /* { dg-error "with the result shape" } */
  (void) __riscv_ztt_mmulneg_ew_i32_1x1 (sq, 0); /* { dg-error "with the result shape" } */
  (void) __riscv_ztt_mmulneg_ew_i32_1x1 (1.5, sq); /* { dg-error "with the result shape" } */
  (void) __riscv_ztt_mmulneg_ew_i32_1x1 (sq); /* { dg-error "too few arguments" } */
  (void) __riscv_ztt_mmulneg_ew_i32_1x1 (sq, sq, sq); /* { dg-error "too many arguments" } */
}
