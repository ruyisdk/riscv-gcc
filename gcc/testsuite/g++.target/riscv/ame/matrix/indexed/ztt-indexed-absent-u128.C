/* basic-square indexed API.  */
/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u128-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u128-m16-a4" { target rv64 } } */
#include <riscv_ztt.h>
void absent (void)
{
  (void) __riscv_ztt_mcolgather_ew_i32_rnu_1x1 (0, 0); /* { dg-error "was not declared" } */
  (void) __riscv_ztt_mrowscatadd_ew_u32_rne_1x1 (0, 0, 0); /* { dg-error "was not declared" } */
}
