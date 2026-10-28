/* { dg-do compile } */
/* { dg-options "-O2 -mstrict-align -fno-tree-vectorize -fno-tree-slp-vectorize -ffreestanding -fno-builtin -fno-pic" } */
#define RESIDUE 1
#include "../../gcc.target/riscv/phi-pack-align.h"
/* { dg-final { scan-assembler-times {\tsb\t} 24 } } */
