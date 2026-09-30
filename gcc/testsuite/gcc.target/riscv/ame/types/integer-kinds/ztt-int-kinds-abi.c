/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a16 " { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a16 " { target rv64 } } */
#include <riscv_ztt.h>
__riscv_ztt_i4_1x2_t
bad_return (void) /* { dg-error "AME/Ztt typed values cannot be passed to or returned from ordinary functions" } */
{
  return __riscv_ztt_mzero_m_i4_1x2 ();
}
void
bad_argument (__riscv_ztt_i8_sat_accx4_t a) /* { dg-error "AME/Ztt typed values cannot be passed to or returned from ordinary functions" } */
{
  __asm__ volatile ("" : : "War" (a));
}
