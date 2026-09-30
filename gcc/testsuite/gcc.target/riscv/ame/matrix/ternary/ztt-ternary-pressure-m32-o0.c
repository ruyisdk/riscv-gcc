/* ternary arithmetic.  */
/* { dg-do compile } */
/* { dg-options "-O0 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m32-a4" { target rv32 } } */
/* { dg-options "-O0 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m32-a4" { target rv64 } } */
#include "ztt-ternary-pressure-body.h"
/* { dg-final { scan-assembler-times {\tmmulacc\.ew\t} 3 } } */
/* { dg-final { scan-assembler-times {\tmmulaccneg\.ew\t} 2 } } */
/* { dg-final { scan-assembler-times {\tmmuladd\.ew\t} 2 } } */
/* { dg-final { scan-assembler-times {\tmmulsub\.ew\t} 2 } } */
/* { dg-final { scan-assembler {\tmls\.1r\t} } } */
/* { dg-final { scan-assembler {\tmss\.1r\t} } } */
