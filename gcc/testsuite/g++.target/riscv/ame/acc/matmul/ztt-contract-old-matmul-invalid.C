/* Normative IDs and adaptations are recorded in F59.  */
/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m32-a16 -fmax-errors=0" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m32-a16 -fmax-errors=0" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>

/* mmulacc_2d:01: Accumulator datatypes differ; spec line 1352.  */
void
case_mmulacc_2d_01 (void)
{
  __riscv_ztt_f32_accx2_t old_acc_f32_accx2 = __riscv_ztt_mzero_acc_f32_accx2 ();
  __riscv_ztt_i16_1x2_t src1_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i32_2x1_t src2_i32_2x1 = __riscv_ztt_mzero_m_i32_2x1 ();
  (void) __riscv_ztt_mmulacc_2d_i16_accx2 (old_acc_f32_accx2, src1_i16_1x2, src2_i32_2x1); /* { dg-error "AME/Ztt floating matmul requires old_acc to have the exact result datatype and shape" } */
}

/* mmulacc_2d:02: Accumulator shapes differ; spec line 1353.  */
void
case_mmulacc_2d_02 (void)
{
  __riscv_ztt_i16_accx1_t old_acc_i16_accx1 = __riscv_ztt_mzero_acc_i16_accx1 ();
  __riscv_ztt_i16_1x2_t src1_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i32_2x1_t src2_i32_2x1 = __riscv_ztt_mzero_m_i32_2x1 ();
  (void) __riscv_ztt_mmulacc_2d_i16_accx2 (old_acc_i16_accx1, src1_i16_1x2, src2_i32_2x1); /* { dg-error "cannot convert '__riscv_ztt_i16_rnu_accx1_t' to '__riscv_ztt_i16_rnu_accx2_t'" } */
}

/* mmulacc_2d:03: src1 must be 1xK; spec line 1354.  */
void
case_mmulacc_2d_03 (void)
{
  __riscv_ztt_i16_accx2_t old_acc_i16_accx2 = __riscv_ztt_mzero_acc_i16_accx2 ();
  __riscv_ztt_i16_2x1_t src1_i16_2x1 = __riscv_ztt_mzero_m_i16_2x1 ();
  __riscv_ztt_i32_2x1_t src2_i32_2x1 = __riscv_ztt_mzero_m_i32_2x1 ();
  (void) __riscv_ztt_mmulacc_2d_i16_accx2 (old_acc_i16_accx2, src1_i16_2x1, src2_i32_2x1); /* { dg-error "cannot convert '__riscv_ztt_i16_rnu_2x1_t' to '__riscv_ztt_i16_rnu_1x1_t'" } */
}

/* mmulacc_2d:04: src2 must be Kx1; spec line 1355.  */
void
case_mmulacc_2d_04 (void)
{
  __riscv_ztt_i16_accx2_t old_acc_i16_accx2 = __riscv_ztt_mzero_acc_i16_accx2 ();
  __riscv_ztt_i16_1x2_t src1_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  (void) __riscv_ztt_mmulacc_2d_i16_accx2 (old_acc_i16_accx2, src1_i16_1x2, src2_i32_1x2); /* { dg-error "cannot convert '__riscv_ztt_i16_rnu_1x2_t' to '__riscv_ztt_i16_rnu_1x1_t'" } */
}

/* mmulacc_2d:05: Input K values differ; spec line 1356.  */
void
case_mmulacc_2d_05 (void)
{
  __riscv_ztt_i16_accx2_t old_acc_i16_accx2 = __riscv_ztt_mzero_acc_i16_accx2 ();
  __riscv_ztt_i16_1x2_t src1_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i32_4x1_t src2_i32_4x1 = __riscv_ztt_mzero_m_i32_4x1 ();
  (void) __riscv_ztt_mmulacc_2d_i16_accx2 (old_acc_i16_accx2, src1_i16_1x2, src2_i32_4x1); /* { dg-error "cannot convert '__riscv_ztt_i16_rnu_1x2_t' to '__riscv_ztt_i16_rnu_1x1_t'" } */
}

