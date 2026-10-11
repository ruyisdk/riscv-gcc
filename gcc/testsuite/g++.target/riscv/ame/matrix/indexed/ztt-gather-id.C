/* { dg-do compile } */
/* { dg-options "-O2 -g -fno-ipa-icf -ffat-lto-objects -fdump-tree-optimized -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m32-a16" { target rv32 } } */
/* { dg-options "-O2 -g -fno-ipa-icf -ffat-lto-objects -fdump-tree-optimized -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m32-a16" { target rv64 } } */
#include "../../../../../gcc.target/riscv/ame/matrix/indexed/ztt-gather-id.h"
/* { dg-final { scan-assembler-times {mcolgather\.ew} 6 } } */
/* { dg-final { scan-assembler-not {mrowgather\.ew} } } */
/* { dg-final { scan-tree-dump-times {__riscv_ztt_mcolid_ew_u32_1x1 \(\)} 7 "optimized" } } */
/* { dg-final { scan-tree-dump-times {__riscv_ztt_mrowid_ew_u32_1x1 \(\)} 2 "optimized" } } */
