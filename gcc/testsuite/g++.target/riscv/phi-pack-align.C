/* { dg-do compile } */
/* { dg-options "-O2 -mstrict-align -fno-tree-vectorize -fno-tree-slp-vectorize -ffreestanding -fno-builtin -fno-pic" } */
#include "../../gcc.target/riscv/phi-pack-align.h"
/* { dg-final { scan-assembler-not {\tsb\t} } } */
/* { dg-final { scan-assembler-times {\tsw\t} 6 } } */
