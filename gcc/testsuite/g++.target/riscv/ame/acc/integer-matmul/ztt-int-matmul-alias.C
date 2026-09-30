/* Compile/assemble checks, not numerical execution evidence.  */
/* { dg-do assemble } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a2" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a2" { target rv64 } } */
#include <riscv_ztt.h>
void alias (void)
{
  __riscv_ztt_i4_rnu_accx2_t d = __riscv_ztt_mzero_acc_i4_accx2 ();
  __riscv_ztt_i4_rnu_1x2_t a = __riscv_ztt_mzero_m_i4_1x2 ();
  d = __riscv_ztt_mmulatacc_2d_i4_accx2 (d, a, a);
  __asm__ volatile ("" : : "War" (d), "Wmr" (a));
}
