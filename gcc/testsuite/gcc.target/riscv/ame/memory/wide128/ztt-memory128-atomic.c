/* 128-bit storage elements, not ordinary C integer arithmetic.  */
/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u128-m32-a16" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u128-m32-a16" { target rv64 } } */
#include <stddef.h>
#include <stdint.h>
#include <riscv_ztt.h>
void atomic_load (_Atomic (__riscv_ztt_i128_storage_t) *p)
{
  __riscv_ztt_mls_rm_i128_1x1 (p); /* { dg-error "cannot access volatile or atomic memory" } */
}
