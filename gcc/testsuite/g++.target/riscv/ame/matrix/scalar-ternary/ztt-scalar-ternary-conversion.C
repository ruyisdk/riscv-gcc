/* { dg-do compile } */
/* { dg-options "-O2 -std=gnu++11 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -std=gnu++11 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv64 } } */

#include <riscv_ztt.h>
struct scalar_like { operator int () const { return 1; } };
void reject_user_conversion (const signed char *p)
{
  __riscv_ztt_i8_rnu_1x1_t d = __riscv_ztt_mls_rm_i8_1x1 (p);
  __riscv_ztt_mmulacc_ew_x_i8_1x1_i32 (d, d, __riscv_ztt_scalar_make_i32_rnu (scalar_like{})); /* { dg-error "Scalar constructor requires an integer carrier" } */
}
