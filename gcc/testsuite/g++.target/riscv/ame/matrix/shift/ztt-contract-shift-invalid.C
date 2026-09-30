/* See the F58 contract mapping for normative IDs and controls.  */
/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m32-a16 -fmax-errors=0" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m32-a16 -fmax-errors=0" { target rv64 } } */
#include <stddef.h>
#include <stdint.h>
#include <riscv_ztt.h>

/* msll_ew:01: Input and output shapes differ; spec line 5401.  */
void
case_msll_ew_01 (int8_t *base_i8,
  int16_t *base_i16, int32_t *base_i32, size_t sh, size_t col,
  size_t row, int offset)
{
  __riscv_ztt_i32_1x4_t src1_i32_1x4 = __riscv_ztt_mzero_m_i32_1x4 ();
  __riscv_ztt_u32_1x2_t src2_u32_1x2 = __riscv_ztt_mzero_m_u32_1x2 ();
  (void) __riscv_ztt_msll_ew_i32_1x2 (src1_i32_1x4, src2_u32_1x2); /* { dg-error "AME/Ztt shift requires integer M operands with the result shape" } */
}

/* msll_ew:02: Input and output shape orientations differ; spec line 5402.  */
void
case_msll_ew_02 (int8_t *base_i8,
  int16_t *base_i16, int32_t *base_i32, size_t sh, size_t col,
  size_t row, int offset)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_u32_2x1_t src2_u32_2x1 = __riscv_ztt_mzero_m_u32_2x1 ();
  (void) __riscv_ztt_msll_ew_i32_1x2 (src1_i32_1x2, src2_u32_2x1); /* { dg-error "AME/Ztt shift requires integer M operands with the result shape" } */
}

/* msll_ew:03: Data source must be integer; spec line 5403.  */
void
case_msll_ew_03 (int8_t *base_i8,
  int16_t *base_i16, int32_t *base_i32, size_t sh, size_t col,
  size_t row, int offset)
{
  __riscv_ztt_f32_1x2_t src1_f32_1x2 = __riscv_ztt_mzero_m_f32_1x2 ();
  __riscv_ztt_u32_1x2_t src2_u32_1x2 = __riscv_ztt_mzero_m_u32_1x2 ();
  (void) __riscv_ztt_msll_ew_i32_1x2 (src1_f32_1x2, src2_u32_1x2); /* { dg-error "AME/Ztt floating operands are not implemented for this operation" } */
}

/* msll_ew:04: dst must be integer; spec line 5404.  */
void
case_msll_ew_04 (int8_t *base_i8,
  int16_t *base_i16, int32_t *base_i32, size_t sh, size_t col,
  size_t row, int offset)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_u32_1x2_t src2_u32_1x2 = __riscv_ztt_mzero_m_u32_1x2 ();
  __riscv_ztt_f32_1x2_t available = __riscv_ztt_mzero_m_f32_1x2 ();
  (void) available;
  (void) __riscv_ztt_msll_ew_f32_1x2 (src1_i32_1x2, src2_u32_1x2); /* { dg-error "'__riscv_ztt_msll_ew_f32_1x2' was not declared" } */
}

/* msll_ew:05: Shift-count matrix must be integer; spec line 5405.  */
void
case_msll_ew_05 (int8_t *base_i8,
  int16_t *base_i16, int32_t *base_i32, size_t sh, size_t col,
  size_t row, int offset)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_f32_1x2_t src2_f32_1x2 = __riscv_ztt_mzero_m_f32_1x2 ();
  (void) __riscv_ztt_msll_ew_i32_1x2 (src1_i32_1x2, src2_f32_1x2); /* { dg-error "AME/Ztt floating operands are not implemented for this operation" } */
}

/* msll_ew_x:01: Input and output shapes differ; spec line 5486.  */
void
case_msll_ew_x_01 (int8_t *base_i8,
  int16_t *base_i16, int32_t *base_i32, size_t sh, size_t col,
  size_t row, int offset)
{
  __riscv_ztt_i32_1x4_t src_i32_1x4 = __riscv_ztt_mzero_m_i32_1x4 ();
  (void) __riscv_ztt_msll_ew_x_i32_1x2 (src_i32_1x4, (size_t)sh); /* { dg-error "AME/Ztt shift requires integer M operands with the result shape" } */
}

/* msll_ew_x:02: Input and output shape orientations differ; spec line 5487.  */
void
case_msll_ew_x_02 (int8_t *base_i8,
  int16_t *base_i16, int32_t *base_i32, size_t sh, size_t col,
  size_t row, int offset)
{
  __riscv_ztt_i32_2x1_t src_i32_2x1 = __riscv_ztt_mzero_m_i32_2x1 ();
  (void) __riscv_ztt_msll_ew_x_i32_1x2 (src_i32_2x1, (size_t)sh); /* { dg-error "AME/Ztt shift requires integer M operands with the result shape" } */
}

