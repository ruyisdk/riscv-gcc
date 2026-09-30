/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a16 " { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a16 " { target rv64 } } */
#include <riscv_ztt.h>
__SIZE_TYPE__ flags (void)
{
  __riscv_ztt_i8_rnu_1x2_t m = __riscv_ztt_mzero_m_i8_1x2 ();
  __asm__ volatile ("" : "+Wmr" (m));
  __SIZE_TYPE__ before = __riscv_ztt_get_amexsat ();
  __riscv_ztt_mconv_ew_i4_sat_1x2 (m);
  __SIZE_TYPE__ after = __riscv_ztt_get_amexsat ();
  return before ^ after;
}
/* { dg-final { scan-assembler-times {mconv\.ew} 1 } } */
/* { dg-final { scan-assembler-times {csrr[^\n]*amexsat} 2 } } */
