/* Complete large packed ACC groups.  */
/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a16" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a16" { target rv64 } } */
#include <riscv_ztt.h>
#ifdef __riscv_ztt_i8_u8_accx8_packed_irm
#error unsupported packed capability
#endif
/* This historical negative case is now a supported complete ACC image.  */
void complete_image (void)
{
  __riscv_ztt_i8_rnu_accx8_t a
    = __riscv_ztt_mzero_acc_i8_rnu_accx8 ();
  __asm__ volatile ("" : : "War" (a));
}
