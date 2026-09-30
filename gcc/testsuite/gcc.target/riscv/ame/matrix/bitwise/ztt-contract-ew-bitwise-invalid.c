/* Normative IDs and adaptations are recorded in F60.  */
/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m32-a16 -fmax-errors=0" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m32-a16 -fmax-errors=0" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>

/* mand_ew:01: Input and output shapes differ; spec line 4536.  */
void
case_mand_ew_01 (void)
{
  __riscv_ztt_i32_1x4_t src1_i32_1x4 = __riscv_ztt_mzero_m_i32_1x4 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  (void) __riscv_ztt_mand_ew_i32_1x2 (src1_i32_1x4, src2_i32_1x2); /* { dg-error "incompatible type for argument 1" } */
}

/* mand_ew:02: Input and output shape orientations differ; spec line 4537.  */
void
case_mand_ew_02 (void)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_2x1_t src2_i32_2x1 = __riscv_ztt_mzero_m_i32_2x1 ();
  (void) __riscv_ztt_mand_ew_i32_1x2 (src1_i32_1x2, src2_i32_2x1); /* { dg-error "incompatible type for argument 2" } */
}

/* mand_ew:03: Data source and dst datatypes differ; spec line 4538.  */
void
case_mand_ew_03 (void)
{
  __riscv_ztt_i16_1x2_t src1_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  (void) __riscv_ztt_mand_ew_i32_1x2 (src1_i16_1x2, src2_i32_1x2); /* { dg-error "incompatible type for argument 1" } */
}

/* mand_ew:04: Matrix datatypes must be integer; spec line 4539.  */
void
case_mand_ew_04 (void)
{
  __riscv_ztt_f32_1x2_t src1_f32_1x2 = __riscv_ztt_mzero_m_f32_1x2 ();
  __riscv_ztt_f32_1x2_t src2_f32_1x2 = __riscv_ztt_mzero_m_f32_1x2 ();
  (void) __riscv_ztt_mand_ew_f32_1x2 (src1_f32_1x2, src2_f32_1x2); /* { dg-error "implicit declaration of function '__riscv_ztt_mand_ew_f32_1x2'" } */
}

/* mandnot_ew:01: Input and output shapes differ; spec line 4709.  */
void
case_mandnot_ew_01 (void)
{
  __riscv_ztt_i32_1x4_t src1_i32_1x4 = __riscv_ztt_mzero_m_i32_1x4 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  (void) __riscv_ztt_mandnot_ew_i32_1x2 (src1_i32_1x4, src2_i32_1x2); /* { dg-error "incompatible type for argument 1" } */
}

/* mandnot_ew:02: Input and output shape orientations differ; spec line 4710.  */
void
case_mandnot_ew_02 (void)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_2x1_t src2_i32_2x1 = __riscv_ztt_mzero_m_i32_2x1 ();
  (void) __riscv_ztt_mandnot_ew_i32_1x2 (src1_i32_1x2, src2_i32_2x1); /* { dg-error "incompatible type for argument 2" } */
}

/* mandnot_ew:03: Data source and dst datatypes differ; spec line 4711.  */
void
case_mandnot_ew_03 (void)
{
  __riscv_ztt_i16_1x2_t src1_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  (void) __riscv_ztt_mandnot_ew_i32_1x2 (src1_i16_1x2, src2_i32_1x2); /* { dg-error "incompatible type for argument 1" } */
}

/* mandnot_ew:04: Matrix datatypes must be integer; spec line 4712.  */
void
case_mandnot_ew_04 (void)
{
  __riscv_ztt_f32_1x2_t src1_f32_1x2 = __riscv_ztt_mzero_m_f32_1x2 ();
  __riscv_ztt_f32_1x2_t src2_f32_1x2 = __riscv_ztt_mzero_m_f32_1x2 ();
  (void) __riscv_ztt_mandnot_ew_f32_1x2 (src1_f32_1x2, src2_f32_1x2); /* { dg-error "implicit declaration of function '__riscv_ztt_mandnot_ew_f32_1x2'" } */
}

/* mor_ew:01: Input and output shapes differ; spec line 4882.  */
void
case_mor_ew_01 (void)
{
  __riscv_ztt_i32_1x4_t src1_i32_1x4 = __riscv_ztt_mzero_m_i32_1x4 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  (void) __riscv_ztt_mor_ew_i32_1x2 (src1_i32_1x4, src2_i32_1x2); /* { dg-error "incompatible type for argument 1" } */
}

/* mor_ew:02: Input and output shape orientations differ; spec line 4883.  */
void
case_mor_ew_02 (void)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_2x1_t src2_i32_2x1 = __riscv_ztt_mzero_m_i32_2x1 ();
  (void) __riscv_ztt_mor_ew_i32_1x2 (src1_i32_1x2, src2_i32_2x1); /* { dg-error "incompatible type for argument 2" } */
}

