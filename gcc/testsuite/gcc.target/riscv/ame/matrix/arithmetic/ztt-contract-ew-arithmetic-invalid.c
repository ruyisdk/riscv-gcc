/* Normative IDs and adaptations are recorded in F60.  */
/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m32-a16 -fmax-errors=0" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m32-a16 -fmax-errors=0" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>

/* mabsdiff_ew:01: Input and output shapes differ; spec line 1988.  */
void
case_mabsdiff_ew_01 (void)
{
  __riscv_ztt_i32_1x4_t src1_i32_1x4 = __riscv_ztt_mzero_m_i32_1x4 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  (void) __riscv_ztt_mabsdiff_ew_i32_1x2 (src1_i32_1x4, src2_i32_1x2); /* { dg-error "AME/Ztt elementwise arithmetic requires integer M operands with the result shape" } */
}

/* mabsdiff_ew:02: Input and output shape orientations differ; spec line 1989.  */
void
case_mabsdiff_ew_02 (void)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_2x1_t src2_i32_2x1 = __riscv_ztt_mzero_m_i32_2x1 ();
  (void) __riscv_ztt_mabsdiff_ew_i32_1x2 (src1_i32_1x2, src2_i32_2x1); /* { dg-error "AME/Ztt elementwise arithmetic requires integer M operands with the result shape" } */
}

/* madd_ew:01: Input shapes differ; spec line 2157.  */
void
case_madd_ew_01 (void)
{
  __riscv_ztt_i16_1x2_t src1_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i32_1x4_t src2_i32_1x4 = __riscv_ztt_mzero_m_i32_1x4 ();
  (void) __riscv_ztt_madd_ew_i16_1x2 (src1_i16_1x2, src2_i32_1x4); /* { dg-error "incompatible type for argument 2" } */
}

/* madd_ew:02: Input shape orientations differ; spec line 2158.  */
void
case_madd_ew_02 (void)
{
  __riscv_ztt_i16_1x2_t src1_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i32_2x1_t src2_i32_2x1 = __riscv_ztt_mzero_m_i32_2x1 ();
  (void) __riscv_ztt_madd_ew_i16_1x2 (src1_i16_1x2, src2_i32_2x1); /* { dg-error "incompatible type for argument 2" } */
}

/* madd_ew:03: Input and output shapes differ; spec line 2159.  */
void
case_madd_ew_03 (void)
{
  __riscv_ztt_i16_1x1_t src1_i16_1x1 = __riscv_ztt_mzero_m_i16_1x1 ();
  __riscv_ztt_i32_1x1_t src2_i32_1x1 = __riscv_ztt_mzero_m_i32_1x1 ();
  (void) __riscv_ztt_madd_ew_i16_1x2 (src1_i16_1x1, src2_i32_1x1); /* { dg-error "incompatible type for argument 1" } */
  /* { dg-error "incompatible type for argument 2" "" { target *-*-* } .-1 } */
}

/* mhdiff_ew:01: Input and output shapes differ; spec line 2648.  */
void
case_mhdiff_ew_01 (void)
{
  __riscv_ztt_i32_1x4_t src1_i32_1x4 = __riscv_ztt_mzero_m_i32_1x4 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  (void) __riscv_ztt_mhdiff_ew_i32_1x2 (src1_i32_1x4, src2_i32_1x2); /* { dg-error "AME/Ztt elementwise arithmetic requires integer M operands with the result shape" } */
}

/* mhdiff_ew:02: Input and output shape orientations differ; spec line 2649.  */
void
case_mhdiff_ew_02 (void)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_2x1_t src2_i32_2x1 = __riscv_ztt_mzero_m_i32_2x1 ();
  (void) __riscv_ztt_mhdiff_ew_i32_1x2 (src1_i32_1x2, src2_i32_2x1); /* { dg-error "AME/Ztt elementwise arithmetic requires integer M operands with the result shape" } */
}

/* mmean_ew:01: Input and output shapes differ; spec line 2988.  */
void
case_mmean_ew_01 (void)
{
  __riscv_ztt_i32_1x4_t src1_i32_1x4 = __riscv_ztt_mzero_m_i32_1x4 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  (void) __riscv_ztt_mmean_ew_i32_1x2 (src1_i32_1x4, src2_i32_1x2); /* { dg-error "AME/Ztt elementwise arithmetic requires integer M operands with the result shape" } */
}

/* mmean_ew:02: Input and output shape orientations differ; spec line 2989.  */
void
case_mmean_ew_02 (void)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_2x1_t src2_i32_2x1 = __riscv_ztt_mzero_m_i32_2x1 ();
  (void) __riscv_ztt_mmean_ew_i32_1x2 (src1_i32_1x2, src2_i32_2x1); /* { dg-error "AME/Ztt elementwise arithmetic requires integer M operands with the result shape" } */
}

/* mmul_ew:01: Input and output shapes differ; spec line 3328.  */
void
case_mmul_ew_01 (void)
{
  __riscv_ztt_i32_1x4_t src1_i32_1x4 = __riscv_ztt_mzero_m_i32_1x4 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  (void) __riscv_ztt_mmul_ew_i32_1x2 (src1_i32_1x4, src2_i32_1x2); /* { dg-error "AME/Ztt elementwise multiply requires integer M operands with the result shape" } */
}

/* mmul_ew:02: Input and output shape orientations differ; spec line 3329.  */
void
case_mmul_ew_02 (void)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_2x1_t src2_i32_2x1 = __riscv_ztt_mzero_m_i32_2x1 ();
  (void) __riscv_ztt_mmul_ew_i32_1x2 (src1_i32_1x2, src2_i32_2x1); /* { dg-error "AME/Ztt elementwise multiply requires integer M operands with the result shape" } */
}

/* mmulneg_ew:01: Input and output shapes differ; spec line 3992.  */
void
case_mmulneg_ew_01 (void)
{
  __riscv_ztt_i32_1x4_t src1_i32_1x4 = __riscv_ztt_mzero_m_i32_1x4 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  (void) __riscv_ztt_mmulneg_ew_i32_1x2 (src1_i32_1x4, src2_i32_1x2); /* { dg-error "AME/Ztt elementwise arithmetic requires integer M operands with the result shape" } */
}

/* mmulneg_ew:02: Input and output shape orientations differ; spec line 3993.  */
void
case_mmulneg_ew_02 (void)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_2x1_t src2_i32_2x1 = __riscv_ztt_mzero_m_i32_2x1 ();
  (void) __riscv_ztt_mmulneg_ew_i32_1x2 (src1_i32_1x2, src2_i32_2x1); /* { dg-error "AME/Ztt elementwise arithmetic requires integer M operands with the result shape" } */
}

/* msub_ew:01: Input and output shapes differ; spec line 4326.  */
void
case_msub_ew_01 (void)
{
  __riscv_ztt_i32_1x4_t src1_i32_1x4 = __riscv_ztt_mzero_m_i32_1x4 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  (void) __riscv_ztt_msub_ew_i32_1x2 (src1_i32_1x4, src2_i32_1x2); /* { dg-error "incompatible type for argument 1" } */
}

/* msub_ew:02: Input and output shape orientations differ; spec line 4327.  */
void
case_msub_ew_02 (void)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_2x1_t src2_i32_2x1 = __riscv_ztt_mzero_m_i32_2x1 ();
  (void) __riscv_ztt_msub_ew_i32_1x2 (src1_i32_1x2, src2_i32_2x1); /* { dg-error "incompatible type for argument 2" } */
}
