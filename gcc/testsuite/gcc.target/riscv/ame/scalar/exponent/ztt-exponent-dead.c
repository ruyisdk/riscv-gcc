/* Matrix mathematics; compile contracts are not numerical execution.  */
/* { dg-do compile } */
/* { dg-options "-O2 -ffast-math -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u16-m32-a16" { target rv32 } } */
/* { dg-options "-O2 -ffast-math -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u16-m32-a16" { target rv64 } } */
#include <riscv_ztt.h>
unsigned long dead (long e)
{
  __riscv_ztt_f16_1x1_t a = __riscv_ztt_mzero_m_f16_1x1 ();
  __riscv_ztt_i16_rnu_sat_1x1_t s = __riscv_ztt_mzero_m_i16_rnu_sat_1x1 ();
  unsigned long flags = __riscv_ztt_get_amefflags () + __riscv_ztt_get_amexsat ();
  __riscv_ztt_mldexp_ew_x_f16_1x1 (a, e);
  __riscv_ztt_mldexpacc_ew_x_f16_1x1 (a, a, e);
  __riscv_ztt_mldexp_ew_x_i16_rnu_sat_1x1 (s, e);
  __riscv_ztt_mldexpacc_ew_x_i16_rnu_sat_1x1 (s, s, e);
  return flags + __riscv_ztt_get_amefflags () + __riscv_ztt_get_amexsat ();
}
/* { dg-final { scan-assembler-times {\tmldexp\.ew\.x\t} 2 } } */
/* { dg-final { scan-assembler-times {\tmldexpacc\.ew\.x\t} 2 } } */
/* { dg-final { scan-assembler-not {amestype} } } */
