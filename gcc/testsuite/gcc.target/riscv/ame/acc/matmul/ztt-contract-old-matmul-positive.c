/* Normative IDs and adaptations are recorded in F59.  */
/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m32-a16 -fmax-errors=0" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m32-a16 -fmax-errors=0" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>

/* Observable legal counterpart of mmulacc_2d:01.  */
void
positive_mmulacc_2d_01 (void *out)
{
  __riscv_ztt_i16_accx2_t old_acc_i16_accx2 = __riscv_ztt_mzero_acc_i16_accx2 ();
  __riscv_ztt_i16_1x2_t src1_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i32_2x1_t src2_i32_2x1 = __riscv_ztt_mzero_m_i32_2x1 ();
  __riscv_ztt_i16_accx2_t value = __riscv_ztt_mmulacc_2d_i16_accx2 (old_acc_i16_accx2, src1_i16_1x2, src2_i32_2x1);
  __riscv_ztt_i16_1x2_t m = __riscv_ztt_mcopy_a2m_i16_1x2 (value);
  __riscv_ztt_mss_rm ((int16_t *) out, m);
}

/* Observable legal counterpart of mmulacc_2d:02.  */
void
positive_mmulacc_2d_02 (void *out)
{
  __riscv_ztt_i16_accx2_t old_acc_i16_accx2 = __riscv_ztt_mzero_acc_i16_accx2 ();
  __riscv_ztt_i16_1x2_t src1_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i32_2x1_t src2_i32_2x1 = __riscv_ztt_mzero_m_i32_2x1 ();
  __riscv_ztt_i16_accx2_t value = __riscv_ztt_mmulacc_2d_i16_accx2 (old_acc_i16_accx2, src1_i16_1x2, src2_i32_2x1);
  __riscv_ztt_i16_1x2_t m = __riscv_ztt_mcopy_a2m_i16_1x2 (value);
  __riscv_ztt_mss_rm ((int16_t *) out, m);
}

/* Observable legal counterpart of mmulacc_2d:03.  */
void
positive_mmulacc_2d_03 (void *out)
{
  __riscv_ztt_i16_accx2_t old_acc_i16_accx2 = __riscv_ztt_mzero_acc_i16_accx2 ();
  __riscv_ztt_i16_1x2_t src1_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i32_2x1_t src2_i32_2x1 = __riscv_ztt_mzero_m_i32_2x1 ();
  __riscv_ztt_i16_accx2_t value = __riscv_ztt_mmulacc_2d_i16_accx2 (old_acc_i16_accx2, src1_i16_1x2, src2_i32_2x1);
  __riscv_ztt_i16_1x2_t m = __riscv_ztt_mcopy_a2m_i16_1x2 (value);
  __riscv_ztt_mss_rm ((int16_t *) out, m);
}

/* Observable legal counterpart of mmulacc_2d:04.  */
void
positive_mmulacc_2d_04 (void *out)
{
  __riscv_ztt_i16_accx2_t old_acc_i16_accx2 = __riscv_ztt_mzero_acc_i16_accx2 ();
  __riscv_ztt_i16_1x2_t src1_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i32_2x1_t src2_i32_2x1 = __riscv_ztt_mzero_m_i32_2x1 ();
  __riscv_ztt_i16_accx2_t value = __riscv_ztt_mmulacc_2d_i16_accx2 (old_acc_i16_accx2, src1_i16_1x2, src2_i32_2x1);
  __riscv_ztt_i16_1x2_t m = __riscv_ztt_mcopy_a2m_i16_1x2 (value);
  __riscv_ztt_mss_rm ((int16_t *) out, m);
}

/* Observable legal counterpart of mmulacc_2d:05.  */
void
positive_mmulacc_2d_05 (void *out)
{
  __riscv_ztt_i16_accx2_t old_acc_i16_accx2 = __riscv_ztt_mzero_acc_i16_accx2 ();
  __riscv_ztt_i16_1x2_t src1_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i32_2x1_t src2_i32_2x1 = __riscv_ztt_mzero_m_i32_2x1 ();
  __riscv_ztt_i16_accx2_t value = __riscv_ztt_mmulacc_2d_i16_accx2 (old_acc_i16_accx2, src1_i16_1x2, src2_i32_2x1);
  __riscv_ztt_i16_1x2_t m = __riscv_ztt_mcopy_a2m_i16_1x2 (value);
  __riscv_ztt_mss_rm ((int16_t *) out, m);
}

