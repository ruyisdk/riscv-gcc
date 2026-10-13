/* { dg-do compile } */
/* { dg-options "-O2 -g -fno-ipa-icf -ffat-lto-objects -mztt-profile=gcc-runtime-u8-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#define MX_KIND 2
#include "../../../../../gcc.target/riscv/ame/matrix/ternary/ztt-mixed-old-source.h"
/* { dg-final { scan-assembler-times {mcmovge\.ew\s} 8 } } */
/* { dg-final { scan-assembler-times {mcmovlt\.ew\s} 2 } } */
/* { dg-final { scan-assembler {mcmovge\.ew\s+m([0-9]+),m[0-9]+,m\1} } } */
