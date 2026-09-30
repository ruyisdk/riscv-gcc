/* Compile/assemble checks, not numerical execution evidence.  */
/* { dg-do assemble } */
/* { dg-options "-O2 -std=c++11 --param ggc-min-expand=0 --param ggc-min-heapsize=65536 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -std=c++11 --param ggc-min-expand=0 --param ggc-min-heapsize=65536 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>
template<class T, class C> __attribute__((always_inline)) inline void body (C c)
{
  T a = __riscv_ztt_mzero_m_i8_rnu_sat_1x1 ();
  T b = __riscv_ztt_mzero_m_i8_rnu_sat_1x1 ();
  T d = __riscv_ztt_mmulacc_ew_x_i8_sat_1x1_i128_sat (a, b, __riscv_ztt_scalar_from_bits_i128_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void use (uintptr_t x)
{
  body<__riscv_ztt_i8_rnu_sat_1x1_t> (x);
}
