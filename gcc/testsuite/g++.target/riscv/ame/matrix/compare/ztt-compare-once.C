/* { dg-do compile } */
/* { dg-options "-O2 -std=gnu++11 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -std=gnu++11 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>
uint32_t once (int8_t *out, const int8_t *in, uint32_t c)
{
  uint32_t start = c;
  __riscv_ztt_i8_1x4_t b = __riscv_ztt_mls_rm_i8_1x4 (in);
  __riscv_ztt_i8_1x4_t r = __riscv_ztt_mcmpge_ew_x_i8_1x4_u32 (b, __riscv_ztt_scalar_make_u32_rnu (c++));
  r = __riscv_ztt_mcmplt_ew_x_i8_1x4_i16 (r, __riscv_ztt_scalar_make_i16_rnu (c++));
  __riscv_ztt_mss_rm (out, r);
  return c - start;
}
/* { dg-final { scan-assembler-times {\tmcmpge\.ew\.x\t} 4 } } */
/* { dg-final { scan-assembler-times {\tmcmplt\.ew\.x\t} 4 } } */
/* { dg-final { scan-assembler-times {csrw\tamestype,} 2 } } */
/* { dg-final { scan-assembler {li[ \t]+a0,2} } } */
