/* Compilation checks only; no AME numerical execution is implied.  */
/* { dg-do assemble } */
/* { dg-options "-O2 -std=c++11 --param ggc-min-expand=0 --param ggc-min-heapsize=65536 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m32-a16" { target rv32 } } */
/* { dg-options "-O2 -std=c++11 --param ggc-min-expand=0 --param ggc-min-heapsize=65536 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m32-a16" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>
template<class T> __attribute__((always_inline)) inline void body ()
{
  T a = __riscv_ztt_mzero_m_f32_rno_1x1 ();
  T d = __riscv_ztt_msqrt_ew_f32_rno_1x1 (a);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a));
}
void use () { body<__riscv_ztt_f32_rno_1x1_t> (); }
