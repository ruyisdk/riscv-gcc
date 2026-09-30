/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -std=gnu11 -Werror=implicit-function-declaration -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u16-m32-a4" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -std=gnu11 -Werror=implicit-function-declaration -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u16-m32-a4" { target rv64 } } */
#define MEMORY_UDS 16
#include "ztt-memory-body.h"
/* { dg-final { scan-assembler {\tmls\.cm\t} } } */
/* { dg-final { scan-assembler {\tmls\.st\t} } } */
/* { dg-final { scan-assembler {\tmls\.tst\t} } } */
/* { dg-final { scan-assembler {\tmss\.cm\t} } } */
/* { dg-final { scan-assembler {\tmss\.st\t} } } */
/* { dg-final { scan-assembler {\tmss\.tst\t} } } */
/* { dg-final { scan-assembler-not {\tcall\t} } } */
