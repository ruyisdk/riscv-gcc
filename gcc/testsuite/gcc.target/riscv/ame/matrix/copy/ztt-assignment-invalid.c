/* { dg-do compile } */
/* { dg-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u16-m32-a16" { target rv32 } } */
/* { dg-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u16-m32-a16" { target rv64 } } */
#include <riscv_ztt.h>
void invalid (void)
{
  __riscv_ztt_i32_rnu_1x1_t a = __riscv_ztt_mzero_m_i32_rnu_1x1 ();
  __riscv_ztt_i32_rne_1x1_t b = a; /* { dg-error "variable-sized object may not be initialized" } */
  __riscv_ztt_i32_rnu_1x2_t c = a; /* { dg-error "variable-sized object may not be initialized" } */
  __riscv_ztt_f32_rne_1x1_t d = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  a = d; /* { dg-error "(incompatible|cannot convert)" } */
}
