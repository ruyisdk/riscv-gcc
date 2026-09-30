/* Compilation checks only; no AME numerical execution is implied.  */
/* { dg-do assemble } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u16-m32-a16" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u16-m32-a16" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>
#if __riscv_ztt_floating_unary != 1
#error missing floating unary capability
#endif
void alias (void)
{
  __riscv_ztt_f16_1x1_t a = __riscv_ztt_mzero_m_f16_1x1 ();
  __riscv_ztt_f16_rne_1x1_t b = __riscv_ztt_msqrt_ew_f16_1x1 (a);
  __riscv_ztt_f16_rne_1x2_t c = __riscv_ztt_mconcat_m_f16_1x2 (a, b);
  __riscv_ztt_f16_1x1_t d = __riscv_ztt_mextract_f16_1x1 (c, 1);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
