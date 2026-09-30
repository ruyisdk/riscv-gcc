/* UDS8.  */
/* { dg-do compile } */
/* { dg-options " -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv32 } } */
/* { dg-options " -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv64 } } */
#include <riscv_ztt.h>
#ifndef __riscv_ztt_i32_rnu_accx1
#error wide i32 ACC capability required
#endif
void complete_wide_image (void)
{
  __riscv_ztt_i64_rnu_accx1_t a = __riscv_ztt_mzero_acc_i64_rnu_accx1 ();
  __asm__ volatile ("" : : "War" (a));
}
