/* Normative IDs and adaptations are recorded in F60.  */
/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m32-a16 -fmax-errors=0" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m32-a16 -fmax-errors=0" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>

/* Observable legal counterpart of mabsdiff_ew:01.  */
void
positive_mabsdiff_ew_01 (void *out)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mabsdiff_ew_i32_1x2 (src1_i32_1x2, src2_i32_1x2);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mabsdiff_ew:02.  */
void
positive_mabsdiff_ew_02 (void *out)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mabsdiff_ew_i32_1x2 (src1_i32_1x2, src2_i32_1x2);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of madd_ew:01.  */
void
positive_madd_ew_01 (void *out)
{
  __riscv_ztt_i16_1x2_t src1_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i16_1x2_t value = __riscv_ztt_madd_ew_i16_1x2 (src1_i16_1x2, src2_i32_1x2);
  __riscv_ztt_mss_rm ((int16_t *) out, value);
}

/* Observable legal counterpart of madd_ew:02.  */
void
positive_madd_ew_02 (void *out)
{
  __riscv_ztt_i16_1x2_t src1_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i16_1x2_t value = __riscv_ztt_madd_ew_i16_1x2 (src1_i16_1x2, src2_i32_1x2);
  __riscv_ztt_mss_rm ((int16_t *) out, value);
}

/* Observable legal counterpart of madd_ew:03.  */
void
positive_madd_ew_03 (void *out)
{
  __riscv_ztt_i16_1x2_t src1_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i16_1x2_t value = __riscv_ztt_madd_ew_i16_1x2 (src1_i16_1x2, src2_i32_1x2);
  __riscv_ztt_mss_rm ((int16_t *) out, value);
}

/* Observable legal counterpart of mhdiff_ew:01.  */
void
positive_mhdiff_ew_01 (void *out)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mhdiff_ew_i32_1x2 (src1_i32_1x2, src2_i32_1x2);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mhdiff_ew:02.  */
void
positive_mhdiff_ew_02 (void *out)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mhdiff_ew_i32_1x2 (src1_i32_1x2, src2_i32_1x2);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mmean_ew:01.  */
void
positive_mmean_ew_01 (void *out)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mmean_ew_i32_1x2 (src1_i32_1x2, src2_i32_1x2);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mmean_ew:02.  */
void
positive_mmean_ew_02 (void *out)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mmean_ew_i32_1x2 (src1_i32_1x2, src2_i32_1x2);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mmul_ew:01.  */
void
positive_mmul_ew_01 (void *out)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mmul_ew_i32_1x2 (src1_i32_1x2, src2_i32_1x2);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mmul_ew:02.  */
void
positive_mmul_ew_02 (void *out)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mmul_ew_i32_1x2 (src1_i32_1x2, src2_i32_1x2);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mmulneg_ew:01.  */
void
positive_mmulneg_ew_01 (void *out)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mmulneg_ew_i32_1x2 (src1_i32_1x2, src2_i32_1x2);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mmulneg_ew:02.  */
void
positive_mmulneg_ew_02 (void *out)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mmulneg_ew_i32_1x2 (src1_i32_1x2, src2_i32_1x2);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of msub_ew:01.  */
void
positive_msub_ew_01 (void *out)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_msub_ew_i32_1x2 (src1_i32_1x2, src2_i32_1x2);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of msub_ew:02.  */
void
positive_msub_ew_02 (void *out)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_msub_ew_i32_1x2 (src1_i32_1x2, src2_i32_1x2);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* { dg-final { scan-assembler {\tmabsdiff\.ew\t} } } */
/* { dg-final { scan-assembler {\tmadd\.ew\t} } } */
/* { dg-final { scan-assembler {\tmhdiff\.ew\t} } } */
/* { dg-final { scan-assembler {\tmmean\.ew\t} } } */
/* { dg-final { scan-assembler {\tmmul\.ew\t} } } */
/* { dg-final { scan-assembler {\tmmulneg\.ew\t} } } */
/* { dg-final { scan-assembler {\tmsub\.ew\t} } } */
