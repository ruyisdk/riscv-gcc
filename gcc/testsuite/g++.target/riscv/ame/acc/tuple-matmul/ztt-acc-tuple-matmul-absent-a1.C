/* Tuple matmul contracts.  */
/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a1" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a1" { target rv64 } } */
#include <riscv_ztt.h>
#ifdef __riscv_ztt_acc_tuple_matmul_1x1
#error unsupported tuple matmul capability exposed
#endif
void absent (void)
{
  (void) __riscv_ztt_mmulacc_2d_i8_rnu_accx2; /* { dg-error "undeclared|was not declared" } */
}
