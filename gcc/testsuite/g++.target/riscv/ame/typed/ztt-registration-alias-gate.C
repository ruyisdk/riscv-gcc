/* { dg-do compile } */
/* { dg-options "-std=gnu++17 -O2 -march=rv32gc_ztt0p6 -mabi=ilp32d -mztt-profile=gcc-runtime-u32-m32-a16" { target rv32 } } */
/* { dg-options "-std=gnu++17 -O2 -march=rv64gc_ztt0p6 -mabi=lp64d -mztt-profile=gcc-runtime-u32-m32-a16" { target rv64 } } */
#include <riscv_ztt.h>

void
unavailable_short_names ()
{
  (void) __riscv_ztt_mclear_acc_i32_accx32; /* { dg-error "not declared" } */
  (void) __riscv_ztt_mss_rm_i32_1x1; /* { dg-error "not declared" } */
  (void) __builtin_riscv_ztt_mextract_column_i32_1x1; /* { dg-error "not declared" } */
}
