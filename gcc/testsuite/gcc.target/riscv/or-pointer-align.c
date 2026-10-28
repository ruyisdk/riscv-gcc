/* { dg-do compile } */
/* { dg-options "-O2 -mstrict-align -fno-tree-vectorize -fno-tree-slp-vectorize" } */

#include "or-pointer-align.h"

/* { dg-final { scan-assembler-times "\\tsh\\t" 2 } } */
/* { dg-final { scan-assembler-not "\\tsb\\t" } } */
