/* Nonpacked ACC tuples.  */
/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u128-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u128-m16-a4" { target rv64 } } */
#include <riscv_ztt.h>
#ifdef __riscv_ztt_acc_tuple_copy
#error unsupported tuple capability exposed
#endif
void invalid (void)
{
  __riscv_ztt_i32_rnu_accx2_t x; /* { dg-error "unknown type name|was not declared" } */
}
