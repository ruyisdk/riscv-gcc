/* { dg-do compile } */
/* { dg-options "-O2 -std=gnu11 -Werror=implicit-function-declaration -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a4 -fno-lto -fdiagnostics-plain-output" { target rv32 } } */
/* { dg-options "-O2 -std=gnu11 -Werror=implicit-function-declaration -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a4 -fno-lto -fdiagnostics-plain-output" { target rv64 } } */

#include <riscv_ztt.h>

void mixed_acquire (signed char *out)
{
  __riscv_ztt_i8_rnu_1x1_t value = __riscv_ztt_mclear_m_i8_rnu_1x1 ();
  __riscv_ztt_ame_acquire (0); /* { dg-error "AME/Ztt ownership changes in a function using typed values require ownership-region support" } */
  __riscv_ztt_mss_rm (out, value);
}
