/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -mztt-profile=gcc-runtime-u32-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#define LC_TYPE f32_rne
#define LC_ELEMENT float
#include "ztt-binary-carrier-layout.h"
/* { dg-final { scan-assembler-times {m(?:row|col)gather\.ew\s} 5 } } */
/* { dg-final { scan-assembler-times {m(?:row|col)bcast\.ew\.x\s} 24 } } */
/* { dg-final { scan-assembler-times {madd\.ew\s} 10 } } */
/* { dg-final { scan-assembler-times {mmul\.ew\s} 1 } } */
/* { dg-final { scan-assembler-times {msub\.ew\s} 1 } } */
