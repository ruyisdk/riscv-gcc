/* { dg-do compile } */
/* { dg-options "-O2 -std=gnu11 -mstrict-align -fno-tree-vectorize -fno-tree-slp-vectorize" } */

#define RESIDUE 1
#include "loop-pointer-align.h"

/* { dg-final { scan-assembler "\\tlbu\\t" } } */
/* { dg-final { scan-assembler "\\tsb\\t" } } */
/* { dg-final { scan-assembler-not "\\tlw\\t" } } */
/* { dg-final { scan-assembler-not "\\tsw\\t" } } */
