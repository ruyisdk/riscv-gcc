/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a16" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a16" { target rv64 } } */
#include <riscv_ztt.h>
#define KEEP(X) __asm__ volatile ("" : "+Wmr" (X))
void crosswidth (__SIZE_TYPE__ *count)
{
  __riscv_ztt_i4_rdn_sat_1x2_t a = __riscv_ztt_mzero_m_i4_rdn_sat_1x2 ();
  __riscv_ztt_u8_rod_1x2_t b = __riscv_ztt_mzero_m_u8_rod_1x2 ();
  __riscv_ztt_i16_rne_1x2_t c = __riscv_ztt_mzero_m_i16_rne_1x2 ();
  KEEP(a); KEEP(b); KEEP(c);
  __riscv_ztt_i16_rnu_1x2_t old_result = __riscv_ztt_madd_ew_i16_1x2 (a, b);
  KEEP(old_result);
  __riscv_ztt_i8_rne_sat_1x2_t x = __riscv_ztt_mmul_ew_i8_rne_sat_1x2 (c, a);
  KEEP(x);
  x = __riscv_ztt_mmulacc_ew_i8_rne_sat_1x2 (x, a, c);
  KEEP(x);
  x = __riscv_ztt_msub_ew_i8_rne_sat_1x2 (x, x);
  KEEP(x);
  x = __riscv_ztt_msll_ew_x_i8_rne_sat_1x2 (x, ++*count);
  KEEP(x); KEEP(a); KEEP(b); KEEP(c); KEEP(old_result);
}
/* { dg-final { scan-assembler {madd\.ew} } } */
/* { dg-final { scan-assembler {mmulacc\.ew} } } */
/* { dg-final { scan-assembler {msll\.ew\.x} } } */
/* { dg-final { scan-assembler-not {mconv\.ew|__builtin_riscv_ztt_integer_matrix} } } */
