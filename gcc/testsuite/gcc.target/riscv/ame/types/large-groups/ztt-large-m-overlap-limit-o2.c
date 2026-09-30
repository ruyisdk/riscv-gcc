/* { dg-do compile } */
/* This RTL diagnostic is also checked at real LTO link in the batch suite.  */
/* { dg-options "-O2 -fno-lto -mztt-profile=gcc-runtime-u8-m16-a16 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-options "-O2 -fno-lto -mztt-profile=gcc-runtime-u8-m16-a16 -march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#include <riscv_ztt.h>
void impossible_sources (signed char x, signed char y)
{
  __riscv_ztt_i128_rnu_1x1_t a = __riscv_ztt_mbcast_m_x_i128_rnu_1x1_i8_rnu ( __riscv_ztt_scalar_make_i8_rnu (x));
  __riscv_ztt_i128_rnu_1x1_t b = __riscv_ztt_mbcast_m_x_i128_rnu_1x1_i8_rnu ( __riscv_ztt_scalar_make_i8_rnu (y));
  a = __riscv_ztt_madd_ew_i128_rnu_1x1 (a, b); /* { dg-error "requires 32 simultaneously allocated M registers for distinct sources; profile provides 16" } */
  __asm__ volatile ("" : : "Wmr" (a));
}
