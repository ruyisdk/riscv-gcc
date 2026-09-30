/* Packed ACC boundaries.  */
/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u16-m16-a1" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u16-m16-a1" { target rv64 } } */
#include <riscv_ztt.h>
#ifdef __riscv_ztt_acc_packed_copy
#error unsupported packed capability
#endif
void invalid (void)
{
  __riscv_ztt_i8_rnu_accx2_t a; /* { dg-error "unknown type name|was not declared" } */
}
