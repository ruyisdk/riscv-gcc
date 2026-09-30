/* integer index constructors.  */
/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv64 } } */
#include <riscv_ztt.h>
void wrong (void)
{
  __riscv_ztt_mrowid_ew_i8_rnu_1x1 (1); /* { dg-error "too many arguments" } */
  __riscv_ztt_mcolid_ew_u32_rod_1x1 (1); /* { dg-error "too many arguments" } */
  __riscv_ztt_mrowid_ew_i8_rnu_1x2 (); /* { dg-error "implicit declaration" } */
  __riscv_ztt_mcolid_ew_u16_rnu_2x1 (); /* { dg-error "implicit declaration" } */
  __riscv_ztt_mrowid_ew_f64_rne_1x1 (); /* { dg-error "implicit declaration" } */
}
