/* Matrix mathematics; compile contracts are not numerical execution.  */
/* { dg-do compile } */
/* { dg-options "-O2 -ffast-math -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u16-m32-a16" { target rv32 } } */
/* { dg-options "-O2 -ffast-math -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u16-m32-a16" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>
unsigned long dead (void)
{
  __riscv_ztt_f16_1x1_t a = __riscv_ztt_mzero_m_f16_1x1 ();
  __riscv_ztt_i16_1x1_t b = __riscv_ztt_mzero_m_i16_1x1 ();
  __riscv_ztt_i16_rnu_sat_1x1_t s = __riscv_ztt_mzero_m_i16_rnu_sat_1x1 ();
  unsigned long before = __riscv_ztt_get_amefflags () + __riscv_ztt_get_amexsat ();
  __riscv_ztt_mldexp_ew_f16_1x1 (a, b);
  __riscv_ztt_mrdexp_ew_f16_1x1 (a, b);
  __riscv_ztt_mldexpacc_ew_f16_1x1 (a, a, b);
  __riscv_ztt_mrdexpacc_ew_f16_1x1 (a, a, b);
  __riscv_ztt_mlog2sub_ew_f16_1x1 (a, b);
  __riscv_ztt_msublog2_ew_f16_1x1 (a, b);
  __riscv_ztt_mldexp_ew_i16_rnu_sat_1x1 (b, b);
  __riscv_ztt_mrdexp_ew_i16_rnu_sat_1x1 (b, b);
  __riscv_ztt_mldexpacc_ew_i16_rnu_sat_1x1 (s, b, b);
  __riscv_ztt_mrdexpacc_ew_i16_rnu_sat_1x1 (s, b, b);
  return __riscv_ztt_get_amefflags () + __riscv_ztt_get_amexsat () - before;
}
/* { dg-final { scan-assembler-times {	mldexp\.ew	} 2 } } */
/* { dg-final { scan-assembler-times {	mrdexp\.ew	} 2 } } */
/* { dg-final { scan-assembler-times {	mldexpacc\.ew	} 2 } } */
/* { dg-final { scan-assembler-times {	mrdexpacc\.ew	} 2 } } */
/* { dg-final { scan-assembler-times {	mlog2sub\.ew	} 1 } } */
/* { dg-final { scan-assembler-times {	msublog2\.ew	} 1 } } */
/* { dg-final { scan-assembler-times {amefflags} 2 } } */
/* { dg-final { scan-assembler-times {amexsat} 2 } } */
