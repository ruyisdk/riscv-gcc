/* Compilation checks only; no AME numerical execution is implied.  */
/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u16-m32-a16" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u16-m32-a16" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>
void invalid (void)
{
  __riscv_ztt_i16_1x1_t a = __riscv_ztt_mzero_m_i16_1x1 ();
  __riscv_ztt_f32_1x1_t b = __riscv_ztt_mzero_m_f32_1x1 ();
  __riscv_ztt_f16_1x2_t c = __riscv_ztt_mzero_m_f16_1x2 ();
  __riscv_ztt_msqrt_ew_f32_1x1 (a); /* { dg-error "floating-only operations" } */
  __riscv_ztt_mconv_ew_f32_1x1 (c); /* { dg-error "compatible M shapes" } */
}
