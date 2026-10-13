/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a16" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a16" { target rv64 } } */
#include "ztt-ternary-bank-source.h"
/* { dg-final { scan-assembler-times {\tmmulacc\.ew\t} 5 } } */
/* { dg-final { scan-assembler-times {\tmmulsub\.ew\t} 1 } } */
/* { dg-final { scan-assembler {\tmls\.1r\t} } } */
/* { dg-final { scan-assembler {\tmss\.1r\t} } } */
