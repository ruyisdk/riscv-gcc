/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -ffat-lto-objects -fdump-tree-optimized -mztt-profile=gcc-runtime-u32-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#include "ztt-fp-repeat-bcast.h"
/* { dg-final { scan-assembler-times {mrowbcast\.ew\.x} 24 } } */
/* { dg-final { scan-assembler-times {mcolbcast\.ew\.x} 3 } } */
/* { dg-final { scan-tree-dump-times {__riscv_ztt_mrowbcast_ew_x_f32_rne_1x1 \(} 24 "optimized" } } */
/* { dg-final { scan-tree-dump-times {__riscv_ztt_mcolbcast_ew_x_f32_rne_1x1 \(} 3 "optimized" } } */
