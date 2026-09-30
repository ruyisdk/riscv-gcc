/* lazy mixed declarations.  */
/* { dg-do compile } */
/* { dg-options "-O2 -std=c++11 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u128-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -std=c++11 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u128-m16-a4" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>
template<typename T> __attribute__((always_inline)) inline
void ternary (uint8_t *out, const uint8_t *old, const T *a, const uint8_t *b)
{
  auto d = __riscv_ztt_mls_rm_u8_rne_1x32 (old);
  auto x = __riscv_ztt_mls_rm_i16_rod_1x32 (a);
  auto y = __riscv_ztt_mls_rm_u8_rnu_1x32 (b);
  auto r = __riscv_ztt_mmulsub_ew_u8_rne_1x32 (d, x, y);
  __riscv_ztt_mss_rm (out, r);
}
void call_ternary (uint8_t *out, const uint8_t *old, const int16_t *a, const uint8_t *b)
{
  ternary (out, old, a, b);
}
/* { dg-final { scan-assembler-times {\tmmulsub\.ew\t} 2 } } */
