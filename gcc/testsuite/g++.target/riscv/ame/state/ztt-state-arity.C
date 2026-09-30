/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv64 } } */
#include <riscv_ztt.h>
void bad_calls (void)
{
  __riscv_ztt_get_ameown (1); /* { dg-error "too many arguments" } */
  __riscv_ztt_ame_acquire (); /* { dg-error "too few arguments" } */
  __riscv_ztt_ame_acquire (1, 2); /* { dg-error "too many arguments" } */
  __riscv_ztt_ame_release (1); /* { dg-error "too many arguments" } */
}
