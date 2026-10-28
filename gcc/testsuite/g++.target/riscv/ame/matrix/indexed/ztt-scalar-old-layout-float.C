/* { dg-do compile } */
/* { dg-options "-O2 -g -fno-ipa-icf -ffat-lto-objects -mztt-profile=gcc-runtime-u32-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#define SL_TYPE f32_rne
#define SL_ELEMENT float
#define SL_SCALAR f32_rne
#include "../../../../../gcc.target/riscv/ame/matrix/indexed/ztt-scalar-old-layout.h"
/* { dg-final { scan-assembler-times {m(?:row|col)gather\.ew\s} 8 } } */
/* { dg-final { scan-assembler-times {m(?:row|col)bcast\.ew\.x\s} 31 } } */
/* { dg-final { scan-assembler-times {mmulacc\.ew\.x\s} 13 } } */
/* { dg-final { scan-assembler-times {mmulaccneg\.ew\.x\s} 1 } } */
/* { dg-final { scan-assembler-times {mmuladd\.ew\.x\s} 1 } } */
/* { dg-final { scan-assembler-times {mmulsub\.ew\.x\s} 1 } } */
