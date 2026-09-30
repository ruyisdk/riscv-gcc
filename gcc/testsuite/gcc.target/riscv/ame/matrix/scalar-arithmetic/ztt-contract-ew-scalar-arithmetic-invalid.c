/* Normative IDs and adaptations are recorded in F60.  */
/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m32-a16 -fmax-errors=0" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m32-a16 -fmax-errors=0" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>

/* mabsdiff_ew_x:01: Input and output shapes differ; spec line 2070.  */
void
case_mabsdiff_ew_x_01 (void)
{
  __riscv_ztt_i32_1x4_t src_i32_1x4 = __riscv_ztt_mzero_m_i32_1x4 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  (void) __riscv_ztt_mabsdiff_ew_x_i32_1x2 (src_i32_1x4, scalar_i32); /* { dg-error "AME/Ztt integer data-scalar operation requires compatible types, shapes and complete M groups; min/max and bitwise require the exact result datatype for the M source" } */
}

/* mabsdiff_ew_x:02: Input and output shape orientations differ; spec line 2071.  */
void
case_mabsdiff_ew_x_02 (void)
{
  __riscv_ztt_i32_2x1_t src_i32_2x1 = __riscv_ztt_mzero_m_i32_2x1 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  (void) __riscv_ztt_mabsdiff_ew_x_i32_1x2 (src_i32_2x1, scalar_i32); /* { dg-error "AME/Ztt integer data-scalar operation requires compatible types, shapes and complete M groups; min/max and bitwise require the exact result datatype for the M source" } */
}

/* mabsdiff_ew_x:03: 4-bit Scalar types are unsupported; spec line 2072.  */
void
case_mabsdiff_ew_x_03 (void)
{
  /* The excluded type prevents forming the original call.  */
  typedef __riscv_ztt_i4_scalar_t unavailable_scalar; /* { dg-error "unknown type name '__riscv_ztt_i4_scalar_t'" } */
}

/* madd_ew_x:01: Input and output shapes differ; spec line 2240.  */
void
case_madd_ew_x_01 (void)
{
  __riscv_ztt_i32_1x4_t src_i32_1x4 = __riscv_ztt_mzero_m_i32_1x4 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  (void) __riscv_ztt_madd_ew_x_i32_1x2 (src_i32_1x4, scalar_i32); /* { dg-error "AME/Ztt integer data-scalar operation requires compatible types, shapes and complete M groups; min/max and bitwise require the exact result datatype for the M source" } */
}

/* madd_ew_x:02: Input and output shape orientations differ; spec line 2241.  */
void
case_madd_ew_x_02 (void)
{
  __riscv_ztt_i32_2x1_t src_i32_2x1 = __riscv_ztt_mzero_m_i32_2x1 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  (void) __riscv_ztt_madd_ew_x_i32_1x2 (src_i32_2x1, scalar_i32); /* { dg-error "AME/Ztt integer data-scalar operation requires compatible types, shapes and complete M groups; min/max and bitwise require the exact result datatype for the M source" } */
}

/* madd_ew_x:03: 4-bit Scalar types are unsupported; spec line 2242.  */
void
case_madd_ew_x_03 (void)
{
  /* The excluded type prevents forming the original call.  */
  typedef __riscv_ztt_i4_scalar_t unavailable_scalar; /* { dg-error "unknown type name '__riscv_ztt_i4_scalar_t'" } */
}

/* mhdiff_ew_x:01: Input and output shapes differ; spec line 2730.  */
void
case_mhdiff_ew_x_01 (void)
{
  __riscv_ztt_i32_1x4_t src_i32_1x4 = __riscv_ztt_mzero_m_i32_1x4 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  (void) __riscv_ztt_mhdiff_ew_x_i32_1x2 (src_i32_1x4, scalar_i32); /* { dg-error "AME/Ztt integer data-scalar operation requires compatible types, shapes and complete M groups; min/max and bitwise require the exact result datatype for the M source" } */
}

/* mhdiff_ew_x:02: Input and output shape orientations differ; spec line 2731.  */
void
case_mhdiff_ew_x_02 (void)
{
  __riscv_ztt_i32_2x1_t src_i32_2x1 = __riscv_ztt_mzero_m_i32_2x1 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  (void) __riscv_ztt_mhdiff_ew_x_i32_1x2 (src_i32_2x1, scalar_i32); /* { dg-error "AME/Ztt integer data-scalar operation requires compatible types, shapes and complete M groups; min/max and bitwise require the exact result datatype for the M source" } */
}

/* mhdiff_ew_x:03: 4-bit Scalar types are unsupported; spec line 2732.  */
void
case_mhdiff_ew_x_03 (void)
{
  /* The excluded type prevents forming the original call.  */
  typedef __riscv_ztt_i4_scalar_t unavailable_scalar; /* { dg-error "unknown type name '__riscv_ztt_i4_scalar_t'" } */
}

