/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv64 } } */
#include <riscv_ztt.h>
#include <stdint.h>
void incompatible (int32_t *out)
{
  __riscv_ztt_i64_rnu_1x1_t w = __riscv_ztt_mzero_m_i64_1x1 ();
  __riscv_ztt_i128_rnu_1x1_t v = __riscv_ztt_mzero_m_i128_1x1 ();
  __riscv_ztt_i32_rnu_1x1_t m = __riscv_ztt_mzero_m_i32_1x1 ();
  __riscv_ztt_i32_rnu_accx1_t a = __riscv_ztt_mzero_acc_i32_accx1 ();
  __riscv_ztt_mconv_ew_i32_1x1 (w);
  __riscv_ztt_madd_ew_i32_1x1 (m, w);
  __riscv_ztt_mmulacc_2d_i32_accx1 (a, m, w);
  __riscv_ztt_mss_rm (out, w); /* { dg-error "pointer to" } */
  __riscv_ztt_mss_rm (out, v); /* { dg-error "pointer to writable.*__riscv_ztt_i128_storage_t" } */
}
