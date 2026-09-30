/* Nonpacked ACC tuples.  */
/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u64-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u64-m16-a4" { target rv64 } } */
#include <riscv_ztt.h>
#ifdef __riscv_ztt_acc_tuple_copy
#error unsupported tuple capability exposed
#endif
void invalid (void)
{
  __riscv_ztt_i32_rnu_accx2_t a = __riscv_ztt_mclear_acc_i32_rnu_accx2 ();
  __riscv_ztt_i32_rnu_1x2_t row = __riscv_ztt_mclear_m_i32_rnu_1x2 ();
  __riscv_ztt_i32_rnu_2x1_t column = __riscv_ztt_mclear_m_i32_rnu_2x1 ();
  a = __riscv_ztt_mmulacc_2d_i32_rnu_accx2 (a, row, column);
}
