/* See the F58 contract mapping for normative IDs and controls.  */
/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m32-a16 -fmax-errors=0" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m32-a16 -fmax-errors=0" { target rv64 } } */
#include <stddef.h>
#include <stdint.h>
#include <riscv_ztt.h>

/* mcolbcast_ew_x:01: Source and result datatypes differ; spec line 8999.  */
void
case_mcolbcast_ew_x_01 (int8_t *base_i8,
  int16_t *base_i16, int32_t *base_i32, size_t sh, size_t col,
  size_t row, int offset)
{
  __riscv_ztt_f32_1x1_t src_f32_1x1 = __riscv_ztt_mzero_m_f32_1x1 ();
  (void) __riscv_ztt_mcolbcast_ew_x_i32_1x1 (src_f32_1x1, (size_t)col); /* { dg-error "cannot convert '__riscv_ztt_f32_rne_1x1_t' to '__riscv_ztt_i32_rnu_1x1_t'" } */
}

/* mcolbcast_ew_x:02: Only 1x1 shapes are supported; spec line 9000.  */
void
case_mcolbcast_ew_x_02 (int8_t *base_i8,
  int16_t *base_i16, int32_t *base_i32, size_t sh, size_t col,
  size_t row, int offset)
{
  __riscv_ztt_i32_1x2_t src_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t available = __riscv_ztt_mzero_m_i32_1x2 ();
  (void) available;
  (void) __riscv_ztt_mcolbcast_ew_x_i32_1x2 (src_i32_1x2, (size_t)col); /* { dg-error "'__riscv_ztt_mcolbcast_ew_x_i32_1x2' was not declared" } */
}

/* mrowbcast_ew_x:01: Source and result datatypes differ; spec line 9076.  */
void
case_mrowbcast_ew_x_01 (int8_t *base_i8,
  int16_t *base_i16, int32_t *base_i32, size_t sh, size_t col,
  size_t row, int offset)
{
  __riscv_ztt_f32_1x1_t src_f32_1x1 = __riscv_ztt_mzero_m_f32_1x1 ();
  (void) __riscv_ztt_mrowbcast_ew_x_i32_1x1 (src_f32_1x1, (size_t)row); /* { dg-error "cannot convert '__riscv_ztt_f32_rne_1x1_t' to '__riscv_ztt_i32_rnu_1x1_t'" } */
}

/* mrowbcast_ew_x:02: Only 1x1 shapes are supported; spec line 9077.  */
void
case_mrowbcast_ew_x_02 (int8_t *base_i8,
  int16_t *base_i16, int32_t *base_i32, size_t sh, size_t col,
  size_t row, int offset)
{
  __riscv_ztt_i32_1x2_t src_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t available = __riscv_ztt_mzero_m_i32_1x2 ();
  (void) available;
  (void) __riscv_ztt_mrowbcast_ew_x_i32_1x2 (src_i32_1x2, (size_t)row); /* { dg-error "'__riscv_ztt_mrowbcast_ew_x_i32_1x2' was not declared" } */
}

/* mcolgather_ew:01: Index matrix must be integer; spec line 9156.  */
void
case_mcolgather_ew_01 (int8_t *base_i8,
  int16_t *base_i16, int32_t *base_i32, size_t sh, size_t col,
  size_t row, int offset)
{
  __riscv_ztt_i32_1x1_t src1_i32_1x1 = __riscv_ztt_mzero_m_i32_1x1 ();
  __riscv_ztt_f32_1x1_t src2_f32_1x1 = __riscv_ztt_mzero_m_f32_1x1 ();
  (void) __riscv_ztt_mcolgather_ew_i32_1x1 (src1_i32_1x1, src2_f32_1x1); /* { dg-error "AME/Ztt floating matrix operation requires compatible types, shapes and complete M groups; comparison results and indices must be integer" } */
}

/* mcolgather_ew:02: Only 1x1 shapes are supported; spec line 9157.  */
void
case_mcolgather_ew_02 (int8_t *base_i8,
  int16_t *base_i16, int32_t *base_i32, size_t sh, size_t col,
  size_t row, int offset)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_u32_1x2_t src2_u32_1x2 = __riscv_ztt_mzero_m_u32_1x2 ();
  __riscv_ztt_i32_1x2_t available = __riscv_ztt_mzero_m_i32_1x2 ();
  (void) available;
  (void) __riscv_ztt_mcolgather_ew_i32_1x2 (src1_i32_1x2, src2_u32_1x2); /* { dg-error "'__riscv_ztt_mcolgather_ew_i32_1x2' was not declared" } */
}

