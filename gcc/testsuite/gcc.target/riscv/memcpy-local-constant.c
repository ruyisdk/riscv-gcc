/* { dg-do compile } */
/* { dg-options "-O2 -std=gnu99 -mstrict-align -fno-unroll-loops -fdump-tree-optimized" } */
#include "memcpy-local-constant.h"
/* { dg-final { scan-tree-dump-not "&value" "optimized" } } */
/* { dg-final { scan-assembler-not {\taddi\tsp,sp,} } } */
/* { dg-final { scan-assembler-times {\tsb\t} 8 } } */
