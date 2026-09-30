/* Compile/assemble checks, not numerical execution evidence.  */
/* { dg-do compile } */
/* { dg-options "-O2 -fdump-tree-optimized -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m16-a16" { target rv32 } } */
/* { dg-options "-O2 -fdump-tree-optimized -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m16-a16" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>
void raw_carrier (uintptr_t x, uint64_t wide, volatile unsigned *counter)
{
  __riscv_ztt_i64_rne_1x1_t b = __riscv_ztt_mzero_m_i64_rne_1x1 ();
  b = __riscv_ztt_madd_ew_x_i64_rne_1x1_i128_rod (b, __riscv_ztt_scalar_from_bits_i128_rod (x));
  b = __riscv_ztt_msub_ew_x_i64_rne_1x1_u128_rdn (b, __riscv_ztt_scalar_from_bits_u128_rdn ((uintptr_t) wide));
  b = __riscv_ztt_mmul_ew_x_i64_rne_1x1_i64_rnu (b, __riscv_ztt_scalar_from_bits_i64_rnu (~(uintptr_t) 0));
  b = __riscv_ztt_madd_ew_x_i64_rne_1x1_u128_rne
    (b, __riscv_ztt_scalar_from_bits_u128_rne (((void) (*counter = *counter + 1), x)));
  __asm__ volatile ("" : : "Wmr" (b));
}
void broadcast_carrier (uintptr_t x)
{
  __riscv_ztt_i128_rnu_1x1_t d = __riscv_ztt_mbcast_m_x_i128_1x1_i128 ( __riscv_ztt_scalar_from_bits_i128_rnu (x));
  __asm__ volatile ("" : : "Wmr" (d));
}
/* { dg-final { scan-assembler-times {\tmadd\.ew\.x\t} 2 } } */
/* { dg-final { scan-assembler-times {\tmsub\.ew\.x\t} 1 } } */
/* { dg-final { scan-assembler-times {\tmmul\.ew\.x\t} 1 } } */
/* { dg-final { scan-assembler-times {\tmbcast\.m\.x\t} 1 } } */
/* { dg-final { scan-tree-dump-times { =\{v\} \*counter} 1 "optimized" } } */
/* { dg-final { scan-tree-dump-times {\*counter[^;]* =\{v\}} 1 "optimized" } } */
