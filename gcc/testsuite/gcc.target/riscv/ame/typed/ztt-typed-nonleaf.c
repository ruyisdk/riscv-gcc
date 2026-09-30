/* { dg-do compile } */
/* { dg-additional-options "-ffat-lto-objects" } */
/* { dg-options "-O2 -fdiagnostics-plain-output -march=rv32gc_ztt0p6 -mabi=ilp32d -mztt-profile=gcc-p0-n128-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -fdiagnostics-plain-output -march=rv64gc_ztt0p6 -mabi=lp64d -mztt-profile=gcc-p0-n128-u8-m16-a4" { target rv64 } } */

#include <riscv_ztt.h>

extern void external_call (void);

void
nonleaf (signed char *output)
{
  __riscv_ztt_i8_rne_1x1_t value
    = __riscv_ztt_mzero_2d_m_i8_rne_1x1 ();
  asm volatile ("" : : "Wmr" (value));
  external_call ();
  __riscv_ztt_mss_rm (output, value);
}
/* { dg-final { scan-assembler {mss\.1r(.|\n)*call\s+external_call(.|\n)*mls\.1r} } } */