/* mcolgather_ew:03: src1 and dst datatypes differ; spec line 9158.  */
void
case_mcolgather_ew_03 (int8_t *base_i8,
  int16_t *base_i16, int32_t *base_i32, size_t sh, size_t col,
  size_t row, int offset)
{
  __riscv_ztt_f32_1x1_t src1_f32_1x1 = __riscv_ztt_mzero_m_f32_1x1 ();
  __riscv_ztt_u32_1x1_t src2_u32_1x1 = __riscv_ztt_mzero_m_u32_1x1 ();
  (void) __riscv_ztt_mcolgather_ew_i32_1x1 (src1_f32_1x1, src2_u32_1x1); /* { dg-error "AME/Ztt floating matrix operation requires compatible types, shapes and complete M groups; comparison results and indices must be integer" } */
}

/* mrowgather_ew:01: Index matrix must be integer; spec line 9238.  */
void
case_mrowgather_ew_01 (int8_t *base_i8,
  int16_t *base_i16, int32_t *base_i32, size_t sh, size_t col,
  size_t row, int offset)
{
  __riscv_ztt_i32_1x1_t src1_i32_1x1 = __riscv_ztt_mzero_m_i32_1x1 ();
  __riscv_ztt_f32_1x1_t src2_f32_1x1 = __riscv_ztt_mzero_m_f32_1x1 ();
  (void) __riscv_ztt_mrowgather_ew_i32_1x1 (src1_i32_1x1, src2_f32_1x1); /* { dg-error "AME/Ztt floating matrix operation requires compatible types, shapes and complete M groups; comparison results and indices must be integer" } */
}

/* mrowgather_ew:02: Only 1x1 shapes are supported; spec line 9239.  */
void
case_mrowgather_ew_02 (int8_t *base_i8,
  int16_t *base_i16, int32_t *base_i32, size_t sh, size_t col,
  size_t row, int offset)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_u32_1x2_t src2_u32_1x2 = __riscv_ztt_mzero_m_u32_1x2 ();
  __riscv_ztt_i32_1x2_t available = __riscv_ztt_mzero_m_i32_1x2 ();
  (void) available;
  (void) __riscv_ztt_mrowgather_ew_i32_1x2 (src1_i32_1x2, src2_u32_1x2); /* { dg-error "'__riscv_ztt_mrowgather_ew_i32_1x2' was not declared" } */
}

/* mrowgather_ew:03: src1 and dst datatypes differ; spec line 9240.  */
void
case_mrowgather_ew_03 (int8_t *base_i8,
  int16_t *base_i16, int32_t *base_i32, size_t sh, size_t col,
  size_t row, int offset)
{
  __riscv_ztt_f32_1x1_t src1_f32_1x1 = __riscv_ztt_mzero_m_f32_1x1 ();
  __riscv_ztt_u32_1x1_t src2_u32_1x1 = __riscv_ztt_mzero_m_u32_1x1 ();
  (void) __riscv_ztt_mrowgather_ew_i32_1x1 (src1_f32_1x1, src2_u32_1x1); /* { dg-error "AME/Ztt floating matrix operation requires compatible types, shapes and complete M groups; comparison results and indices must be integer" } */
}

/* mcolscatadd_ew:01: Index matrix must be integer; spec line 9321.  */
void
case_mcolscatadd_ew_01 (int8_t *base_i8,
  int16_t *base_i16, int32_t *base_i32, size_t sh, size_t col,
  size_t row, int offset)
{
  __riscv_ztt_i32_1x1_t old_d_i32_1x1 = __riscv_ztt_mzero_m_i32_1x1 ();
  __riscv_ztt_i32_1x1_t src1_i32_1x1 = __riscv_ztt_mzero_m_i32_1x1 ();
  __riscv_ztt_f32_1x1_t src2_f32_1x1 = __riscv_ztt_mzero_m_f32_1x1 ();
  (void) __riscv_ztt_mcolscatadd_ew_i32_1x1 (old_d_i32_1x1, src1_i32_1x1, src2_f32_1x1); /* { dg-error "AME/Ztt floating matrix operation requires compatible types, shapes and complete M groups; comparison results and indices must be integer" } */
}

