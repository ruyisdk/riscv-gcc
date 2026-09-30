/* Compile/assemble contracts, not AME numerical execution tests.  */
/* { dg-do assemble } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u16-m32-a16" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u16-m32-a16" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>
void shared (void)
{
  __riscv_ztt_f16_1x2_t a = __riscv_ztt_mzero_m_f16_1x2 ();
  __riscv_ztt_f16_1x2_t b = __riscv_ztt_mmulacc_ew_f16_1x2 (a, a, a);
  __riscv_ztt_f16_1x2_t c = __riscv_ztt_mmax_ew_f16_1x2 (b, b);
  __asm__ volatile ("" : : "Wmr" (a), "Wmr" (b), "Wmr" (c));
}
void mixed_integer_result (void)
{
  __riscv_ztt_i16_1x1_t a = __riscv_ztt_mzero_m_i16_1x1 ();
  __riscv_ztt_f32_1x1_t b = __riscv_ztt_mzero_m_f32_1x1 ();
  __riscv_ztt_i16_1x1_t d = __riscv_ztt_madd_ew_i16_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
