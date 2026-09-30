/* single-M
   i8 integer rounding-mode subset.  */
/* { dg-do compile } */
/* { dg-skip-if "RTL state-boundary diagnostics require LTO final code generation" { *-*-* } { "-flto" } } */
/* { dg-options "-O2 -fdiagnostics-plain-output -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -fdiagnostics-plain-output -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv64 } } */

#include <riscv_ztt.h>

void
raw_mixed (signed char *out0, signed char *out1) /* { dg-error "functions using AME/Ztt typed values cannot mix L0 selector builtins" } */
{
  __riscv_ztt_i8_rnu_1x1_t a = __riscv_ztt_mclear_m_i8_rnu_1x1 ();
  __riscv_ztt_i8_rdn_1x1_t b = __riscv_ztt_mclear_m_i8_rdn_1x1 ();
  __builtin_riscv_ztt_msettyp (0, 0);
  __riscv_ztt_mss_rm (out0, a);
  __riscv_ztt_mss_rm (out1, b);
}
