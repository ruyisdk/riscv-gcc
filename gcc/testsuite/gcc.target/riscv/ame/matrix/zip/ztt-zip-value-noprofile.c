/* { dg-do compile } */
/* { dg-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#include <riscv_ztt.h>
/* { dg-error "requires a supported -mztt-profile configuration" "" { target *-*-* } 0 } */
/* { dg-error "requires '-mztt-profile=gcc-p0-n128-u8-m16-a4'" "" { target *-*-* } 0 } */
#ifdef __riscv_ztt_zip_value
#error unsupported value capability
#endif
void absent (void)
{
  __riscv_ztt_mcolzip_ew_i32_rnu_1x2 (0); /* { dg-error "implicit declaration|not declared" } */
}
