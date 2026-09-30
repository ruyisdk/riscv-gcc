/* Function-local frame policy.  */
/* { dg-do compile } */
/* { dg-options "-O2 -g -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -g -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv64 } } */

#include <riscv_ztt.h>
extern "C" {
void asm_m (void)
{
  __riscv_ztt_i8_rne_1x1_t value;
  __asm__ volatile ("# produce %0" : "=Wmr" (value));
  __asm__ volatile ("# consume %0" : : "Wmr" (value));
}
}

/* { dg-final { scan-assembler-times "csrr\\ts11,amenlen" 1 } } */
/* { dg-final { scan-assembler "\\.cfi_offset 27," } } */
/* { dg-final { scan-assembler "\\.cfi_restore 27" } } */
/* { dg-final { scan-assembler "msettyp" } } */