/* Observable legal counterpart of mmulaccneg_2d:01.  */
void
positive_mmulaccneg_2d_01 (void *out)
{
  __riscv_ztt_i16_accx2_t old_acc_i16_accx2 = __riscv_ztt_mzero_acc_i16_accx2 ();
  __riscv_ztt_i16_1x2_t src1_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i32_2x1_t src2_i32_2x1 = __riscv_ztt_mzero_m_i32_2x1 ();
  __riscv_ztt_i16_accx2_t value = __riscv_ztt_mmulaccneg_2d_i16_accx2 (old_acc_i16_accx2, src1_i16_1x2, src2_i32_2x1);
  __riscv_ztt_i16_1x2_t m = __riscv_ztt_mcopy_a2m_i16_1x2 (value);
  __riscv_ztt_mss_rm ((int16_t *) out, m);
}

/* Observable legal counterpart of mmulaccneg_2d:02.  */
void
positive_mmulaccneg_2d_02 (void *out)
{
  __riscv_ztt_i16_accx2_t old_acc_i16_accx2 = __riscv_ztt_mzero_acc_i16_accx2 ();
  __riscv_ztt_i16_1x2_t src1_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i32_2x1_t src2_i32_2x1 = __riscv_ztt_mzero_m_i32_2x1 ();
  __riscv_ztt_i16_accx2_t value = __riscv_ztt_mmulaccneg_2d_i16_accx2 (old_acc_i16_accx2, src1_i16_1x2, src2_i32_2x1);
  __riscv_ztt_i16_1x2_t m = __riscv_ztt_mcopy_a2m_i16_1x2 (value);
  __riscv_ztt_mss_rm ((int16_t *) out, m);
}

/* Observable legal counterpart of mmulaccneg_2d:03.  */
void
positive_mmulaccneg_2d_03 (void *out)
{
  __riscv_ztt_i16_accx2_t old_acc_i16_accx2 = __riscv_ztt_mzero_acc_i16_accx2 ();
  __riscv_ztt_i16_1x2_t src1_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i32_2x1_t src2_i32_2x1 = __riscv_ztt_mzero_m_i32_2x1 ();
  __riscv_ztt_i16_accx2_t value = __riscv_ztt_mmulaccneg_2d_i16_accx2 (old_acc_i16_accx2, src1_i16_1x2, src2_i32_2x1);
  __riscv_ztt_i16_1x2_t m = __riscv_ztt_mcopy_a2m_i16_1x2 (value);
  __riscv_ztt_mss_rm ((int16_t *) out, m);
}

/* Observable legal counterpart of mmulaccneg_2d:04.  */
void
positive_mmulaccneg_2d_04 (void *out)
{
  __riscv_ztt_i16_accx2_t old_acc_i16_accx2 = __riscv_ztt_mzero_acc_i16_accx2 ();
  __riscv_ztt_i16_1x2_t src1_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i32_2x1_t src2_i32_2x1 = __riscv_ztt_mzero_m_i32_2x1 ();
  __riscv_ztt_i16_accx2_t value = __riscv_ztt_mmulaccneg_2d_i16_accx2 (old_acc_i16_accx2, src1_i16_1x2, src2_i32_2x1);
  __riscv_ztt_i16_1x2_t m = __riscv_ztt_mcopy_a2m_i16_1x2 (value);
  __riscv_ztt_mss_rm ((int16_t *) out, m);
}

