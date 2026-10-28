/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -ffat-lto-objects -mztt-profile=gcc-runtime-u32-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#define ZS_TYPE f32_rne
#define ZS_ELEMENT float
#include "../../../../../gcc.target/riscv/ame/matrix/indexed/ztt-zero-scatter.h"
/* { dg-final { scan-assembler-times {mrowscatadd\.ew} 5 } } */
/* { dg-final { scan-assembler-times {mcolscatadd\.ew} 5 } } */
/* { dg-final { scan-assembler-times {mrowscatmax\.ew} 1 } } */
