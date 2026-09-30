/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m32-a16" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m32-a16" { target rv64 } } */
#include <stddef.h>
#include <stdint.h>
#include <riscv_ztt.h>
void packed (void)
{
  __riscv_ztt_i16_1x2_t a = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_mcolzip_ew_i16_rnu_1x2 (a); /* { dg-error "implicit declaration|not declared" } */
}
