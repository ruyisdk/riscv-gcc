/* Normative IDs and adaptations are recorded in F60.  */
/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m32-a16 -fmax-errors=0" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m32-a16 -fmax-errors=0" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>

/* mabs_ew:01: Input and output shapes differ; spec line 1910.  */
void
case_mabs_ew_01 (void)
{
  __riscv_ztt_i32_1x4_t src_i32_1x4 = __riscv_ztt_mzero_m_i32_1x4 ();
  (void) __riscv_ztt_mabs_ew_i32_1x2 (src_i32_1x4); /* { dg-error "AME/Ztt absolute value requires an integer M operand with the result shape" } */
}

/* mabs_ew:02: Input and output shape orientations differ; spec line 1911.  */
void
case_mabs_ew_02 (void)
{
  __riscv_ztt_i32_2x1_t src_i32_2x1 = __riscv_ztt_mzero_m_i32_2x1 ();
  (void) __riscv_ztt_mabs_ew_i32_1x2 (src_i32_2x1); /* { dg-error "AME/Ztt absolute value requires an integer M operand with the result shape" } */
}
