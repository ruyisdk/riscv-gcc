/* { dg-do compile } */
/* { dg-options "-O2 --param ggc-min-expand=0 --param ggc-min-heapsize=0 -mztt-profile=gcc-p0-n128-u8-m16-a4" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#include "../../../../gcc.target/riscv/ame/typed/ztt-matrix-signatures.h"
/* { dg-final { scan-assembler-times {\tmadd\.ew\t} 1 } } */
/* { dg-final { scan-assembler-times {\tmmulacc\.ew\t} 1 } } */