/* mor_ew:03: Data source and dst datatypes differ; spec line 4884.  */
void
case_mor_ew_03 (void)
{
  __riscv_ztt_i16_1x2_t src1_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  (void) __riscv_ztt_mor_ew_i32_1x2 (src1_i16_1x2, src2_i32_1x2); /* { dg-error "incompatible type for argument 1" } */
}

/* mor_ew:04: Matrix datatypes must be integer; spec line 4885.  */
void
case_mor_ew_04 (void)
{
  __riscv_ztt_f32_1x2_t src1_f32_1x2 = __riscv_ztt_mzero_m_f32_1x2 ();
  __riscv_ztt_f32_1x2_t src2_f32_1x2 = __riscv_ztt_mzero_m_f32_1x2 ();
  (void) __riscv_ztt_mor_ew_f32_1x2 (src1_f32_1x2, src2_f32_1x2); /* { dg-error "implicit declaration of function '__riscv_ztt_mor_ew_f32_1x2'" } */
}

/* mornot_ew:01: Input and output shapes differ; spec line 5055.  */
void
case_mornot_ew_01 (void)
{
  __riscv_ztt_i32_1x4_t src1_i32_1x4 = __riscv_ztt_mzero_m_i32_1x4 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  (void) __riscv_ztt_mornot_ew_i32_1x2 (src1_i32_1x4, src2_i32_1x2); /* { dg-error "incompatible type for argument 1" } */
}

/* mornot_ew:02: Input and output shape orientations differ; spec line 5056.  */
void
case_mornot_ew_02 (void)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_2x1_t src2_i32_2x1 = __riscv_ztt_mzero_m_i32_2x1 ();
  (void) __riscv_ztt_mornot_ew_i32_1x2 (src1_i32_1x2, src2_i32_2x1); /* { dg-error "incompatible type for argument 2" } */
}

/* mornot_ew:03: Data source and dst datatypes differ; spec line 5057.  */
void
case_mornot_ew_03 (void)
{
  __riscv_ztt_i16_1x2_t src1_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  (void) __riscv_ztt_mornot_ew_i32_1x2 (src1_i16_1x2, src2_i32_1x2); /* { dg-error "incompatible type for argument 1" } */
}

/* mornot_ew:04: Matrix datatypes must be integer; spec line 5058.  */
void
case_mornot_ew_04 (void)
{
  __riscv_ztt_f32_1x2_t src1_f32_1x2 = __riscv_ztt_mzero_m_f32_1x2 ();
  __riscv_ztt_f32_1x2_t src2_f32_1x2 = __riscv_ztt_mzero_m_f32_1x2 ();
  (void) __riscv_ztt_mornot_ew_f32_1x2 (src1_f32_1x2, src2_f32_1x2); /* { dg-error "implicit declaration of function '__riscv_ztt_mornot_ew_f32_1x2'" } */
}

/* mxor_ew:01: Input and output shapes differ; spec line 5228.  */
void
case_mxor_ew_01 (void)
{
  __riscv_ztt_i32_1x4_t src1_i32_1x4 = __riscv_ztt_mzero_m_i32_1x4 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  (void) __riscv_ztt_mxor_ew_i32_1x2 (src1_i32_1x4, src2_i32_1x2); /* { dg-error "incompatible type for argument 1" } */
}

/* mxor_ew:02: Input and output shape orientations differ; spec line 5229.  */
void
case_mxor_ew_02 (void)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_2x1_t src2_i32_2x1 = __riscv_ztt_mzero_m_i32_2x1 ();
  (void) __riscv_ztt_mxor_ew_i32_1x2 (src1_i32_1x2, src2_i32_2x1); /* { dg-error "incompatible type for argument 2" } */
}

/* mxor_ew:03: Data source and dst datatypes differ; spec line 5230.  */
void
case_mxor_ew_03 (void)
{
  __riscv_ztt_i16_1x2_t src1_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  (void) __riscv_ztt_mxor_ew_i32_1x2 (src1_i16_1x2, src2_i32_1x2); /* { dg-error "incompatible type for argument 1" } */
}

/* mxor_ew:04: Matrix datatypes must be integer; spec line 5231.  */
void
case_mxor_ew_04 (void)
{
  __riscv_ztt_f32_1x2_t src1_f32_1x2 = __riscv_ztt_mzero_m_f32_1x2 ();
  __riscv_ztt_f32_1x2_t src2_f32_1x2 = __riscv_ztt_mzero_m_f32_1x2 ();
  (void) __riscv_ztt_mxor_ew_f32_1x2 (src1_f32_1x2, src2_f32_1x2); /* { dg-error "implicit declaration of function '__riscv_ztt_mxor_ew_f32_1x2'" } */
}
