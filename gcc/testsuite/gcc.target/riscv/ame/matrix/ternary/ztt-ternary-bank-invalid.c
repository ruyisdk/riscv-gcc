/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a16" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a16" { target rv64 } } */
#include <riscv_ztt.h>
void test (const __INT64_TYPE__ *a, const __UINT64_TYPE__ *b,
           const __INT64_TYPE__ *old, __INT64_TYPE__ *out)
{
  __riscv_ztt_i64_rnu_1x1_t x = __riscv_ztt_mls_rm_i64_rnu_1x1 (a);
  __riscv_ztt_u64_rnu_1x1_t y = __riscv_ztt_mls_rm_u64_rnu_1x1 (b);
  __riscv_ztt_i64_rnu_1x1_t d = __riscv_ztt_mls_rm_i64_rnu_1x1 (old);
  __riscv_ztt_i64_rnu_1x1_t z = __riscv_ztt_mmulacc_ew_i64_rnu_1x1 (d, x, y); /* { dg-error "ternary operation requires 24 simultaneously allocated M registers.*profile provides 16" } */
  __riscv_ztt_mss_rm_i64_rnu_1x1 (out, z);
}
