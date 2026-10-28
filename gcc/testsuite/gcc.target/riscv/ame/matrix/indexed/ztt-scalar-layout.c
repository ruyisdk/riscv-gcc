/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -mztt-profile=gcc-runtime-u8-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#include "ztt-scalar-layout.h"
/* { dg-final { scan-assembler-times {m(?:row|col)gather\.ew\s} 5 } } */
/* { dg-final { scan-assembler-times {m(?:row|col)bcast\.ew\.x\s} 12 } } */
/* { dg-final { scan-assembler-times {madd\.ew\.x\s} 10 } } */
/* { dg-final { scan-assembler-times {mmul\.ew\.x\s} 1 } } */
/* { dg-final { scan-assembler-times {msub\.ew\.x\s} 1 } } */
