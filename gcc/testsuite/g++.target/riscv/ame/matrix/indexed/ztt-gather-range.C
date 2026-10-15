/* { dg-do compile } */
/* { dg-options "-O2 -g -fno-ipa-icf -ffat-lto-objects -fdump-tree-optimized -mztt-profile=gcc-runtime-u8-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#include "../../../../../gcc.target/riscv/ame/matrix/indexed/ztt-gather-range.h"
/* { dg-final { scan-assembler-times {mcolgather\.ew} 8 } } */
/* { dg-final { scan-assembler-not {mrowgather\.ew} } } */
/* { dg-final { scan-assembler-times {mconv\.ew} 13 } } */
/* { dg-final { scan-tree-dump-times {__builtin_riscv_ztt_convert_[0-9]+ \(} 13 "optimized" } } */
/* { dg-final { scan-tree-dump-times {__riscv_ztt_mcolid_ew_i8_rnu_sat_1x1 \(\)} 10 "optimized" } } */
/* { dg-final { scan-tree-dump-times {__riscv_ztt_mrowid_ew_i8_rnu_sat_1x1 \(\)} 2 "optimized" } } */
