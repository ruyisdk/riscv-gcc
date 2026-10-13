/* { dg-do compile } */
/* { dg-options "-O2 -g -fno-ipa-icf -ffat-lto-objects -mztt-profile=gcc-runtime-u8-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#include "../../../../../gcc.target/riscv/ame/matrix/scalar-ternary/ztt-scalar-old-source.h"
/* { dg-final { scan-assembler-times {mmulacc\.ew\.x} 7 } } */
/* { dg-final { scan-assembler-times {mmulaccneg\.ew\.x} 1 } } */
/* { dg-final { scan-assembler-times {mmuladd\.ew\.x} 1 } } */
/* { dg-final { scan-assembler-times {mmulsub\.ew\.x} 1 } } */
/* { dg-final { scan-assembler {mmulacc\.ew\.x\s+m([0-9]+),[^,]+,m\1} } } */
