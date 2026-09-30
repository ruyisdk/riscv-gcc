/* 128-bit storage elements, not ordinary C integer arithmetic.  */
/* { dg-do assemble } */
/* { dg-options "-O2 --param ggc-min-expand=0 --param ggc-min-heapsize=0 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u128-m32-a16" { target rv32 } } */
/* { dg-options "-O2 --param ggc-min-expand=0 --param ggc-min-heapsize=0 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u128-m32-a16" { target rv64 } } */
#include <stddef.h>
#include <stdint.h>
#include <riscv_ztt.h>
void mem128_tst_u128_rod_sat_1x4 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rod_sat_1x4_t value = __riscv_ztt_mls_tst_u128_rod_sat_1x4 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
