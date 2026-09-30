/* Matrix mathematics; compile contracts are not numerical execution.  */
/* { dg-do assemble } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u16-m32-a16" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u16-m32-a16" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>
void shared (void)
{
  __riscv_ztt_i16_1x2_t a = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i16_1x2_t b = __riscv_ztt_mldexpacc_ew_i16_1x2 (a, a, a);
  __riscv_ztt_i16_1x2_t c = __riscv_ztt_mrdexpacc_ew_i16_1x2 (b, b, b);
  __riscv_ztt_f16_1x2_t f = __riscv_ztt_mzero_m_f16_1x2 ();
  __riscv_ztt_f16_1x2_t g = __riscv_ztt_mlog2sub_ew_f16_1x2 (f, f);
  __asm__ volatile ("" : : "Wmr" (a), "Wmr" (b), "Wmr" (c), "Wmr" (f), "Wmr" (g));
}
