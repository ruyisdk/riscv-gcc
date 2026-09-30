/* Selected compiler checks, not floating arithmetic execution evidence.  */
/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv64 } } */
#include <riscv_ztt.h>
void invalid (void)
{
  __riscv_ztt_f32_rne_accx2_t d = __riscv_ztt_mzero_acc_f32_accx2 ();
  __riscv_ztt_f32_rtz_accx2_t rm = __riscv_ztt_mzero_acc_f32_rtz_accx2 ();
  __riscv_ztt_f32_accx1_t one = __riscv_ztt_mzero_acc_f32_accx1 ();
  __riscv_ztt_i32_accx2_t integer = __riscv_ztt_mzero_acc_i32_accx2 ();
  __riscv_ztt_bf16_1x2_t ar = __riscv_ztt_mzero_m_bf16_1x2 ();
  __riscv_ztt_bf16_2x1_t ac = __riscv_ztt_mzero_m_bf16_2x1 ();
  __riscv_ztt_f16_1x4_t four = __riscv_ztt_mzero_m_f16_1x4 ();
  __riscv_ztt_mmulacc_2d_f32_accx2 (rm, ar, ac); /* { dg-error "exact result datatype and shape" } */
  __riscv_ztt_mmulacc_2d_f32_accx2 (one, ar, ac); /* { dg-error "exact result datatype and shape" } */
  __riscv_ztt_mmulacc_2d_f32_accx2 (integer, ar, ac); /* { dg-error "exact result datatype and shape" } */
  __riscv_ztt_mmulacc_2d_f32_accx2 (d, ar, ar); /* { dg-error "compatible orientations" } */
  __riscv_ztt_mmulatacc_2d_f32_accx2 (d, ar, ac); /* { dg-error "compatible orientations" } */
  __riscv_ztt_mmulbtacc_2d_f32_accx2 (d, ar, four); /* { dg-error "compatible orientations" } */
  __riscv_ztt_mmulacc_2d_f32_accx2 (d, d, ac); /* { dg-error "compatible orientations" } */
  __riscv_ztt_mmulacc_2d_f32_accx2 (d); /* { dg-error "too few arguments" } */
}
