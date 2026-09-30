/* Experimental single-M clear/zero names from intrinsic draft v0.2.4.  */
/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv64 } } */


#include <riscv_ztt.h>

void
invalid (void)
{
  __riscv_ztt_mclear_m_i8_rne_1x1 (0); /* { dg-error "too many arguments" } */
  __riscv_ztt_mzero_m_i8_rne_1x1 (0); /* { dg-error "too many arguments" } */
  /* These groups exceed M16 or Acc4; their smaller forms are supported.  */
  __riscv_ztt_mclear_m_i64_1x4 (); /* { dg-error "was not declared" } */
  __riscv_ztt_mzero_acc_i64_rne_accx8 (); /* { dg-error "was not declared" } */
  __riscv_ztt_mclear_m_i8_rne_1x32 (); /* { dg-error "was not declared" } */
}
