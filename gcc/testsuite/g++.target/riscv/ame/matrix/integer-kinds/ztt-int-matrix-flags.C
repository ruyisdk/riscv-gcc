/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a16" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a16" { target rv64 } } */
#include <riscv_ztt.h>
__SIZE_TYPE__ flags (void)
{
  __riscv_ztt_i8_rnu_sat_1x1_t a = __riscv_ztt_mzero_m_i8_sat_1x1 ();
  __riscv_ztt_i16_rdn_1x1_t b = __riscv_ztt_mzero_m_i16_rdn_1x1 ();
  __riscv_ztt_u8_rnu_1x1_t index = __riscv_ztt_mzero_m_u8_1x1 ();
  __asm__ volatile ("" : "+Wmr" (a), "+Wmr" (b), "+Wmr" (index));
  __SIZE_TYPE__ before = __riscv_ztt_get_amexsat ();
  __riscv_ztt_madd_ew_i8_sat_1x1 (a, b);
  __riscv_ztt_msll_ew_x_i8_sat_1x1 (b, 5);
  __riscv_ztt_mmulacc_ew_i8_sat_1x1 (a, b, b);
  __riscv_ztt_mcolgather_ew_i8_sat_1x1 (a, index);
  __riscv_ztt_mrowscatadd_ew_i8_sat_1x1 (a, b, index);
  return before ^ __riscv_ztt_get_amexsat ();
}
/* { dg-final { scan-assembler {madd\.ew} } } */
/* { dg-final { scan-assembler {msll\.ew\.x} } } */
/* { dg-final { scan-assembler {mmulacc\.ew} } } */
/* { dg-final { scan-assembler {mcolgather\.ew} } } */
/* { dg-final { scan-assembler {mrowscatadd\.ew} } } */
/* { dg-final { scan-assembler-times {csrr[^\n]*amexsat} 2 } } */
