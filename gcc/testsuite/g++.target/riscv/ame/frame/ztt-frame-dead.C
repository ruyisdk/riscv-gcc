/* Function-local frame policy.  */
/* { dg-do compile } */
/* { dg-options "-O2 -g -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -g -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv64 } } */

#include <riscv_ztt.h>
extern "C" {
int dead_typed (int x, const signed char *src, signed char *dst)
{
  if (0)
    __riscv_ztt_mss_rm (dst, __riscv_ztt_mls_rm_i8_rne_1x1 (src));
  return x + 1;
}
}

/* { dg-final { scan-assembler-not "s11" } } */
/* { dg-final { scan-assembler-not "s0" } } */
/* { dg-final { scan-assembler-not "amenlen" } } */
/* { dg-final { scan-assembler-not "mls" } } */
