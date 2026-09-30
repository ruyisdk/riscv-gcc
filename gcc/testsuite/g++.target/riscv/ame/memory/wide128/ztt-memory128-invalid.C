/* 128-bit storage elements, not ordinary C integer arithmetic.  */
/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u128-m32-a16" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u128-m32-a16" { target rv64 } } */
#include <stddef.h>
#include <stdint.h>
#include <riscv_ztt.h>
void invalid (__riscv_ztt_i128_storage_t *i,
              const __riscv_ztt_i128_storage_t *ci,
              volatile __riscv_ztt_i128_storage_t *vi,
              __riscv_ztt_u128_storage_t *u, void *p, uint64_t *w)
{
  __riscv_ztt_i128_1x1_t value = __riscv_ztt_mzero_m_i128_1x1 ();
  __riscv_ztt_mls_rm_i128_1x1 (u); /* { dg-error "requires a pointer" } */
  __riscv_ztt_mls_rm_i128_1x1 (p); /* { dg-error "requires a pointer" } */
  __riscv_ztt_mls_rm_i128_1x1 (w); /* { dg-error "requires a pointer" } */
  __riscv_ztt_mss_rm (ci, value); /* { dg-error "requires a pointer to writable" } */
  __riscv_ztt_mss_rm (u, value); /* { dg-error "requires a pointer to writable" } */
  __riscv_ztt_mls_rm_i128_1x1 (vi); /* { dg-error "cannot access volatile or atomic memory" } */
  __riscv_ztt_mss_rm (vi, value); /* { dg-error "cannot access volatile or atomic memory" } */
  *i = *u; /* { dg-error "incompatible types|no match for" } */
  *i = *i + *i; /* { dg-error "invalid operands|no match for" } */
}
