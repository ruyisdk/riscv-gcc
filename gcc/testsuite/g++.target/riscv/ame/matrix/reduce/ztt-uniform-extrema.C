/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -mztt-profile=gcc-runtime-u8-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#include "../../../../../gcc.target/riscv/ame/matrix/reduce/ztt-uniform-extrema.h"
/* { dg-warning "volatile.*deprecated" "" { target c++20 } 0 } */
/* { dg-final { scan-assembler-times {mreducemax\.row\t} 1 } } */
/* { dg-final { scan-assembler-times {mreducemax\.col\t} 1 } } */
/* { dg-final { scan-assembler-times {mreducemin\.row\t} 1 } } */
/* { dg-final { scan-assembler-times {mreducemin\.col\t} 1 } } */
/* { dg-final { scan-assembler-times {mabs\.ew\t} 1 } } */
/* { dg-final { scan-assembler-times {mreduceadd\.row\t} 1 } } */
/* { dg-final { scan-assembler-not {mprefixmax\.(row|col)\t} } } */
/* { dg-final { scan-assembler-times {mbcast\.m\.x\t} 17 } } */
