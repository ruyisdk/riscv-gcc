/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m32-a16" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m32-a16" { target rv64 } } */
#include "ztt-overload-index-body.h"
/* { dg-final { scan-assembler {\tmmulacc\.2d\t} } } */
/* { dg-final { scan-assembler {\tmmulaccneg\.2d\t} } } */
/* { dg-final { scan-assembler {\tmmulatacc\.2d\t} } } */
/* { dg-final { scan-assembler {\tmmulataccneg\.2d\t} } } */
/* { dg-final { scan-assembler {\tmmulbtacc\.2d\t} } } */
/* { dg-final { scan-assembler {\tmmulbtaccneg\.2d\t} } } */
/* { dg-final { scan-assembler-not {call\s+__builtin_riscv_ztt} } } */
