/* Compile/assemble checks, not numerical execution evidence.  */
/* { dg-do assemble } */
/* { dg-options "-O2 -std=c++11 --param ggc-min-expand=0 --param ggc-min-heapsize=1024 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -std=c++11 --param ggc-min-expand=0 --param ggc-min-heapsize=1024 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>
template<class S> void bcast (S x)
{
  __riscv_ztt_u8_rnu_sat_1x1_t d = __riscv_ztt_mbcast_m_x_u8_sat_1x1_i128_sat ( __riscv_ztt_scalar_from_bits_i128_rnu_sat (x));
  __riscv_ztt_u8_rnu_sat_1x1_t e = __riscv_ztt_mbcast_m_x_u8_rnu_sat_1x1_i128_rnu_sat ( __riscv_ztt_scalar_from_bits_i128_rnu_sat (x));
  static_assert (__is_same (decltype(d), decltype(e)), "alias type mismatch");
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (e));
}
template void bcast<uintptr_t> (uintptr_t);
