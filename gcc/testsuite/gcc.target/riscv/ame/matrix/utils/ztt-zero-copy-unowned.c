/* { dg-do compile } */
/* { dg-options "-O2 -ffat-lto-objects -fdump-rtl-ztt_regions -mztt-profile=gcc-runtime-u32-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#include <riscv_ztt.h>
void zc_unowned (const __INT32_TYPE__ *in, __INT32_TYPE__ *out,
                 unsigned long k)
{
  if (!(__riscv_ztt_ame_acquire (0) & 1)) return;
  __riscv_ztt_i32_1x1_t a = __riscv_ztt_mls_rm_i32_1x1 (in);
  __riscv_ztt_i32_1x1_t b = __riscv_ztt_mrowbcast_ew_x_i32_1x1 (a,k);
  __riscv_ztt_ame_release ();
  __riscv_ztt_i32_1x1_t c = __riscv_ztt_mrowshift_ew_x_i32_1x1 (b,0);
  __riscv_ztt_i32_1x1_t d = __riscv_ztt_mrowbcast_ew_x_i32_1x1 (c,k);
  if (!(__riscv_ztt_ame_acquire (0) & 1)) return;
  __riscv_ztt_mss_rm (out,d);
  __riscv_ztt_ame_release ();
}
/* { dg-error "ownership changes.*require ownership-region support" "" { target *-*-* } 0 } */
/* { dg-final { scan-rtl-dump {Unproved Ztt access:} "ztt_regions" } } */