/* Observable legal counterpart of mmulaccneg_2d:05.  */
void
positive_mmulaccneg_2d_05 (void *out)
{
  __riscv_ztt_i16_accx2_t old_acc_i16_accx2 = __riscv_ztt_mzero_acc_i16_accx2 ();
  __riscv_ztt_i16_1x2_t src1_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i32_2x1_t src2_i32_2x1 = __riscv_ztt_mzero_m_i32_2x1 ();
  __riscv_ztt_i16_accx2_t value = __riscv_ztt_mmulaccneg_2d_i16_accx2 (old_acc_i16_accx2, src1_i16_1x2, src2_i32_2x1);
  __riscv_ztt_i16_1x2_t m = __riscv_ztt_mcopy_a2m_i16_1x2 (value);
  __riscv_ztt_mss_rm ((int16_t *) out, m);
}

/* Observable legal counterpart of mmulatacc_2d:01.  */
void
positive_mmulatacc_2d_01 (void *out)
{
  __riscv_ztt_i16_accx2_t old_acc_i16_accx2 = __riscv_ztt_mzero_acc_i16_accx2 ();
  __riscv_ztt_i16_1x2_t src1_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i16_accx2_t value = __riscv_ztt_mmulatacc_2d_i16_accx2 (old_acc_i16_accx2, src1_i16_1x2, src2_i32_1x2);
  __riscv_ztt_i16_1x2_t m = __riscv_ztt_mcopy_a2m_i16_1x2 (value);
  __riscv_ztt_mss_rm ((int16_t *) out, m);
}

/* Observable legal counterpart of mmulatacc_2d:02.  */
void
positive_mmulatacc_2d_02 (void *out)
{
  __riscv_ztt_i16_accx2_t old_acc_i16_accx2 = __riscv_ztt_mzero_acc_i16_accx2 ();
  __riscv_ztt_i16_1x2_t src1_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i16_accx2_t value = __riscv_ztt_mmulatacc_2d_i16_accx2 (old_acc_i16_accx2, src1_i16_1x2, src2_i32_1x2);
  __riscv_ztt_i16_1x2_t m = __riscv_ztt_mcopy_a2m_i16_1x2 (value);
  __riscv_ztt_mss_rm ((int16_t *) out, m);
}

/* Observable legal counterpart of mmulatacc_2d:03.  */
void
positive_mmulatacc_2d_03 (void *out)
{
  __riscv_ztt_i16_accx2_t old_acc_i16_accx2 = __riscv_ztt_mzero_acc_i16_accx2 ();
  __riscv_ztt_i16_1x2_t src1_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i16_accx2_t value = __riscv_ztt_mmulatacc_2d_i16_accx2 (old_acc_i16_accx2, src1_i16_1x2, src2_i32_1x2);
  __riscv_ztt_i16_1x2_t m = __riscv_ztt_mcopy_a2m_i16_1x2 (value);
  __riscv_ztt_mss_rm ((int16_t *) out, m);
}

/* Observable legal counterpart of mmulatacc_2d:04.  */
void
positive_mmulatacc_2d_04 (void *out)
{
  __riscv_ztt_i16_accx2_t old_acc_i16_accx2 = __riscv_ztt_mzero_acc_i16_accx2 ();
  __riscv_ztt_i16_1x2_t src1_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i16_accx2_t value = __riscv_ztt_mmulatacc_2d_i16_accx2 (old_acc_i16_accx2, src1_i16_1x2, src2_i32_1x2);
  __riscv_ztt_i16_1x2_t m = __riscv_ztt_mcopy_a2m_i16_1x2 (value);
  __riscv_ztt_mss_rm ((int16_t *) out, m);
}

/* Observable legal counterpart of mmulataccneg_2d:01.  */
void
positive_mmulataccneg_2d_01 (void *out)
{
  __riscv_ztt_i16_accx2_t old_acc_i16_accx2 = __riscv_ztt_mzero_acc_i16_accx2 ();
  __riscv_ztt_i16_1x2_t src1_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i16_accx2_t value = __riscv_ztt_mmulataccneg_2d_i16_accx2 (old_acc_i16_accx2, src1_i16_1x2, src2_i32_1x2);
  __riscv_ztt_i16_1x2_t m = __riscv_ztt_mcopy_a2m_i16_1x2 (value);
  __riscv_ztt_mss_rm ((int16_t *) out, m);
}

