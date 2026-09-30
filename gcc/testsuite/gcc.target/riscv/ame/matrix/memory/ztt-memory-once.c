/* { dg-do compile } */
/* { dg-options "-O2 -std=gnu11 -Werror=implicit-function-declaration -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -std=gnu11 -Werror=implicit-function-declaration -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv64 } } */

#include <riscv_ztt.h>
#include <stddef.h>
size_t once (signed char *out, const signed char *in, size_t stride)
{
  const signed char *p = in;
  signed char *q = out;
  size_t s = stride;
  __riscv_ztt_i8_rnu_1x4_t a = __riscv_ztt_mls_st_i8_1x4 (p++, s++);
  __riscv_ztt_mss_tst (q++, s++, a);
  return (p - in) + (q - out) + (s - stride);
}
/* { dg-final { scan-assembler {li[ \t]+a0,4} } } */
/* { dg-final { scan-assembler-times {mls\.st[ \t]} 4 } } */
/* { dg-final { scan-assembler-times {mss\.tst[ \t]} 4 } } */
