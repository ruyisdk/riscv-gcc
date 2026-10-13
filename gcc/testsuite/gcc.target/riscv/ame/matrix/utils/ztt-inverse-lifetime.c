/* { dg-do compile } */
/* { dg-options "-O2 -g -fno-ipa-icf -ffat-lto-objects -fdump-tree-optimized -mztt-profile=gcc-runtime-u32-m32-a16" } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
#include "ztt-inverse-lifetime.h"
/* { dg-final { scan-tree-dump-times {= __riscv_ztt_mrowunzip_ew_} 4 "optimized" } } */
/* { dg-final { scan-tree-dump-times {= __riscv_ztt_mcolunzip_ew_} 3 "optimized" } } */
/* { dg-final { scan-tree-dump-times {= __riscv_ztt_mrowzip_ew_} 7 "optimized" } } */
/* { dg-final { scan-tree-dump-times {= __riscv_ztt_mcolzip_ew_} 3 "optimized" } } */
