/* basic-square indexed API.  */
/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv64 } } */
#include <riscv_ztt.h>
void invalid (void)
{
  __riscv_ztt_i16_1x2_t packed = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_i32_1x2_t concat = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x1_t a = __riscv_ztt_mzero_m_i32_1x1 ();
  __riscv_ztt_i32_rne_1x1_t rm = __riscv_ztt_mzero_m_i32_rne_1x1 ();
  __riscv_ztt_u32_1x1_t u = __riscv_ztt_mzero_m_u32_1x1 ();
  __riscv_ztt_i32_accx1_t acc = __riscv_ztt_mzero_acc_i32_accx1 ();
  (void) __riscv_ztt_mcolgather_ew_i32_1x1 (u, a); /* { dg-error "exact result datatype" } */
  (void) __riscv_ztt_mrowgather_ew_i32_1x1 (rm, a); /* { dg-error "exact result datatype" } */
  (void) __riscv_ztt_mcolgather_ew_i32_1x1 (a, packed); /* { dg-error "basic 1x1" } */
  (void) __riscv_ztt_mrowgather_ew_i32_1x1 (a, concat); /* { dg-error "basic 1x1" } */
  (void) __riscv_ztt_mcolgather_ew_i32_1x1 (a, acc); /* { dg-error "basic 1x1" } */
  (void) __riscv_ztt_mrowgather_ew_i32_1x1 (a, 3); /* { dg-error "basic 1x1" } */
  (void) __riscv_ztt_mcolscatadd_ew_i32_1x1 (u, a, a); /* { dg-error "exact result datatype" } */
  (void) __riscv_ztt_mrowscatadd_ew_i32_1x1 (rm, a, a); /* { dg-error "exact result datatype" } */
  (void) __riscv_ztt_mcolscatmax_ew_i32_1x1 (a, packed, a); /* { dg-error "basic 1x1" } */
  (void) __riscv_ztt_mrowscatmax_ew_i32_1x1 (a, a, acc); /* { dg-error "basic 1x1" } */
  (void) __riscv_ztt_mcolscatadd_ew_i32_1x1 (a, 1.5, a); /* { dg-error "basic 1x1" } */
  (void) __riscv_ztt_mrowscatadd_ew_i32_1x1 (a, a, (int *) 0); /* { dg-error "basic 1x1" } */
  (void) __riscv_ztt_mcolgather_ew_i32_1x1 (a); /* { dg-error "too few arguments" } */
  (void) __riscv_ztt_mrowscatmax_ew_i32_1x1 (a, a, a, a); /* { dg-error "too many arguments" } */
}