/* msll_ew_x:03: Data source must be integer; spec line 5488.  */
void
case_msll_ew_x_03 (int8_t *base_i8,
  int16_t *base_i16, int32_t *base_i32, size_t sh, size_t col,
  size_t row, int offset)
{
  __riscv_ztt_f32_1x2_t src_f32_1x2 = __riscv_ztt_mzero_m_f32_1x2 ();
  (void) __riscv_ztt_msll_ew_x_i32_1x2 (src_f32_1x2, (size_t)sh); /* { dg-error "AME/Ztt floating operands are not implemented for this operation" } */
}

/* msll_ew_x:04: dst must be integer; spec line 5489.  */
void
case_msll_ew_x_04 (int8_t *base_i8,
  int16_t *base_i16, int32_t *base_i32, size_t sh, size_t col,
  size_t row, int offset)
{
  __riscv_ztt_i32_1x2_t src_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_f32_1x2_t available = __riscv_ztt_mzero_m_f32_1x2 ();
  (void) available;
  (void) __riscv_ztt_msll_ew_x_f32_1x2 (src_i32_1x2, (size_t)sh); /* { dg-error "'__riscv_ztt_msll_ew_x_f32_1x2' was not declared" } */
}

/* msra_ew:01: Input and output shapes differ; spec line 5569.  */
void
case_msra_ew_01 (int8_t *base_i8,
  int16_t *base_i16, int32_t *base_i32, size_t sh, size_t col,
  size_t row, int offset)
{
  __riscv_ztt_i32_1x4_t src1_i32_1x4 = __riscv_ztt_mzero_m_i32_1x4 ();
  __riscv_ztt_u32_1x2_t src2_u32_1x2 = __riscv_ztt_mzero_m_u32_1x2 ();
  (void) __riscv_ztt_msra_ew_i32_1x2 (src1_i32_1x4, src2_u32_1x2); /* { dg-error "AME/Ztt shift requires integer M operands with the result shape" } */
}

/* msra_ew:02: Input and output shape orientations differ; spec line 5570.  */
void
case_msra_ew_02 (int8_t *base_i8,
  int16_t *base_i16, int32_t *base_i32, size_t sh, size_t col,
  size_t row, int offset)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_u32_2x1_t src2_u32_2x1 = __riscv_ztt_mzero_m_u32_2x1 ();
  (void) __riscv_ztt_msra_ew_i32_1x2 (src1_i32_1x2, src2_u32_2x1); /* { dg-error "AME/Ztt shift requires integer M operands with the result shape" } */
}

/* msra_ew:03: Data source must be integer; spec line 5571.  */
void
case_msra_ew_03 (int8_t *base_i8,
  int16_t *base_i16, int32_t *base_i32, size_t sh, size_t col,
  size_t row, int offset)
{
  __riscv_ztt_f32_1x2_t src1_f32_1x2 = __riscv_ztt_mzero_m_f32_1x2 ();
  __riscv_ztt_u32_1x2_t src2_u32_1x2 = __riscv_ztt_mzero_m_u32_1x2 ();
  (void) __riscv_ztt_msra_ew_i32_1x2 (src1_f32_1x2, src2_u32_1x2); /* { dg-error "AME/Ztt floating operands are not implemented for this operation" } */
}

/* msra_ew:04: dst must be integer; spec line 5572.  */
void
case_msra_ew_04 (int8_t *base_i8,
  int16_t *base_i16, int32_t *base_i32, size_t sh, size_t col,
  size_t row, int offset)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_u32_1x2_t src2_u32_1x2 = __riscv_ztt_mzero_m_u32_1x2 ();
  __riscv_ztt_f32_1x2_t available = __riscv_ztt_mzero_m_f32_1x2 ();
  (void) available;
  (void) __riscv_ztt_msra_ew_f32_1x2 (src1_i32_1x2, src2_u32_1x2); /* { dg-error "'__riscv_ztt_msra_ew_f32_1x2' was not declared" } */
}

/* msra_ew:05: Shift-count matrix must be integer; spec line 5573.  */
void
case_msra_ew_05 (int8_t *base_i8,
  int16_t *base_i16, int32_t *base_i32, size_t sh, size_t col,
  size_t row, int offset)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_f32_1x2_t src2_f32_1x2 = __riscv_ztt_mzero_m_f32_1x2 ();
  (void) __riscv_ztt_msra_ew_i32_1x2 (src1_i32_1x2, src2_f32_1x2); /* { dg-error "AME/Ztt floating operands are not implemented for this operation" } */
}

