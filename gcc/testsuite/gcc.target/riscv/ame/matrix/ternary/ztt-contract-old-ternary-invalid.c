/* Normative IDs and adaptations are recorded in F59.  */
/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m32-a16 -fmax-errors=0" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m32-a16 -fmax-errors=0" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>

/* mmulacc_ew:01: Input and output shapes differ; spec line 3497.  */
void
case_mmulacc_ew_01 (void)
{
  __riscv_ztt_i32_1x2_t old_d_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x4_t src1_i32_1x4 = __riscv_ztt_mzero_m_i32_1x4 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  (void) __riscv_ztt_mmulacc_ew_i32_1x2 (old_d_i32_1x2, src1_i32_1x4, src2_i32_1x2); /* { dg-error "AME/Ztt elementwise arithmetic requires integer M operands with the result shape" } */
}

/* mmulacc_ew:02: Input and output shape orientations differ; spec line 3498.  */
void
case_mmulacc_ew_02 (void)
{
  __riscv_ztt_i32_1x2_t old_d_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_2x1_t src2_i32_2x1 = __riscv_ztt_mzero_m_i32_2x1 ();
  (void) __riscv_ztt_mmulacc_ew_i32_1x2 (old_d_i32_1x2, src1_i32_1x2, src2_i32_2x1); /* { dg-error "AME/Ztt elementwise arithmetic requires integer M operands with the result shape" } */
}

/* mmulacc_ew:03: old_d and dst datatypes differ; spec line 3499.  */
void
case_mmulacc_ew_03 (void)
{
  __riscv_ztt_i16_1x2_t old_d_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  (void) __riscv_ztt_mmulacc_ew_i32_1x2 (old_d_i16_1x2, src1_i32_1x2, src2_i32_1x2); /* { dg-error "AME/Ztt ternary arithmetic requires old_d to have the exact result datatype, rounding mode and shape" } */
}

/* mmulacc_ew:04: old_d and dst shapes differ; spec line 3500.  */
void
case_mmulacc_ew_04 (void)
{
  __riscv_ztt_i32_1x4_t old_d_i32_1x4 = __riscv_ztt_mzero_m_i32_1x4 ();
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  (void) __riscv_ztt_mmulacc_ew_i32_1x2 (old_d_i32_1x4, src1_i32_1x2, src2_i32_1x2); /* { dg-error "AME/Ztt ternary arithmetic requires old_d to have the exact result datatype, rounding mode and shape" } */
}

/* mmulaccneg_ew:01: Input and output shapes differ; spec line 3662.  */
void
case_mmulaccneg_ew_01 (void)
{
  __riscv_ztt_i32_1x2_t old_d_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x4_t src1_i32_1x4 = __riscv_ztt_mzero_m_i32_1x4 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  (void) __riscv_ztt_mmulaccneg_ew_i32_1x2 (old_d_i32_1x2, src1_i32_1x4, src2_i32_1x2); /* { dg-error "AME/Ztt elementwise arithmetic requires integer M operands with the result shape" } */
}

/* mmulaccneg_ew:02: Input and output shape orientations differ; spec line 3663.  */
void
case_mmulaccneg_ew_02 (void)
{
  __riscv_ztt_i32_1x2_t old_d_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_2x1_t src2_i32_2x1 = __riscv_ztt_mzero_m_i32_2x1 ();
  (void) __riscv_ztt_mmulaccneg_ew_i32_1x2 (old_d_i32_1x2, src1_i32_1x2, src2_i32_2x1); /* { dg-error "AME/Ztt elementwise arithmetic requires integer M operands with the result shape" } */
}

/* mmulaccneg_ew:03: old_d and dst datatypes differ; spec line 3664.  */
void
case_mmulaccneg_ew_03 (void)
{
  __riscv_ztt_i16_1x2_t old_d_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  (void) __riscv_ztt_mmulaccneg_ew_i32_1x2 (old_d_i16_1x2, src1_i32_1x2, src2_i32_1x2); /* { dg-error "AME/Ztt ternary arithmetic requires old_d to have the exact result datatype, rounding mode and shape" } */
}

/* mmulaccneg_ew:04: old_d and dst shapes differ; spec line 3665.  */
void
case_mmulaccneg_ew_04 (void)
{
  __riscv_ztt_i32_1x4_t old_d_i32_1x4 = __riscv_ztt_mzero_m_i32_1x4 ();
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  (void) __riscv_ztt_mmulaccneg_ew_i32_1x2 (old_d_i32_1x4, src1_i32_1x2, src2_i32_1x2); /* { dg-error "AME/Ztt ternary arithmetic requires old_d to have the exact result datatype, rounding mode and shape" } */
}

