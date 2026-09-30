/* { dg-do compile } */
/* { dg-options "-march=rv32im_zicsr -mabi=ilp32" { target rv32 } } */
/* { dg-options "-march=rv64im_zicsr -mabi=lp64" { target rv64 } } */
#include <riscv_ztt.h>
/* { dg-error "requires the AME/Ztt ISA extension" "" { target *-*-* } 0 } */
/* { dg-error "requires a supported -mztt-profile configuration" "" { target *-*-* } 0 } */
/* { dg-error "requires the 'ztt0p6' ISA extension" "" { target *-*-* } 0 } */
#ifdef __riscv_ztt_zip_value
#error unsupported value capability
#endif
void absent (void)
{
  __riscv_ztt_mcolzip_ew_i32_rnu_1x2 (0); /* { dg-error "implicit declaration|not declared" } */
}
