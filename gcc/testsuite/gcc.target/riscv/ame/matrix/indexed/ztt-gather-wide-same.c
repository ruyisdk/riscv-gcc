/* { dg-do compile } */
/* { dg-options "-O2 -ffat-lto-objects -mztt-profile=gcc-runtime-u8-m16-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#include <riscv_ztt.h>
void shared (const __riscv_ztt_u128_storage_t *in, __riscv_ztt_u128_storage_t *out)
{
  __riscv_ztt_u128_rnu_sat_1x1_t a = __riscv_ztt_mls_rm_u128_rnu_sat_1x1 (in);
  __riscv_ztt_u128_rnu_sat_1x1_t c = __riscv_ztt_mcolgather_ew_u128_rnu_sat_1x1 (a, a);
  __riscv_ztt_mss_rm (out, c);
}
/* { dg-final { scan-assembler-times {mcolgather\.ew} 1 } } */
