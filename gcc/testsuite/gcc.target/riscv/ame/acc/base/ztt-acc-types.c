/* UDS32 i32/RNU accx1 only.  */
/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv64 } } */
#include <riscv_ztt.h>
void bad_types (void)
{
  __riscv_ztt_i32_rnu_1x1_t m = __riscv_ztt_mclear_m_i32_rnu_1x1 ();
  __riscv_ztt_i32_rne_1x1_t r = __riscv_ztt_mclear_m_i32_rne_1x1 ();
  __riscv_ztt_u32_rnu_1x1_t u = __riscv_ztt_mclear_m_u32_rnu_1x1 ();
  __riscv_ztt_i32_accx1_t a = __riscv_ztt_mclear_acc_i32_accx1 ();
  __riscv_ztt_mcopy_m2a_i32_accx1 (r); /* { dg-error "incompatible type|cannot convert" } */
  __riscv_ztt_mcopy_m2a_i32_accx1 (u); /* { dg-error "incompatible type|cannot convert" } */
  __riscv_ztt_mcopy_a2m_i32_1x1 (m); /* { dg-error "incompatible type|cannot convert" } */
  __riscv_ztt_mmulacc_2d_i32_accx1 (a, r, m); /* Mixed sources are now valid. */
}