/* mmulaccneg_2d:01: Accumulator datatypes differ; spec line 1433.  */
void
case_mmulaccneg_2d_01 (void)
{
  __riscv_ztt_f32_accx2_t old_acc_f32_accx2 = __riscv_ztt_mzero_acc_f32_accx2 ();
  __riscv_ztt_i16_1x2_t src1_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i32_2x1_t src2_i32_2x1 = __riscv_ztt_mzero_m_i32_2x1 ();
  (void) __riscv_ztt_mmulaccneg_2d_i16_accx2 (old_acc_f32_accx2, src1_i16_1x2, src2_i32_2x1); /* { dg-error "AME/Ztt floating matmul requires old_acc to have the exact result datatype and shape" } */
}

/* mmulaccneg_2d:02: Accumulator shapes differ; spec line 1434.  */
void
case_mmulaccneg_2d_02 (void)
{
  __riscv_ztt_i16_accx1_t old_acc_i16_accx1 = __riscv_ztt_mzero_acc_i16_accx1 ();
  __riscv_ztt_i16_1x2_t src1_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i32_2x1_t src2_i32_2x1 = __riscv_ztt_mzero_m_i32_2x1 ();
  (void) __riscv_ztt_mmulaccneg_2d_i16_accx2 (old_acc_i16_accx1, src1_i16_1x2, src2_i32_2x1); /* { dg-error "cannot convert '__riscv_ztt_i16_rnu_accx1_t' to '__riscv_ztt_i16_rnu_accx2_t'" } */
}

/* mmulaccneg_2d:03: src2 must be Kx1; spec line 1435.  */
void
case_mmulaccneg_2d_03 (void)
{
  __riscv_ztt_i16_accx2_t old_acc_i16_accx2 = __riscv_ztt_mzero_acc_i16_accx2 ();
  __riscv_ztt_i16_1x2_t src1_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  (void) __riscv_ztt_mmulaccneg_2d_i16_accx2 (old_acc_i16_accx2, src1_i16_1x2, src2_i32_1x2); /* { dg-error "cannot convert '__riscv_ztt_i16_rnu_1x2_t' to '__riscv_ztt_i16_rnu_1x1_t'" } */
}

/* mmulaccneg_2d:04: Input K values differ; spec line 1436.  */
void
case_mmulaccneg_2d_04 (void)
{
  __riscv_ztt_i16_accx2_t old_acc_i16_accx2 = __riscv_ztt_mzero_acc_i16_accx2 ();
  __riscv_ztt_i16_1x2_t src1_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i32_4x1_t src2_i32_4x1 = __riscv_ztt_mzero_m_i32_4x1 ();
  (void) __riscv_ztt_mmulaccneg_2d_i16_accx2 (old_acc_i16_accx2, src1_i16_1x2, src2_i32_4x1); /* { dg-error "cannot convert '__riscv_ztt_i16_rnu_1x2_t' to '__riscv_ztt_i16_rnu_1x1_t'" } */
}

/* mmulaccneg_2d:05: src1 must be 1xK; spec line 1437.  */
void
case_mmulaccneg_2d_05 (void)
{
  __riscv_ztt_i16_accx2_t old_acc_i16_accx2 = __riscv_ztt_mzero_acc_i16_accx2 ();
  __riscv_ztt_i16_2x1_t src1_i16_2x1 = __riscv_ztt_mzero_m_i16_2x1 ();
  __riscv_ztt_i32_2x1_t src2_i32_2x1 = __riscv_ztt_mzero_m_i32_2x1 ();
  (void) __riscv_ztt_mmulaccneg_2d_i16_accx2 (old_acc_i16_accx2, src1_i16_2x1, src2_i32_2x1); /* { dg-error "cannot convert '__riscv_ztt_i16_rnu_2x1_t' to '__riscv_ztt_i16_rnu_1x1_t'" } */
}

