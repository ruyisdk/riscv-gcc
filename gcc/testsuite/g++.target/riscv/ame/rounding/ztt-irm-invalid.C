/* single-M
   i8 integer rounding-mode subset.  */
/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv64 } } */


#include <riscv_ztt.h>

void
bad (signed char *out)
{
  __riscv_ztt_i8_rnu_1x1_t a = __riscv_ztt_mclear_m_i8_rnu_1x1 ();
  __riscv_ztt_i8_rne_1x1_t b = __riscv_ztt_mclear_m_i8_rne_1x1 ();
  a = b; /* { dg-error "cannot convert" } */
  a = __riscv_ztt_madd_ew_i8_rdn_1x1 (a, a); /* { dg-error "cannot convert" } */
  __riscv_ztt_mss_rm_i8_rod_1x1 (out, b); /* { dg-error "cannot convert" } */
  __riscv_ztt_mclear_m_i8_rnu_1x1 (0); /* { dg-error "too many arguments" } */
}