/* msra_ew:06: Data source must be signed integer; spec line 5574.  */
void
case_msra_ew_06 (int8_t *base_i8,
  int16_t *base_i16, int32_t *base_i32, size_t sh, size_t col,
  size_t row, int offset)
{
  __riscv_ztt_u32_1x2_t src1_u32_1x2 = __riscv_ztt_mzero_m_u32_1x2 ();
  __riscv_ztt_u32_1x2_t src2_u32_1x2 = __riscv_ztt_mzero_m_u32_1x2 ();
  (void) __riscv_ztt_msra_ew_i32_1x2 (src1_u32_1x2, src2_u32_1x2); /* { dg-error "AME/Ztt shift requires complete M groups and a signed data source for arithmetic right shift" } */
}

/* msra_ew_x:01: Input and output shapes differ; spec line 5655.  */
void
case_msra_ew_x_01 (int8_t *base_i8,
  int16_t *base_i16, int32_t *base_i32, size_t sh, size_t col,
  size_t row, int offset)
{
  __riscv_ztt_i32_1x4_t src_i32_1x4 = __riscv_ztt_mzero_m_i32_1x4 ();
  (void) __riscv_ztt_msra_ew_x_i32_1x2 (src_i32_1x4, (size_t)sh); /* { dg-error "AME/Ztt shift requires integer M operands with the result shape" } */
}

/* msra_ew_x:02: Input and output shape orientations differ; spec line 5656.  */
void
case_msra_ew_x_02 (int8_t *base_i8,
  int16_t *base_i16, int32_t *base_i32, size_t sh, size_t col,
  size_t row, int offset)
{
  __riscv_ztt_i32_2x1_t src_i32_2x1 = __riscv_ztt_mzero_m_i32_2x1 ();
  (void) __riscv_ztt_msra_ew_x_i32_1x2 (src_i32_2x1, (size_t)sh); /* { dg-error "AME/Ztt shift requires integer M operands with the result shape" } */
}

/* msra_ew_x:03: Data source must be integer; spec line 5657.  */
void
case_msra_ew_x_03 (int8_t *base_i8,
  int16_t *base_i16, int32_t *base_i32, size_t sh, size_t col,
  size_t row, int offset)
{
  __riscv_ztt_f32_1x2_t src_f32_1x2 = __riscv_ztt_mzero_m_f32_1x2 ();
  (void) __riscv_ztt_msra_ew_x_i32_1x2 (src_f32_1x2, (size_t)sh); /* { dg-error "AME/Ztt floating operands are not implemented for this operation" } */
}

/* msra_ew_x:04: dst must be integer; spec line 5658.  */
void
case_msra_ew_x_04 (int8_t *base_i8,
  int16_t *base_i16, int32_t *base_i32, size_t sh, size_t col,
  size_t row, int offset)
{
  __riscv_ztt_i32_1x2_t src_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_f32_1x2_t available = __riscv_ztt_mzero_m_f32_1x2 ();
  (void) available;
  (void) __riscv_ztt_msra_ew_x_f32_1x2 (src_i32_1x2, (size_t)sh); /* { dg-error "'__riscv_ztt_msra_ew_x_f32_1x2' was not declared" } */
}

/* msra_ew_x:05: Data source must be signed integer; spec line 5659.  */
void
case_msra_ew_x_05 (int8_t *base_i8,
  int16_t *base_i16, int32_t *base_i32, size_t sh, size_t col,
  size_t row, int offset)
{
  __riscv_ztt_u32_1x2_t src_u32_1x2 = __riscv_ztt_mzero_m_u32_1x2 ();
  (void) __riscv_ztt_msra_ew_x_i32_1x2 (src_u32_1x2, (size_t)sh); /* { dg-error "AME/Ztt shift requires complete M groups and a signed data source for arithmetic right shift" } */
}

/* msrl_ew:01: Input and output shapes differ; spec line 5739.  */
void
case_msrl_ew_01 (int8_t *base_i8,
  int16_t *base_i16, int32_t *base_i32, size_t sh, size_t col,
  size_t row, int offset)
{
  __riscv_ztt_i32_1x4_t src1_i32_1x4 = __riscv_ztt_mzero_m_i32_1x4 ();
  __riscv_ztt_u32_1x2_t src2_u32_1x2 = __riscv_ztt_mzero_m_u32_1x2 ();
  (void) __riscv_ztt_msrl_ew_i32_1x2 (src1_i32_1x4, src2_u32_1x2); /* { dg-error "AME/Ztt shift requires integer M operands with the result shape" } */
}

/* msrl_ew:02: Input and output shape orientations differ; spec line 5740.  */
void
case_msrl_ew_02 (int8_t *base_i8,
  int16_t *base_i16, int32_t *base_i32, size_t sh, size_t col,
  size_t row, int offset)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_u32_2x1_t src2_u32_2x1 = __riscv_ztt_mzero_m_u32_2x1 ();
  (void) __riscv_ztt_msrl_ew_i32_1x2 (src1_i32_1x2, src2_u32_2x1); /* { dg-error "AME/Ztt shift requires integer M operands with the result shape" } */
}

