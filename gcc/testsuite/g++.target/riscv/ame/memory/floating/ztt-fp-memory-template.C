/* Floating memory keeps full native elements on both XLENs.  */
/* { dg-do assemble } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u16-m32-a16 --param ggc-min-expand=0 --param ggc-min-heapsize=0" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u16-m32-a16 --param ggc-min-expand=0 --param ggc-min-heapsize=0" { target rv64 } } */
#include <stddef.h>
#include <stdint.h>
#include <riscv_ztt.h>
template <int I> void template_memory (double *out, const double *in)
{
  __riscv_ztt_f64_rmm_1x1_t value = __riscv_ztt_mls_tst_f64_rmm_1x1 (in, I);
  __riscv_ztt_mss_st (out, I, value);
}
template void template_memory<3> (double *, const double *);
