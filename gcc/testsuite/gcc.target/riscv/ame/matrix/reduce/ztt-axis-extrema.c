/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -mztt-profile=gcc-runtime-u8-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#include "ztt-axis-extrema.h"
/* { dg-final { scan-assembler-times {mreduce(max|min)\.(row|col)\t} 5 } } */
/* { dg-final { scan-assembler-not {mprefixmax\.(row|col)\t} } } */
/* { dg-final { scan-assembler-times {mabs\.ew\t} 1 } } */
/* { dg-final { scan-assembler-times {mreduceadd\.col\t} 1 } } */
/* { dg-final { scan-assembler-times {mrowbcast\.ew\.x\t} 16 } } */
/* { dg-final { scan-assembler-times {mcolbcast\.ew\.x\t} 4 } } */
/* { dg-final { scan-assembler-times {mrowid\.ew\t} 2 } } */
/* { dg-final { scan-assembler-times {mcolid\.ew\t} 1 } } */
