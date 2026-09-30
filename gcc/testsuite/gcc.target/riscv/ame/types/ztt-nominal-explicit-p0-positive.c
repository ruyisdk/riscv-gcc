/* AME/Ztt v0.2.5 nominal Scalar migration; draft/provisional. */
/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32gc_ztt0p6 -mabi=ilp32d -mztt-profile=gcc-p0-n128-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -march=rv64gc_ztt0p6 -mabi=lp64d -mztt-profile=gcc-p0-n128-u8-m16-a4" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>
void arithmetic (int8_t *out, const int8_t *in, int8_t input)
{
  __riscv_ztt_i8_1x1_t m = __riscv_ztt_mls_rm_i8_1x1 (in);
  __riscv_ztt_i8_rod_scalar_t s = __riscv_ztt_scalar_make_i8_rod (input);
  m = __riscv_ztt_madd_ew_x_i8_rnu_1x1_i8_rod (m, s);
  m = __riscv_ztt_mmulacc_ew_x_i8_rnu_1x1_i8_rod (m, m, s);
  __riscv_ztt_mss_rm (out, m);
}
void broadcast (int8_t *out, int8_t input)
{
  __riscv_ztt_i8_scalar_t s = __riscv_ztt_scalar_make_i8_rnu (input);
  __riscv_ztt_mss_rm (out, __riscv_ztt_mbcast_m_x_i8_1x1_i8 (s));
}
/* { dg-final { scan-assembler "madd.ew.x" } } */
/* { dg-final { scan-assembler "mmulacc.ew.x" } } */
/* { dg-final { scan-assembler "mbcast.m.x" } } */
