/* { dg-do compile } */
/* { dg-options "-O2 -g -fno-ipa-icf -ffat-lto-objects -fdump-tree-optimized -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -g -fno-ipa-icf -ffat-lto-objects -fdump-tree-optimized -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv64 } } */
#include "ztt-structure-geometry.h"
/* { dg-final { scan-assembler-times {mrowzip\.ew} 8 } } */
/* { dg-final { scan-assembler-times {mrowunzip\.ew} 8 } } */
/* { dg-final { scan-tree-dump-not {= __riscv_ztt_mextract} "optimized" } } */
/* { dg-final { scan-tree-dump-not {= __riscv_ztt_mconcat} "optimized" } } */
