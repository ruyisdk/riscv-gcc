/* { dg-do compile } */
/* { dg-options "-O2 -g -fno-ipa-icf -ffat-lto-objects -fdump-tree-optimized -mztt-profile=gcc-runtime-u8-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#include "../../../../../gcc.target/riscv/ame/matrix/bitwise/ztt-andnot-zero.h"
/* { dg-final { scan-assembler-times {mandnot\.ew\t} 5 } } */
/* { dg-final { scan-tree-dump-times {__riscv_ztt_mzero_m_i32_rnu_1x1 \(\)} 6 "optimized" } } */
/* { dg-final { scan-tree-dump-times {__riscv_ztt_mcopy_m2m_i32_rnu_1x1 \(} 9 "optimized" } } */
