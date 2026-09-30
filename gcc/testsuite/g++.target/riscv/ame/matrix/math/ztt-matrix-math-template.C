/* Matrix mathematics; compile contracts are not numerical execution.  */
/* { dg-do assemble } */
/* { dg-options "-O2 -std=c++11 --param ggc-min-expand=0 --param ggc-min-heapsize=65536 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u16-m32-a16" { target rv32 } } */
/* { dg-options "-O2 -std=c++11 --param ggc-min-expand=0 --param ggc-min-heapsize=65536 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u16-m32-a16" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>
template<class T> __attribute__((always_inline)) inline void body ()
{
  T a = __riscv_ztt_mzero_m_f16_1x1 ();
  __riscv_ztt_i16_1x1_t b = __riscv_ztt_mzero_m_i16_1x1 ();
  T c = __riscv_ztt_mldexpacc_ew_f16_1x1 (a, a, b);
  T d = __riscv_ztt_msublog2_ew_f16_1x1 (c, a);
  __asm__ volatile ("" : : "Wmr" (a), "Wmr" (b), "Wmr" (c), "Wmr" (d));
}
void use () { body<__riscv_ztt_f16_1x1_t> (); }
