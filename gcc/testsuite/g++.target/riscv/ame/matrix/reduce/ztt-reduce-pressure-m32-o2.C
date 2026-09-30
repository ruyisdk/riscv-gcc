/* integer folds.  */
/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m32-a4" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m32-a4" { target rv64 } } */
#include "../../../../../gcc.target/riscv/ame/matrix/reduce/ztt-reduce-pressure-body.h"
/* { dg-final { scan-assembler-times {\tmreduceadd\.col\t} 1 } } */
/* { dg-final { scan-assembler-times {\tmreduceadd\.row\t} 1 } } */
/* { dg-final { scan-assembler-times {\tmreducemax\.col\t} 1 } } */
/* { dg-final { scan-assembler-times {\tmreducemax\.row\t} 1 } } */
/* { dg-final { scan-assembler-times {\tmreducemin\.col\t} 1 } } */
/* { dg-final { scan-assembler-times {\tmreducemin\.row\t} 1 } } */
/* { dg-final { scan-assembler-times {\tmprefixadd\.col\t} 1 } } */
/* { dg-final { scan-assembler-times {\tmprefixadd\.row\t} 1 } } */
/* { dg-final { scan-assembler-times {\tmprefixmax\.col\t} 1 } } */
/* { dg-final { scan-assembler-times {\tmprefixmax\.row\t} 1 } } */
