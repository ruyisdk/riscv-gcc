/* Normative IDs and adaptations are recorded in F60.  */
/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m32-a16 -fmax-errors=0" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m32-a16 -fmax-errors=0" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>

/* mcmpge_ew:01: Input and output shapes differ; spec line 6095.  */
void
case_mcmpge_ew_01 (void)
{
  __riscv_ztt_i32_1x4_t src1_i32_1x4 = __riscv_ztt_mzero_m_i32_1x4 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  (void) __riscv_ztt_mcmpge_ew_i32_1x2 (src1_i32_1x4, src2_i32_1x2); /* { dg-error "AME/Ztt elementwise arithmetic requires integer M operands with the result shape" } */
}

/* mcmpge_ew:02: Input and output shape orientations differ; spec line 6096.  */
void
case_mcmpge_ew_02 (void)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_2x1_t src2_i32_2x1 = __riscv_ztt_mzero_m_i32_2x1 ();
  (void) __riscv_ztt_mcmpge_ew_i32_1x2 (src1_i32_1x2, src2_i32_2x1); /* { dg-error "AME/Ztt elementwise arithmetic requires integer M operands with the result shape" } */
}

/* mcmpge_ew:03: dst must be integer; spec line 6097.  */
void
case_mcmpge_ew_03 (void)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  (void) __riscv_ztt_mcmpge_ew_f32_1x2 (src1_i32_1x2, src2_i32_1x2); /* { dg-error "implicit declaration of function '__riscv_ztt_mcmpge_ew_f32_1x2'" } */
}

/* mcmpge_ew_x:01: Input and output shapes differ; spec line 6178.  */
void
case_mcmpge_ew_x_01 (void)
{
  __riscv_ztt_i32_1x4_t src_i32_1x4 = __riscv_ztt_mzero_m_i32_1x4 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  (void) __riscv_ztt_mcmpge_ew_x_i32_1x2 (src_i32_1x4, scalar_i32); /* { dg-error "AME/Ztt integer data-scalar operation requires compatible types, shapes and complete M groups; min/max and bitwise require the exact result datatype for the M source" } */
}

/* mcmpge_ew_x:02: Input and output shape orientations differ; spec line 6179.  */
void
case_mcmpge_ew_x_02 (void)
{
  __riscv_ztt_i32_2x1_t src_i32_2x1 = __riscv_ztt_mzero_m_i32_2x1 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  (void) __riscv_ztt_mcmpge_ew_x_i32_1x2 (src_i32_2x1, scalar_i32); /* { dg-error "AME/Ztt integer data-scalar operation requires compatible types, shapes and complete M groups; min/max and bitwise require the exact result datatype for the M source" } */
}

/* mcmpge_ew_x:03: dst must be integer; spec line 6180.  */
void
case_mcmpge_ew_x_03 (void)
{
  __riscv_ztt_i32_1x2_t src_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  (void) __riscv_ztt_mcmpge_ew_x_f32_1x2 (src_i32_1x2, scalar_i32); /* { dg-error "implicit declaration of function '__riscv_ztt_mcmpge_ew_x_f32_1x2'" } */
}

/* mcmpge_ew_x:04: 4-bit Scalar types are unsupported; spec line 6181.  */
void
case_mcmpge_ew_x_04 (void)
{
  /* The excluded type prevents forming the original call.  */
  typedef __riscv_ztt_i4_scalar_t unavailable_scalar; /* { dg-error "unknown type name '__riscv_ztt_i4_scalar_t'" } */
}

/* mcmplt_ew:01: Input and output shapes differ; spec line 6266.  */
void
case_mcmplt_ew_01 (void)
{
  __riscv_ztt_i32_1x4_t src1_i32_1x4 = __riscv_ztt_mzero_m_i32_1x4 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  (void) __riscv_ztt_mcmplt_ew_i32_1x2 (src1_i32_1x4, src2_i32_1x2); /* { dg-error "AME/Ztt elementwise arithmetic requires integer M operands with the result shape" } */
}

/* mcmplt_ew:02: Input and output shape orientations differ; spec line 6267.  */
void
case_mcmplt_ew_02 (void)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_2x1_t src2_i32_2x1 = __riscv_ztt_mzero_m_i32_2x1 ();
  (void) __riscv_ztt_mcmplt_ew_i32_1x2 (src1_i32_1x2, src2_i32_2x1); /* { dg-error "AME/Ztt elementwise arithmetic requires integer M operands with the result shape" } */
}

/* mcmplt_ew:03: dst must be integer; spec line 6268.  */
void
case_mcmplt_ew_03 (void)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  (void) __riscv_ztt_mcmplt_ew_f32_1x2 (src1_i32_1x2, src2_i32_1x2); /* { dg-error "implicit declaration of function '__riscv_ztt_mcmplt_ew_f32_1x2'" } */
}

