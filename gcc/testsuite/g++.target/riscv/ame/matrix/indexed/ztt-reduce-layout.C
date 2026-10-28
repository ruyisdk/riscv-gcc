/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -mztt-profile=gcc-runtime-u32-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#include "../../../../../gcc.target/riscv/ame/matrix/indexed/ztt-reduce-layout.h"
/* { dg-warning "volatile.*deprecated" "" { target c++20 } 0 } */
/* { dg-final { scan-assembler-times {m(?:row|col)gather\.ew\s} 5 } } */
/* { dg-final { scan-assembler-times {m(?:row|col)bcast\.ew\.x\s} 1 } } */
/* { dg-final { scan-assembler-times {mreduce(?:add|max|min)\.(?:row|col)\s} 12 } } */