/* mmuladd_ew:01: Input and output shapes differ; spec line 3827.  */
void
case_mmuladd_ew_01 (void)
{
  __riscv_ztt_i32_1x2_t old_d_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x4_t src1_i32_1x4 = __riscv_ztt_mzero_m_i32_1x4 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  (void) __riscv_ztt_mmuladd_ew_i32_1x2 (old_d_i32_1x2, src1_i32_1x4, src2_i32_1x2); /* { dg-error "AME/Ztt elementwise arithmetic requires integer M operands with the result shape" } */
}

/* mmuladd_ew:02: Input and output shape orientations differ; spec line 3828.  */
void
case_mmuladd_ew_02 (void)
{
  __riscv_ztt_i32_1x2_t old_d_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_2x1_t src2_i32_2x1 = __riscv_ztt_mzero_m_i32_2x1 ();
  (void) __riscv_ztt_mmuladd_ew_i32_1x2 (old_d_i32_1x2, src1_i32_1x2, src2_i32_2x1); /* { dg-error "AME/Ztt elementwise arithmetic requires integer M operands with the result shape" } */
}

/* mmuladd_ew:03: old_d and dst datatypes differ; spec line 3829.  */
void
case_mmuladd_ew_03 (void)
{
  __riscv_ztt_i16_1x2_t old_d_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  (void) __riscv_ztt_mmuladd_ew_i32_1x2 (old_d_i16_1x2, src1_i32_1x2, src2_i32_1x2); /* { dg-error "AME/Ztt ternary arithmetic requires old_d to have the exact result datatype, rounding mode and shape" } */
}

/* mmuladd_ew:04: old_d and dst shapes differ; spec line 3830.  */
void
case_mmuladd_ew_04 (void)
{
  __riscv_ztt_i32_1x4_t old_d_i32_1x4 = __riscv_ztt_mzero_m_i32_1x4 ();
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  (void) __riscv_ztt_mmuladd_ew_i32_1x2 (old_d_i32_1x4, src1_i32_1x2, src2_i32_1x2); /* { dg-error "AME/Ztt ternary arithmetic requires old_d to have the exact result datatype, rounding mode and shape" } */
}

/* mmulsub_ew:01: Input and output shapes differ; spec line 4161.  */
void
case_mmulsub_ew_01 (void)
{
  __riscv_ztt_i32_1x2_t old_d_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x4_t src1_i32_1x4 = __riscv_ztt_mzero_m_i32_1x4 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  (void) __riscv_ztt_mmulsub_ew_i32_1x2 (old_d_i32_1x2, src1_i32_1x4, src2_i32_1x2); /* { dg-error "AME/Ztt elementwise arithmetic requires integer M operands with the result shape" } */
}

/* mmulsub_ew:02: Input and output shape orientations differ; spec line 4162.  */
void
case_mmulsub_ew_02 (void)
{
  __riscv_ztt_i32_1x2_t old_d_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_2x1_t src2_i32_2x1 = __riscv_ztt_mzero_m_i32_2x1 ();
  (void) __riscv_ztt_mmulsub_ew_i32_1x2 (old_d_i32_1x2, src1_i32_1x2, src2_i32_2x1); /* { dg-error "AME/Ztt elementwise arithmetic requires integer M operands with the result shape" } */
}

/* mmulsub_ew:03: old_d and dst datatypes differ; spec line 4163.  */
void
case_mmulsub_ew_03 (void)
{
  __riscv_ztt_i16_1x2_t old_d_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  (void) __riscv_ztt_mmulsub_ew_i32_1x2 (old_d_i16_1x2, src1_i32_1x2, src2_i32_1x2); /* { dg-error "AME/Ztt ternary arithmetic requires old_d to have the exact result datatype, rounding mode and shape" } */
}

/* mmulsub_ew:04: old_d and dst shapes differ; spec line 4164.  */
void
case_mmulsub_ew_04 (void)
{
  __riscv_ztt_i32_1x4_t old_d_i32_1x4 = __riscv_ztt_mzero_m_i32_1x4 ();
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  (void) __riscv_ztt_mmulsub_ew_i32_1x2 (old_d_i32_1x4, src1_i32_1x2, src2_i32_1x2); /* { dg-error "AME/Ztt ternary arithmetic requires old_d to have the exact result datatype, rounding mode and shape" } */
}
