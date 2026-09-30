/* Matmul interface checks.  */
/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m16-a1" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m16-a1" { target rv64 } } */
#include <riscv_ztt.h>
void bad (void)
{
  __riscv_ztt_i32_rnu_accx1_t a = __riscv_ztt_mzero_acc_i32_rnu_accx1 ();
  __riscv_ztt_i32_rnu_1x1_t m = __riscv_ztt_mzero_m_i32_rnu_1x1 ();
  __riscv_ztt_u32_rnu_1x1_t u = __riscv_ztt_mzero_m_u32_rnu_1x1 ();
  __riscv_ztt_i32_rne_1x1_t r = __riscv_ztt_mzero_m_i32_rne_1x1 ();
  __riscv_ztt_i32_rnu_1x2_t wide = __riscv_ztt_mzero_m_i32_rnu_1x2 ();
  __riscv_ztt_mmulaccneg_2d_i32_rnu_accx1 (a, m, u); /* Mixed sources are now valid. */
  __riscv_ztt_mmulatacc_2d_i32_rnu_accx1 (a, m, u); /* Mixed sources are now valid. */
  __riscv_ztt_mmulataccneg_2d_i32_rnu_accx1 (a, m, u); /* Mixed sources are now valid. */
  __riscv_ztt_mmulbtacc_2d_i32_rnu_accx1 (a, m, u); /* Mixed sources are now valid. */
  __riscv_ztt_mmulbtaccneg_2d_i32_rnu_accx1 (a, m, u); /* Mixed sources are now valid. */
  __riscv_ztt_mmulatacc_2d_i32_rnu_accx1 (a, r, m); /* Mixed sources are now valid. */
  __riscv_ztt_mmulbtacc_2d_i32_rnu_accx1 (a, wide, m); /* { dg-error "incompatible type|cannot convert" } */
  __riscv_ztt_mmulbtaccneg_2d_i32_rnu_accx1 (a, a, m); /* { dg-error "incompatible type|cannot convert" } */
  __riscv_ztt_mmulaccneg_2d_i32_rnu_accx1 (a, m); /* { dg-error "too few arguments" } */
}
