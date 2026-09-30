/* Compile/assemble checks, not numerical execution evidence.  */
/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a1" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a1" { target rv64 } } */
#include <riscv_ztt.h>
unsigned long dead (void)
{
  __riscv_ztt_i8_rne_sat_accx1_t d = __riscv_ztt_mzero_acc_i8_rne_sat_accx1 ();
  __riscv_ztt_i4_rne_1x2_t a = __riscv_ztt_mzero_m_i4_rne_1x2 ();
  __riscv_ztt_u8_rdn_2x1_t b = __riscv_ztt_mzero_m_u8_rdn_2x1 ();
  unsigned long before = __riscv_ztt_get_amexsat ();
  __riscv_ztt_mmulacc_2d_i8_rne_sat_accx1 (d, a, b);
  return __riscv_ztt_get_amexsat () - before;
}
/* { dg-final { scan-assembler-times {\tmmulacc\.2d\t} 1 } } */
/* { dg-final { scan-assembler-times {amexsat} 2 } } */
