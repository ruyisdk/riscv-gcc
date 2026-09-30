/* Compile/assemble checks, not numerical execution evidence.  */
/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u64-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u64-m16-a4" { target rv64 } } */
#include <riscv_ztt.h>
void invalid (void)
{
  __riscv_ztt_i64_rnu_accx2_t old = __riscv_ztt_mzero_acc_i64_accx2 ();
  __riscv_ztt_i64_rne_accx2_t rm = __riscv_ztt_mzero_acc_i64_rne_accx2 ();
  __riscv_ztt_i64_rnu_accx1_t one = __riscv_ztt_mzero_acc_i64_accx1 ();
  __riscv_ztt_i64_rnu_1x2_t ar = __riscv_ztt_mzero_m_i64_1x2 ();
  __riscv_ztt_u128_rod_2x1_t bc = __riscv_ztt_mzero_m_u128_rod_2x1 ();
  __riscv_ztt_i64_rnu_1x4_t four = __riscv_ztt_mzero_m_i64_1x4 ();
  __riscv_ztt_mmulacc_2d_i64_accx2 (rm, ar, bc); /* { dg-error "incompatible|cannot convert" } */
  __riscv_ztt_mmulacc_2d_i64_accx2 (one, ar, bc); /* { dg-error "incompatible|cannot convert" } */
  __riscv_ztt_mmulacc_2d_i64_accx2 (old, ar, ar); /* { dg-error "incompatible|cannot convert" } */
  __riscv_ztt_mmulatacc_2d_i64_accx2 (old, ar, bc); /* { dg-error "incompatible|cannot convert" } */
  __riscv_ztt_mmulbtacc_2d_i64_accx2 (old, four, ar); /* { dg-error "incompatible|cannot convert" } */
  __riscv_ztt_mmulaccneg_2d_i64_accx2 (old, old, bc); /* { dg-error "incompatible|cannot convert" } */
  __riscv_ztt_mmulacc_2d_i64_accx2 (old); /* { dg-error "too few arguments" } */
}
