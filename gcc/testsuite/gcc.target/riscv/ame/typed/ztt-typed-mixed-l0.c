/* { dg-do compile } */
/* { dg-skip-if "RTL state-boundary diagnostics require LTO final code generation" { *-*-* } { "-flto" } } */
/* { dg-options "-O2 -fdiagnostics-plain-output -march=rv32gc_ztt0p6 -mabi=ilp32d -mztt-profile=gcc-p0-n128-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -fdiagnostics-plain-output -march=rv64gc_ztt0p6 -mabi=lp64d -mztt-profile=gcc-p0-n128-u8-m16-a4" { target rv64 } } */

#include <riscv_ztt.h>

void
bad_mixed_l0 (signed char *output) /* { dg-error "functions using AME/Ztt typed values cannot mix L0 selector builtins" } */
{
  __riscv_ztt_i8_rne_1x1_t value
    = __riscv_ztt_mzero_2d_m_i8_rne_1x1 ();
  __builtin_riscv_ztt_msettyp (0, 0);
  __riscv_ztt_mss_rm (output, value);
}
