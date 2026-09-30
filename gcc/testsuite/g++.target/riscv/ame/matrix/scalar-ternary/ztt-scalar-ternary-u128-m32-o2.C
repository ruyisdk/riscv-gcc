/* { dg-do compile } */
/* { dg-options "-O2 -std=gnu++11 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u128-m32-a4" { target rv32 } } */
/* { dg-options "-O2 -std=gnu++11 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u128-m32-a4" { target rv64 } } */
#include "../../../../../gcc.target/riscv/ame/matrix/scalar-ternary/ztt-scalar-ternary-body.h"
/* { dg-final { scan-assembler {\tmmulacc\.ew\.x\t} } } */
/* { dg-final { scan-assembler {\tmmulaccneg\.ew\.x\t} } } */
/* { dg-final { scan-assembler {\tmmuladd\.ew\.x\t} } } */
/* { dg-final { scan-assembler {\tmmulsub\.ew\.x\t} } } */
/* { dg-final { scan-assembler {csrw\tamestype,} } } */
/* { dg-final { scan-assembler-not {\tcall\t} } } */
