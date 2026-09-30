/* Function-local frame policy.  */
/* { dg-do compile } */
/* { dg-options "-O2 -g -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a4 -g0" { target rv32 } } */
/* { dg-options "-O2 -g -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a4 -g0" { target rv64 } } */
/* { dg-additional-options "-ffat-lto-objects" } */

#include <riscv_ztt.h>
extern "C" {
/*
** before:
**  addiw?\s+a0,a0,1
**  ret
*/
int before (int x) { return x + 1; }
void typed (const signed char *src, signed char *dst)
{
  __riscv_ztt_mss_rm (dst, __riscv_ztt_mls_rm_i8_rne_1x1 (src));
}
/*
** after:
**  addiw?\s+a0,a0,2
**  ret
*/
int after (int x) { return x + 2; }
}

/* { dg-final { check-function-bodies "**" "" } } */
/* { dg-final { scan-assembler-times "csrr\\ts11,amenlen" 1 } } */
