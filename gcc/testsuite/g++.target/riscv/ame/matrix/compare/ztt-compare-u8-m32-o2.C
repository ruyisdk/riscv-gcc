/* { dg-do compile } */
/* { dg-options "-O2 -std=gnu++11 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m32-a4" { target rv32 } } */
/* { dg-options "-O2 -std=gnu++11 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m32-a4" { target rv64 } } */
#include "../../../../../gcc.target/riscv/ame/matrix/compare/ztt-compare-body.h"
/* { dg-final { scan-assembler {\tmcmovge\.ew\t} } } */
/* { dg-final { scan-assembler {\tmcmovlt\.ew\t} } } */
/* { dg-final { scan-assembler {\tmcmpge\.ew\t} } } */
/* { dg-final { scan-assembler {\tmcmplt\.ew\t} } } */
/* { dg-final { scan-assembler {\tmselge\.ew\t} } } */
/* { dg-final { scan-assembler {\tmsellt\.ew\t} } } */
/* { dg-final { scan-assembler {\tmcmpge\.ew\.x\t} } } */
/* { dg-final { scan-assembler {\tmcmplt\.ew\.x\t} } } */
/* { dg-final { scan-assembler {csrw\tamestype,} } } */
/* { dg-final { scan-assembler-not {\tcall\t} } } */
