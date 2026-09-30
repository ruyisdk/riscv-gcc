/* Packed ACC boundaries.  */
/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u128-m16-a2" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u128-m16-a2" { target rv64 } } */
#include <riscv_ztt.h>
#ifdef __riscv_ztt_acc_packed_copy
#error unsupported packed capability
#endif
void invalid (void)
{
  __riscv_ztt_i32_rnu_accx4_t a; /* { dg-error "unknown type name|was not declared" } */
}
