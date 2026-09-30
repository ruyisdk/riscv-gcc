/* integer index constructors.  */
/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u128-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u128-m16-a4" { target rv64 } } */
#include <riscv_ztt.h>
#if defined (__riscv_ztt_mrowid_ew_int) || defined (__riscv_ztt_mcolid_ew_int)
#error no available basic-square integer type at this UDS
#endif
void absent (void)
{
  __riscv_ztt_mrowid_ew_i32_rnu_1x1 (); /* { dg-error "not declared" } */
  __riscv_ztt_mcolid_ew_i32_rnu_1x1 (); /* { dg-error "not declared" } */
}
