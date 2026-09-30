/* exact old destination.  */
/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>
void invalid (void)
{
  __riscv_ztt_i16_1x2_t row = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i16_2x1_t col = __riscv_ztt_mzero_m_i16_2x1 ();
  __riscv_ztt_i16_rod_1x2_t rm = __riscv_ztt_mzero_m_i16_rod_1x2 ();
  __riscv_ztt_u16_1x2_t sign = __riscv_ztt_mzero_m_u16_1x2 ();
  __riscv_ztt_i32_1x1_t square = __riscv_ztt_mzero_m_i32_1x1 ();
  __riscv_ztt_i32_accx1_t acc = __riscv_ztt_mzero_acc_i32_accx1 ();
  (void) __riscv_ztt_mmulacc_ew_i16_1x2 (col, row, row); /* { dg-error "exact result datatype" } */
  (void) __riscv_ztt_mmulaccneg_ew_i16_1x2 (rm, row, row); /* { dg-error "exact result datatype" } */
  (void) __riscv_ztt_mmuladd_ew_i16_1x2 (sign, row, row); /* { dg-error "exact result datatype" } */
  (void) __riscv_ztt_mmulsub_ew_i16_1x2 (acc, row, row); /* { dg-error "exact result datatype" } */
  (void) __riscv_ztt_mmulacc_ew_i16_1x2 (3, row, row); /* { dg-error "exact result datatype" } */
  (void) __riscv_ztt_mmulacc_ew_i16_1x2 (row, col, row); /* { dg-error "with the result shape" } */
  (void) __riscv_ztt_mmulaccneg_ew_i16_1x2 (row, row, square); /* { dg-error "with the result shape" } */
  (void) __riscv_ztt_mmuladd_ew_i32_1x1 (square, acc, square); /* { dg-error "with the result shape" } */
  (void) __riscv_ztt_mmulsub_ew_i32_1x1 (square, square, 3); /* { dg-error "with the result shape" } */
  (void) __riscv_ztt_mmulacc_ew_i32_1x1 (square, 1.5, square); /* { dg-error "with the result shape" } */
  (void) __riscv_ztt_mmulacc_ew_i32_1x1 (square, square, (int *) 0); /* { dg-error "with the result shape" } */
  (void) __riscv_ztt_mmulacc_ew_i32_1x1 (square, square); /* { dg-error "too few arguments" } */
  (void) __riscv_ztt_mmulacc_ew_i32_1x1 (square, square, square, square); /* { dg-error "too many arguments" } */
}
