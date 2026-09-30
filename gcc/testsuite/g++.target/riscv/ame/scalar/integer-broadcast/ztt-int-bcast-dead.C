/* Compile/assemble checks, not numerical execution evidence.  */
/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>
unsigned long dead (uintptr_t x)
{
  unsigned long before = __riscv_ztt_get_amexsat ();
  __riscv_ztt_mbcast_m_x_i4_rne_sat_1x2_i128_rod ( __riscv_ztt_scalar_from_bits_i128_rod (x));
  return __riscv_ztt_get_amexsat () - before;
}
/* { dg-final { scan-assembler-times {\tmbcast\.m\.x\t} 1 } } */
/* { dg-final { scan-assembler-times {amexsat} 2 } } */
/* { dg-final { scan-assembler-not {amestype} } } */