/* mcmplt_ew_x:01: Input and output shapes differ; spec line 6349.  */
void
case_mcmplt_ew_x_01 (void)
{
  __riscv_ztt_i32_1x4_t src_i32_1x4 = __riscv_ztt_mzero_m_i32_1x4 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  (void) __riscv_ztt_mcmplt_ew_x_i32_1x2 (src_i32_1x4, scalar_i32); /* { dg-error "AME/Ztt integer data-scalar operation requires compatible types, shapes and complete M groups; min/max and bitwise require the exact result datatype for the M source" } */
}

/* mcmplt_ew_x:02: Input and output shape orientations differ; spec line 6350.  */
void
case_mcmplt_ew_x_02 (void)
{
  __riscv_ztt_i32_2x1_t src_i32_2x1 = __riscv_ztt_mzero_m_i32_2x1 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  (void) __riscv_ztt_mcmplt_ew_x_i32_1x2 (src_i32_2x1, scalar_i32); /* { dg-error "AME/Ztt integer data-scalar operation requires compatible types, shapes and complete M groups; min/max and bitwise require the exact result datatype for the M source" } */
}

/* mcmplt_ew_x:03: dst must be integer; spec line 6351.  */
void
case_mcmplt_ew_x_03 (void)
{
  __riscv_ztt_i32_1x2_t src_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  (void) __riscv_ztt_mcmplt_ew_x_f32_1x2 (src_i32_1x2, scalar_i32); /* { dg-error "implicit declaration of function '__riscv_ztt_mcmplt_ew_x_f32_1x2'" } */
}

/* mcmplt_ew_x:04: 4-bit Scalar types are unsupported; spec line 6352.  */
void
case_mcmplt_ew_x_04 (void)
{
  /* The excluded type prevents forming the original call.  */
  typedef __riscv_ztt_i4_scalar_t unavailable_scalar; /* { dg-error "unknown type name '__riscv_ztt_i4_scalar_t'" } */
}

/* mselge_ew:01: Input and output shapes differ; spec line 6437.  */
void
case_mselge_ew_01 (void)
{
  __riscv_ztt_i32_1x4_t src1_i32_1x4 = __riscv_ztt_mzero_m_i32_1x4 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  (void) __riscv_ztt_mselge_ew_i32_1x2 (src1_i32_1x4, src2_i32_1x2); /* { dg-error "AME/Ztt elementwise arithmetic requires integer M operands with the result shape" } */
}

/* mselge_ew:02: Input and output shape orientations differ; spec line 6438.  */
void
case_mselge_ew_02 (void)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_2x1_t src2_i32_2x1 = __riscv_ztt_mzero_m_i32_2x1 ();
  (void) __riscv_ztt_mselge_ew_i32_1x2 (src1_i32_1x2, src2_i32_2x1); /* { dg-error "AME/Ztt elementwise arithmetic requires integer M operands with the result shape" } */
}

/* mselge_ew:03: src2 and dst datatypes differ; spec line 6439.  */
void
case_mselge_ew_03 (void)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i16_1x2_t src2_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  (void) __riscv_ztt_mselge_ew_i32_1x2 (src1_i32_1x2, src2_i16_1x2); /* { dg-error "AME/Ztt conditional selection requires selected data to have the exact result datatype, rounding mode and shape" } */
}

/* msellt_ew:01: Input and output shapes differ; spec line 6521.  */
void
case_msellt_ew_01 (void)
{
  __riscv_ztt_i32_1x4_t src1_i32_1x4 = __riscv_ztt_mzero_m_i32_1x4 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  (void) __riscv_ztt_msellt_ew_i32_1x2 (src1_i32_1x4, src2_i32_1x2); /* { dg-error "AME/Ztt elementwise arithmetic requires integer M operands with the result shape" } */
}

/* msellt_ew:02: Input and output shape orientations differ; spec line 6522.  */
void
case_msellt_ew_02 (void)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_2x1_t src2_i32_2x1 = __riscv_ztt_mzero_m_i32_2x1 ();
  (void) __riscv_ztt_msellt_ew_i32_1x2 (src1_i32_1x2, src2_i32_2x1); /* { dg-error "AME/Ztt elementwise arithmetic requires integer M operands with the result shape" } */
}

/* msellt_ew:03: src2 and dst datatypes differ; spec line 6523.  */
void
case_msellt_ew_03 (void)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i16_1x2_t src2_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  (void) __riscv_ztt_msellt_ew_i32_1x2 (src1_i32_1x2, src2_i16_1x2); /* { dg-error "AME/Ztt conditional selection requires selected data to have the exact result datatype, rounding mode and shape" } */
}
