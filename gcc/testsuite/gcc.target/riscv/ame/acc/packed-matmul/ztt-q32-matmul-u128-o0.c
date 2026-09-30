/* Q32.  */
/* { dg-do compile } */
/* { dg-options "-O0 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u128-m16-a4" { target rv32 } } */
/* { dg-options "-O0 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u128-m16-a4" { target rv64 } } */
#include "ztt-q32-matmul-body.h"
/* { dg-final { scan-assembler-times {\tmmulacc\.2d\t} 2 } } */
/* { dg-final { scan-assembler-times {\tmmulaccneg\.2d\t} 2 } } */
/* { dg-final { scan-assembler-times {\tmmulatacc\.2d\t} 4 } } */
/* { dg-final { scan-assembler-times {\tmmulataccneg\.2d\t} 4 } } */
/* { dg-final { scan-assembler-times {\tmmulbtacc\.2d\t} 4 } } */
/* { dg-final { scan-assembler-times {\tmmulbtaccneg\.2d\t} 4 } } */
/* { dg-final { scan-assembler-not {amestype} } } */
