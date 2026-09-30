/* Matrix mathematics; compile contracts are not numerical execution.  */
/* { dg-do assemble } */
/* { dg-options "-O0 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m32-a16" { target rv32 } } */
/* { dg-options "-O0 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m32-a16" { target rv64 } } */
#include <riscv_ztt.h>
void shared (long e)
{
  __riscv_ztt_i128_1x2_t a = __riscv_ztt_mzero_m_i128_1x2 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i128_1x2_t d = __riscv_ztt_mldexpacc_ew_x_i128_1x2 (a, a, e);
  __asm__ volatile ("" : : "Wmr" (d));
}
