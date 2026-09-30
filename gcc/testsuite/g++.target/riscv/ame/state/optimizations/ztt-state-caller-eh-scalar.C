/* { dg-do compile } */
/* { dg-options "-std=gnu++17 -fexceptions -march=rv32gc_ztt0p6 -mabi=ilp32d -mztt-profile=gcc-runtime-u8-m16-a4" { target rv32 } } */
/* { dg-options "-std=gnu++17 -fexceptions -march=rv64gc_ztt0p6 -mabi=lp64d -mztt-profile=gcc-runtime-u8-m16-a4" { target rv64 } } */
#include <riscv_ztt.h>
extern void may_throw ();
void caller_exception (signed char *out)
{
  try { may_throw (); }
  catch (...) { }
  *out = 1;
}
/* { dg-final { scan-assembler-not {csrr[^\n]*ame|msettyp|agettyp|asettyp} } } */
