/* { dg-do compile } */
/* { dg-options "-O2 -ffat-lto-objects -fdump-tree-optimized -fdump-rtl-ztt_regions -mztt-profile=gcc-runtime-u8-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#include <riscv_ztt.h>
void giw_unowned (const float *in, float *out)
{
  if (!(__riscv_ztt_ame_acquire (0) & 1)) return;
  __riscv_ztt_f32_rne_1x1_t a = __riscv_ztt_mls_rm_f32_rne_1x1 (in);
  __riscv_ztt_ame_release ();
  __riscv_ztt_i8_rnu_sat_1x1_t i = __riscv_ztt_mcolid_ew_i8_rnu_sat_1x1 ();
  __riscv_ztt_u32_rod_1x1_t j = __riscv_ztt_mconv_ew_u32_rod_1x1 (i);
  __riscv_ztt_f32_rne_1x1_t b = __riscv_ztt_mcolgather_ew_f32_rne_1x1 (a, j);
  if (!(__riscv_ztt_ame_acquire (0) & 1)) return;
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_ame_release ();
}
/* { dg-error "ownership changes.*require ownership-region support" "" { target *-*-* } 0 } */
/* { dg-final { scan-rtl-dump {Unproved Ztt access:} "ztt_regions" } } */
/* { dg-final { scan-tree-dump-times {__riscv_ztt_mcolid_ew_i8_rnu_sat_1x1 \(\)} 1 "optimized" } } */
/* { dg-final { scan-tree-dump-times {__builtin_riscv_ztt_convert_[0-9]+ \(} 1 "optimized" } } */