/* mcolscatadd_ew:02: Only 1x1 shapes are supported; spec line 9322.  */
void
case_mcolscatadd_ew_02 (int8_t *base_i8,
  int16_t *base_i16, int32_t *base_i32, size_t sh, size_t col,
  size_t row, int offset)
{
  __riscv_ztt_i32_1x2_t old_d_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_u32_1x2_t src2_u32_1x2 = __riscv_ztt_mzero_m_u32_1x2 ();
  __riscv_ztt_i32_1x2_t available = __riscv_ztt_mzero_m_i32_1x2 ();
  (void) available;
  (void) __riscv_ztt_mcolscatadd_ew_i32_1x2 (old_d_i32_1x2, src1_i32_1x2, src2_u32_1x2); /* { dg-error "'__riscv_ztt_mcolscatadd_ew_i32_1x2' was not declared" } */
}

/* mcolscatadd_ew:03: old_d and dst datatypes differ; spec line 9323.  */
void
case_mcolscatadd_ew_03 (int8_t *base_i8,
  int16_t *base_i16, int32_t *base_i32, size_t sh, size_t col,
  size_t row, int offset)
{
  __riscv_ztt_f32_1x1_t old_d_f32_1x1 = __riscv_ztt_mzero_m_f32_1x1 ();
  __riscv_ztt_i32_1x1_t src1_i32_1x1 = __riscv_ztt_mzero_m_i32_1x1 ();
  __riscv_ztt_u32_1x1_t src2_u32_1x1 = __riscv_ztt_mzero_m_u32_1x1 ();
  (void) __riscv_ztt_mcolscatadd_ew_i32_1x1 (old_d_f32_1x1, src1_i32_1x1, src2_u32_1x1); /* { dg-error "AME/Ztt floating matrix operation requires old_d to have the exact result datatype and shape" } */
}

/* mcolscatadd_ew:04: old_d and dst shapes differ; spec line 9324.  */
void
case_mcolscatadd_ew_04 (int8_t *base_i8,
  int16_t *base_i16, int32_t *base_i32, size_t sh, size_t col,
  size_t row, int offset)
{
  __riscv_ztt_i32_1x2_t old_d_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x1_t src1_i32_1x1 = __riscv_ztt_mzero_m_i32_1x1 ();
  __riscv_ztt_u32_1x1_t src2_u32_1x1 = __riscv_ztt_mzero_m_u32_1x1 ();
  (void) __riscv_ztt_mcolscatadd_ew_i32_1x1 (old_d_i32_1x2, src1_i32_1x1, src2_u32_1x1); /* { dg-error "AME/Ztt indexed operation requires basic 1x1 integer M operands" } */
}

/* mrowscatadd_ew:01: Index matrix must be integer; spec line 9403.  */
void
case_mrowscatadd_ew_01 (int8_t *base_i8,
  int16_t *base_i16, int32_t *base_i32, size_t sh, size_t col,
  size_t row, int offset)
{
  __riscv_ztt_i32_1x1_t old_d_i32_1x1 = __riscv_ztt_mzero_m_i32_1x1 ();
  __riscv_ztt_i32_1x1_t src1_i32_1x1 = __riscv_ztt_mzero_m_i32_1x1 ();
  __riscv_ztt_f32_1x1_t src2_f32_1x1 = __riscv_ztt_mzero_m_f32_1x1 ();
  (void) __riscv_ztt_mrowscatadd_ew_i32_1x1 (old_d_i32_1x1, src1_i32_1x1, src2_f32_1x1); /* { dg-error "AME/Ztt floating matrix operation requires compatible types, shapes and complete M groups; comparison results and indices must be integer" } */
}

/* mrowscatadd_ew:02: Only 1x1 shapes are supported; spec line 9404.  */
void
case_mrowscatadd_ew_02 (int8_t *base_i8,
  int16_t *base_i16, int32_t *base_i32, size_t sh, size_t col,
  size_t row, int offset)
{
  __riscv_ztt_i32_1x2_t old_d_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_u32_1x2_t src2_u32_1x2 = __riscv_ztt_mzero_m_u32_1x2 ();
  __riscv_ztt_i32_1x2_t available = __riscv_ztt_mzero_m_i32_1x2 ();
  (void) available;
  (void) __riscv_ztt_mrowscatadd_ew_i32_1x2 (old_d_i32_1x2, src1_i32_1x2, src2_u32_1x2); /* { dg-error "'__riscv_ztt_mrowscatadd_ew_i32_1x2' was not declared" } */
}

