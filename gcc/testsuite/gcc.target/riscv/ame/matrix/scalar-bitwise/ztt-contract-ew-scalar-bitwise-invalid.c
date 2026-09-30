/* Normative IDs and adaptations are recorded in F60.  */
/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m32-a16 -fmax-errors=0" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m32-a16 -fmax-errors=0" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>

/* mand_ew_x:01: Input and output shapes differ; spec line 4620.  */
void
case_mand_ew_x_01 (void)
{
  __riscv_ztt_i32_1x4_t src_i32_1x4 = __riscv_ztt_mzero_m_i32_1x4 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  (void) __riscv_ztt_mand_ew_x_i32_1x2 (src_i32_1x4, scalar_i32); /* { dg-error "AME/Ztt integer data-scalar operation requires compatible types, shapes and complete M groups; min/max and bitwise require the exact result datatype for the M source" } */
}

/* mand_ew_x:02: Input and output shape orientations differ; spec line 4621.  */
void
case_mand_ew_x_02 (void)
{
  __riscv_ztt_i32_2x1_t src_i32_2x1 = __riscv_ztt_mzero_m_i32_2x1 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  (void) __riscv_ztt_mand_ew_x_i32_1x2 (src_i32_2x1, scalar_i32); /* { dg-error "AME/Ztt integer data-scalar operation requires compatible types, shapes and complete M groups; min/max and bitwise require the exact result datatype for the M source" } */
}

/* mand_ew_x:03: Data source and dst datatypes differ; spec line 4622.  */
void
case_mand_ew_x_03 (void)
{
  __riscv_ztt_i16_1x2_t src_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  (void) __riscv_ztt_mand_ew_x_i32_1x2 (src_i16_1x2, scalar_i32); /* { dg-error "AME/Ztt integer data-scalar operation requires compatible types, shapes and complete M groups; min/max and bitwise require the exact result datatype for the M source" } */
}

/* mand_ew_x:04: Matrix datatypes must be integer; spec line 4623.  */
void
case_mand_ew_x_04 (void)
{
  __riscv_ztt_f32_1x2_t src_f32_1x2 = __riscv_ztt_mzero_m_f32_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  (void) __riscv_ztt_mand_ew_x_f32_1x2 (src_f32_1x2, scalar_i32); /* { dg-error "implicit declaration of function '__riscv_ztt_mand_ew_x_f32_1x2'" } */
}

/* mand_ew_x:05: 4-bit Scalar types are unsupported; spec line 4624.  */
void
case_mand_ew_x_05 (void)
{
  /* The excluded type prevents forming the original call.  */
  typedef __riscv_ztt_i4_scalar_t unavailable_scalar; /* { dg-error "unknown type name '__riscv_ztt_i4_scalar_t'" } */
}

/* mandnot_ew_x:01: Input and output shapes differ; spec line 4793.  */
void
case_mandnot_ew_x_01 (void)
{
  __riscv_ztt_i32_1x4_t src_i32_1x4 = __riscv_ztt_mzero_m_i32_1x4 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  (void) __riscv_ztt_mandnot_ew_x_i32_1x2 (src_i32_1x4, scalar_i32); /* { dg-error "AME/Ztt integer data-scalar operation requires compatible types, shapes and complete M groups; min/max and bitwise require the exact result datatype for the M source" } */
}

/* mandnot_ew_x:02: Input and output shape orientations differ; spec line 4794.  */
void
case_mandnot_ew_x_02 (void)
{
  __riscv_ztt_i32_2x1_t src_i32_2x1 = __riscv_ztt_mzero_m_i32_2x1 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  (void) __riscv_ztt_mandnot_ew_x_i32_1x2 (src_i32_2x1, scalar_i32); /* { dg-error "AME/Ztt integer data-scalar operation requires compatible types, shapes and complete M groups; min/max and bitwise require the exact result datatype for the M source" } */
}

/* mandnot_ew_x:03: Data source and dst datatypes differ; spec line 4795.  */
void
case_mandnot_ew_x_03 (void)
{
  __riscv_ztt_i16_1x2_t src_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  (void) __riscv_ztt_mandnot_ew_x_i32_1x2 (src_i16_1x2, scalar_i32); /* { dg-error "AME/Ztt integer data-scalar operation requires compatible types, shapes and complete M groups; min/max and bitwise require the exact result datatype for the M source" } */
}

