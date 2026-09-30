/* Compile/assemble checks, not numerical execution evidence.  */
/* { dg-do compile } */
/* { dg-options "-O2 -std=gnu++17 --param=ggc-min-expand=0 --param=ggc-min-heapsize=0 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m16-a16" { target rv32 } } */
/* { dg-options "-O2 -std=gnu++17 --param=ggc-min-expand=0 --param=ggc-min-heapsize=0 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m16-a16" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>
template<int K> __attribute__((noinline)) void kernel (uintptr_t x)
{
  __riscv_ztt_i128_rne_1x1_t d = __riscv_ztt_mzero_m_i128_rne_1x1 ();
  __riscv_ztt_u64_rod_1x1_t b = __riscv_ztt_mzero_m_u64_rod_1x1 ();
  d = __riscv_ztt_mmulacc_ew_x_i128_rne_1x1_u128_rdn (d, b, __riscv_ztt_scalar_from_bits_u128_rdn (x + K));
  b = __riscv_ztt_madd_ew_x_u64_rod_1x1_i64_rne (d, __riscv_ztt_scalar_from_bits_i64_rne (x));
  __asm__ volatile ("" : : "Wmr" (b), "Wmr" (d));
}
template void kernel<1> (uintptr_t);
template void kernel<2> (uintptr_t);
/* { dg-final { scan-assembler {\tmmulacc\.ew\.x\t} } } */
/* { dg-final { scan-assembler {\tmadd\.ew\.x\t} } } */
