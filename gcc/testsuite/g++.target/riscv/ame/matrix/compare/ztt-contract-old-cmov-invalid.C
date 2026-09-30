/* Normative IDs and adaptations are recorded in F59.  */
/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m32-a16 -fmax-errors=0" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m32-a16 -fmax-errors=0" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>

/* mcmovge_ew:01: Input and output shapes differ; spec line 5933.  */
void
case_mcmovge_ew_01 (void)
{
  __riscv_ztt_i32_1x2_t old_d_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x4_t src1_i32_1x4 = __riscv_ztt_mzero_m_i32_1x4 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  (void) __riscv_ztt_mcmovge_ew_i32_1x2 (old_d_i32_1x2, src1_i32_1x4, src2_i32_1x2); /* { dg-error "AME/Ztt elementwise arithmetic requires integer M operands with the result shape" } */
}

/* mcmovge_ew:02: Input and output shape orientations differ; spec line 5934.  */
void
case_mcmovge_ew_02 (void)
{
  __riscv_ztt_i32_1x2_t old_d_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_2x1_t src2_i32_2x1 = __riscv_ztt_mzero_m_i32_2x1 ();
  (void) __riscv_ztt_mcmovge_ew_i32_1x2 (old_d_i32_1x2, src1_i32_1x2, src2_i32_2x1); /* { dg-error "AME/Ztt elementwise arithmetic requires integer M operands with the result shape" } */
}

/* mcmovge_ew:03: old_d and dst datatypes differ; spec line 5935.  */
void
case_mcmovge_ew_03 (void)
{
  __riscv_ztt_i16_1x2_t old_d_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  (void) __riscv_ztt_mcmovge_ew_i32_1x2 (old_d_i16_1x2, src1_i32_1x2, src2_i32_1x2); /* { dg-error "AME/Ztt conditional move requires old_d to have the exact result datatype, rounding mode and shape" } */
}

/* mcmovge_ew:04: src2 and dst datatypes differ; spec line 5936.  */
void
case_mcmovge_ew_04 (void)
{
  __riscv_ztt_i32_1x2_t old_d_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i16_1x2_t src2_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  (void) __riscv_ztt_mcmovge_ew_i32_1x2 (old_d_i32_1x2, src1_i32_1x2, src2_i16_1x2); /* { dg-error "AME/Ztt conditional selection requires selected data to have the exact result datatype, rounding mode and shape" } */
}

/* mcmovge_ew:05: old_d and dst shapes differ; spec line 5937.  */
void
case_mcmovge_ew_05 (void)
{
  __riscv_ztt_i32_1x4_t old_d_i32_1x4 = __riscv_ztt_mzero_m_i32_1x4 ();
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  (void) __riscv_ztt_mcmovge_ew_i32_1x2 (old_d_i32_1x4, src1_i32_1x2, src2_i32_1x2); /* { dg-error "AME/Ztt conditional move requires old_d to have the exact result datatype, rounding mode and shape" } */
}

/* mcmovlt_ew:01: Input and output shapes differ; spec line 6014.  */
void
case_mcmovlt_ew_01 (void)
{
  __riscv_ztt_i32_1x2_t old_d_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x4_t src1_i32_1x4 = __riscv_ztt_mzero_m_i32_1x4 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  (void) __riscv_ztt_mcmovlt_ew_i32_1x2 (old_d_i32_1x2, src1_i32_1x4, src2_i32_1x2); /* { dg-error "AME/Ztt elementwise arithmetic requires integer M operands with the result shape" } */
}

/* mcmovlt_ew:02: Input and output shape orientations differ; spec line 6015.  */
void
case_mcmovlt_ew_02 (void)
{
  __riscv_ztt_i32_1x2_t old_d_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_2x1_t src2_i32_2x1 = __riscv_ztt_mzero_m_i32_2x1 ();
  (void) __riscv_ztt_mcmovlt_ew_i32_1x2 (old_d_i32_1x2, src1_i32_1x2, src2_i32_2x1); /* { dg-error "AME/Ztt elementwise arithmetic requires integer M operands with the result shape" } */
}

/* mcmovlt_ew:03: old_d and dst datatypes differ; spec line 6016.  */
void
case_mcmovlt_ew_03 (void)
{
  __riscv_ztt_i16_1x2_t old_d_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  (void) __riscv_ztt_mcmovlt_ew_i32_1x2 (old_d_i16_1x2, src1_i32_1x2, src2_i32_1x2); /* { dg-error "AME/Ztt conditional move requires old_d to have the exact result datatype, rounding mode and shape" } */
}

/* mcmovlt_ew:04: src2 and dst datatypes differ; spec line 6017.  */
void
case_mcmovlt_ew_04 (void)
{
  __riscv_ztt_i32_1x2_t old_d_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i16_1x2_t src2_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  (void) __riscv_ztt_mcmovlt_ew_i32_1x2 (old_d_i32_1x2, src1_i32_1x2, src2_i16_1x2); /* { dg-error "AME/Ztt conditional selection requires selected data to have the exact result datatype, rounding mode and shape" } */
}

/* mcmovlt_ew:05: old_d and dst shapes differ; spec line 6018.  */
void
case_mcmovlt_ew_05 (void)
{
  __riscv_ztt_i32_1x4_t old_d_i32_1x4 = __riscv_ztt_mzero_m_i32_1x4 ();
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  (void) __riscv_ztt_mcmovlt_ew_i32_1x2 (old_d_i32_1x4, src1_i32_1x2, src2_i32_1x2); /* { dg-error "AME/Ztt conditional move requires old_d to have the exact result datatype, rounding mode and shape" } */
}
