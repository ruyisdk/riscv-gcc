/* Compilation checks only; no AME numerical execution is implied.  */
/* { dg-do compile } */
/* { dg-options "-O2 -ffast-math -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u16-m32-a16" { target rv32 } } */
/* { dg-options "-O2 -ffast-math -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u16-m32-a16" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>
unsigned long flags (void)
{
  __riscv_ztt_f32_rno_1x1_t a = __riscv_ztt_mzero_m_f32_rno_1x1 ();
  unsigned long before = __riscv_ztt_get_amefflags ();
  __riscv_ztt_mfrintm_ew_f16_rtz_1x1 (a);
  __riscv_ztt_mfrintn_ew_f16_rtz_1x1 (a);
  __riscv_ztt_mfrintp_ew_f16_rtz_1x1 (a);
  __riscv_ztt_mfrintz_ew_f16_rtz_1x1 (a);
  __riscv_ztt_mexp2_ew_f16_rtz_1x1 (a);
  __riscv_ztt_mlog2_ew_f16_rtz_1x1 (a);
  __riscv_ztt_mcos_ew_f16_rtz_1x1 (a);
  __riscv_ztt_msin_ew_f16_rtz_1x1 (a);
  __riscv_ztt_mtanh_ew_f16_rtz_1x1 (a);
  __riscv_ztt_mrec_ew_f16_rtz_1x1 (a);
  __riscv_ztt_mrsqrt_ew_f16_rtz_1x1 (a);
  __riscv_ztt_msqrt_ew_f16_rtz_1x1 (a);
  __riscv_ztt_mconv_ew_i16_rnu_sat_1x1 (a);
  return __riscv_ztt_get_amefflags () - before;
}
/* { dg-final { scan-assembler-times {	mfrintm\.ew	} 1 } } */
/* { dg-final { scan-assembler-times {	mfrintn\.ew	} 1 } } */
/* { dg-final { scan-assembler-times {	mfrintp\.ew	} 1 } } */
/* { dg-final { scan-assembler-times {	mfrintz\.ew	} 1 } } */
/* { dg-final { scan-assembler-times {	mexp2\.ew	} 1 } } */
/* { dg-final { scan-assembler-times {	mlog2\.ew	} 1 } } */
/* { dg-final { scan-assembler-times {	mcos\.ew	} 1 } } */
/* { dg-final { scan-assembler-times {	msin\.ew	} 1 } } */
/* { dg-final { scan-assembler-times {	mtanh\.ew	} 1 } } */
/* { dg-final { scan-assembler-times {	mrec\.ew	} 1 } } */
/* { dg-final { scan-assembler-times {	mrsqrt\.ew	} 1 } } */
/* { dg-final { scan-assembler-times {	msqrt\.ew	} 1 } } */
/* { dg-final { scan-assembler-times {amefflags} 2 } } */
