/* Source concatenation.  */
/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u16-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u16-m16-a4" { target rv64 } } */
#define TEST_FACTOR 2
#define TEST_Q 2
#define TEST_K 2
#define TEST_NO_BRANCH
#include "ztt-acc-concat-body.h"
/* { dg-final { scan-assembler-times {\tmmulacc\.2d\t} 16 } } */
/* { dg-final { scan-assembler-times {\tmmulaccneg\.2d\t} 16 } } */
/* { dg-final { scan-assembler-times {\tmmulatacc\.2d\t} 32 } } */
/* { dg-final { scan-assembler-times {\tmmulataccneg\.2d\t} 32 } } */
/* { dg-final { scan-assembler-times {\tmmulbtacc\.2d\t} 32 } } */
/* { dg-final { scan-assembler-times {\tmmulbtaccneg\.2d\t} 32 } } */
