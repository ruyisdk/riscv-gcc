/* Floating memory keeps full native elements on both XLENs.  */
/* { dg-do assemble } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u16-m32-a16 " { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u16-m32-a16 " { target rv64 } } */
#include <stddef.h>
#include <stdint.h>
#include <riscv_ztt.h>
#ifndef __riscv_ztt_floating_memory
#error missing floating memory capability
#endif
_Static_assert (sizeof (_Float16) == 2, "f16 memory element");
_Static_assert (sizeof (__bf16) == 2, "bf16 memory element");
_Static_assert (sizeof (float) == 4, "f32 memory element");
_Static_assert (sizeof (double) == 8, "full f64 memory element even on RV32");
void aliases (double *out, const double *in)
{
  __riscv_ztt_f64_1x1_t value = __riscv_ztt_mls_rm_f64_1x1 (in);
  __riscv_ztt_mss_rm_f64_1x1 (out, value);
}