/* msrl_ew:03: Data source must be integer; spec line 5741.  */
void
case_msrl_ew_03 (int8_t *base_i8,
  int16_t *base_i16, int32_t *base_i32, size_t sh, size_t col,
  size_t row, int offset)
{
  __riscv_ztt_f32_1x2_t src1_f32_1x2 = __riscv_ztt_mzero_m_f32_1x2 ();
  __riscv_ztt_u32_1x2_t src2_u32_1x2 = __riscv_ztt_mzero_m_u32_1x2 ();
  (void) __riscv_ztt_msrl_ew_i32_1x2 (src1_f32_1x2, src2_u32_1x2); /* { dg-error "AME/Ztt floating operands are not implemented for this operation" } */
}

/* msrl_ew:04: dst must be integer; spec line 5742.  */
void
case_msrl_ew_04 (int8_t *base_i8,
  int16_t *base_i16, int32_t *base_i32, size_t sh, size_t col,
  size_t row, int offset)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_u32_1x2_t src2_u32_1x2 = __riscv_ztt_mzero_m_u32_1x2 ();
  __riscv_ztt_f32_1x2_t available = __riscv_ztt_mzero_m_f32_1x2 ();
  (void) available;
  (void) __riscv_ztt_msrl_ew_f32_1x2 (src1_i32_1x2, src2_u32_1x2); /* { dg-error "'__riscv_ztt_msrl_ew_f32_1x2' was not declared" } */
}

/* msrl_ew:05: Shift-count matrix must be integer; spec line 5743.  */
void
case_msrl_ew_05 (int8_t *base_i8,
  int16_t *base_i16, int32_t *base_i32, size_t sh, size_t col,
  size_t row, int offset)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_f32_1x2_t src2_f32_1x2 = __riscv_ztt_mzero_m_f32_1x2 ();
  (void) __riscv_ztt_msrl_ew_i32_1x2 (src1_i32_1x2, src2_f32_1x2); /* { dg-error "AME/Ztt floating operands are not implemented for this operation" } */
}

/* msrl_ew_x:01: Input and output shapes differ; spec line 5824.  */
void
case_msrl_ew_x_01 (int8_t *base_i8,
  int16_t *base_i16, int32_t *base_i32, size_t sh, size_t col,
  size_t row, int offset)
{
  __riscv_ztt_i32_1x4_t src_i32_1x4 = __riscv_ztt_mzero_m_i32_1x4 ();
  (void) __riscv_ztt_msrl_ew_x_i32_1x2 (src_i32_1x4, (size_t)sh); /* { dg-error "AME/Ztt shift requires integer M operands with the result shape" } */
}

/* msrl_ew_x:02: Input and output shape orientations differ; spec line 5825.  */
void
case_msrl_ew_x_02 (int8_t *base_i8,
  int16_t *base_i16, int32_t *base_i32, size_t sh, size_t col,
  size_t row, int offset)
{
  __riscv_ztt_i32_2x1_t src_i32_2x1 = __riscv_ztt_mzero_m_i32_2x1 ();
  (void) __riscv_ztt_msrl_ew_x_i32_1x2 (src_i32_2x1, (size_t)sh); /* { dg-error "AME/Ztt shift requires integer M operands with the result shape" } */
}

/* msrl_ew_x:03: Data source must be integer; spec line 5826.  */
void
case_msrl_ew_x_03 (int8_t *base_i8,
  int16_t *base_i16, int32_t *base_i32, size_t sh, size_t col,
  size_t row, int offset)
{
  __riscv_ztt_f32_1x2_t src_f32_1x2 = __riscv_ztt_mzero_m_f32_1x2 ();
  (void) __riscv_ztt_msrl_ew_x_i32_1x2 (src_f32_1x2, (size_t)sh); /* { dg-error "AME/Ztt floating operands are not implemented for this operation" } */
}

/* msrl_ew_x:04: dst must be integer; spec line 5827.  */
void
case_msrl_ew_x_04 (int8_t *base_i8,
  int16_t *base_i16, int32_t *base_i32, size_t sh, size_t col,
  size_t row, int offset)
{
  __riscv_ztt_i32_1x2_t src_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_f32_1x2_t available = __riscv_ztt_mzero_m_f32_1x2 ();
  (void) available;
  (void) __riscv_ztt_msrl_ew_x_f32_1x2 (src_i32_1x2, (size_t)sh); /* { dg-error "'__riscv_ztt_msrl_ew_x_f32_1x2' was not declared" } */
}
