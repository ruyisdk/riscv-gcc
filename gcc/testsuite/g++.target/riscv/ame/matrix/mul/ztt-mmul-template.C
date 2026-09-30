/* mmul.ew.  */
/* { dg-do compile } */
/* { dg-options "-O2 -std=c++11 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u128-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -std=c++11 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u128-m16-a4" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>
template<typename L, typename R> __attribute__((always_inline)) inline
void step (uint8_t *out, const L *left, const R *right)
{
  auto a = __riscv_ztt_mls_rm_i16_rod_1x32 (left);
  auto b = __riscv_ztt_mls_rm_u8_rdn_1x32 (right);
  auto result = __riscv_ztt_mmul_ew_u8_rne_1x32 (a, b);
  __riscv_ztt_mss_rm (out, result);
}
void call_step (uint8_t *out, const int16_t *left, const uint8_t *right)
{
  step (out, left, right);
}
/* { dg-final { scan-assembler-times {\tmmul\.ew\t} 2 } } */
