/* { dg-do compile } */
/* { dg-options "-O2 -std=gnu++11 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -std=gnu++11 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>
struct X { operator uint32_t () const { return 1; } };
void bad (const int8_t *p)
{
  __riscv_ztt_i8_1x1_t x = __riscv_ztt_mls_rm_i8_1x1 (p);
  __riscv_ztt_mcmpge_ew_x_i8_1x1_u32 (x, __riscv_ztt_scalar_make_u32_rnu (X ())); /* { dg-error "Scalar constructor requires an integer carrier" } */
}
