/* UDS32, i32/RNU only.  */
/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m16-a1" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m16-a1" { target rv64 } } */
/* { dg-additional-options "-ffat-lto-objects" } */
#include <riscv_ztt.h>
extern void other (void);
void normal_call (void)
{
  __riscv_ztt_i32_accx1_t a = __riscv_ztt_mclear_acc_i32_accx1 ();
  asm volatile ("" : : "War" (a));
  other ();
  a = __riscv_ztt_mzero_acc_i32_accx1 ();
  asm volatile ("" : : "War" (a));
}
