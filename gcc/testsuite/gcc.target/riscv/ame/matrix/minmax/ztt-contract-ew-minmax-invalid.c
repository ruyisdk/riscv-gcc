/* Normative IDs and adaptations are recorded in F60.  */
/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m32-a16 -fmax-errors=0" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m32-a16 -fmax-errors=0" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>

/* mmax_ew:01: Input and output shapes differ; spec line 2817.  */
void
case_mmax_ew_01 (void)
{
  __riscv_ztt_i32_1x4_t src1_i32_1x4 = __riscv_ztt_mzero_m_i32_1x4 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  (void) __riscv_ztt_mmax_ew_i32_1x2 (src1_i32_1x4, src2_i32_1x2); /* { dg-error "incompatible type for argument 1" } */
}

/* mmax_ew:02: Input and output shape orientations differ; spec line 2818.  */
void
case_mmax_ew_02 (void)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_2x1_t src2_i32_2x1 = __riscv_ztt_mzero_m_i32_2x1 ();
  (void) __riscv_ztt_mmax_ew_i32_1x2 (src1_i32_1x2, src2_i32_2x1); /* { dg-error "incompatible type for argument 2" } */
}

/* mmax_ew:03: Data source and dst datatypes differ; spec line 2819.  */
void
case_mmax_ew_03 (void)
{
  __riscv_ztt_i16_1x2_t src1_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  (void) __riscv_ztt_mmax_ew_i32_1x2 (src1_i16_1x2, src2_i32_1x2); /* { dg-error "incompatible type for argument 1" } */
}

/* mmin_ew:01: Input and output shapes differ; spec line 3157.  */
void
case_mmin_ew_01 (void)
{
  __riscv_ztt_i32_1x4_t src1_i32_1x4 = __riscv_ztt_mzero_m_i32_1x4 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  (void) __riscv_ztt_mmin_ew_i32_1x2 (src1_i32_1x4, src2_i32_1x2); /* { dg-error "incompatible type for argument 1" } */
}

/* mmin_ew:02: Input and output shape orientations differ; spec line 3158.  */
void
case_mmin_ew_02 (void)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_2x1_t src2_i32_2x1 = __riscv_ztt_mzero_m_i32_2x1 ();
  (void) __riscv_ztt_mmin_ew_i32_1x2 (src1_i32_1x2, src2_i32_2x1); /* { dg-error "incompatible type for argument 2" } */
}

/* mmin_ew:03: Data source and dst datatypes differ; spec line 3159.  */
void
case_mmin_ew_03 (void)
{
  __riscv_ztt_i16_1x2_t src1_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  (void) __riscv_ztt_mmin_ew_i32_1x2 (src1_i16_1x2, src2_i32_1x2); /* { dg-error "incompatible type for argument 1" } */
}