/* mmulatacc_2d:01: Accumulator datatypes differ; spec line 1514.  */
void
case_mmulatacc_2d_01 (void)
{
  __riscv_ztt_f32_accx2_t old_acc_f32_accx2 = __riscv_ztt_mzero_acc_f32_accx2 ();
  __riscv_ztt_i16_1x2_t src1_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  (void) __riscv_ztt_mmulatacc_2d_i16_accx2 (old_acc_f32_accx2, src1_i16_1x2, src2_i32_1x2); /* { dg-error "AME/Ztt floating matmul requires old_acc to have the exact result datatype and shape" } */
}

/* mmulatacc_2d:02: Accumulator shapes differ; spec line 1515.  */
void
case_mmulatacc_2d_02 (void)
{
  __riscv_ztt_i16_accx1_t old_acc_i16_accx1 = __riscv_ztt_mzero_acc_i16_accx1 ();
  __riscv_ztt_i16_1x2_t src1_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  (void) __riscv_ztt_mmulatacc_2d_i16_accx2 (old_acc_i16_accx1, src1_i16_1x2, src2_i32_1x2); /* { dg-error "cannot convert '__riscv_ztt_i16_rnu_accx1_t' to '__riscv_ztt_i16_rnu_accx2_t'" } */
}

/* mmulatacc_2d:03: Inputs must have the same orientation; spec line 1516.  */
void
case_mmulatacc_2d_03 (void)
{
  __riscv_ztt_i16_accx2_t old_acc_i16_accx2 = __riscv_ztt_mzero_acc_i16_accx2 ();
  __riscv_ztt_i16_1x2_t src1_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i32_2x1_t src2_i32_2x1 = __riscv_ztt_mzero_m_i32_2x1 ();
  (void) __riscv_ztt_mmulatacc_2d_i16_accx2 (old_acc_i16_accx2, src1_i16_1x2, src2_i32_2x1); /* { dg-error "cannot convert '__riscv_ztt_i16_rnu_1x2_t' to '__riscv_ztt_i16_rnu_1x1_t'" } */
}

/* mmulatacc_2d:04: Input K values differ; spec line 1517.  */
void
case_mmulatacc_2d_04 (void)
{
  __riscv_ztt_i16_accx2_t old_acc_i16_accx2 = __riscv_ztt_mzero_acc_i16_accx2 ();
  __riscv_ztt_i16_1x2_t src1_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i32_1x4_t src2_i32_1x4 = __riscv_ztt_mzero_m_i32_1x4 ();
  (void) __riscv_ztt_mmulatacc_2d_i16_accx2 (old_acc_i16_accx2, src1_i16_1x2, src2_i32_1x4); /* { dg-error "cannot convert '__riscv_ztt_i16_rnu_1x2_t' to '__riscv_ztt_i16_rnu_1x1_t'" } */
}

/* mmulataccneg_2d:01: Accumulator datatypes differ; spec line 1594.  */
void
case_mmulataccneg_2d_01 (void)
{
  __riscv_ztt_f32_accx2_t old_acc_f32_accx2 = __riscv_ztt_mzero_acc_f32_accx2 ();
  __riscv_ztt_i16_1x2_t src1_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  (void) __riscv_ztt_mmulataccneg_2d_i16_accx2 (old_acc_f32_accx2, src1_i16_1x2, src2_i32_1x2); /* { dg-error "AME/Ztt floating matmul requires old_acc to have the exact result datatype and shape" } */
}

