/* M utilities.  */
/* { dg-do compile } */
/* { dg-options "-O2 -fstack-clash-protection -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a1" { target rv32 } } */
/* { dg-options "-O2 -fstack-clash-protection -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a1" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>
void invalid (int8_t *out, int index)
{
  __riscv_ztt_i8_rnu_1x1_t a = __riscv_ztt_mclear_m_i8_rnu_1x1 ();
  __riscv_ztt_u8_rnu_1x1_t u = __riscv_ztt_mclear_m_u8_rnu_1x1 ();
  __riscv_ztt_i8_rne_1x1_t rm = __riscv_ztt_mclear_m_i8_rne_1x1 ();
  __riscv_ztt_i8_rnu_1x2_t r = __riscv_ztt_mconcat_m_i8_rnu_1x2 (a, a);
  __riscv_ztt_i8_rnu_2x1_t c = __riscv_ztt_mconcat_m_i8_rnu_2x1 (a, a);
  __riscv_ztt_mconcat_m_i8_rnu_1x2 (a, u); /* { dg-error "incompatible type|cannot convert" } */
  __riscv_ztt_mconcat_m_i8_rnu_1x2 (a, rm); /* { dg-error "incompatible type|cannot convert" } */
  __riscv_ztt_mconcat_m_i8_rnu_1x4 (r, c); /* { dg-error "incompatible type|cannot convert" } */
  __riscv_ztt_mconcat_m_i8_rnu_1x4 (a, a); /* { dg-error "incompatible type|cannot convert" } */
  __riscv_ztt_mextract_i8_rnu_1x1 (a, 0); /* { dg-error "incompatible type|cannot convert" } */
  __riscv_ztt_mextract_i8_rne_1x1 (r, 0); /* { dg-error "incompatible type|cannot convert" } */
  __riscv_ztt_mextract_i8_rnu_1x1 (r, index); /* { dg-error "index must be an integer constant 0 or 1" } */
  __riscv_ztt_mextract_i8_rnu_1x1 (r, -1); /* { dg-error "index must be an integer constant 0 or 1" } */
  __riscv_ztt_mextract_i8_rnu_1x1 (r, 2); /* { dg-error "index must be an integer constant 0 or 1" } */
  __riscv_ztt_mextract_i8_rnu_1x1 (c, 2); /* { dg-error "index must be an integer constant 0 or 1" } */
  __riscv_ztt_mextract_i8_rnu_1x1 (r, 1.5); /* { dg-error "index must be an integer constant 0 or 1" } */
  __riscv_ztt_mextract_i8_rnu_1x1 (r, 0x100000000ULL); /* { dg-error "index must be an integer constant 0 or 1" } */
  __riscv_ztt_mextract_i8_rnu_1x1 (c, 0x100000001ULL); /* { dg-error "index must be an integer constant 0 or 1" } */
  __riscv_ztt_mextract_i8_rnu_1x1 (r, -0x100000000LL); /* { dg-error "index must be an integer constant 0 or 1" } */
  __riscv_ztt_mextract_i8_rnu_1x1 (r); /* { dg-error "too few arguments" } */
  __riscv_ztt_mconcat_m_i8_rnu_1x2 (a); /* { dg-error "too few arguments" } */
  __riscv_ztt_mss_rm (out, a);
}
