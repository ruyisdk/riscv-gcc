/* Source-shape diagnostics.  */
/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u64-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u64-m16-a4" { target rv64 } } */
#include <riscv_ztt.h>
#ifdef __riscv_ztt_acc_matmul_concat
#error concatenated ACC support is not available in this profile
#endif
void absent (void)
{
  (void) __riscv_ztt_mmulacc_2d_i8_rnu_accx2; /* { dg-error "undeclared|was not declared" } */
}
