/* { dg-do compile } */
/* { dg-options "-O2 -ffat-lto-objects -fdump-tree-optimized -fdump-rtl-ztt_regions -mztt-profile=gcc-runtime-u8-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target { rv32 } } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target { rv64 } } } */
#include <riscv_ztt.h>
void unowned (const __INT32_TYPE__ *in, __INT32_TYPE__ *out)
{
  if (!(__riscv_ztt_ame_acquire (0) & 1)) return;
  __riscv_ztt_i32_rnu_1x1_t a = __riscv_ztt_mls_rm_i32_rnu_1x1 (in);
  __riscv_ztt_ame_release ();
  __riscv_ztt_u8_rnu_1x1_t i = __riscv_ztt_mcolid_ew_u8_rnu_1x1 ();
  __riscv_ztt_i32_rnu_1x1_t copy = __riscv_ztt_mcopy_m2m_i32_rnu_1x1 (a);
  __riscv_ztt_i32_rnu_1x1_t b = __riscv_ztt_mcolscatmax_ew_i32_rnu_1x1 (a, copy, i);
  if (!(__riscv_ztt_ame_acquire (0) & 1)) return;
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_ame_release ();
}
/* { dg-error "ownership changes.*require ownership-region support" "" { target *-*-* } 0 } */
/* { dg-final { scan-rtl-dump {Unproved Ztt access:} "ztt_regions" } } */
/* { dg-final { scan-tree-dump-times {__riscv_ztt_mcolid_ew_u8_rnu_1x1 \(\)} 1 "optimized" } } */
/* { dg-final { scan-tree-dump-times {__riscv_ztt_mcopy_m2m_i32_rnu_1x1 \(} 1 "optimized" } } */
