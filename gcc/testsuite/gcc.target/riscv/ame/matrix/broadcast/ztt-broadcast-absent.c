/* integer broadcast.  */
/* { dg-do compile } */
/* { dg-options "-O2 -Werror=implicit-function-declaration -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -Werror=implicit-function-declaration -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv64 } } */
#include <riscv_ztt.h>
void absent (void)
{
  /* Fractional M and a group exceeding M16 are both unavailable.  */
  (void) __riscv_ztt_mbcast_m_x_i8_1x1_i8 (1); /* { dg-error "(implicit declaration|not declared)" } */
  (void) __riscv_ztt_mbcast_m_x_i32_1x32_i32 (1); /* { dg-error "(implicit declaration|not declared)" } */
}
