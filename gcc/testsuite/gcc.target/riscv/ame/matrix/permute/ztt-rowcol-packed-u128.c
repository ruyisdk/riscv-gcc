/* row/column controls.  */
/* { dg-do compile } */
/* { dg-options "-O2 -std=gnu11 -fno-ipa-icf -Werror=implicit-function-declaration -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u128-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -std=gnu11 -fno-ipa-icf -Werror=implicit-function-declaration -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u128-m16-a4" { target rv64 } } */
#include <riscv_ztt.h>
void absent (void)
{
  __riscv_ztt_mcolbcast_ew_x_i32_rnu_1x1 (0, 0); /* { dg-error "implicit declaration|not declared" } */
  __riscv_ztt_mrowbcast_ew_x_i32_rnu_1x1 (0, 0); /* { dg-error "implicit declaration|not declared" } */
  __riscv_ztt_mcolshift_ew_x_i32_rnu_1x1 (0, 0); /* { dg-error "implicit declaration|not declared" } */
  __riscv_ztt_mrowshift_ew_x_i32_rnu_1x1 (0, 0); /* { dg-error "implicit declaration|not declared" } */
}
