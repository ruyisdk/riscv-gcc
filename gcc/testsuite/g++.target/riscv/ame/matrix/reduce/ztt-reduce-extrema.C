/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -mztt-profile=gcc-runtime-u8-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#include "../../../../../gcc.target/riscv/ame/matrix/reduce/ztt-reduce-extrema.h"
/* { dg-final { scan-assembler-times {mreduceadd\.row\t} 5 } } */
/* { dg-final { scan-assembler-times {mreduceadd\.col\t} 2 } } */
/* { dg-final { scan-assembler-times {mreducemax\.row\t} 5 } } */
/* { dg-final { scan-assembler-times {mreducemax\.col\t} 2 } } */
/* { dg-final { scan-assembler-times {mreducemin\.row\t} 2 } } */
/* { dg-final { scan-assembler-times {mreducemin\.col\t} 6 } } */
/* { dg-final { scan-assembler-times {mprefixmax\.col\t} 1 } } */
/* { dg-final { scan-assembler-not {mprefixmax\.row\t} } } */
/* { dg-final { scan-assembler-times {mls\.rm\t} 17 } } */
