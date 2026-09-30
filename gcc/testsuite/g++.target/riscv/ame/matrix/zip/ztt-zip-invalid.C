/* distinct in/out M objects.  */
/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv64 } } */
#include <riscv_ztt.h>
void invalid (void)
{
  __riscv_ztt_i32_1x1_t a = __riscv_ztt_mzero_m_i32_1x1 ();
  __riscv_ztt_i32_1x1_t b = a;
  __riscv_ztt_u32_1x1_t u = __riscv_ztt_mzero_m_u32_1x1 ();
  __riscv_ztt_i32_rne_1x1_t rm = __riscv_ztt_mzero_m_i32_rne_1x1 ();
  __riscv_ztt_i16_1x2_t packed = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i32_1x2_t concat = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_accx1_t acc = __riscv_ztt_mzero_acc_i32_accx1 ();
  __riscv_ztt_mcolzip_ew_i32_1x1 (&a, &a); /* { dg-error "was replaced in AME/Ztt intrinsic v0.2.5; use the 1x2 value interface" } */
  __riscv_ztt_mrowzip_ew_i32_1x1 (&a, &u); /* { dg-error "was replaced in AME/Ztt intrinsic v0.2.5; use the 1x2 value interface" } */
  __riscv_ztt_mcolunzip_ew_i32_1x1 (&rm, &b); /* { dg-error "was replaced in AME/Ztt intrinsic v0.2.5; use the 1x2 value interface" } */
  __riscv_ztt_mrowunzip_ew_i32_1x1 (&a, &packed); /* { dg-error "was replaced in AME/Ztt intrinsic v0.2.5; use the 1x2 value interface" } */
  __riscv_ztt_mcolzip_ew_i32_1x1 (&concat, &b); /* { dg-error "was replaced in AME/Ztt intrinsic v0.2.5; use the 1x2 value interface" } */
  __riscv_ztt_mrowzip_ew_i32_1x1 (&a, &acc); /* { dg-error "was replaced in AME/Ztt intrinsic v0.2.5; use the 1x2 value interface" } */
  __riscv_ztt_mcolunzip_ew_i32_1x1 (a, &b); /* { dg-error "was replaced in AME/Ztt intrinsic v0.2.5; use the 1x2 value interface" } */
  __riscv_ztt_mrowunzip_ew_i32_1x1 ((void *) &a, &b); /* { dg-error "was replaced in AME/Ztt intrinsic v0.2.5; use the 1x2 value interface" } */
  __riscv_ztt_mcolzip_ew_i32_1x1 ((const __riscv_ztt_i32_1x1_t *) &a, &b); /* { dg-error "was replaced in AME/Ztt intrinsic v0.2.5; use the 1x2 value interface" } */
  __riscv_ztt_mrowzip_ew_i32_1x1 (&a, (volatile __riscv_ztt_i32_1x1_t *) &b); /* { dg-error "was replaced in AME/Ztt intrinsic v0.2.5; use the 1x2 value interface" } */
  __riscv_ztt_mcolunzip_ew_i32_1x1 ((__riscv_ztt_i32_1x1_t *) 0, &b); /* { dg-error "was replaced in AME/Ztt intrinsic v0.2.5; use the 1x2 value interface" } */
  __riscv_ztt_mrowunzip_ew_i32_1x1 (&a); /* { dg-error "too few arguments" } */
  __riscv_ztt_mcolzip_ew_i32_1x1 (&a, &b, &u); /* { dg-error "too many arguments" } */
}
void same_pointer (__riscv_ztt_i32_1x1_t *p)
{
  __riscv_ztt_mrowunzip_ew_i32_1x1 (p, p); /* { dg-error "was replaced in AME/Ztt intrinsic v0.2.5; use the 1x2 value interface" } */
}