/* Observable legal counterpart of mmulataccneg_2d:02.  */
void
positive_mmulataccneg_2d_02 (void *out)
{
  __riscv_ztt_i16_accx2_t old_acc_i16_accx2 = __riscv_ztt_mzero_acc_i16_accx2 ();
  __riscv_ztt_i16_1x2_t src1_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i16_accx2_t value = __riscv_ztt_mmulataccneg_2d_i16_accx2 (old_acc_i16_accx2, src1_i16_1x2, src2_i32_1x2);
  __riscv_ztt_i16_1x2_t m = __riscv_ztt_mcopy_a2m_i16_1x2 (value);
  __riscv_ztt_mss_rm ((int16_t *) out, m);
}

/* Observable legal counterpart of mmulataccneg_2d:03.  */
void
positive_mmulataccneg_2d_03 (void *out)
{
  __riscv_ztt_i16_accx2_t old_acc_i16_accx2 = __riscv_ztt_mzero_acc_i16_accx2 ();
  __riscv_ztt_i16_1x2_t src1_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i16_accx2_t value = __riscv_ztt_mmulataccneg_2d_i16_accx2 (old_acc_i16_accx2, src1_i16_1x2, src2_i32_1x2);
  __riscv_ztt_i16_1x2_t m = __riscv_ztt_mcopy_a2m_i16_1x2 (value);
  __riscv_ztt_mss_rm ((int16_t *) out, m);
}

/* Observable legal counterpart of mmulataccneg_2d:04.  */
void
positive_mmulataccneg_2d_04 (void *out)
{
  __riscv_ztt_i16_accx2_t old_acc_i16_accx2 = __riscv_ztt_mzero_acc_i16_accx2 ();
  __riscv_ztt_i16_1x2_t src1_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i16_accx2_t value = __riscv_ztt_mmulataccneg_2d_i16_accx2 (old_acc_i16_accx2, src1_i16_1x2, src2_i32_1x2);
  __riscv_ztt_i16_1x2_t m = __riscv_ztt_mcopy_a2m_i16_1x2 (value);
  __riscv_ztt_mss_rm ((int16_t *) out, m);
}

/* Observable legal counterpart of mmulbtacc_2d:01.  */
void
positive_mmulbtacc_2d_01 (void *out)
{
  __riscv_ztt_i16_accx2_t old_acc_i16_accx2 = __riscv_ztt_mzero_acc_i16_accx2 ();
  __riscv_ztt_i16_1x2_t src1_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i16_accx2_t value = __riscv_ztt_mmulbtacc_2d_i16_accx2 (old_acc_i16_accx2, src1_i16_1x2, src2_i32_1x2);
  __riscv_ztt_i16_1x2_t m = __riscv_ztt_mcopy_a2m_i16_1x2 (value);
  __riscv_ztt_mss_rm ((int16_t *) out, m);
}

/* Observable legal counterpart of mmulbtacc_2d:02.  */
void
positive_mmulbtacc_2d_02 (void *out)
{
  __riscv_ztt_i16_accx2_t old_acc_i16_accx2 = __riscv_ztt_mzero_acc_i16_accx2 ();
  __riscv_ztt_i16_1x2_t src1_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i16_accx2_t value = __riscv_ztt_mmulbtacc_2d_i16_accx2 (old_acc_i16_accx2, src1_i16_1x2, src2_i32_1x2);
  __riscv_ztt_i16_1x2_t m = __riscv_ztt_mcopy_a2m_i16_1x2 (value);
  __riscv_ztt_mss_rm ((int16_t *) out, m);
}

/* Observable legal counterpart of mmulbtacc_2d:03.  */
void
positive_mmulbtacc_2d_03 (void *out)
{
  __riscv_ztt_i16_accx2_t old_acc_i16_accx2 = __riscv_ztt_mzero_acc_i16_accx2 ();
  __riscv_ztt_i16_1x2_t src1_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i16_accx2_t value = __riscv_ztt_mmulbtacc_2d_i16_accx2 (old_acc_i16_accx2, src1_i16_1x2, src2_i32_1x2);
  __riscv_ztt_i16_1x2_t m = __riscv_ztt_mcopy_a2m_i16_1x2 (value);
  __riscv_ztt_mss_rm ((int16_t *) out, m);
}

