/* Normative IDs and adaptations are recorded in F59.  */
/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m32-a16 -fmax-errors=0" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m32-a16 -fmax-errors=0" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>

/* mmulacc_ew_x:01: Input and output shapes differ; spec line 3577.  */
void
case_mmulacc_ew_x_01 (void)
{
  __riscv_ztt_i32_1x2_t old_d_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x4_t src_i32_1x4 = __riscv_ztt_mzero_m_i32_1x4 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  (void) __riscv_ztt_mmulacc_ew_x_i32_1x2 (old_d_i32_1x2, src_i32_1x4, scalar_i32); /* { dg-error "AME/Ztt integer data-scalar operation requires compatible types, shapes and complete M groups; min/max and bitwise require the exact result datatype for the M source" } */
}

/* mmulacc_ew_x:02: Input and output shape orientations differ; spec line 3578.  */
void
case_mmulacc_ew_x_02 (void)
{
  __riscv_ztt_i32_1x2_t old_d_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_2x1_t src_i32_2x1 = __riscv_ztt_mzero_m_i32_2x1 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  (void) __riscv_ztt_mmulacc_ew_x_i32_1x2 (old_d_i32_1x2, src_i32_2x1, scalar_i32); /* { dg-error "AME/Ztt integer data-scalar operation requires compatible types, shapes and complete M groups; min/max and bitwise require the exact result datatype for the M source" } */
}

/* mmulacc_ew_x:03: old_d and dst datatypes differ; spec line 3579.  */
void
case_mmulacc_ew_x_03 (void)
{
  __riscv_ztt_i16_1x2_t old_d_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i32_1x2_t src_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  (void) __riscv_ztt_mmulacc_ew_x_i32_1x2 (old_d_i16_1x2, src_i32_1x2, scalar_i32); /* { dg-error "AME/Ztt scalar ternary arithmetic requires old_d to have the exact result datatype and shape" } */
}

/* mmulacc_ew_x:04: 4-bit Scalar types are unsupported; spec line 3580.  */
void
case_mmulacc_ew_x_04 (void)
{
  /* The original call cannot be formed without this excluded type.
     Its legal Scalar counterpart is compiled separately.  */
  typedef __riscv_ztt_i4_scalar_t unavailable_scalar; /* { dg-error "unknown type name '__riscv_ztt_i4_scalar_t'" } */
}

/* mmulacc_ew_x:05: old_d and dst shapes differ; spec line 3581.  */
void
case_mmulacc_ew_x_05 (void)
{
  __riscv_ztt_i32_1x4_t old_d_i32_1x4 = __riscv_ztt_mzero_m_i32_1x4 ();
  __riscv_ztt_i32_1x2_t src_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  (void) __riscv_ztt_mmulacc_ew_x_i32_1x2 (old_d_i32_1x4, src_i32_1x2, scalar_i32); /* { dg-error "AME/Ztt scalar ternary arithmetic requires old_d to have the exact result datatype and shape" } */
}

/* mmulaccneg_ew_x:01: Input and output shapes differ; spec line 3742.  */
void
case_mmulaccneg_ew_x_01 (void)
{
  __riscv_ztt_i32_1x2_t old_d_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x4_t src_i32_1x4 = __riscv_ztt_mzero_m_i32_1x4 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  (void) __riscv_ztt_mmulaccneg_ew_x_i32_1x2 (old_d_i32_1x2, src_i32_1x4, scalar_i32); /* { dg-error "AME/Ztt integer data-scalar operation requires compatible types, shapes and complete M groups; min/max and bitwise require the exact result datatype for the M source" } */
}

/* mmulaccneg_ew_x:02: Input and output shape orientations differ; spec line 3743.  */
void
case_mmulaccneg_ew_x_02 (void)
{
  __riscv_ztt_i32_1x2_t old_d_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_2x1_t src_i32_2x1 = __riscv_ztt_mzero_m_i32_2x1 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  (void) __riscv_ztt_mmulaccneg_ew_x_i32_1x2 (old_d_i32_1x2, src_i32_2x1, scalar_i32); /* { dg-error "AME/Ztt integer data-scalar operation requires compatible types, shapes and complete M groups; min/max and bitwise require the exact result datatype for the M source" } */
}

/* mmulaccneg_ew_x:03: old_d and dst datatypes differ; spec line 3744.  */
void
case_mmulaccneg_ew_x_03 (void)
{
  __riscv_ztt_i16_1x2_t old_d_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i32_1x2_t src_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  (void) __riscv_ztt_mmulaccneg_ew_x_i32_1x2 (old_d_i16_1x2, src_i32_1x2, scalar_i32); /* { dg-error "AME/Ztt scalar ternary arithmetic requires old_d to have the exact result datatype and shape" } */
}

/* mmulaccneg_ew_x:04: 4-bit Scalar types are unsupported; spec line 3745.  */
void
case_mmulaccneg_ew_x_04 (void)
{
  /* The original call cannot be formed without this excluded type.
     Its legal Scalar counterpart is compiled separately.  */
  typedef __riscv_ztt_i4_scalar_t unavailable_scalar; /* { dg-error "unknown type name '__riscv_ztt_i4_scalar_t'" } */
}

/* mmulaccneg_ew_x:05: old_d and dst shapes differ; spec line 3746.  */
void
case_mmulaccneg_ew_x_05 (void)
{
  __riscv_ztt_i32_1x4_t old_d_i32_1x4 = __riscv_ztt_mzero_m_i32_1x4 ();
  __riscv_ztt_i32_1x2_t src_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  (void) __riscv_ztt_mmulaccneg_ew_x_i32_1x2 (old_d_i32_1x4, src_i32_1x2, scalar_i32); /* { dg-error "AME/Ztt scalar ternary arithmetic requires old_d to have the exact result datatype and shape" } */
}

