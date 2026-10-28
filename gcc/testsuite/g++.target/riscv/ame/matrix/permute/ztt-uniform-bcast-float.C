/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -ffat-lto-objects -mztt-profile=gcc-runtime-u32-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#define UB_TYPE f32_rne
#define UB_ELEMENT float
#include "../../../../../gcc.target/riscv/ame/matrix/permute/ztt-uniform-bcast.h"
/* { dg-final { scan-assembler-times {mrowbcast\.ew\.x} 4 } } */
/* { dg-final { scan-assembler-times {mcolbcast\.ew\.x} 2 } } */
/* { dg-final { scan-assembler-times {mbcast\.m\.x} 12 } } */