/* mmulataccneg_2d:02: Accumulator shapes differ; spec line 1595.  */
void
case_mmulataccneg_2d_02 (void)
{
  __riscv_ztt_i16_accx1_t old_acc_i16_accx1 = __riscv_ztt_mzero_acc_i16_accx1 ();
  __riscv_ztt_i16_1x2_t src1_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  (void) __riscv_ztt_mmulataccneg_2d_i16_accx2 (old_acc_i16_accx1, src1_i16_1x2, src2_i32_1x2); /* { dg-error "cannot convert '__riscv_ztt_i16_rnu_accx1_t' to '__riscv_ztt_i16_rnu_accx2_t'" } */
}

/* mmulataccneg_2d:03: Inputs must have the same orientation; spec line 1596.  */
void
case_mmulataccneg_2d_03 (void)
{
  __riscv_ztt_i16_accx2_t old_acc_i16_accx2 = __riscv_ztt_mzero_acc_i16_accx2 ();
  __riscv_ztt_i16_1x2_t src1_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i32_2x1_t src2_i32_2x1 = __riscv_ztt_mzero_m_i32_2x1 ();
  (void) __riscv_ztt_mmulataccneg_2d_i16_accx2 (old_acc_i16_accx2, src1_i16_1x2, src2_i32_2x1); /* { dg-error "cannot convert '__riscv_ztt_i16_rnu_1x2_t' to '__riscv_ztt_i16_rnu_1x1_t'" } */
}

/* mmulataccneg_2d:04: Input K values differ; spec line 1597.  */
void
case_mmulataccneg_2d_04 (void)
{
  __riscv_ztt_i16_accx2_t old_acc_i16_accx2 = __riscv_ztt_mzero_acc_i16_accx2 ();
  __riscv_ztt_i16_1x2_t src1_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i32_1x4_t src2_i32_1x4 = __riscv_ztt_mzero_m_i32_1x4 ();
  (void) __riscv_ztt_mmulataccneg_2d_i16_accx2 (old_acc_i16_accx2, src1_i16_1x2, src2_i32_1x4); /* { dg-error "cannot convert '__riscv_ztt_i16_rnu_1x2_t' to '__riscv_ztt_i16_rnu_1x1_t'" } */
}

/* mmulbtacc_2d:01: Accumulator datatypes differ; spec line 1674.  */
void
case_mmulbtacc_2d_01 (void)
{
  __riscv_ztt_f32_accx2_t old_acc_f32_accx2 = __riscv_ztt_mzero_acc_f32_accx2 ();
  __riscv_ztt_i16_1x2_t src1_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  (void) __riscv_ztt_mmulbtacc_2d_i16_accx2 (old_acc_f32_accx2, src1_i16_1x2, src2_i32_1x2); /* { dg-error "AME/Ztt floating matmul requires old_acc to have the exact result datatype and shape" } */
}

/* mmulbtacc_2d:02: Accumulator shapes differ; spec line 1675.  */
void
case_mmulbtacc_2d_02 (void)
{
  __riscv_ztt_i16_accx1_t old_acc_i16_accx1 = __riscv_ztt_mzero_acc_i16_accx1 ();
  __riscv_ztt_i16_1x2_t src1_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  (void) __riscv_ztt_mmulbtacc_2d_i16_accx2 (old_acc_i16_accx1, src1_i16_1x2, src2_i32_1x2); /* { dg-error "cannot convert '__riscv_ztt_i16_rnu_accx1_t' to '__riscv_ztt_i16_rnu_accx2_t'" } */
}

/* mmulbtacc_2d:03: Inputs must have the same orientation; spec line 1676.  */
void
case_mmulbtacc_2d_03 (void)
{
  __riscv_ztt_i16_accx2_t old_acc_i16_accx2 = __riscv_ztt_mzero_acc_i16_accx2 ();
  __riscv_ztt_i16_1x2_t src1_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i32_2x1_t src2_i32_2x1 = __riscv_ztt_mzero_m_i32_2x1 ();
  (void) __riscv_ztt_mmulbtacc_2d_i16_accx2 (old_acc_i16_accx2, src1_i16_1x2, src2_i32_2x1); /* { dg-error "cannot convert '__riscv_ztt_i16_rnu_1x2_t' to '__riscv_ztt_i16_rnu_1x1_t'" } */
}

