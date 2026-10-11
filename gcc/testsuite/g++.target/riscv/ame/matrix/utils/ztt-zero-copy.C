/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -ffat-lto-objects -fdump-tree-optimized -mztt-profile=gcc-runtime-u32-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#include "../../../../../gcc.target/riscv/ame/matrix/utils/ztt-zero-copy.h"
/* { dg-final { scan-tree-dump-times {__riscv_ztt_mconcat_m_i32_1x2 \(} 2 "optimized" } } */
/* { dg-final { scan-assembler-not {mcolgather\.ew} } } */
/* { dg-final { scan-assembler-times {mrowbcast\.ew\.x} 12 } } */
