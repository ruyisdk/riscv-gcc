/* { dg-do compile } */
/* { dg-options "-O2 --param ggc-min-expand=0 --param ggc-min-heapsize=0 -mztt-profile=gcc-runtime-u8-m16-a1" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#include "ztt-matmul-signatures.h"
/* { dg-final { scan-assembler-times {\tmmulacc\.2d\t} 2 } } */
/* { dg-final { scan-assembler-times {\tmmulatacc\.2d\t} 2 } } */
/* { dg-final { scan-assembler-times {\tmmulbtacc\.2d\t} 2 } } */
