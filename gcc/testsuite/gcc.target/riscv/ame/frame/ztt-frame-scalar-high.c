/* Function-local frame policy.  */
/* { dg-do compile } */
/* { dg-options "-O2 -g -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u128-m32-a16" { target rv32 } } */
/* { dg-options "-O2 -g -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u128-m32-a16" { target rv64 } } */

#include <riscv_ztt.h>
int plain_high (int a) { return a + 1; }

/* { dg-final { scan-assembler-not "s11" } } */
/* { dg-final { scan-assembler-not "s0" } } */
/* { dg-final { scan-assembler-not "amenlen" } } */
/* { dg-final { scan-assembler-not "addi\\tsp" } } */
