/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m32-a16" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m32-a16" { target rv64 } } */
#include <stddef.h>
#include <stdint.h>
#include <riscv_ztt.h>
void invalid (void)
{
  __riscv_ztt_i32_1x2_t a = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_u32_1x2_t u = __riscv_ztt_mzero_m_u32_1x2 ();
  __riscv_ztt_i32_rne_1x2_t rm = __riscv_ztt_mzero_m_i32_rne_1x2 ();
  __riscv_ztt_i32_1x1_t one = __riscv_ztt_mzero_m_i32_1x1 ();
  __riscv_ztt_i32_2x1_t col = __riscv_ztt_mzero_m_i32_2x1 ();
  __riscv_ztt_i32_1x4_t four = __riscv_ztt_mzero_m_i32_1x4 ();
  __riscv_ztt_i32_accx2_t acc = __riscv_ztt_mzero_acc_i32_accx2 ();
  __riscv_ztt_mcolzip_ew_i32_1x2 (&a); /* { dg-error "incompatible type|cannot convert" } */
  __riscv_ztt_mcolzip_ew_i32_1x2 (u); /* { dg-error "incompatible type|cannot convert" } */
  __riscv_ztt_mrowzip_ew_i32_1x2 (rm); /* { dg-error "incompatible type|cannot convert" } */
  __riscv_ztt_mcolunzip_ew_i32_1x2 (one); /* { dg-error "incompatible type|cannot convert" } */
  __riscv_ztt_mrowunzip_ew_i32_1x2 (col); /* { dg-error "incompatible type|cannot convert" } */
  __riscv_ztt_mcolzip_ew_i32_1x2 (four); /* { dg-error "incompatible type|cannot convert" } */
  __riscv_ztt_mrowzip_ew_i32_1x2 (acc); /* { dg-error "incompatible type|cannot convert" } */
  __riscv_ztt_mcolunzip_ew_i32_1x2 (); /* { dg-error "too few arguments" } */
  __riscv_ztt_mrowunzip_ew_i32_1x2 (a, a); /* { dg-error "too many arguments" } */
}
