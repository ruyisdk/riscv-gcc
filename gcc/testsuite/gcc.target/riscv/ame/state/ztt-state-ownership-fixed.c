/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-p0-n128-u8-m16-a4 -fno-lto" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-p0-n128-u8-m16-a4 -fno-lto" { target rv64 } } */
#include <riscv_ztt.h>

void
fixed_release (signed char *out)
{
  __riscv_ztt_i8_rne_1x1_t value
    = __riscv_ztt_mzero_2d_m_i8_rne_1x1 ();
  __builtin_riscv_ztt_ame_release (); /* { dg-error "AME/Ztt ownership changes in a function using typed values require ownership-region support" } */
  __riscv_ztt_mss_rm (out, value);
}