/* mrowscatadd_ew:03: old_d and dst datatypes differ; spec line 9405.  */
void
case_mrowscatadd_ew_03 (int8_t *base_i8,
  int16_t *base_i16, int32_t *base_i32, size_t sh, size_t col,
  size_t row, int offset)
{
  __riscv_ztt_f32_1x1_t old_d_f32_1x1 = __riscv_ztt_mzero_m_f32_1x1 ();
  __riscv_ztt_i32_1x1_t src1_i32_1x1 = __riscv_ztt_mzero_m_i32_1x1 ();
  __riscv_ztt_u32_1x1_t src2_u32_1x1 = __riscv_ztt_mzero_m_u32_1x1 ();
  (void) __riscv_ztt_mrowscatadd_ew_i32_1x1 (old_d_f32_1x1, src1_i32_1x1, src2_u32_1x1); /* { dg-error "AME/Ztt floating matrix operation requires old_d to have the exact result datatype and shape" } */
}

/* mrowscatadd_ew:04: old_d and dst shapes differ; spec line 9406.  */
void
case_mrowscatadd_ew_04 (int8_t *base_i8,
  int16_t *base_i16, int32_t *base_i32, size_t sh, size_t col,
  size_t row, int offset)
{
  __riscv_ztt_i32_1x2_t old_d_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x1_t src1_i32_1x1 = __riscv_ztt_mzero_m_i32_1x1 ();
  __riscv_ztt_u32_1x1_t src2_u32_1x1 = __riscv_ztt_mzero_m_u32_1x1 ();
  (void) __riscv_ztt_mrowscatadd_ew_i32_1x1 (old_d_i32_1x2, src1_i32_1x1, src2_u32_1x1); /* { dg-error "AME/Ztt indexed operation requires basic 1x1 integer M operands" } */
}

/* mcolscatmax_ew:01: Index matrix must be integer; spec line 9485.  */
void
case_mcolscatmax_ew_01 (int8_t *base_i8,
  int16_t *base_i16, int32_t *base_i32, size_t sh, size_t col,
  size_t row, int offset)
{
  __riscv_ztt_i32_1x1_t old_d_i32_1x1 = __riscv_ztt_mzero_m_i32_1x1 ();
  __riscv_ztt_i32_1x1_t src1_i32_1x1 = __riscv_ztt_mzero_m_i32_1x1 ();
  __riscv_ztt_f32_1x1_t src2_f32_1x1 = __riscv_ztt_mzero_m_f32_1x1 ();
  (void) __riscv_ztt_mcolscatmax_ew_i32_1x1 (old_d_i32_1x1, src1_i32_1x1, src2_f32_1x1); /* { dg-error "AME/Ztt floating matrix operation requires compatible types, shapes and complete M groups; comparison results and indices must be integer" } */
}

/* mcolscatmax_ew:02: Only 1x1 shapes are supported; spec line 9486.  */
void
case_mcolscatmax_ew_02 (int8_t *base_i8,
  int16_t *base_i16, int32_t *base_i32, size_t sh, size_t col,
  size_t row, int offset)
{
  __riscv_ztt_i32_1x2_t old_d_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_u32_1x2_t src2_u32_1x2 = __riscv_ztt_mzero_m_u32_1x2 ();
  __riscv_ztt_i32_1x2_t available = __riscv_ztt_mzero_m_i32_1x2 ();
  (void) available;
  (void) __riscv_ztt_mcolscatmax_ew_i32_1x2 (old_d_i32_1x2, src1_i32_1x2, src2_u32_1x2); /* { dg-error "'__riscv_ztt_mcolscatmax_ew_i32_1x2' was not declared" } */
}

/* mcolscatmax_ew:03: old_d and dst datatypes differ; spec line 9487.  */
void
case_mcolscatmax_ew_03 (int8_t *base_i8,
  int16_t *base_i16, int32_t *base_i32, size_t sh, size_t col,
  size_t row, int offset)
{
  __riscv_ztt_f32_1x1_t old_d_f32_1x1 = __riscv_ztt_mzero_m_f32_1x1 ();
  __riscv_ztt_i32_1x1_t src1_i32_1x1 = __riscv_ztt_mzero_m_i32_1x1 ();
  __riscv_ztt_u32_1x1_t src2_u32_1x1 = __riscv_ztt_mzero_m_u32_1x1 ();
  (void) __riscv_ztt_mcolscatmax_ew_i32_1x1 (old_d_f32_1x1, src1_i32_1x1, src2_u32_1x1); /* { dg-error "AME/Ztt floating matrix operation requires old_d to have the exact result datatype and shape" } */
}

