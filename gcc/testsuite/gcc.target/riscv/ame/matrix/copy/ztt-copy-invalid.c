/* M copy.  */
/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>

void invalid (int32_t *p)
{
  __riscv_ztt_i32_rnu_1x1_t a = __riscv_ztt_mls_rm_i32_rnu_1x1 (p);
  __riscv_ztt_i32_rne_1x1_t r = __riscv_ztt_mzero_m_i32_rne_1x1 ();
  __riscv_ztt_u32_rnu_1x1_t u = __riscv_ztt_mzero_m_u32_rnu_1x1 ();
  __riscv_ztt_i32_rnu_1x2_t s = __riscv_ztt_mzero_m_i32_rnu_1x2 ();
  __riscv_ztt_i32_accx1_t acc = __riscv_ztt_mzero_acc_i32_accx1 ();
  a = __riscv_ztt_mcopy_m2m_i32_rnu_1x1 (r); /* { dg-error "incompatible type for argument" } */
  a = __riscv_ztt_mcopy_m2m_i32_rnu_1x1 (u); /* { dg-error "incompatible type for argument" } */
  a = __riscv_ztt_mcopy_m2m_i32_rnu_1x1 (s); /* { dg-error "incompatible type for argument" } */
  a = __riscv_ztt_mcopy_m2m_i32_rnu_1x1 (acc); /* { dg-error "incompatible type for argument" } */
  a = __riscv_ztt_mcopy_m2m_i32_rnu_1x1 (0); /* { dg-error "incompatible type for argument" } */
  a = __riscv_ztt_mcopy_m2m_i32_rnu_1x1 (); /* { dg-error "too few arguments" } */
  a = __riscv_ztt_mcopy_m2m_i32_rnu_1x1 (a, a); /* { dg-error "too many arguments" } */
  __riscv_ztt_mss_rm (p, a);
}
