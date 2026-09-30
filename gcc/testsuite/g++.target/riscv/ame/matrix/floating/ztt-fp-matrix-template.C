/* Compile/assemble contracts, not AME numerical execution tests.  */
/* { dg-do assemble } */
/* { dg-options "-O2 -std=c++11 --param ggc-min-expand=0 --param ggc-min-heapsize=65536 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u16-m32-a16" { target rv32 } } */
/* { dg-options "-O2 -std=c++11 --param ggc-min-expand=0 --param ggc-min-heapsize=65536 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u16-m32-a16" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>
template<class T> __attribute__((always_inline)) inline void body ()
{
  T a = __riscv_ztt_mzero_m_f16_1x1 ();
  T b = __riscv_ztt_madd_ew_f16_1x1 (a, a);
  T c = __riscv_ztt_mmuladd_ew_f16_1x1 (b, a, b);
  __asm__ volatile ("" : : "Wmr" (a), "Wmr" (b), "Wmr" (c));
}
void use () { body<__riscv_ztt_f16_1x1_t> (); }