/* mcolscatmax_ew:04: old_d and dst shapes differ; spec line 9488.  */
void
case_mcolscatmax_ew_04 (int8_t *base_i8,
  int16_t *base_i16, int32_t *base_i32, size_t sh, size_t col,
  size_t row, int offset)
{
  __riscv_ztt_i32_1x2_t old_d_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x1_t src1_i32_1x1 = __riscv_ztt_mzero_m_i32_1x1 ();
  __riscv_ztt_u32_1x1_t src2_u32_1x1 = __riscv_ztt_mzero_m_u32_1x1 ();
  (void) __riscv_ztt_mcolscatmax_ew_i32_1x1 (old_d_i32_1x2, src1_i32_1x1, src2_u32_1x1); /* { dg-error "AME/Ztt indexed operation requires basic 1x1 integer M operands" } */
}

/* mrowscatmax_ew:01: Index matrix must be integer; spec line 9567.  */
void
case_mrowscatmax_ew_01 (int8_t *base_i8,
  int16_t *base_i16, int32_t *base_i32, size_t sh, size_t col,
  size_t row, int offset)
{
  __riscv_ztt_i32_1x1_t old_d_i32_1x1 = __riscv_ztt_mzero_m_i32_1x1 ();
  __riscv_ztt_i32_1x1_t src1_i32_1x1 = __riscv_ztt_mzero_m_i32_1x1 ();
  __riscv_ztt_f32_1x1_t src2_f32_1x1 = __riscv_ztt_mzero_m_f32_1x1 ();
  (void) __riscv_ztt_mrowscatmax_ew_i32_1x1 (old_d_i32_1x1, src1_i32_1x1, src2_f32_1x1); /* { dg-error "AME/Ztt floating matrix operation requires compatible types, shapes and complete M groups; comparison results and indices must be integer" } */
}

/* mrowscatmax_ew:02: Only 1x1 shapes are supported; spec line 9568.  */
void
case_mrowscatmax_ew_02 (int8_t *base_i8,
  int16_t *base_i16, int32_t *base_i32, size_t sh, size_t col,
  size_t row, int offset)
{
  __riscv_ztt_i32_1x2_t old_d_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_u32_1x2_t src2_u32_1x2 = __riscv_ztt_mzero_m_u32_1x2 ();
  __riscv_ztt_i32_1x2_t available = __riscv_ztt_mzero_m_i32_1x2 ();
  (void) available;
  (void) __riscv_ztt_mrowscatmax_ew_i32_1x2 (old_d_i32_1x2, src1_i32_1x2, src2_u32_1x2); /* { dg-error "'__riscv_ztt_mrowscatmax_ew_i32_1x2' was not declared" } */
}

/* mrowscatmax_ew:03: old_d and dst datatypes differ; spec line 9569.  */
void
case_mrowscatmax_ew_03 (int8_t *base_i8,
  int16_t *base_i16, int32_t *base_i32, size_t sh, size_t col,
  size_t row, int offset)
{
  __riscv_ztt_f32_1x1_t old_d_f32_1x1 = __riscv_ztt_mzero_m_f32_1x1 ();
  __riscv_ztt_i32_1x1_t src1_i32_1x1 = __riscv_ztt_mzero_m_i32_1x1 ();
  __riscv_ztt_u32_1x1_t src2_u32_1x1 = __riscv_ztt_mzero_m_u32_1x1 ();
  (void) __riscv_ztt_mrowscatmax_ew_i32_1x1 (old_d_f32_1x1, src1_i32_1x1, src2_u32_1x1); /* { dg-error "AME/Ztt floating matrix operation requires old_d to have the exact result datatype and shape" } */
}

/* mrowscatmax_ew:04: old_d and dst shapes differ; spec line 9570.  */
void
case_mrowscatmax_ew_04 (int8_t *base_i8,
  int16_t *base_i16, int32_t *base_i32, size_t sh, size_t col,
  size_t row, int offset)
{
  __riscv_ztt_i32_1x2_t old_d_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x1_t src1_i32_1x1 = __riscv_ztt_mzero_m_i32_1x1 ();
  __riscv_ztt_u32_1x1_t src2_u32_1x1 = __riscv_ztt_mzero_m_u32_1x1 ();
  (void) __riscv_ztt_mrowscatmax_ew_i32_1x1 (old_d_i32_1x2, src1_i32_1x1, src2_u32_1x1); /* { dg-error "AME/Ztt indexed operation requires basic 1x1 integer M operands" } */
}

