/* { dg-do compile } */
/* { dg-options "-O2 -std=gnu++11 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -std=gnu++11 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>
void invalid (const int8_t *p)
{
  __riscv_ztt_i8_1x1_t d = __riscv_ztt_mls_rm_i8_1x1 (p);
  __riscv_ztt_i8_rne_1x1_t rm = __riscv_ztt_mzero_m_i8_rne_1x1 ();
  __riscv_ztt_u8_1x1_t sign = __riscv_ztt_mzero_m_u8_1x1 ();
  __riscv_ztt_i16_1x1_t wide = __riscv_ztt_mzero_m_i16_1x1 ();
  __riscv_ztt_i8_1x2_t shape = __riscv_ztt_mzero_m_i8_1x2 ();
  __riscv_ztt_i32_accx1_t acc = __riscv_ztt_mclear_acc_i32_accx1 ();
  __riscv_ztt_mcmovge_ew_i8_1x1 (rm, d, d); /* { dg-error "conditional move requires old_d" } */
  __riscv_ztt_mcmovlt_ew_i8_1x1 (acc, d, d); /* { dg-error "conditional move requires old_d" } */
  __riscv_ztt_mcmovge_ew_i8_1x1 (shape, d, d); /* { dg-error "conditional move requires old_d" } */
  __riscv_ztt_mcmovlt_ew_i8_1x1 (d, d, rm); /* { dg-error "conditional selection requires selected data" } */
  __riscv_ztt_mselge_ew_i8_1x1 (d, sign); /* { dg-error "conditional selection requires selected data" } */
  __riscv_ztt_msellt_ew_i8_1x1 (d, wide); /* { dg-error "conditional selection requires selected data" } */
  __riscv_ztt_mselge_ew_i8_1x1 (acc, d); /* { dg-error "M operands with the result shape" } */
  __riscv_ztt_msellt_ew_i8_1x1 (d, shape); /* { dg-error "M operands with the result shape" } */
  __riscv_ztt_mcmpge_ew_i8_1x1 (d, acc); /* { dg-error "M operands with the result shape" } */
  __riscv_ztt_mcmplt_ew_i8_1x1 (shape, d); /* { dg-error "M operands with the result shape" } */
  __riscv_ztt_mcmpge_ew_x_i8_1x1_u32 (d, __riscv_ztt_scalar_make_u32_rnu (1.5)); /* { dg-error "Scalar constructor requires an integer carrier" } */
  __riscv_ztt_mcmplt_ew_x_i8_1x1_i16 (d, __riscv_ztt_scalar_make_i16_rnu (p)); /* { dg-error "Scalar constructor requires an integer carrier" } */
  __riscv_ztt_mcmpge_ew_x_i8_1x1_u8 (acc, __riscv_ztt_scalar_make_u8_rnu (1)); /* { dg-error "compatible types, shapes" } */
  __riscv_ztt_mcmplt_ew_x_i8_1x1_i8 (shape, __riscv_ztt_scalar_make_i8_rnu (1)); /* { dg-error "compatible types, shapes" } */
  __riscv_ztt_mcmovge_ew_i8_1x1 (d, d); /* { dg-error "too few arguments" } */
  __riscv_ztt_mcmpge_ew_i8_1x1 (d); /* { dg-error "too few arguments" } */
}
