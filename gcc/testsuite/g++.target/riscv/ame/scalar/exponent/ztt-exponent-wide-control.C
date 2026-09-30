/* Matrix mathematics; compile contracts are not numerical execution.  */
/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u16-m32-a16" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u16-m32-a16" { target rv64 } } */
#include <riscv_ztt.h>
void wide_control (long long e)
{
  __riscv_ztt_i16_1x1_t a = __riscv_ztt_mzero_m_i16_1x1 ();
  __riscv_ztt_mldexp_ew_x_i16_1x1 (a, e); /* { dg-error "exponent control exceeds" "" { target rv32 } } */
}
