/* { dg-do compile } */
/* { dg-options "-O2 -g -fno-ipa-icf -ffat-lto-objects -fdump-tree-optimized -mztt-profile=gcc-runtime-u32-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#include "ztt-fp-gather.h"
/* { dg-final { scan-assembler-times {mcolgather\.ew} 8 } } */
/* { dg-final { scan-assembler-not {mrowgather\.ew} } } */
/* { dg-final { scan-tree-dump-times {__riscv_ztt_mcolid_ew_u32_1x1 \(\)} 9 "optimized" } } */
/* { dg-final { scan-tree-dump-times {__riscv_ztt_mrowid_ew_u32_1x1 \(\)} 2 "optimized" } } */
/* { dg-final { scan-tree-dump-times {__riscv_ztt_mcopy_m2m_u32_1x1 \(} 23 "optimized" } } */
