/* Compile/assemble contracts, not AME numerical execution tests.  */
/* { dg-do compile } */
/* { dg-options "-O2 -ffast-math -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u16-m32-a16" { target rv32 } } */
/* { dg-options "-O2 -ffast-math -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u16-m32-a16" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>
unsigned long dead (void)
{
  __riscv_ztt_f16_1x1_t a = __riscv_ztt_mzero_m_f16_1x1 ();
  __riscv_ztt_f16_1x1_t b = __riscv_ztt_mzero_m_f16_1x1 ();
  __riscv_ztt_i16_1x1_t idx = __riscv_ztt_mzero_m_i16_1x1 ();
  unsigned long before = __riscv_ztt_get_amefflags ();
  __riscv_ztt_madd_ew_f16_1x1 (a, b);
  __riscv_ztt_msub_ew_f16_1x1 (a, b);
  __riscv_ztt_mmul_ew_f16_1x1 (a, b);
  __riscv_ztt_mmulneg_ew_f16_1x1 (a, b);
  __riscv_ztt_mabsdiff_ew_f16_1x1 (a, b);
  __riscv_ztt_mhdiff_ew_f16_1x1 (a, b);
  __riscv_ztt_mmean_ew_f16_1x1 (a, b);
  __riscv_ztt_mmin_ew_f16_1x1 (a, b);
  __riscv_ztt_mmax_ew_f16_1x1 (a, b);
  __riscv_ztt_mcmpge_ew_i16_1x1 (a, b);
  __riscv_ztt_mcmplt_ew_i16_1x1 (a, b);
  __riscv_ztt_mselge_ew_f16_1x1 (a, b);
  __riscv_ztt_msellt_ew_f16_1x1 (a, b);
  __riscv_ztt_mmulacc_ew_f16_1x1 (a, a, b);
  __riscv_ztt_mmulaccneg_ew_f16_1x1 (a, a, b);
  __riscv_ztt_mmuladd_ew_f16_1x1 (a, a, b);
  __riscv_ztt_mmulsub_ew_f16_1x1 (a, a, b);
  __riscv_ztt_mcmovge_ew_f16_1x1 (a, a, b);
  __riscv_ztt_mcmovlt_ew_f16_1x1 (a, a, b);
  __riscv_ztt_mcolscatadd_ew_f16_1x1 (a, a, idx);
  __riscv_ztt_mrowscatadd_ew_f16_1x1 (a, a, idx);
  __riscv_ztt_mcolscatmax_ew_f16_1x1 (a, a, idx);
  __riscv_ztt_mrowscatmax_ew_f16_1x1 (a, a, idx);
  return __riscv_ztt_get_amefflags () - before;
}
/* { dg-final { scan-assembler-times {	madd\.ew	} 1 } } */
/* { dg-final { scan-assembler-times {	msub\.ew	} 1 } } */
/* { dg-final { scan-assembler-times {	mmul\.ew	} 1 } } */
/* { dg-final { scan-assembler-times {	mmulneg\.ew	} 1 } } */
/* { dg-final { scan-assembler-times {	mabsdiff\.ew	} 1 } } */
/* { dg-final { scan-assembler-times {	mhdiff\.ew	} 1 } } */
/* { dg-final { scan-assembler-times {	mmean\.ew	} 1 } } */
/* { dg-final { scan-assembler-times {	mmin\.ew	} 1 } } */
/* { dg-final { scan-assembler-times {	mmax\.ew	} 1 } } */
/* { dg-final { scan-assembler-times {	mcmpge\.ew	} 1 } } */
/* { dg-final { scan-assembler-times {	mcmplt\.ew	} 1 } } */
/* { dg-final { scan-assembler-times {	mselge\.ew	} 1 } } */
/* { dg-final { scan-assembler-times {	msellt\.ew	} 1 } } */
/* { dg-final { scan-assembler-times {	mmulacc\.ew	} 1 } } */
/* { dg-final { scan-assembler-times {	mmulaccneg\.ew	} 1 } } */
/* { dg-final { scan-assembler-times {	mmuladd\.ew	} 1 } } */
/* { dg-final { scan-assembler-times {	mmulsub\.ew	} 1 } } */
/* { dg-final { scan-assembler-times {	mcmovge\.ew	} 1 } } */
/* { dg-final { scan-assembler-times {	mcmovlt\.ew	} 1 } } */
/* { dg-final { scan-assembler-times {	mcolscatadd\.ew	} 1 } } */
/* { dg-final { scan-assembler-times {	mrowscatadd\.ew	} 1 } } */
/* { dg-final { scan-assembler-times {	mcolscatmax\.ew	} 1 } } */
/* { dg-final { scan-assembler-times {	mrowscatmax\.ew	} 1 } } */
/* { dg-final { scan-assembler-times {amefflags} 2 } } */
