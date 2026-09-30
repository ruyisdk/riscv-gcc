/* Normative IDs and adaptations are recorded in F60.  */
/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m32-a16 -fmax-errors=0" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m32-a16 -fmax-errors=0" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>

/* Observable legal counterpart of mand_ew:01.  */
void
positive_mand_ew_01 (void *out)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mand_ew_i32_1x2 (src1_i32_1x2, src2_i32_1x2);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mand_ew:02.  */
void
positive_mand_ew_02 (void *out)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mand_ew_i32_1x2 (src1_i32_1x2, src2_i32_1x2);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mand_ew:03.  */
void
positive_mand_ew_03 (void *out)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mand_ew_i32_1x2 (src1_i32_1x2, src2_i32_1x2);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mand_ew:04.  */
void
positive_mand_ew_04 (void *out)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mand_ew_i32_1x2 (src1_i32_1x2, src2_i32_1x2);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mandnot_ew:01.  */
void
positive_mandnot_ew_01 (void *out)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mandnot_ew_i32_1x2 (src1_i32_1x2, src2_i32_1x2);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mandnot_ew:02.  */
void
positive_mandnot_ew_02 (void *out)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mandnot_ew_i32_1x2 (src1_i32_1x2, src2_i32_1x2);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mandnot_ew:03.  */
void
positive_mandnot_ew_03 (void *out)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mandnot_ew_i32_1x2 (src1_i32_1x2, src2_i32_1x2);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mandnot_ew:04.  */
void
positive_mandnot_ew_04 (void *out)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mandnot_ew_i32_1x2 (src1_i32_1x2, src2_i32_1x2);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mor_ew:01.  */
void
positive_mor_ew_01 (void *out)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mor_ew_i32_1x2 (src1_i32_1x2, src2_i32_1x2);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mor_ew:02.  */
void
positive_mor_ew_02 (void *out)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mor_ew_i32_1x2 (src1_i32_1x2, src2_i32_1x2);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mor_ew:03.  */
void
positive_mor_ew_03 (void *out)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mor_ew_i32_1x2 (src1_i32_1x2, src2_i32_1x2);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mor_ew:04.  */
void
positive_mor_ew_04 (void *out)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mor_ew_i32_1x2 (src1_i32_1x2, src2_i32_1x2);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mornot_ew:01.  */
void
positive_mornot_ew_01 (void *out)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mornot_ew_i32_1x2 (src1_i32_1x2, src2_i32_1x2);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mornot_ew:02.  */
void
positive_mornot_ew_02 (void *out)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mornot_ew_i32_1x2 (src1_i32_1x2, src2_i32_1x2);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mornot_ew:03.  */
void
positive_mornot_ew_03 (void *out)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mornot_ew_i32_1x2 (src1_i32_1x2, src2_i32_1x2);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mornot_ew:04.  */
void
positive_mornot_ew_04 (void *out)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mornot_ew_i32_1x2 (src1_i32_1x2, src2_i32_1x2);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mxor_ew:01.  */
void
positive_mxor_ew_01 (void *out)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mxor_ew_i32_1x2 (src1_i32_1x2, src2_i32_1x2);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mxor_ew:02.  */
void
positive_mxor_ew_02 (void *out)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mxor_ew_i32_1x2 (src1_i32_1x2, src2_i32_1x2);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mxor_ew:03.  */
void
positive_mxor_ew_03 (void *out)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mxor_ew_i32_1x2 (src1_i32_1x2, src2_i32_1x2);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mxor_ew:04.  */
void
positive_mxor_ew_04 (void *out)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mxor_ew_i32_1x2 (src1_i32_1x2, src2_i32_1x2);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* { dg-final { scan-assembler {\tmand\.ew\t} } } */
/* { dg-final { scan-assembler {\tmandnot\.ew\t} } } */
/* { dg-final { scan-assembler {\tmor\.ew\t} } } */
/* { dg-final { scan-assembler {\tmornot\.ew\t} } } */
/* { dg-final { scan-assembler {\tmxor\.ew\t} } } */
