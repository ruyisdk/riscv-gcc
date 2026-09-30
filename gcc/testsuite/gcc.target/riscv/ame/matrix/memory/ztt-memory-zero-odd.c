/* { dg-do compile } */
/* { dg-options "-O2 -std=gnu11 -Werror=implicit-function-declaration -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -std=gnu11 -Werror=implicit-function-declaration -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv64 } } */

#include <riscv_ztt.h>
#include <stdint.h>
void zero_odd (int32_t *out, const int32_t *in)
{
  __riscv_ztt_i32_rnu_1x1_t a = __riscv_ztt_mls_st_i32_1x1 (in, 0);
  __riscv_ztt_i32_rnu_1x1_t b = __riscv_ztt_mls_tst_i32_1x1 (in, 3);
  __riscv_ztt_mss_st (out, 0, a);
  __riscv_ztt_mss_tst (out, 3, b);
}
/* { dg-final { scan-assembler {mls\.st\t[^,]+,\([^)]+\),zero} } } */
/* { dg-final { scan-assembler {mss\.st\t[^,]+,\([^)]+\),zero} } } */
/* { dg-final { scan-assembler {mls\.tst\t} } } */
/* { dg-final { scan-assembler {mss\.tst\t} } } */
