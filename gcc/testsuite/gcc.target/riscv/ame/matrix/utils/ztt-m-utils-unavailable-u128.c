/* M utilities.  */
/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u128-m16-a1" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u128-m16-a1" { target rv64 } } */
#include <riscv_ztt.h>
void unavailable (void)
{
  (void) &__riscv_ztt_mconcat_m_i8_rnu_1x16; /* { dg-error "undeclared|not declared" } */
  (void) &__riscv_ztt_mextract_i8_rnu_1x8; /* { dg-error "undeclared|not declared" } */
}