/* mmax_ew_x:01: Input and output shapes differ; spec line 2900.  */
void
case_mmax_ew_x_01 (void)
{
  __riscv_ztt_i32_1x4_t src_i32_1x4 = __riscv_ztt_mzero_m_i32_1x4 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  (void) __riscv_ztt_mmax_ew_x_i32_1x2 (src_i32_1x4, scalar_i32); /* { dg-error "AME/Ztt integer data-scalar operation requires compatible types, shapes and complete M groups; min/max and bitwise require the exact result datatype for the M source" } */
}

/* mmax_ew_x:02: Input and output shape orientations differ; spec line 2901.  */
void
case_mmax_ew_x_02 (void)
{
  __riscv_ztt_i32_2x1_t src_i32_2x1 = __riscv_ztt_mzero_m_i32_2x1 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  (void) __riscv_ztt_mmax_ew_x_i32_1x2 (src_i32_2x1, scalar_i32); /* { dg-error "AME/Ztt integer data-scalar operation requires compatible types, shapes and complete M groups; min/max and bitwise require the exact result datatype for the M source" } */
}

/* mmax_ew_x:03: Data source and dst datatypes differ; spec line 2902.  */
void
case_mmax_ew_x_03 (void)
{
  __riscv_ztt_i16_1x2_t src_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  (void) __riscv_ztt_mmax_ew_x_i32_1x2 (src_i16_1x2, scalar_i32); /* { dg-error "AME/Ztt integer data-scalar operation requires compatible types, shapes and complete M groups; min/max and bitwise require the exact result datatype for the M source" } */
}

/* mmax_ew_x:04: 4-bit Scalar types are unsupported; spec line 2903.  */
void
case_mmax_ew_x_04 (void)
{
  /* The excluded type prevents forming the original call.  */
  typedef __riscv_ztt_i4_scalar_t unavailable_scalar; /* { dg-error "unknown type name '__riscv_ztt_i4_scalar_t'" } */
}

/* mmean_ew_x:01: Input and output shapes differ; spec line 3070.  */
void
case_mmean_ew_x_01 (void)
{
  __riscv_ztt_i32_1x4_t src_i32_1x4 = __riscv_ztt_mzero_m_i32_1x4 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  (void) __riscv_ztt_mmean_ew_x_i32_1x2 (src_i32_1x4, scalar_i32); /* { dg-error "AME/Ztt integer data-scalar operation requires compatible types, shapes and complete M groups; min/max and bitwise require the exact result datatype for the M source" } */
}

/* mmean_ew_x:02: Input and output shape orientations differ; spec line 3071.  */
void
case_mmean_ew_x_02 (void)
{
  __riscv_ztt_i32_2x1_t src_i32_2x1 = __riscv_ztt_mzero_m_i32_2x1 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  (void) __riscv_ztt_mmean_ew_x_i32_1x2 (src_i32_2x1, scalar_i32); /* { dg-error "AME/Ztt integer data-scalar operation requires compatible types, shapes and complete M groups; min/max and bitwise require the exact result datatype for the M source" } */
}

/* mmean_ew_x:03: 4-bit Scalar types are unsupported; spec line 3072.  */
void
case_mmean_ew_x_03 (void)
{
  /* The excluded type prevents forming the original call.  */
  typedef __riscv_ztt_i4_scalar_t unavailable_scalar; /* { dg-error "unknown type name '__riscv_ztt_i4_scalar_t'" } */
}

/* mmin_ew_x:01: Input and output shapes differ; spec line 3240.  */
void
case_mmin_ew_x_01 (void)
{
  __riscv_ztt_i32_1x4_t src_i32_1x4 = __riscv_ztt_mzero_m_i32_1x4 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  (void) __riscv_ztt_mmin_ew_x_i32_1x2 (src_i32_1x4, scalar_i32); /* { dg-error "AME/Ztt integer data-scalar operation requires compatible types, shapes and complete M groups; min/max and bitwise require the exact result datatype for the M source" } */
}

/* mmin_ew_x:02: Input and output shape orientations differ; spec line 3241.  */
void
case_mmin_ew_x_02 (void)
{
  __riscv_ztt_i32_2x1_t src_i32_2x1 = __riscv_ztt_mzero_m_i32_2x1 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  (void) __riscv_ztt_mmin_ew_x_i32_1x2 (src_i32_2x1, scalar_i32); /* { dg-error "AME/Ztt integer data-scalar operation requires compatible types, shapes and complete M groups; min/max and bitwise require the exact result datatype for the M source" } */
}

/* mmin_ew_x:03: Data source and dst datatypes differ; spec line 3242.  */
void
case_mmin_ew_x_03 (void)
{
  __riscv_ztt_i16_1x2_t src_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  (void) __riscv_ztt_mmin_ew_x_i32_1x2 (src_i16_1x2, scalar_i32); /* { dg-error "AME/Ztt integer data-scalar operation requires compatible types, shapes and complete M groups; min/max and bitwise require the exact result datatype for the M source" } */
}

