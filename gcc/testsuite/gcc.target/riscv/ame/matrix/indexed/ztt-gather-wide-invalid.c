/* { dg-do compile } */
/* { dg-options "-O2 -ffat-lto-objects -mztt-profile=gcc-runtime-u8-m16-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#include <riscv_ztt.h>
void impossible (const __riscv_ztt_u128_storage_t *in,
                 const __INT8_TYPE__ *index, __riscv_ztt_u128_storage_t *out)
{
  __riscv_ztt_u128_rnu_sat_1x1_t a = __riscv_ztt_mls_rm_u128_rnu_sat_1x1 (in);
  __riscv_ztt_i8_rnu_sat_1x1_t b = __riscv_ztt_mls_rm_i8_rnu_sat_1x1 (index);
  __riscv_ztt_u128_rnu_sat_1x1_t c = __riscv_ztt_mcolgather_ew_u128_rnu_sat_1x1 (a, b);
  __riscv_ztt_mss_rm (out, c);
}
/* { dg-error "Ztt gather operation requires 17 simultaneously allocated M registers for distinct sources; profile provides 16" "" { target *-*-* } 0 } */
