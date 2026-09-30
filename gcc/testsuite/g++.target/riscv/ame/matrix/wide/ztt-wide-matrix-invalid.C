/* Compile/assemble checks, not numerical execution evidence.  */
/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv64 } } */
#include <riscv_ztt.h>
void invalid (void)
{
  __riscv_ztt_i64_rnu_1x1_t a = __riscv_ztt_mzero_m_i64_rnu_1x1 ();
  __riscv_ztt_u64_rnu_1x1_t b = __riscv_ztt_mzero_m_u64_rnu_1x1 ();
  __riscv_ztt_i64_rne_1x1_t rm = __riscv_ztt_mzero_m_i64_rne_1x1 ();
  __riscv_ztt_i128_rdn_1x1_t w = __riscv_ztt_mzero_m_i128_rdn_1x1 ();
  __riscv_ztt_i64_rnu_1x2_t shape = __riscv_ztt_mzero_m_i64_rnu_1x2 ();
  __riscv_ztt_msra_ew_i64_1x1 (b, a); /* { dg-error "signed data source" } */
  __riscv_ztt_msra_ew_x_i64_1x1 (b, 1); /* { dg-error "signed data source" } */
  __riscv_ztt_msll_ew_x_i64_1x1 (a, 1.5); /* { dg-error "count must be an integer" } */
  __riscv_ztt_mmulacc_ew_i64_1x1 (rm, a, w); /* { dg-error "requires old_d" } */
  __riscv_ztt_mcmovge_ew_i64_1x1 (a, w, b); /* { dg-error "requires selected data" } */
  __riscv_ztt_mselge_ew_i64_1x1 (w, rm); /* { dg-error "requires selected data" } */
  __riscv_ztt_mmul_ew_i64_1x1 (a, shape); /* { dg-error "M operands with the result shape" } */
  __riscv_ztt_mconv_ew_i64_1x1 (shape); /* { dg-error "M operand with the result shape" } */
  __riscv_ztt_mcolgather_ew_i64_1x1 (b, a); /* { dg-error "exact result datatype" } */
  __riscv_ztt_mrowscatadd_ew_i64_1x1 (rm, w, a); /* { dg-error "exact result datatype" } */
  __riscv_ztt_mcolzip_ew_i64_1x1 (&a, &a); /* { dg-error "was replaced in AME/Ztt intrinsic v0.2.5; use the 1x2 value interface" } */
  __riscv_ztt_madd_ew_x_i32_1x1_i32 (w, __riscv_ztt_scalar_make_i32_rnu (1));
}
