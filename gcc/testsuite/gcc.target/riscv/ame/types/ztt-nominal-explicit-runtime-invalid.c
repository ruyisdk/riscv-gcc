/* AME/Ztt v0.2.5 nominal Scalar migration; draft/provisional. */
/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32gc_ztt0p6 -mabi=ilp32d -mztt-profile=gcc-runtime-u8-m32-a16" { target rv32 } } */
/* { dg-options "-O2 -march=rv64gc_ztt0p6 -mabi=lp64d -mztt-profile=gcc-runtime-u8-m32-a16" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>
void invalid (int8_t *out)
{
  __riscv_ztt_i8_1x1_t m = __riscv_ztt_mzero_m_i8_1x1 ();
  __riscv_ztt_i8_scalar_t s = __riscv_ztt_scalar_make_i8_rnu (3);
  m = __riscv_ztt_madd_ew_x_i8_1x1_i8 (m, 3); /* { dg-error "independent Scalar type" } */
  m = __riscv_ztt_mbcast_m_x_i8_1x1_i8 (3); /* { dg-error "independent Scalar type" } */
  m = __riscv_ztt_mmulacc_ew_x_i8_1x1_i8 (m, m, 3); /* { dg-error "independent Scalar type" } */
  m = __riscv_ztt_madd_ew_x_i8_rnu_1x1_i8_rod (m, s); /* { dg-error "exact TC/RM/SAT" } */
  m = __riscv_ztt_madd_ew_x_i8_1x1_u8 (m, s); /* { dg-error "exact TC/RM/SAT" } */
  m = __riscv_ztt_madd_ew_x_i8_1x1_i8 (m, __riscv_ztt_scalar_make_i8_rnu_sat (3)); /* { dg-error "exact TC/RM/SAT" } */
  struct { unsigned char bits; } fake = { 3 };
  m = __riscv_ztt_mbcast_m_x_i8_1x1_i8 (fake); /* { dg-error "independent Scalar type" } */
  __riscv_ztt_mss_rm (out, m);
}
