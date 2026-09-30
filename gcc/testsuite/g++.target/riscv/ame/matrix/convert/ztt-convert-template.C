/* mconv.ew.  */
/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -std=c++11 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u128-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -std=c++11 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u128-m16-a4" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>
template<typename T> __attribute__((always_inline)) inline
void convert (uint8_t *out, const T *input)
{
  auto source = __riscv_ztt_mls_rm_i16_rod_1x32 (input);
  auto result = __riscv_ztt_mconv_ew_u8_rne_1x32 (source);
  __riscv_ztt_mss_rm (out, result);
}
void call_convert (uint8_t *out, const int16_t *input)
{
  convert (out, input);
}
/* { dg-final { scan-assembler-times {\tmconv\.ew\t} 2 } } */
