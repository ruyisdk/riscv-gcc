/* { dg-do compile } */
/* { dg-options "-O2 -g -fno-ipa-icf -ffat-lto-objects -fdump-tree-optimized -mztt-profile=gcc-runtime-u8-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target { rv32 } } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target { rv64 } } } */
#include "../../../../../gcc.target/riscv/ame/matrix/indexed/ztt-scatter-identity.h"
/* { dg-final { scan-assembler-times {mcolscatmax\.ew} 9 } } */
/* { dg-final { scan-assembler-not {mrowscatmax\.ew} } } */
/* { dg-final { scan-assembler-times {mcolscatadd\.ew} 1 } } */
/* { dg-final { scan-tree-dump-times {__builtin_riscv_ztt_convert_[0-9]+ \(} 15 "optimized" } } */
