/* { dg-do compile } */
/* { dg-options "-std=gnu++17 -fexceptions -march=rv32gc_ztt0p6 -mabi=ilp32d -mztt-profile=gcc-runtime-u8-m16-a4" { target rv32 } } */
/* { dg-options "-std=gnu++17 -fexceptions -march=rv64gc_ztt0p6 -mabi=lp64d -mztt-profile=gcc-runtime-u8-m16-a4" { target rv64 } } */
#include <riscv_ztt.h>
extern void may_throw ();

/* Removing an observational query must not bypass exceptional re-proof.  */
void caller_exception (signed char *out) /* { dg-error "caller-owned function cannot prove ownership" } */
{
  try { may_throw (); }
  catch (...) { }
  auto m = __riscv_ztt_mclear_m_i8_rnu_1x1 ();
  __riscv_ztt_mss_rm (out, m);
}
