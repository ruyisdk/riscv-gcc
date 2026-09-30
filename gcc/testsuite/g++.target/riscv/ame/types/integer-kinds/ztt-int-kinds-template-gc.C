/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m16-a16 --param ggc-min-expand=0 --param ggc-min-heapsize=0" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m16-a16 --param ggc-min-expand=0 --param ggc-min-heapsize=0" { target rv64 } } */
#include <riscv_ztt.h>
template<int N> void kernel ()
{
  auto source = __riscv_ztt_mzero_m_i8_1x8 ();
  __asm__ volatile ("" : "+Wmr" (source));
  auto nibble = __riscv_ztt_mconv_ew_i4_rne_sat_1x8 (source);
  auto widened = __riscv_ztt_mconv_ew_u8_rod_sat_1x8 (nibble);
  auto back = __riscv_ztt_mconv_ew_i8_1x8 (widened);
  __asm__ volatile ("" : : "Wmr" (back));
}
void instantiate () { kernel<0> (); kernel<1> (); }
/* { dg-final { scan-assembler "mconv\\.ew" } } */
