/* Packed ACC boundaries.  */
/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u128-m16-a16" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u128-m16-a16" { target rv64 } } */
#include <riscv_ztt.h>
#if __riscv_ztt_i8_u8_accx16_packed_irm != 15
#error missing complete packed copy capability
#endif
void invalid (void)
{
  __riscv_ztt_i8_rnu_accx16_t a = __riscv_ztt_mclear_acc_i8_rnu_accx16 ();
  __riscv_ztt_i8_rnu_1x16_t row = __riscv_ztt_mclear_m_i8_rnu_1x16 ();
  __riscv_ztt_i8_rnu_16x1_t column = __riscv_ztt_mclear_m_i8_rnu_16x1 ();
  a = __riscv_ztt_mmulacc_2d_i8_rnu_accx16 (a, row, column);
}
