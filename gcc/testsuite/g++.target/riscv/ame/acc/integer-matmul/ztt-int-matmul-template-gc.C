/* Compile/assemble checks, not numerical execution evidence.  */
/* { dg-do compile } */
/* { dg-options "-O2 --param ggc-min-expand=0 --param ggc-min-heapsize=0 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv32 } } */
/* { dg-options "-O2 --param ggc-min-expand=0 --param ggc-min-heapsize=0 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv64 } } */
#include <riscv_ztt.h>
template<bool Neg>
void local_values ()
{
  __riscv_ztt_i8_rne_sat_accx4_t a = __riscv_ztt_mzero_acc_i8_rne_sat_accx4 ();
  __riscv_ztt_i4_rdn_1x8_t x = __riscv_ztt_mzero_m_i4_rdn_1x8 ();
  __riscv_ztt_u8_rod_8x1_t y = __riscv_ztt_mzero_m_u8_rod_8x1 ();
  if (Neg)
    a = __riscv_ztt_mmulaccneg_2d_i8_rne_sat_accx4 (a, x, y);
  else
    a = __riscv_ztt_mmulacc_2d_i8_rne_sat_accx4 (a, x, y);
  __asm__ volatile ("" : : "War" (a));
}
template void local_values<false> ();
template void local_values<true> ();
/* { dg-final { scan-assembler {\tmmulacc\.2d\t} } } */
/* { dg-final { scan-assembler {\tmmulaccneg\.2d\t} } } */
