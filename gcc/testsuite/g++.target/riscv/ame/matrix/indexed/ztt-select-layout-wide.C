/* { dg-do compile } */
/* { dg-options "-O2 -g -fno-ipa-icf -ffat-lto-objects -mztt-profile=gcc-runtime-u32-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#define LG_TYPE i64_rnu
#define LG_ELEMENT __INT64_TYPE__
#include "../../../../../gcc.target/riscv/ame/matrix/indexed/ztt-select-layout.h"
/* { dg-final { scan-assembler-times {m(?:row|col)gather\.ew\s} 9 } } */
/* { dg-final { scan-assembler-times {mcmovge\.ew\s} 5 } } */
/* { dg-final { scan-assembler-times {mmean\.ew\s} 7 } } */
