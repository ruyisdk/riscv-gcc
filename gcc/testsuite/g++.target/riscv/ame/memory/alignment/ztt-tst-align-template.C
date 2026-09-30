/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u64-m16-a16 --param ggc-min-expand=0 --param ggc-min-heapsize=0" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u64-m16-a16 --param ggc-min-expand=0 --param ggc-min-heapsize=0" { target rv64 } } */
#include <stdint.h>
#include <stddef.h>
#include <riscv_ztt.h>
template <int S> void templ (double *out, const double *in)
{
  __riscv_ztt_f64_rmm_1x4_t a = __riscv_ztt_mls_tst_f64_rmm_1x4 (in, S);
  __riscv_ztt_mss_tst (out, S, a);
}
template void templ<3> (double *, const double *);
