/* Compile/assemble checks, not numerical execution evidence.  */
/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>
unsigned long ingress_only (uintptr_t c)
{
  __riscv_ztt_i8_rne_sat_1x1_t b = __riscv_ztt_mzero_m_i8_rne_sat_1x1 ();
  __riscv_ztt_i8_rnu_1x1_t d = __riscv_ztt_mzero_m_i8_rnu_1x1 ();
  unsigned long before = __riscv_ztt_get_amexsat ();
  __riscv_ztt_madd_ew_x_i8_1x1_i128 (b, __riscv_ztt_scalar_from_bits_i128_rnu (c));
  __riscv_ztt_mmulacc_ew_x_i8_1x1_i128 (d, b, __riscv_ztt_scalar_from_bits_i128_rnu (c));
  return __riscv_ztt_get_amexsat () - before;
}
unsigned long result_only (uintptr_t c)
{
  __riscv_ztt_i8_rne_1x1_t b = __riscv_ztt_mzero_m_i8_rne_1x1 ();
  __riscv_ztt_i8_rnu_sat_1x1_t d = __riscv_ztt_mzero_m_i8_rnu_sat_1x1 ();
  unsigned long before = __riscv_ztt_get_amexsat ();
  __riscv_ztt_msub_ew_x_i8_sat_1x1_i128 (b, __riscv_ztt_scalar_from_bits_i128_rnu (c));
  __riscv_ztt_mmulsub_ew_x_i8_sat_1x1_i128 (d, b, __riscv_ztt_scalar_from_bits_i128_rnu (c));
  return __riscv_ztt_get_amexsat () - before;
}
/* { dg-final { scan-assembler-times {\tmadd\.ew\.x\t} 1 } } */
/* { dg-final { scan-assembler-times {\tmsub\.ew\.x\t} 1 } } */
/* { dg-final { scan-assembler-times {\tmmulacc\.ew\.x\t} 1 } } */
/* { dg-final { scan-assembler-times {\tmmulsub\.ew\.x\t} 1 } } */
/* { dg-final { scan-assembler-times {amexsat} 4 } } */
