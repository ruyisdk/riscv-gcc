/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -mztt-profile=gcc-runtime-u32-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#define UE_TYPE f32_rne
#define UE_ELEMENT float
#define UE_CARRIER __UINT32_TYPE__
#include "ztt-uniform-extrema.h"
/* { dg-final { scan-assembler-times {mreduce(max|min)\.(row|col)\t} 12 } } */
/* { dg-final { scan-assembler-times {mprefixmax\.(row|col)\t} 2 } } */
/* { dg-final { scan-assembler-times {mabs\.ew\t} 1 } } */
/* { dg-final { scan-assembler-times {mreduceadd\.row\t} 1 } } */
/* { dg-final { scan-assembler-times {mbcast\.m\.x\t} 17 } } */
