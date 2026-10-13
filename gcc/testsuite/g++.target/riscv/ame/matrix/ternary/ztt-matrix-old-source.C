/* { dg-do compile } */
/* { dg-options "-O2 -g -fno-ipa-icf -ffat-lto-objects -mztt-profile=gcc-runtime-u8-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#include "../../../../../gcc.target/riscv/ame/matrix/ternary/ztt-matrix-old-source.h"
/* { dg-final { scan-assembler-times {mmulacc\.ew\s} 8 } } */
/* { dg-final { scan-assembler-times {mmulaccneg\.ew\s} 1 } } */
/* { dg-final { scan-assembler-times {mmuladd\.ew\s} 1 } } */
/* { dg-final { scan-assembler-times {mmulsub\.ew\s} 2 } } */
/* { dg-final { scan-assembler {mmulacc\.ew\s+m([0-9]+),m\1,m\1} } } */
