/* Tuple ABI remains private.  */
/* { dg-do compile } */
/* { dg-options "-O2 -ffat-lto-objects -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -ffat-lto-objects -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv64 } } */
#include <riscv_ztt.h>
extern void other (void);
void normal_call (void)
{
  __riscv_ztt_i8_accx2_t a = __riscv_ztt_mclear_acc_i8_accx2 ();
  asm volatile ("" : : "War" (a));
  other ();
  asm volatile ("" : : "War" (a));
}
