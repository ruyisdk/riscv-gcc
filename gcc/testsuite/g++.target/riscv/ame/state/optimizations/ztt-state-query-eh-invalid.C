/* { dg-do compile } */
/* { dg-options "-std=gnu++17 -fexceptions -march=rv32gc_ztt0p6 -mabi=ilp32d -mztt-profile=gcc-runtime-u8-m16-a4 -fdump-rtl-ztt_regions -fdump-rtl-ztt_verify_regions" { target rv32 } } */
/* { dg-options "-std=gnu++17 -fexceptions -march=rv64gc_ztt0p6 -mabi=lp64d -mztt-profile=gcc-runtime-u8-m16-a4 -fdump-rtl-ztt_regions -fdump-rtl-ztt_verify_regions" { target rv64 } } */
#include <riscv_ztt.h>
extern void may_throw ();
void query_exception (signed char *out)
{
  (void) __riscv_ztt_get_ameown ();
  try { may_throw (); }
  catch (...) { }
  __riscv_ztt_i8_rnu_1x1_t value = __riscv_ztt_mclear_m_i8_rnu_1x1 ();
  __riscv_ztt_mss_rm (out, value);
}
/* { dg-error "query-only function cannot prove ownership" "" { target *-*-* } 0 } */
