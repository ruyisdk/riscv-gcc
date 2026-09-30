/* integer folds.  */
/* { dg-do compile } */
/* { dg-options "-O0 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u16-m16-a4" { target rv32 } } */
/* { dg-options "-O0 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u16-m16-a4" { target rv64 } } */
#include "ztt-reduce-body.h"
/* { dg-final { scan-assembler-times {\tmreduceadd\.col\t} 15 } } */
/* { dg-final { scan-assembler-times {\tmreduceadd\.row\t} 15 } } */
/* { dg-final { scan-assembler-times {\tmreducemax\.col\t} 15 } } */
/* { dg-final { scan-assembler-times {\tmreducemax\.row\t} 15 } } */
/* { dg-final { scan-assembler-times {\tmreducemin\.col\t} 15 } } */
/* { dg-final { scan-assembler-times {\tmreducemin\.row\t} 15 } } */
/* { dg-final { scan-assembler-times {\tmprefixadd\.col\t} 15 } } */
/* { dg-final { scan-assembler-times {\tmprefixadd\.row\t} 15 } } */
/* { dg-final { scan-assembler-times {\tmprefixmax\.col\t} 15 } } */
/* { dg-final { scan-assembler-times {\tmprefixmax\.row\t} 15 } } */
/* { dg-final { scan-assembler-not {amestype|\tmconv\.ew\t} } } */
