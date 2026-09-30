/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32gc_ztt0p6 -mabi=ilp32d -mztt-profile=gcc-p0-n128-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -march=rv64gc_ztt0p6 -mabi=lp64d -mztt-profile=gcc-p0-n128-u8-m16-a4" { target rv64 } } */

#include <riscv_ztt.h>

void
ztt_typed_move (const signed char *input, signed char *output0,
		signed char *output1)
{
  __riscv_ztt_i8_rne_1x1_t original
    = __riscv_ztt_mls_rm_i8_rne_1x1 (input);
  __riscv_ztt_i8_rne_1x1_t copy = original;
  __asm__ volatile ("" : "+Wmr" (original), "+Wmr" (copy));
  __riscv_ztt_mss_rm (output0, original);
  __riscv_ztt_mss_rm (output1, copy);
}

/* { dg-final { scan-assembler-times "mmov\\.m\\.m\tm\[0-9\]+,m\[0-9\]+" 1 } } */
