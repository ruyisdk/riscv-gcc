/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -mztt-profile=gcc-runtime-u32-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#define AE_TYPE f32_rne
#define AE_ELEMENT float
#define AE_FLOAT
#include "../../../../../gcc.target/riscv/ame/matrix/reduce/ztt-axis-extrema.h"
/* { dg-warning "volatile.*deprecated" "" { target c++20 } 0 } */
/* { dg-final { scan-assembler-times {mreduce(max|min)\.(row|col)\t} 16 } } */
/* { dg-final { scan-assembler-times {mprefixmax\.(row|col)\t} 3 } } */