/* mandnot_ew_x:04: Matrix datatypes must be integer; spec line 4796.  */
void
case_mandnot_ew_x_04 (void)
{
  __riscv_ztt_f32_1x2_t src_f32_1x2 = __riscv_ztt_mzero_m_f32_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  (void) __riscv_ztt_mandnot_ew_x_f32_1x2 (src_f32_1x2, scalar_i32); /* { dg-error "implicit declaration of function '__riscv_ztt_mandnot_ew_x_f32_1x2'" } */
}

/* mandnot_ew_x:05: 4-bit Scalar types are unsupported; spec line 4797.  */
void
case_mandnot_ew_x_05 (void)
{
  /* The excluded type prevents forming the original call.  */
  typedef __riscv_ztt_i4_scalar_t unavailable_scalar; /* { dg-error "unknown type name '__riscv_ztt_i4_scalar_t'" } */
}

/* mor_ew_x:01: Input and output shapes differ; spec line 4966.  */
void
case_mor_ew_x_01 (void)
{
  __riscv_ztt_i32_1x4_t src_i32_1x4 = __riscv_ztt_mzero_m_i32_1x4 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  (void) __riscv_ztt_mor_ew_x_i32_1x2 (src_i32_1x4, scalar_i32); /* { dg-error "AME/Ztt integer data-scalar operation requires compatible types, shapes and complete M groups; min/max and bitwise require the exact result datatype for the M source" } */
}

/* mor_ew_x:02: Input and output shape orientations differ; spec line 4967.  */
void
case_mor_ew_x_02 (void)
{
  __riscv_ztt_i32_2x1_t src_i32_2x1 = __riscv_ztt_mzero_m_i32_2x1 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  (void) __riscv_ztt_mor_ew_x_i32_1x2 (src_i32_2x1, scalar_i32); /* { dg-error "AME/Ztt integer data-scalar operation requires compatible types, shapes and complete M groups; min/max and bitwise require the exact result datatype for the M source" } */
}

/* mor_ew_x:03: Data source and dst datatypes differ; spec line 4968.  */
void
case_mor_ew_x_03 (void)
{
  __riscv_ztt_i16_1x2_t src_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  (void) __riscv_ztt_mor_ew_x_i32_1x2 (src_i16_1x2, scalar_i32); /* { dg-error "AME/Ztt integer data-scalar operation requires compatible types, shapes and complete M groups; min/max and bitwise require the exact result datatype for the M source" } */
}

/* mor_ew_x:04: Matrix datatypes must be integer; spec line 4969.  */
void
case_mor_ew_x_04 (void)
{
  __riscv_ztt_f32_1x2_t src_f32_1x2 = __riscv_ztt_mzero_m_f32_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  (void) __riscv_ztt_mor_ew_x_f32_1x2 (src_f32_1x2, scalar_i32); /* { dg-error "implicit declaration of function '__riscv_ztt_mor_ew_x_f32_1x2'" } */
}

/* mor_ew_x:05: 4-bit Scalar types are unsupported; spec line 4970.  */
void
case_mor_ew_x_05 (void)
{
  /* The excluded type prevents forming the original call.  */
  typedef __riscv_ztt_i4_scalar_t unavailable_scalar; /* { dg-error "unknown type name '__riscv_ztt_i4_scalar_t'" } */
}

/* mornot_ew_x:01: Input and output shapes differ; spec line 5139.  */
void
case_mornot_ew_x_01 (void)
{
  __riscv_ztt_i32_1x4_t src_i32_1x4 = __riscv_ztt_mzero_m_i32_1x4 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  (void) __riscv_ztt_mornot_ew_x_i32_1x2 (src_i32_1x4, scalar_i32); /* { dg-error "AME/Ztt integer data-scalar operation requires compatible types, shapes and complete M groups; min/max and bitwise require the exact result datatype for the M source" } */
}

