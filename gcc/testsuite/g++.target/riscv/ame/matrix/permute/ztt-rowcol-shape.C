/* row/column controls.  */
/* { dg-do compile } */
/* { dg-options "-O2 -std=gnu++17 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -std=gnu++17 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv64 } } */
#include <riscv_ztt.h>
void absent (void)
{
  __riscv_ztt_mcolbcast_ew_x_i32_rnu_1x2 (0, 0); /* { dg-error "implicit declaration|not declared" } */
  __riscv_ztt_mrowshift_ew_x_i32_rnu_2x1 (0, 0); /* { dg-error "implicit declaration|not declared" } */
}
