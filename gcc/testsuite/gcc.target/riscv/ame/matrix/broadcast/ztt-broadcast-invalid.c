/* integer broadcast.  */
/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>
void invalid (void)
{
  __riscv_ztt_i32_1x1_t m = __riscv_ztt_mzero_m_i32_1x1 ();
  __riscv_ztt_i32_accx1_t a = __riscv_ztt_mzero_acc_i32_accx1 ();
  (void) __riscv_ztt_mbcast_m_x_i32_1x1_i32 ( __riscv_ztt_scalar_make_i32_rnu (1.5)); /* { dg-error "Scalar constructor requires an integer carrier" } */
  (void) __riscv_ztt_mbcast_m_x_i32_1x1_i32 ( __riscv_ztt_scalar_make_i32_rnu ((int *) 0)); /* { dg-error "Scalar constructor requires an integer carrier" } */
  (void) __riscv_ztt_mbcast_m_x_i32_1x1_i32 ( __riscv_ztt_scalar_make_i32_rnu (m)); /* { dg-error "Scalar constructor requires an integer carrier" } */
  (void) __riscv_ztt_mbcast_m_x_i32_1x1_i32 ( __riscv_ztt_scalar_make_i32_rnu (a)); /* { dg-error "Scalar constructor requires an integer carrier" } */
  (void) __riscv_ztt_mbcast_m_x_i32_1x1_i32 (); /* { dg-error "data-scalar operation expects" } */
  (void) __riscv_ztt_mbcast_m_x_i32_1x1_i32 (1, 2); /* { dg-error "data-scalar operation expects" } */
}
