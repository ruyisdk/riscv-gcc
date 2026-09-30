/* { dg-do compile } */
/* { dg-options "-std=gnu++17 -fexceptions -march=rv32gc_ztt0p6 -mabi=ilp32d -mztt-profile=gcc-runtime-u8-m16-a4 -fdump-rtl-ztt_verify_regions" { target rv32 } } */
/* { dg-options "-std=gnu++17 -fexceptions -march=rv64gc_ztt0p6 -mabi=lp64d -mztt-profile=gcc-runtime-u8-m16-a4 -fdump-rtl-ztt_verify_regions" { target rv64 } } */
#include <riscv_ztt.h>
extern void may_throw ();

/* Only normal returns reach the typed access. No ownership query is needed.  */
void caller_exception (signed char *out)
{
  auto m = __riscv_ztt_mclear_m_i8_rnu_1x1 ();
  try { may_throw (); }
  catch (...) { return; }
  __riscv_ztt_mss_rm (out, m);
}

void caller_rethrow (signed char *out)
{
  try { may_throw (); }
  catch (...) { throw; }
  auto m = __riscv_ztt_mclear_m_i8_rnu_1x1 ();
  __riscv_ztt_mss_rm (out, m);
}
/* { dg-final { scan-rtl-dump {Ztt caller-owned entry contract} "ztt_verify_regions" } } */
/* { dg-final { scan-rtl-dump-not {Unproved Ztt access:} "ztt_verify_regions" } } */
/* { dg-final { scan-assembler-not {csrr[^\n]*ameown} } } */
