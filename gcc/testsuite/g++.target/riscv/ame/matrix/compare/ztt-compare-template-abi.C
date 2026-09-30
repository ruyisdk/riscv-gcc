/* { dg-do compile } */
/* { dg-options "-O2 -std=gnu++11 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -std=gnu++11 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>
template<typename T>
static __attribute__((always_inline)) inline T choose (T old, T pred, T data) /* { dg-error "typed values cannot be passed to or returned from ordinary functions" } */
{
  return __riscv_ztt_mcmovge_ew_i8_1x1 (old, pred, data);
}
void instantiated (int8_t *out, const int8_t *in)
{
  __riscv_ztt_i8_1x1_t x = __riscv_ztt_mls_rm_i8_1x1 (in);
  __riscv_ztt_mss_rm (out, choose (x, x, x));
}
