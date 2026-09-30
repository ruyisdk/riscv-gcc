/* Resource boundaries.  */
/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a16" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a16" { target rv64 } } */
#include <riscv_ztt.h>
void complete_acc_but_no_whole_m (void)
{
  __riscv_ztt_i128_rnu_accx16_t a
    = __riscv_ztt_mzero_acc_i128_rnu_accx16 ();
  __asm__ volatile ("" : : "War" (a));
  (void) __riscv_ztt_mcopy_a2m_i128_rnu_1x16; /* { dg-error "undeclared|was not declared" } */
  (void) __riscv_ztt_mcopy_m2a_i128_rnu_accx16; /* { dg-error "undeclared|was not declared" } */
}
