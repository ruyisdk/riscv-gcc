/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u64-m16-a16 -ffat-lto-objects -fdump-tree-optimized" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u64-m16-a16 -ffat-lto-objects -fdump-tree-optimized" { target rv64 } } */
#include <stdint.h>
#include <stddef.h>
#include <riscv_ztt.h>
void once (double *out, const double *in, volatile size_t *step)
{
  __riscv_ztt_f64_1x2_t a = __riscv_ztt_mls_tst_f64_1x2 (in, *step);
  __riscv_ztt_mss_tst (out, *step, a);
}
/* { dg-final { scan-tree-dump-times { =\{v\} \*step[^;]*;} 2 "optimized" } } */
