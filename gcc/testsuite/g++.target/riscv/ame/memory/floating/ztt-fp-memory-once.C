/* Floating memory keeps full native elements on both XLENs.  */
/* { dg-do assemble } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u16-m32-a16 -ffat-lto-objects -fdump-tree-optimized" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u16-m32-a16 -ffat-lto-objects -fdump-tree-optimized" { target rv64 } } */
#include <stddef.h>
#include <stdint.h>
#include <riscv_ztt.h>
void once (float *out, const float *in, volatile size_t *step)
{
  __riscv_ztt_f32_1x2_t a = __riscv_ztt_mls_st_f32_1x2 (in, *step);
  __riscv_ztt_mss_tst (out, *step, a);
}
/* { dg-final { scan-tree-dump-times { =\{v\} \*step[^;]*;} 2 "optimized" } } */