/* Observable legal counterpart of mmulbtacc_2d:04.  */
void
positive_mmulbtacc_2d_04 (void *out)
{
  __riscv_ztt_i16_accx2_t old_acc_i16_accx2 = __riscv_ztt_mzero_acc_i16_accx2 ();
  __riscv_ztt_i16_1x2_t src1_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i16_accx2_t value = __riscv_ztt_mmulbtacc_2d_i16_accx2 (old_acc_i16_accx2, src1_i16_1x2, src2_i32_1x2);
  __riscv_ztt_i16_1x2_t m = __riscv_ztt_mcopy_a2m_i16_1x2 (value);
  __riscv_ztt_mss_rm ((int16_t *) out, m);
}

/* Observable legal counterpart of mmulbtaccneg_2d:01.  */
void
positive_mmulbtaccneg_2d_01 (void *out)
{
  __riscv_ztt_i16_accx2_t old_acc_i16_accx2 = __riscv_ztt_mzero_acc_i16_accx2 ();
  __riscv_ztt_i16_1x2_t src1_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i16_accx2_t value = __riscv_ztt_mmulbtaccneg_2d_i16_accx2 (old_acc_i16_accx2, src1_i16_1x2, src2_i32_1x2);
  __riscv_ztt_i16_1x2_t m = __riscv_ztt_mcopy_a2m_i16_1x2 (value);
  __riscv_ztt_mss_rm ((int16_t *) out, m);
}

/* Observable legal counterpart of mmulbtaccneg_2d:02.  */
void
positive_mmulbtaccneg_2d_02 (void *out)
{
  __riscv_ztt_i16_accx2_t old_acc_i16_accx2 = __riscv_ztt_mzero_acc_i16_accx2 ();
  __riscv_ztt_i16_1x2_t src1_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i16_accx2_t value = __riscv_ztt_mmulbtaccneg_2d_i16_accx2 (old_acc_i16_accx2, src1_i16_1x2, src2_i32_1x2);
  __riscv_ztt_i16_1x2_t m = __riscv_ztt_mcopy_a2m_i16_1x2 (value);
  __riscv_ztt_mss_rm ((int16_t *) out, m);
}

/* Observable legal counterpart of mmulbtaccneg_2d:03.  */
void
positive_mmulbtaccneg_2d_03 (void *out)
{
  __riscv_ztt_i16_accx2_t old_acc_i16_accx2 = __riscv_ztt_mzero_acc_i16_accx2 ();
  __riscv_ztt_i16_1x2_t src1_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i16_accx2_t value = __riscv_ztt_mmulbtaccneg_2d_i16_accx2 (old_acc_i16_accx2, src1_i16_1x2, src2_i32_1x2);
  __riscv_ztt_i16_1x2_t m = __riscv_ztt_mcopy_a2m_i16_1x2 (value);
  __riscv_ztt_mss_rm ((int16_t *) out, m);
}

/* Observable legal counterpart of mmulbtaccneg_2d:04.  */
void
positive_mmulbtaccneg_2d_04 (void *out)
{
  __riscv_ztt_i16_accx2_t old_acc_i16_accx2 = __riscv_ztt_mzero_acc_i16_accx2 ();
  __riscv_ztt_i16_1x2_t src1_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i16_accx2_t value = __riscv_ztt_mmulbtaccneg_2d_i16_accx2 (old_acc_i16_accx2, src1_i16_1x2, src2_i32_1x2);
  __riscv_ztt_i16_1x2_t m = __riscv_ztt_mcopy_a2m_i16_1x2 (value);
  __riscv_ztt_mss_rm ((int16_t *) out, m);
}

/* { dg-final { scan-assembler {\tmmulacc\.2d\t} } } */
/* { dg-final { scan-assembler {\tmmulaccneg\.2d\t} } } */
/* { dg-final { scan-assembler {\tmmulatacc\.2d\t} } } */
/* { dg-final { scan-assembler {\tmmulataccneg\.2d\t} } } */
/* { dg-final { scan-assembler {\tmmulbtacc\.2d\t} } } */
/* { dg-final { scan-assembler {\tmmulbtaccneg\.2d\t} } } */
