/* Complete large packed ACC groups.  */
/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u16-m16-a16" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u16-m16-a16" { target rv64 } } */
#include <riscv_ztt.h>
#ifndef __riscv_ztt_i8_u8_accx16_packed_irm
#error complete packed ACC capability required
#endif
/* This historical negative case is now a supported complete ACC image.  */
void complete_image (void)
{
  __riscv_ztt_i8_rnu_accx16_t a
    = __riscv_ztt_mzero_acc_i8_rnu_accx16 ();
  __asm__ volatile ("" : : "War" (a));
}