/* mmuladd_ew_x:01: Input and output shapes differ; spec line 3907.  */
void
case_mmuladd_ew_x_01 (void)
{
  __riscv_ztt_i32_1x2_t old_d_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x4_t src_i32_1x4 = __riscv_ztt_mzero_m_i32_1x4 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  (void) __riscv_ztt_mmuladd_ew_x_i32_1x2 (old_d_i32_1x2, src_i32_1x4, scalar_i32); /* { dg-error "AME/Ztt integer data-scalar operation requires compatible types, shapes and complete M groups; min/max and bitwise require the exact result datatype for the M source" } */
}

/* mmuladd_ew_x:02: Input and output shape orientations differ; spec line 3908.  */
void
case_mmuladd_ew_x_02 (void)
{
  __riscv_ztt_i32_1x2_t old_d_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_2x1_t src_i32_2x1 = __riscv_ztt_mzero_m_i32_2x1 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  (void) __riscv_ztt_mmuladd_ew_x_i32_1x2 (old_d_i32_1x2, src_i32_2x1, scalar_i32); /* { dg-error "AME/Ztt integer data-scalar operation requires compatible types, shapes and complete M groups; min/max and bitwise require the exact result datatype for the M source" } */
}

/* mmuladd_ew_x:03: old_d and dst datatypes differ; spec line 3909.  */
void
case_mmuladd_ew_x_03 (void)
{
  __riscv_ztt_i16_1x2_t old_d_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i32_1x2_t src_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  (void) __riscv_ztt_mmuladd_ew_x_i32_1x2 (old_d_i16_1x2, src_i32_1x2, scalar_i32); /* { dg-error "AME/Ztt scalar ternary arithmetic requires old_d to have the exact result datatype and shape" } */
}

/* mmuladd_ew_x:04: 4-bit Scalar types are unsupported; spec line 3910.  */
void
case_mmuladd_ew_x_04 (void)
{
  /* The original call cannot be formed without this excluded type.
     Its legal Scalar counterpart is compiled separately.  */
  typedef __riscv_ztt_i4_scalar_t unavailable_scalar; /* { dg-error "unknown type name '__riscv_ztt_i4_scalar_t'" } */
}

/* mmuladd_ew_x:05: old_d and dst shapes differ; spec line 3911.  */
void
case_mmuladd_ew_x_05 (void)
{
  __riscv_ztt_i32_1x4_t old_d_i32_1x4 = __riscv_ztt_mzero_m_i32_1x4 ();
  __riscv_ztt_i32_1x2_t src_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  (void) __riscv_ztt_mmuladd_ew_x_i32_1x2 (old_d_i32_1x4, src_i32_1x2, scalar_i32); /* { dg-error "AME/Ztt scalar ternary arithmetic requires old_d to have the exact result datatype and shape" } */
}

/* mmulsub_ew_x:01: Input and output shapes differ; spec line 4241.  */
void
case_mmulsub_ew_x_01 (void)
{
  __riscv_ztt_i32_1x2_t old_d_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x4_t src_i32_1x4 = __riscv_ztt_mzero_m_i32_1x4 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  (void) __riscv_ztt_mmulsub_ew_x_i32_1x2 (old_d_i32_1x2, src_i32_1x4, scalar_i32); /* { dg-error "AME/Ztt integer data-scalar operation requires compatible types, shapes and complete M groups; min/max and bitwise require the exact result datatype for the M source" } */
}

/* mmulsub_ew_x:02: Input and output shape orientations differ; spec line 4242.  */
void
case_mmulsub_ew_x_02 (void)
{
  __riscv_ztt_i32_1x2_t old_d_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_2x1_t src_i32_2x1 = __riscv_ztt_mzero_m_i32_2x1 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  (void) __riscv_ztt_mmulsub_ew_x_i32_1x2 (old_d_i32_1x2, src_i32_2x1, scalar_i32); /* { dg-error "AME/Ztt integer data-scalar operation requires compatible types, shapes and complete M groups; min/max and bitwise require the exact result datatype for the M source" } */
}

/* mmulsub_ew_x:03: old_d and dst datatypes differ; spec line 4243.  */
void
case_mmulsub_ew_x_03 (void)
{
  __riscv_ztt_i16_1x2_t old_d_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i32_1x2_t src_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  (void) __riscv_ztt_mmulsub_ew_x_i32_1x2 (old_d_i16_1x2, src_i32_1x2, scalar_i32); /* { dg-error "AME/Ztt scalar ternary arithmetic requires old_d to have the exact result datatype and shape" } */
}

/* mmulsub_ew_x:04: 4-bit Scalar types are unsupported; spec line 4244.  */
void
case_mmulsub_ew_x_04 (void)
{
  /* The original call cannot be formed without this excluded type.
     Its legal Scalar counterpart is compiled separately.  */
  typedef __riscv_ztt_i4_scalar_t unavailable_scalar; /* { dg-error "unknown type name '__riscv_ztt_i4_scalar_t'" } */
}

/* mmulsub_ew_x:05: old_d and dst shapes differ; spec line 4245.  */
void
case_mmulsub_ew_x_05 (void)
{
  __riscv_ztt_i32_1x4_t old_d_i32_1x4 = __riscv_ztt_mzero_m_i32_1x4 ();
  __riscv_ztt_i32_1x2_t src_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  (void) __riscv_ztt_mmulsub_ew_x_i32_1x2 (old_d_i32_1x4, src_i32_1x2, scalar_i32); /* { dg-error "AME/Ztt scalar ternary arithmetic requires old_d to have the exact result datatype and shape" } */
}