/* mmin_ew_x:04: 4-bit Scalar types are unsupported; spec line 3243.  */
void
case_mmin_ew_x_04 (void)
{
  /* The excluded type prevents forming the original call.  */
  typedef __riscv_ztt_i4_scalar_t unavailable_scalar; /* { dg-error "unknown type name '__riscv_ztt_i4_scalar_t'" } */
}

/* mmul_ew_x:01: Input and output shapes differ; spec line 3410.  */
void
case_mmul_ew_x_01 (void)
{
  __riscv_ztt_i32_1x4_t src_i32_1x4 = __riscv_ztt_mzero_m_i32_1x4 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  (void) __riscv_ztt_mmul_ew_x_i32_1x2 (src_i32_1x4, scalar_i32); /* { dg-error "AME/Ztt integer data-scalar operation requires compatible types, shapes and complete M groups; min/max and bitwise require the exact result datatype for the M source" } */
}

/* mmul_ew_x:02: Input and output shape orientations differ; spec line 3411.  */
void
case_mmul_ew_x_02 (void)
{
  __riscv_ztt_i32_2x1_t src_i32_2x1 = __riscv_ztt_mzero_m_i32_2x1 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  (void) __riscv_ztt_mmul_ew_x_i32_1x2 (src_i32_2x1, scalar_i32); /* { dg-error "AME/Ztt integer data-scalar operation requires compatible types, shapes and complete M groups; min/max and bitwise require the exact result datatype for the M source" } */
}

/* mmul_ew_x:03: 4-bit Scalar types are unsupported; spec line 3412.  */
void
case_mmul_ew_x_03 (void)
{
  /* The excluded type prevents forming the original call.  */
  typedef __riscv_ztt_i4_scalar_t unavailable_scalar; /* { dg-error "unknown type name '__riscv_ztt_i4_scalar_t'" } */
}

/* mmulneg_ew_x:01: Input and output shapes differ; spec line 4074.  */
void
case_mmulneg_ew_x_01 (void)
{
  __riscv_ztt_i32_1x4_t src_i32_1x4 = __riscv_ztt_mzero_m_i32_1x4 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  (void) __riscv_ztt_mmulneg_ew_x_i32_1x2 (src_i32_1x4, scalar_i32); /* { dg-error "AME/Ztt integer data-scalar operation requires compatible types, shapes and complete M groups; min/max and bitwise require the exact result datatype for the M source" } */
}

/* mmulneg_ew_x:02: Input and output shape orientations differ; spec line 4075.  */
void
case_mmulneg_ew_x_02 (void)
{
  __riscv_ztt_i32_2x1_t src_i32_2x1 = __riscv_ztt_mzero_m_i32_2x1 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  (void) __riscv_ztt_mmulneg_ew_x_i32_1x2 (src_i32_2x1, scalar_i32); /* { dg-error "AME/Ztt integer data-scalar operation requires compatible types, shapes and complete M groups; min/max and bitwise require the exact result datatype for the M source" } */
}

/* mmulneg_ew_x:03: 4-bit Scalar types are unsupported; spec line 4076.  */
void
case_mmulneg_ew_x_03 (void)
{
  /* The excluded type prevents forming the original call.  */
  typedef __riscv_ztt_i4_scalar_t unavailable_scalar; /* { dg-error "unknown type name '__riscv_ztt_i4_scalar_t'" } */
}

/* msub_ew_x:01: Input and output shapes differ; spec line 4408.  */
void
case_msub_ew_x_01 (void)
{
  __riscv_ztt_i32_1x4_t src_i32_1x4 = __riscv_ztt_mzero_m_i32_1x4 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  (void) __riscv_ztt_msub_ew_x_i32_1x2 (src_i32_1x4, scalar_i32); /* { dg-error "AME/Ztt integer data-scalar operation requires compatible types, shapes and complete M groups; min/max and bitwise require the exact result datatype for the M source" } */
}

/* msub_ew_x:02: Input and output shape orientations differ; spec line 4409.  */
void
case_msub_ew_x_02 (void)
{
  __riscv_ztt_i32_2x1_t src_i32_2x1 = __riscv_ztt_mzero_m_i32_2x1 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  (void) __riscv_ztt_msub_ew_x_i32_1x2 (src_i32_2x1, scalar_i32); /* { dg-error "AME/Ztt integer data-scalar operation requires compatible types, shapes and complete M groups; min/max and bitwise require the exact result datatype for the M source" } */
}

/* msub_ew_x:03: 4-bit Scalar types are unsupported; spec line 4410.  */
void
case_msub_ew_x_03 (void)
{
  /* The excluded type prevents forming the original call.  */
  typedef __riscv_ztt_i4_scalar_t unavailable_scalar; /* { dg-error "unknown type name '__riscv_ztt_i4_scalar_t'" } */
}
