/* Q32.  */
/* { dg-do compile } */
/* { dg-options "-O2 -std=c++11 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u128-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -std=c++11 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u128-m16-a4" { target rv64 } } */
#include <stdint.h>
#include <stddef.h>
#include <riscv_ztt.h>
template<typename Count> __attribute__((always_inline)) inline
void step (uint16_t *out, const int8_t *in, Count count)
{
  auto a = __riscv_ztt_mls_rm_i8_rne_1x32 (in);
  auto b = __riscv_ztt_msra_ew_x_u16_1x32 (a, count);
  __riscv_ztt_mss_rm (out, b);
}
void call_step (uint16_t *out, const int8_t *in)
{
  step (out, in, size_t (33));
}
/* { dg-final { scan-assembler-times {\tmsra\.ew\.x\t} 2 } } */
