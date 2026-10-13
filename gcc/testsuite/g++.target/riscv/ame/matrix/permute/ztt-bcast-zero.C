/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -ffat-lto-objects -fdump-tree-optimized -mztt-profile=gcc-runtime-u32-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#include "../../../../../gcc.target/riscv/ame/matrix/permute/ztt-bcast-zero.h"
/* { dg-final { scan-assembler-times {mrowbcast\.ew\.x} 18 } } */
/* { dg-final { scan-assembler-times {mcolbcast\.ew\.x} 2 } } */
/* { dg-final { scan-tree-dump-times {__riscv_ztt_mrowbcast_ew_x_i32_1x1 \(} 18 "optimized" } } */
/* { dg-final { scan-tree-dump-times {__riscv_ztt_mcolbcast_ew_x_i32_1x1 \(} 2 "optimized" } } */
