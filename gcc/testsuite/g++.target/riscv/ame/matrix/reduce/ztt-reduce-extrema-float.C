/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -mztt-profile=gcc-runtime-u32-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#define UI_TYPE f32_rne
#define UI_ELEMENT float
#include "../../../../../gcc.target/riscv/ame/matrix/reduce/ztt-reduce-extrema.h"
/* { dg-final { scan-assembler-times {mreduceadd\.(row|col)\t} 7 } } */
/* { dg-final { scan-assembler-times {mreducemax\.(row|col)\t} 7 } } */
/* { dg-final { scan-assembler-times {mreducemin\.(row|col)\t} 8 } } */
/* { dg-final { scan-assembler-times {mprefixmax\.col\t} 1 } } */
/* { dg-final { scan-assembler-not {mprefixmax\.row\t} } } */
/* { dg-final { scan-assembler-times {mls\.rm\t} 17 } } */
