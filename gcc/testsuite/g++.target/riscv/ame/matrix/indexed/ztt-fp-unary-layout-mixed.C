/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -mztt-profile=gcc-runtime-u32-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#define FU_SOURCE f64_rne
#define FU_INPUT double
#define FU_DEST f32_rne
#define FU_OUTPUT float
#include "../../../../../gcc.target/riscv/ame/matrix/indexed/ztt-fp-unary-layout.h"
/* { dg-final { scan-assembler-times {m(?:row|col)gather\.ew\s} 7 } } */
/* { dg-final { scan-assembler-times {m(?:row|col)bcast\.ew\.x\s} 24 } } */
/* { dg-final { scan-assembler-times {msqrt\.ew\s} 12 } } */
/* { dg-final { scan-assembler-times {mrec\.ew\s} 3 } } */
/* { dg-final { scan-assembler-times {m(?:frint[mnpz]|exp2|log2|cos|sin|tanh|rsqrt)\.ew\s} 10 } } */
