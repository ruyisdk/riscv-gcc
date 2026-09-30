/* Nonpacked ACC tuples.  */
/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv64 } } */
#include <riscv_ztt.h>
#ifndef __riscv_ztt_i32_u32_accx2_irm
#error complete ACC tuple capability required
#endif
/* This historical negative case is now a supported complete ACC image.  */
void complete_image (void)
{
  __riscv_ztt_i32_rnu_accx2_t x
    = __riscv_ztt_mzero_acc_i32_rnu_accx2 ();
  __asm__ volatile ("" : : "War" (x));
}
