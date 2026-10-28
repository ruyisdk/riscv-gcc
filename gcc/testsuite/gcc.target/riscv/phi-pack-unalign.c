/* { dg-do compile } */
/* { dg-options "-O2 -std=gnu99 -mstrict-align -fno-tree-vectorize -fno-tree-slp-vectorize -ffreestanding -fno-builtin -fno-pic" } */
#define RESIDUE 1
#include "phi-pack-align.h"
/* { dg-final { scan-assembler-times {\tsb\t} 24 } } */
