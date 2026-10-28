/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -ffat-lto-objects -mztt-profile=gcc-runtime-u32-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#define MS_TYPE f32_rne
#define MS_ELEMENT float
#include "../../../../../gcc.target/riscv/ame/matrix/indexed/ztt-max-scatter.h"
/* { dg-final { scan-assembler-times {mrowscatmax\.ew} 7 } } */
/* { dg-final { scan-assembler-times {mcolscatmax\.ew} 6 } } */
