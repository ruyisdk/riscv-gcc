/* { dg-do compile } */
/* { dg-options "-O2 -std=gnu11 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u128-m32-a16" { target rv32 } } */
/* { dg-options "-O2 -std=gnu11 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u128-m32-a16" { target rv64 } } */
#include <riscv_ztt.h>
void packed (void)
{
  __riscv_ztt_f64_1x2_t pair = __riscv_ztt_mzero_m_f64_1x2 ();
  (void) pair;
  (void) __riscv_ztt_mcolbcast_ew_x_f64_1x1; /* { dg-error "mcolbcast_ew_x_f64_1x1' (undeclared|was not declared)" } */
  (void) __riscv_ztt_mrowbcast_ew_x_f64_1x1; /* { dg-error "mrowbcast_ew_x_f64_1x1' (undeclared|was not declared)" } */
  (void) __riscv_ztt_mcolshift_ew_x_f64_1x1; /* { dg-error "mcolshift_ew_x_f64_1x1' (undeclared|was not declared)" } */
  (void) __riscv_ztt_mrowshift_ew_x_f64_1x1; /* { dg-error "mrowshift_ew_x_f64_1x1' (undeclared|was not declared)" } */
}
