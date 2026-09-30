/* Normative IDs and adaptations are recorded in F60.  */
/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m32-a16 -fmax-errors=0" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m32-a16 -fmax-errors=0" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>

/* mbcast_m_x:01: 4-bit Scalar types are unsupported; spec line 10193.  */
void
case_mbcast_m_x_01 (void)
{
  /* The excluded type prevents forming the original call.  */
  typedef __riscv_ztt_i4_scalar_t unavailable_scalar; /* { dg-error "'__riscv_ztt_i4_scalar_t' does not name a type" } */
}

/* mbcast_m_x:02: Source must be a Scalar value; spec line 10194.  */
void
case_mbcast_m_x_02 (void)
{
  __riscv_ztt_i32_1x2_t src_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  (void) __riscv_ztt_mbcast_m_x_i32_1x2 (src_i32_1x2); /* { dg-error "AME/Ztt data scalar requires an independent Scalar type; use an explicit Scalar constructor" } */
}