/* mmulbtacc_2d:04: Input K values differ; spec line 1677.  */
void
case_mmulbtacc_2d_04 (void)
{
  __riscv_ztt_i16_accx2_t old_acc_i16_accx2 = __riscv_ztt_mzero_acc_i16_accx2 ();
  __riscv_ztt_i16_1x2_t src1_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i32_1x4_t src2_i32_1x4 = __riscv_ztt_mzero_m_i32_1x4 ();
  (void) __riscv_ztt_mmulbtacc_2d_i16_accx2 (old_acc_i16_accx2, src1_i16_1x2, src2_i32_1x4); /* { dg-error "cannot convert '__riscv_ztt_i16_rnu_1x2_t' to '__riscv_ztt_i16_rnu_1x1_t'" } */
}

/* mmulbtaccneg_2d:01: Accumulator datatypes differ; spec line 1754.  */
void
case_mmulbtaccneg_2d_01 (void)
{
  __riscv_ztt_f32_accx2_t old_acc_f32_accx2 = __riscv_ztt_mzero_acc_f32_accx2 ();
  __riscv_ztt_i16_1x2_t src1_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  (void) __riscv_ztt_mmulbtaccneg_2d_i16_accx2 (old_acc_f32_accx2, src1_i16_1x2, src2_i32_1x2); /* { dg-error "AME/Ztt floating matmul requires old_acc to have the exact result datatype and shape" } */
}

/* mmulbtaccneg_2d:02: Accumulator shapes differ; spec line 1755.  */
void
case_mmulbtaccneg_2d_02 (void)
{
  __riscv_ztt_i16_accx1_t old_acc_i16_accx1 = __riscv_ztt_mzero_acc_i16_accx1 ();
  __riscv_ztt_i16_1x2_t src1_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  (void) __riscv_ztt_mmulbtaccneg_2d_i16_accx2 (old_acc_i16_accx1, src1_i16_1x2, src2_i32_1x2); /* { dg-error "cannot convert '__riscv_ztt_i16_rnu_accx1_t' to '__riscv_ztt_i16_rnu_accx2_t'" } */
}

/* mmulbtaccneg_2d:03: Inputs must have the same orientation; spec line 1756.  */
void
case_mmulbtaccneg_2d_03 (void)
{
  __riscv_ztt_i16_accx2_t old_acc_i16_accx2 = __riscv_ztt_mzero_acc_i16_accx2 ();
  __riscv_ztt_i16_1x2_t src1_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i32_2x1_t src2_i32_2x1 = __riscv_ztt_mzero_m_i32_2x1 ();
  (void) __riscv_ztt_mmulbtaccneg_2d_i16_accx2 (old_acc_i16_accx2, src1_i16_1x2, src2_i32_2x1); /* { dg-error "cannot convert '__riscv_ztt_i16_rnu_1x2_t' to '__riscv_ztt_i16_rnu_1x1_t'" } */
}

/* mmulbtaccneg_2d:04: Input K values differ; spec line 1757.  */
void
case_mmulbtaccneg_2d_04 (void)
{
  __riscv_ztt_i16_accx2_t old_acc_i16_accx2 = __riscv_ztt_mzero_acc_i16_accx2 ();
  __riscv_ztt_i16_1x2_t src1_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i32_1x4_t src2_i32_1x4 = __riscv_ztt_mzero_m_i32_1x4 ();
  (void) __riscv_ztt_mmulbtaccneg_2d_i16_accx2 (old_acc_i16_accx2, src1_i16_1x2, src2_i32_1x4); /* { dg-error "cannot convert '__riscv_ztt_i16_rnu_1x2_t' to '__riscv_ztt_i16_rnu_1x1_t'" } */
}
