/* rejects the retired pointer interface.  */
/* { dg-do compile } */
/* Reach RTL in compile-only LTO torture runs; slim-LTO link rejection is
   checked separately with two translation units.  */
/* { dg-options "-O2 -ffat-lto-objects -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -ffat-lto-objects -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv64 } } */
#include <riscv_ztt.h>
void propagated_null (__riscv_ztt_i32_1x1_t *b)
{
  __riscv_ztt_i32_1x1_t *a = 0;
  __riscv_ztt_mcolunzip_ew_i32_1x1 (a, b);
}
/* { dg-error "was replaced in AME/Ztt intrinsic v0.2.5; use the 1x2 value interface" "" { target *-*-* } 0 } */
