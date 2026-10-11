/* { dg-do compile } */
/* { dg-options "-std=gnu11 -O2 -march=rv32gc_ztt0p6 -mabi=ilp32d -mztt-profile=gcc-runtime-u32-m32-a16" { target rv32 } } */
/* { dg-options "-std=gnu11 -O2 -march=rv64gc_ztt0p6 -mabi=lp64d -mztt-profile=gcc-runtime-u32-m32-a16" { target rv64 } } */
#include <riscv_ztt.h>

void
unavailable_short_names (void)
{
  /* Reject unsupported groups and names without public aliases.  */
  (void) __riscv_ztt_mclear_acc_i32_accx32; /* { dg-error "undeclared" } */
  (void) __riscv_ztt_mss_rm_i32_1x1; /* { dg-error "undeclared" } */
  (void) __builtin_riscv_ztt_mextract_column_i32_1x1; /* { dg-error "undeclared" } */
}
