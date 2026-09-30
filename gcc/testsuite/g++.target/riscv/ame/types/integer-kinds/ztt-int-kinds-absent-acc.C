/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u128-m16-a16 " { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u128-m16-a16 " { target rv64 } } */
#include <riscv_ztt.h>
void absent (void)
{
  __riscv_ztt_i4_rnu_accx16_t partial; /* { dg-error "unknown type name|not declared|does not name" } */
}
