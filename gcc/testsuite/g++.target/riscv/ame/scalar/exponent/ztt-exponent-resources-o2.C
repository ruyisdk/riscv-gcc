/* Matrix mathematics; compile contracts are not numerical execution.  */
/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a16" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a16" { target rv64 } } */
/* Distinct full-bank inputs.  */
#include <riscv_ztt.h>
/* { dg-additional-options "-ffat-lto-objects" } */

void
probe (long e)
{
  __riscv_ztt_i128_1x1_t a = __riscv_ztt_mzero_m_i128_1x1 ();
  __riscv_ztt_i128_1x1_t old = __riscv_ztt_mzero_m_i128_1x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_i128_1x1_t d = __riscv_ztt_mldexpacc_ew_x_i128_1x1 (old, a, e); /* { dg-error "exponent operation requires 32 simultaneously allocated M registers" } */
  __asm__ volatile ("" : : "Wmr" (d));
}