/* mornot_ew_x:02: Input and output shape orientations differ; spec line 5140.  */
void
case_mornot_ew_x_02 (void)
{
  __riscv_ztt_i32_2x1_t src_i32_2x1 = __riscv_ztt_mzero_m_i32_2x1 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  (void) __riscv_ztt_mornot_ew_x_i32_1x2 (src_i32_2x1, scalar_i32); /* { dg-error "AME/Ztt integer data-scalar operation requires compatible types, shapes and complete M groups; min/max and bitwise require the exact result datatype for the M source" } */
}

/* mornot_ew_x:03: Data source and dst datatypes differ; spec line 5141.  */
void
case_mornot_ew_x_03 (void)
{
  __riscv_ztt_i16_1x2_t src_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  (void) __riscv_ztt_mornot_ew_x_i32_1x2 (src_i16_1x2, scalar_i32); /* { dg-error "AME/Ztt integer data-scalar operation requires compatible types, shapes and complete M groups; min/max and bitwise require the exact result datatype for the M source" } */
}

/* mornot_ew_x:04: Matrix datatypes must be integer; spec line 5142.  */
void
case_mornot_ew_x_04 (void)
{
  __riscv_ztt_f32_1x2_t src_f32_1x2 = __riscv_ztt_mzero_m_f32_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  (void) __riscv_ztt_mornot_ew_x_f32_1x2 (src_f32_1x2, scalar_i32); /* { dg-error "implicit declaration of function '__riscv_ztt_mornot_ew_x_f32_1x2'" } */
}

/* mornot_ew_x:05: 4-bit Scalar types are unsupported; spec line 5143.  */
void
case_mornot_ew_x_05 (void)
{
  /* The excluded type prevents forming the original call.  */
  typedef __riscv_ztt_i4_scalar_t unavailable_scalar; /* { dg-error "unknown type name '__riscv_ztt_i4_scalar_t'" } */
}

/* mxor_ew_x:01: Input and output shapes differ; spec line 5312.  */
void
case_mxor_ew_x_01 (void)
{
  __riscv_ztt_i32_1x4_t src_i32_1x4 = __riscv_ztt_mzero_m_i32_1x4 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  (void) __riscv_ztt_mxor_ew_x_i32_1x2 (src_i32_1x4, scalar_i32); /* { dg-error "AME/Ztt integer data-scalar operation requires compatible types, shapes and complete M groups; min/max and bitwise require the exact result datatype for the M source" } */
}

/* mxor_ew_x:02: Input and output shape orientations differ; spec line 5313.  */
void
case_mxor_ew_x_02 (void)
{
  __riscv_ztt_i32_2x1_t src_i32_2x1 = __riscv_ztt_mzero_m_i32_2x1 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  (void) __riscv_ztt_mxor_ew_x_i32_1x2 (src_i32_2x1, scalar_i32); /* { dg-error "AME/Ztt integer data-scalar operation requires compatible types, shapes and complete M groups; min/max and bitwise require the exact result datatype for the M source" } */
}

/* mxor_ew_x:03: Data source and dst datatypes differ; spec line 5314.  */
void
case_mxor_ew_x_03 (void)
{
  __riscv_ztt_i16_1x2_t src_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  (void) __riscv_ztt_mxor_ew_x_i32_1x2 (src_i16_1x2, scalar_i32); /* { dg-error "AME/Ztt integer data-scalar operation requires compatible types, shapes and complete M groups; min/max and bitwise require the exact result datatype for the M source" } */
}

/* mxor_ew_x:04: Matrix datatypes must be integer; spec line 5315.  */
void
case_mxor_ew_x_04 (void)
{
  __riscv_ztt_f32_1x2_t src_f32_1x2 = __riscv_ztt_mzero_m_f32_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  (void) __riscv_ztt_mxor_ew_x_f32_1x2 (src_f32_1x2, scalar_i32); /* { dg-error "implicit declaration of function '__riscv_ztt_mxor_ew_x_f32_1x2'" } */
}

/* mxor_ew_x:05: 4-bit Scalar types are unsupported; spec line 5316.  */
void
case_mxor_ew_x_05 (void)
{
  /* The excluded type prevents forming the original call.  */
  typedef __riscv_ztt_i4_scalar_t unavailable_scalar; /* { dg-error "unknown type name '__riscv_ztt_i4_scalar_t'" } */
}
