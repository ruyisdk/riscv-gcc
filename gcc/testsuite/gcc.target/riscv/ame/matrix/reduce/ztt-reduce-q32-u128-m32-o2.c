/* integer folds.  */
/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u128-m32-a4" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u128-m32-a4" { target rv64 } } */
#define TEST_Q32 1
#include "ztt-reduce-body.h"
/* { dg-final { scan-assembler-times {\tmreduceadd\.col\t} 10 } } */
/* { dg-final { scan-assembler-times {\tmreduceadd\.row\t} 10 } } */
/* { dg-final { scan-assembler-times {\tmreducemax\.col\t} 10 } } */
/* { dg-final { scan-assembler-times {\tmreducemax\.row\t} 10 } } */
/* { dg-final { scan-assembler-times {\tmreducemin\.col\t} 10 } } */
/* { dg-final { scan-assembler-times {\tmreducemin\.row\t} 10 } } */
/* { dg-final { scan-assembler-times {\tmprefixadd\.col\t} 10 } } */
/* { dg-final { scan-assembler-times {\tmprefixadd\.row\t} 10 } } */
/* { dg-final { scan-assembler-times {\tmprefixmax\.col\t} 10 } } */
/* { dg-final { scan-assembler-times {\tmprefixmax\.row\t} 10 } } */
/* { dg-final { scan-assembler-not {amestype|\tmconv\.ew\t} } } */
