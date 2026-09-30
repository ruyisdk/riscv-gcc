/* Compile/assemble checks, not numerical execution evidence.  */
/* { dg-do compile } */
/* { dg-options "-O2 -fdump-tree-optimized -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u16-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -fdump-tree-optimized -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u16-m16-a4" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>
void alias (uintptr_t c, volatile unsigned *count)
{
  __riscv_ztt_i4_rnu_sat_1x8_t b = __riscv_ztt_mzero_m_i4_rnu_sat_1x8 ();
  __riscv_ztt_i8_rnu_sat_1x8_t d;
  /* UDS16: a 4-M result and a 2-M packed source.  */
  d = __riscv_ztt_madd_ew_x_i8_sat_1x8_u128_sat
    (b, __riscv_ztt_scalar_from_bits_u128_rnu_sat (((void) (*count = *count + 1), c)));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
/* { dg-final { scan-assembler-times {\tmadd\.ew\.x\t} 2 } } */
/* { dg-final { scan-tree-dump-times { =\{v\} \*count} 1 "optimized" } } */
/* { dg-final { scan-tree-dump-times {\*count[^;]* =\{v\}} 1 "optimized" } } */
