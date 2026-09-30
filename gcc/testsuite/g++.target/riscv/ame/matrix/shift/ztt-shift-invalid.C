/* shifts.  */
/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>
void invalid (void)
{
  int ordinary;
  __riscv_ztt_u32_1x1_t u = __riscv_ztt_mzero_m_u32_1x1 ();
  __riscv_ztt_i32_1x1_t i = __riscv_ztt_mzero_m_i32_1x1 ();
  __riscv_ztt_i16_1x2_t s = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i32_accx1_t a = __riscv_ztt_mzero_acc_i32_accx1 ();
  (void) __riscv_ztt_msra_ew_i32_1x1 (u, u); /* { dg-error "signed data source" } */
  (void) __riscv_ztt_msra_ew_x_i32_1x1 (u, 3); /* { dg-error "signed data source" } */
  (void) __riscv_ztt_msll_ew_i32_1x1 (s, i); /* { dg-error "with the result shape" } */
  (void) __riscv_ztt_msrl_ew_i32_1x1 (i, s); /* { dg-error "with the result shape" } */
  (void) __riscv_ztt_msll_ew_i32_1x1 (a, i); /* { dg-error "with the result shape" } */
  (void) __riscv_ztt_msll_ew_i32_1x1 (i, a); /* { dg-error "with the result shape" } */
  (void) __riscv_ztt_msll_ew_i32_1x1 (i, 3); /* { dg-error "with the result shape" } */
  (void) __riscv_ztt_msll_ew_x_i32_1x1 (i, 1.5); /* { dg-error "count must be an integer" } */
  (void) __riscv_ztt_msll_ew_x_i32_1x1 (i, &ordinary); /* { dg-error "count must be an integer" } */
  (void) __riscv_ztt_msll_ew_x_i32_1x1 (i, i); /* { dg-error "count must be an integer" } */
}
