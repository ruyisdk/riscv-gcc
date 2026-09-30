/* Normative IDs and adaptations are recorded in F59.  */
/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m32-a16 -fmax-errors=0" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m32-a16 -fmax-errors=0" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>

extern "C" {
/* Observable legal counterpart of mmulacc_ew:01.  */
void
positive_mmulacc_ew_01 (void *out)
{
  __riscv_ztt_i32_1x2_t old_d_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mmulacc_ew_i32_1x2 (old_d_i32_1x2, src1_i32_1x2, src2_i32_1x2);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mmulacc_ew:02.  */
void
positive_mmulacc_ew_02 (void *out)
{
  __riscv_ztt_i32_1x2_t old_d_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mmulacc_ew_i32_1x2 (old_d_i32_1x2, src1_i32_1x2, src2_i32_1x2);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mmulacc_ew:03.  */
void
positive_mmulacc_ew_03 (void *out)
{
  __riscv_ztt_i32_1x2_t old_d_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mmulacc_ew_i32_1x2 (old_d_i32_1x2, src1_i32_1x2, src2_i32_1x2);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mmulacc_ew:04.  */
void
positive_mmulacc_ew_04 (void *out)
{
  __riscv_ztt_i32_1x2_t old_d_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mmulacc_ew_i32_1x2 (old_d_i32_1x2, src1_i32_1x2, src2_i32_1x2);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mmulaccneg_ew:01.  */
void
positive_mmulaccneg_ew_01 (void *out)
{
  __riscv_ztt_i32_1x2_t old_d_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mmulaccneg_ew_i32_1x2 (old_d_i32_1x2, src1_i32_1x2, src2_i32_1x2);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mmulaccneg_ew:02.  */
void
positive_mmulaccneg_ew_02 (void *out)
{
  __riscv_ztt_i32_1x2_t old_d_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mmulaccneg_ew_i32_1x2 (old_d_i32_1x2, src1_i32_1x2, src2_i32_1x2);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mmulaccneg_ew:03.  */
void
positive_mmulaccneg_ew_03 (void *out)
{
  __riscv_ztt_i32_1x2_t old_d_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mmulaccneg_ew_i32_1x2 (old_d_i32_1x2, src1_i32_1x2, src2_i32_1x2);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mmulaccneg_ew:04.  */
void
positive_mmulaccneg_ew_04 (void *out)
{
  __riscv_ztt_i32_1x2_t old_d_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mmulaccneg_ew_i32_1x2 (old_d_i32_1x2, src1_i32_1x2, src2_i32_1x2);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mmuladd_ew:01.  */
void
positive_mmuladd_ew_01 (void *out)
{
  __riscv_ztt_i32_1x2_t old_d_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mmuladd_ew_i32_1x2 (old_d_i32_1x2, src1_i32_1x2, src2_i32_1x2);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mmuladd_ew:02.  */
void
positive_mmuladd_ew_02 (void *out)
{
  __riscv_ztt_i32_1x2_t old_d_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mmuladd_ew_i32_1x2 (old_d_i32_1x2, src1_i32_1x2, src2_i32_1x2);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mmuladd_ew:03.  */
void
positive_mmuladd_ew_03 (void *out)
{
  __riscv_ztt_i32_1x2_t old_d_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mmuladd_ew_i32_1x2 (old_d_i32_1x2, src1_i32_1x2, src2_i32_1x2);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mmuladd_ew:04.  */
void
positive_mmuladd_ew_04 (void *out)
{
  __riscv_ztt_i32_1x2_t old_d_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mmuladd_ew_i32_1x2 (old_d_i32_1x2, src1_i32_1x2, src2_i32_1x2);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mmulsub_ew:01.  */
void
positive_mmulsub_ew_01 (void *out)
{
  __riscv_ztt_i32_1x2_t old_d_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mmulsub_ew_i32_1x2 (old_d_i32_1x2, src1_i32_1x2, src2_i32_1x2);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mmulsub_ew:02.  */
void
positive_mmulsub_ew_02 (void *out)
{
  __riscv_ztt_i32_1x2_t old_d_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mmulsub_ew_i32_1x2 (old_d_i32_1x2, src1_i32_1x2, src2_i32_1x2);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mmulsub_ew:03.  */
void
positive_mmulsub_ew_03 (void *out)
{
  __riscv_ztt_i32_1x2_t old_d_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mmulsub_ew_i32_1x2 (old_d_i32_1x2, src1_i32_1x2, src2_i32_1x2);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mmulsub_ew:04.  */
void
positive_mmulsub_ew_04 (void *out)
{
  __riscv_ztt_i32_1x2_t old_d_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mmulsub_ew_i32_1x2 (old_d_i32_1x2, src1_i32_1x2, src2_i32_1x2);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

}
/* { dg-final { scan-assembler {\tmmulacc\.ew\t} } } */
/* { dg-final { scan-assembler {\tmmulaccneg\.ew\t} } } */
/* { dg-final { scan-assembler {\tmmuladd\.ew\t} } } */
/* { dg-final { scan-assembler {\tmmulsub\.ew\t} } } */