/* mcolshift_ew_x:01: Source and result datatypes differ; spec line 9645.  */
void
case_mcolshift_ew_x_01 (int8_t *base_i8,
  int16_t *base_i16, int32_t *base_i32, size_t sh, size_t col,
  size_t row, int offset)
{
  __riscv_ztt_f32_1x1_t src_f32_1x1 = __riscv_ztt_mzero_m_f32_1x1 ();
  (void) __riscv_ztt_mcolshift_ew_x_i32_1x1 (src_f32_1x1, (int)offset); /* { dg-error "cannot convert '__riscv_ztt_f32_rne_1x1_t' to '__riscv_ztt_i32_rnu_1x1_t'" } */
}

/* mcolshift_ew_x:02: Only 1x1 shapes are supported; spec line 9646.  */
void
case_mcolshift_ew_x_02 (int8_t *base_i8,
  int16_t *base_i16, int32_t *base_i32, size_t sh, size_t col,
  size_t row, int offset)
{
  __riscv_ztt_i32_1x2_t src_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t available = __riscv_ztt_mzero_m_i32_1x2 ();
  (void) available;
  (void) __riscv_ztt_mcolshift_ew_x_i32_1x2 (src_i32_1x2, (int)offset); /* { dg-error "'__riscv_ztt_mcolshift_ew_x_i32_1x2' was not declared" } */
}

/* mcolshift_ew_x:03: offset cannot be an M value; spec line 9647.  */
void
case_mcolshift_ew_x_03 (int8_t *base_i8,
  int16_t *base_i16, int32_t *base_i32, size_t sh, size_t col,
  size_t row, int offset)
{
  __riscv_ztt_i32_1x1_t src2_i32_1x1 = __riscv_ztt_mzero_m_i32_1x1 ();
  __riscv_ztt_i32_1x1_t src_i32_1x1 = __riscv_ztt_mzero_m_i32_1x1 ();
  (void) __riscv_ztt_mcolshift_ew_x_i32_1x1 (src_i32_1x1, src2_i32_1x1); /* { dg-error "AME/Ztt row/column control must be an integer scalar" } */
}

/* mrowshift_ew_x:01: Source and result datatypes differ; spec line 9723.  */
void
case_mrowshift_ew_x_01 (int8_t *base_i8,
  int16_t *base_i16, int32_t *base_i32, size_t sh, size_t col,
  size_t row, int offset)
{
  __riscv_ztt_f32_1x1_t src_f32_1x1 = __riscv_ztt_mzero_m_f32_1x1 ();
  (void) __riscv_ztt_mrowshift_ew_x_i32_1x1 (src_f32_1x1, (int)offset); /* { dg-error "cannot convert '__riscv_ztt_f32_rne_1x1_t' to '__riscv_ztt_i32_rnu_1x1_t'" } */
}

/* mrowshift_ew_x:02: Only 1x1 shapes are supported; spec line 9724.  */
void
case_mrowshift_ew_x_02 (int8_t *base_i8,
  int16_t *base_i16, int32_t *base_i32, size_t sh, size_t col,
  size_t row, int offset)
{
  __riscv_ztt_i32_1x2_t src_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t available = __riscv_ztt_mzero_m_i32_1x2 ();
  (void) available;
  (void) __riscv_ztt_mrowshift_ew_x_i32_1x2 (src_i32_1x2, (int)offset); /* { dg-error "'__riscv_ztt_mrowshift_ew_x_i32_1x2' was not declared" } */
}

/* mrowshift_ew_x:03: offset cannot be an M value; spec line 9725.  */
void
case_mrowshift_ew_x_03 (int8_t *base_i8,
  int16_t *base_i16, int32_t *base_i32, size_t sh, size_t col,
  size_t row, int offset)
{
  __riscv_ztt_i32_1x1_t src2_i32_1x1 = __riscv_ztt_mzero_m_i32_1x1 ();
  __riscv_ztt_i32_1x1_t src_i32_1x1 = __riscv_ztt_mzero_m_i32_1x1 ();
  (void) __riscv_ztt_mrowshift_ew_x_i32_1x1 (src_i32_1x1, src2_i32_1x1); /* { dg-error "AME/Ztt row/column control must be an integer scalar" } */
}
