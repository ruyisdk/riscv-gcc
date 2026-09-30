/* { dg-do compile } */
/* { dg-options "-O0 -std=gnu11 -Werror=implicit-function-declaration -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv32 } } */
/* { dg-options "-O0 -std=gnu11 -Werror=implicit-function-declaration -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv64 } } */
#include "ztt-compare-pressure.h"
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
/* { dg-final { scan-assembler {\tmss\.1r\t} } } */
/* { dg-final { scan-assembler {\tmls\.1r\t} } } */
