/* { dg-do compile } */
/* { dg-options "-O2 -fdiagnostics-plain-output -march=rv32gc_ztt0p6 -mabi=ilp32d -mztt-profile=gcc-p0-n128-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -fdiagnostics-plain-output -march=rv64gc_ztt0p6 -mabi=lp64d -mztt-profile=gcc-p0-n128-u8-m16-a4" { target rv64 } } */

#include <riscv_ztt.h>

__riscv_ztt_i8_rne_1x1_t
bad_return (void) /* { dg-error "AME/Ztt typed values cannot be passed to or returned from ordinary functions" } */
{
  return __riscv_ztt_mzero_2d_m_i8_rne_1x1 ();
}

void
bad_argument (__riscv_ztt_i8_rne_1x1_t value) /* { dg-error "AME/Ztt typed values cannot be passed to or returned from ordinary functions" } */
{
  (void) value;
}
