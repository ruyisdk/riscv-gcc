/* single-M
   i8 integer rounding-mode subset.  */
/* { dg-do compile } */
/* { dg-options "-O2 -fdiagnostics-plain-output -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -fdiagnostics-plain-output -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv64 } } */

#include <riscv_ztt.h>

void
bad_memory (unsigned char *u, const signed char *c, volatile signed char *v)
{
  __riscv_ztt_i8_rnu_1x1_t a = __riscv_ztt_mclear_m_i8_rnu_1x1 ();
  __riscv_ztt_i8_rod_1x1_t b = __riscv_ztt_mclear_m_i8_rod_1x1 ();
  __riscv_ztt_mls_rm_i8_rdn_1x1 (u); /* { dg-error "requires a pointer to" } */
  __riscv_ztt_mss_rm (c, a); /* { dg-error "requires a pointer to writable" } */
  __riscv_ztt_mss_rm (u, b); /* { dg-error "requires a pointer to writable" } */
  __riscv_ztt_mss_rm (v, a); /* { dg-error "cannot access volatile or atomic memory" } */
  __riscv_ztt_mls_rm_i8_rod_1x1 (v); /* { dg-error "cannot access volatile or atomic memory" } */
}
