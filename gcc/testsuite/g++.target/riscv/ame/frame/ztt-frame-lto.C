/* LTO function-local state.  */
/* { dg-do link } */
/* { dg-options "-O2 -flto=1 -nostdlib -Wl,-e,entry -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -flto=1 -nostdlib -Wl,-e,entry -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv64 } } */
/* { dg-additional-sources "auxiliary/ztt-frame-lto-aux.C" } */
#include <riscv_ztt.h>
extern "C" {
extern int scalar_lto (int);
__attribute__((used,noinline)) int scalar_local (int x) { return x + 1; }
__attribute__((used,noinline)) void typed_lto (const signed char *src, signed char *dst)
{
  __riscv_ztt_mss_rm (dst, __riscv_ztt_mls_rm_i8_rne_1x1 (src));
}
int entry (void) { return scalar_lto (scalar_local (2)); }
}
