/* { dg-do assemble } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv64 } } */
#include <riscv_ztt.h>
void defaults (void)
{
  __riscv_ztt_i64_1x1_t a = __riscv_ztt_mclear_m_i64_1x1 ();
  __riscv_ztt_i64_rnu_1x1_t b = __riscv_ztt_mcopy_m2m_i64_1x1 (a);
  __riscv_ztt_i64_accx1_t acc = __riscv_ztt_mcopy_m2a_i64_accx1 (b);
  a = __riscv_ztt_mcopy_a2m_i64_1x1 (acc);
  __riscv_ztt_u128_1x1_t c = __riscv_ztt_mzero_m_u128_1x1 ();
  __riscv_ztt_u128_rnu_accx1_t d = __riscv_ztt_mcopy_m2a_u128_accx1 (c);
  c = __riscv_ztt_mcopy_a2m_u128_1x1 (d);
  __asm__ volatile ("" : : "Wmr" (a), "Wmr" (c));
}
