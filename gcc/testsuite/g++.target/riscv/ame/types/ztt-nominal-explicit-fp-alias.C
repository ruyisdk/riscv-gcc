/* AME/Ztt v0.2.5 nominal FP aliases; draft/provisional. */
/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32gc_ztt0p6 -mabi=ilp32d -mztt-profile=gcc-runtime-u32-m32-a16" { target rv32 } } */
/* { dg-options "-O2 -march=rv64gc_ztt0p6 -mabi=lp64d -mztt-profile=gcc-runtime-u32-m32-a16" { target rv64 } } */
#include <riscv_ztt.h>
void aliases (float *out, float f)
{
  __riscv_ztt_f32_scalar_t a = __riscv_ztt_scalar_make_f32_rne (f);
  __riscv_ztt_f32_rne_scalar_t b = a;
  __riscv_ztt_f32_1x1_t m = __riscv_ztt_mbcast_m_x_f32_1x1_f32 (b);
  m = __riscv_ztt_madd_ew_x_f32_1x1_f32 (m, a);
  __riscv_ztt_mss_rm (out, m);
}
/* { dg-final { scan-assembler "mbcast.m.x" } } */
/* { dg-final { scan-assembler "madd.ew.x" } } */
