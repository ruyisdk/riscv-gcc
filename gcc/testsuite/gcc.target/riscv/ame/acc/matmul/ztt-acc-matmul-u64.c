/* Matmul interface checks.  */
/* { dg-do compile } */
/* { dg-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u64-m16-a4" { target rv32 } } */
/* { dg-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u64-m16-a4" { target rv64 } } */
#include <riscv_ztt.h>
#ifdef __riscv_ztt_acc_matmul_variants
#error unsupported profile advertises accumulator variants
#endif

void
unavailable_default_alias (void)
{
  (void) __riscv_ztt_mmulatacc_2d_i32_accx1; /* { dg-error "undeclared" } */
}
