/* row/column controls.  */
/* { dg-do compile } */
/* { dg-options "-O2 -std=gnu11 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -std=gnu11 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv64 } } */
#include <riscv_ztt.h>
void invalid (void)
{
  int control = 0;
  __riscv_ztt_i32_rnu_1x1_t a = __riscv_ztt_mzero_m_i32_rnu_1x1 ();
  __riscv_ztt_i32_rne_1x1_t b = __riscv_ztt_mzero_m_i32_rne_1x1 ();
  __riscv_ztt_u32_rnu_1x1_t c = __riscv_ztt_mzero_m_u32_rnu_1x1 ();
  __riscv_ztt_i32_rnu_1x2_t d = __riscv_ztt_mzero_m_i32_rnu_1x2 ();
  __riscv_ztt_mcolbcast_ew_x_i32_1x1 (a, 1.5); /* { dg-error "control must be an integer scalar" } */
  __riscv_ztt_mrowbcast_ew_x_i32_1x1 (a, &control); /* { dg-error "control must be an integer scalar" } */
  __riscv_ztt_mcolshift_ew_x_i32_1x1 (a, 2.0); /* { dg-error "control must be an integer scalar" } */
  __riscv_ztt_mrowshift_ew_x_i32_1x1 (a, &control); /* { dg-error "control must be an integer scalar" } */
  __riscv_ztt_mcolbcast_ew_x_i32_1x1 (b, 0); /* { dg-error "incompatible type|cannot convert" } */
  __riscv_ztt_mrowbcast_ew_x_i32_1x1 (c, 0); /* { dg-error "incompatible type|cannot convert" } */
  __riscv_ztt_mcolshift_ew_x_i32_1x1 (d, 0); /* { dg-error "incompatible type|cannot convert" } */
}
