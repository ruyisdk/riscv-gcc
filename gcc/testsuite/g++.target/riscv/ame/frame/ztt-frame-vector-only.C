/* Function-local frame policy.  */
/* { dg-do compile } */
/* { dg-options "-O0 -g -march=rv32gcv_ztt0p6 -mabi=ilp32d -mztt-profile=gcc-runtime-u32-m16-a4" { target rv32 } } */
/* { dg-options "-O0 -g -march=rv64gcv_ztt0p6 -mabi=lp64d -mztt-profile=gcc-runtime-u32-m16-a4" { target rv64 } } */

#include <riscv_vector.h>
extern "C" {
__attribute__((riscv_vector_cc)) void vector_only
  (const int32_t *src, int32_t *dst, unsigned long n)
{
  vint32m1_t x = __riscv_vle32_v_i32m1 (src, n);
  __riscv_vse32_v_i32m1 (dst, x, n);
}
}

/* { dg-final { scan-assembler-not "s11" } } */
/* { dg-final { scan-assembler-not "amenlen" } } */
/* { dg-final { scan-assembler "vlenb" } } */
/* { dg-final { scan-assembler "\\.cfi_restore 97" } } */
