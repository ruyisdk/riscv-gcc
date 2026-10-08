/* { dg-do compile } */
/* { dg-options "-O2 -std=gnu11 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u16-m32-a16" { target rv32 } } */
/* { dg-options "-O2 -std=gnu11 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u16-m32-a16" { target rv64 } } */
#include <riscv_ztt.h>
void invalid (int *p)
{
  __riscv_ztt_f32_1x1_t a = __riscv_ztt_mzero_m_f32_1x1 ();
  __riscv_ztt_f32_rtz_1x1_t b = __riscv_ztt_mzero_m_f32_rtz_1x1 ();
  __riscv_ztt_f32_1x2_t pair = __riscv_ztt_mzero_m_f32_1x2 ();
  __riscv_ztt_bf16_1x1_t bf = __riscv_ztt_mzero_m_bf16_1x1 ();
  __riscv_ztt_mcolbcast_ew_x_f32_1x1 (a, 1.5); /* { dg-error "control must be an integer scalar" } */
  __riscv_ztt_mrowbcast_ew_x_f32_1x1 (a, p); /* { dg-error "control must be an integer scalar" } */
  __riscv_ztt_mcolshift_ew_x_f32_1x1 (a, 1.5); /* { dg-error "control must be an integer scalar" } */
  __riscv_ztt_mrowshift_ew_x_f32_1x1 (a, p); /* { dg-error "control must be an integer scalar" } */
  __riscv_ztt_mrowbcast_ew_x_f32_1x1 (b, 0); /* { dg-error "incompatible type|cannot convert" } */
  __riscv_ztt_mcolshift_ew_x_f32_1x1 (pair, 0); /* { dg-error "incompatible type|cannot convert" } */
  __riscv_ztt_mcolbcast_ew_x_f16_1x1 (bf, 0); /* { dg-error "incompatible type|cannot convert" } */
  (void) __riscv_ztt_mrowshift_ew_x_f32_1x2; /* { dg-error "undeclared|not declared" } */
}
