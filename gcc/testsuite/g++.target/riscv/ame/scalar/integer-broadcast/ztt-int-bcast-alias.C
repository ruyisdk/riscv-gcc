/* Compile/assemble checks, not numerical execution evidence.  */
/* { dg-do compile } */
/* { dg-options "-O2 -fdump-tree-optimized -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -fdump-tree-optimized -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>
void aliases (uintptr_t x, volatile unsigned *count)
{
  __riscv_ztt_i4_rnu_sat_1x2_t a = __riscv_ztt_mbcast_m_x_i4_sat_1x2_i128 ( __riscv_ztt_scalar_from_bits_i128_rnu (x));
  __riscv_ztt_u8_rnu_1x1_t b = __riscv_ztt_mbcast_m_x_u8_1x1_i32_sat ( __riscv_ztt_scalar_make_i32_rnu_sat (x));
  __riscv_ztt_i8_rnu_sat_4x1_t d =
    __riscv_ztt_mbcast_m_x_i8_sat_4x1_u128_sat
      ( __riscv_ztt_scalar_from_bits_u128_rnu_sat (((void) (*count = *count + 1), x)));
  __asm__ volatile ("" : : "Wmr" (a), "Wmr" (b), "Wmr" (d));
}
/* { dg-final { scan-assembler-times {\tmbcast\.m\.x\t} 6 } } */
/* { dg-final { scan-assembler-not {amestype} } } */
/* { dg-final { scan-tree-dump-times { =\{v\} \*count} 1 "optimized" } } */
/* { dg-final { scan-tree-dump-times {\*count[^;]* =\{v\}} 1 "optimized" } } */
