/* { dg-do compile } */
/* { dg-options "-O2 -std=gnu++11 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -std=gnu++11 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>
template<typename T>
static __attribute__((always_inline)) inline void choose (T *out, const T *in)
{
  __riscv_ztt_i8_1x1_t x = __riscv_ztt_mls_rm_i8_1x1 (in);
  __riscv_ztt_mss_rm (out, __riscv_ztt_mcmovge_ew_i8_1x1 (x, x, x));
}
void instantiated (int8_t *out, const int8_t *in)
{
  choose (out, in);
}
/* { dg-final { scan-assembler-times {\tmcmovge\.ew\t} 1 } } */
/* { dg-final { scan-assembler-not {\tcall\t} } } */
