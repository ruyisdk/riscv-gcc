/* { dg-do compile } */
/* { dg-options "-O2 -std=gnu11 -mstrict-align -fno-tree-vectorize -fno-tree-slp-vectorize" } */

#include "loop-pointer-align.h"

/* { dg-final { scan-assembler "\\tlw\\t" } } */
/* { dg-final { scan-assembler "\\tsw\\t" } } */
/* { dg-final { scan-assembler-not "\\tlbu\\t" } } */
/* { dg-final { scan-assembler-not "\\tsb\\t" } } */
