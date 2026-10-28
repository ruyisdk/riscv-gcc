/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -mztt-profile=gcc-runtime-u8-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#define EL_TYPE i32_rnu_sat
#define EL_ELEMENT __INT32_TYPE__
#include "../../../../../gcc.target/riscv/ame/matrix/indexed/ztt-exponent-layout.h"
/* { dg-final { scan-assembler-times {m(?:row|col)gather\.ew\s} 8 } } */
/* { dg-final { scan-assembler-times {mldexp\.ew\.x\s} 13 } } */
/* { dg-final { scan-assembler-times {mldexpacc\.ew\.x\s} 4 } } */
