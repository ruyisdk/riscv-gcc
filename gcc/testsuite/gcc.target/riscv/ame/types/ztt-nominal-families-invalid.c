/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32gc_ztt0p6 -mabi=ilp32d -mztt-profile=gcc-runtime-u32-m32-a16" { target rv32 } } */
/* { dg-options "-O2 -march=rv64gc_ztt0p6 -mabi=lp64d -mztt-profile=gcc-runtime-u32-m32-a16" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>
struct impostor { uint32_t __bits; };
void invalid (struct impostor fake)
{
  __riscv_ztt_i32_1x2_t m = __riscv_ztt_mclear_m_i32_1x2 ();
  __riscv_ztt_f32_1x2_t f = __riscv_ztt_mclear_m_f32_1x2 ();
  __riscv_ztt_i32_rne_scalar_t s = __riscv_ztt_scalar_make_i32_rne (3);
  (void) __riscv_ztt_madd_ew_x_i32_1x2 (m, 3); /* { dg-error "independent Scalar type" } */
  (void) __riscv_ztt_msub_ew_x_i32_1x2 (m, 3); /* { dg-error "independent Scalar type" } */
  (void) __riscv_ztt_mmul_ew_x_i32_1x2 (m, 3); /* { dg-error "independent Scalar type" } */
  (void) __riscv_ztt_mabsdiff_ew_x_i32_1x2 (m, 3); /* { dg-error "independent Scalar type" } */
  (void) __riscv_ztt_mhdiff_ew_x_i32_1x2 (m, 3); /* { dg-error "independent Scalar type" } */
  (void) __riscv_ztt_mmean_ew_x_i32_1x2 (m, 3); /* { dg-error "independent Scalar type" } */
  (void) __riscv_ztt_mmulneg_ew_x_i32_1x2 (m, 3); /* { dg-error "independent Scalar type" } */
  (void) __riscv_ztt_mmin_ew_x_i32_1x2 (m, 3); /* { dg-error "independent Scalar type" } */
  (void) __riscv_ztt_mmax_ew_x_i32_1x2 (m, 3); /* { dg-error "independent Scalar type" } */
  (void) __riscv_ztt_mand_ew_x_i32_1x2 (m, 3); /* { dg-error "independent Scalar type" } */
  (void) __riscv_ztt_mandnot_ew_x_i32_1x2 (m, 3); /* { dg-error "independent Scalar type" } */
  (void) __riscv_ztt_mor_ew_x_i32_1x2 (m, 3); /* { dg-error "independent Scalar type" } */
  (void) __riscv_ztt_mornot_ew_x_i32_1x2 (m, 3); /* { dg-error "independent Scalar type" } */
  (void) __riscv_ztt_mxor_ew_x_i32_1x2 (m, 3); /* { dg-error "independent Scalar type" } */
  (void) __riscv_ztt_mmulacc_ew_x_i32_1x2 (m, m, 3); /* { dg-error "independent Scalar type" } */
  (void) __riscv_ztt_mmulaccneg_ew_x_i32_1x2 (m, m, 3); /* { dg-error "independent Scalar type" } */
  (void) __riscv_ztt_mmuladd_ew_x_i32_1x2 (m, m, 3); /* { dg-error "independent Scalar type" } */
  (void) __riscv_ztt_mmulsub_ew_x_i32_1x2 (m, m, 3); /* { dg-error "independent Scalar type" } */
  (void) __riscv_ztt_mcmpge_ew_x_i32_1x2 (m, 3); /* { dg-error "independent Scalar type" } */
  (void) __riscv_ztt_mcmplt_ew_x_i32_1x2 (m, 3); /* { dg-error "independent Scalar type" } */
  (void) __riscv_ztt_mlog2sub_ew_x_f32_1x2 (f, 3); /* { dg-error "independent Scalar type" } */
  (void) __riscv_ztt_msublog2_ew_x_f32_1x2 (f, 3); /* { dg-error "independent Scalar type" } */
  (void) __riscv_ztt_mbcast_m_x_i32_1x2 (3); /* { dg-error "independent Scalar type" } */
  (void) __riscv_ztt_msub_ew_x_i32_1x2 (m, fake); /* { dg-error "independent Scalar type" } */
  (void) __riscv_ztt_msub_ew_x_i32_1x2 (m); /* { dg-error "expects 2 arguments" } */
  (void) __riscv_ztt_mmulacc_ew_x_i32_1x2 (m, s); /* { dg-error "expects 3 arguments" } */
  (void) __riscv_ztt_mmulacc_ew_x_i32_1x2 (f, m, s); /* { dg-error "exact result datatype and shape" } */
  (void) __riscv_ztt_mmin_ew_x_i32_1x2 (f, s); /* { dg-error "compatible numeric types" } */
  (void) __riscv_ztt_mand_ew_x_i32_1x2 (f, s); /* { dg-error "compatible numeric types" } */
  (void) __riscv_ztt_mlog2sub_ew_x_f32_1x2 (m, s); /* { dg-error "compatible numeric types" } */
  (void) __riscv_ztt_msub_ew_x_i32_1x1 (m, s); /* { dg-error "compatible types, shapes" } */
  (void) __riscv_ztt_msll_ew_x_i32_1x2 (m, s); /* { dg-error "shift count must be an integer" } */
  (void) __riscv_ztt_mldexp_ew_x_f32_1x2 (f, s); /* { dg-error "exponent control must be an integer" } */
}
