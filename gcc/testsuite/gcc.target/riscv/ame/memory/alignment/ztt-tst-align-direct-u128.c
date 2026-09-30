/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u128-m16-a16 " { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u128-m16-a16 " { target rv64 } } */
#include <stdint.h>
#include <stddef.h>
#include <riscv_ztt.h>
void unaffected (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rne_1x4_t value = __riscv_ztt_mls_tst_f64_rne_1x4 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
/* { dg-final { scan-assembler-not {\tlbu?\t} } } */
/* { dg-final { scan-assembler-not {\tsb\t} } } */
