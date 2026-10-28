/* { dg-do compile } */
/* { dg-options "-O2 -mstrict-align -fno-unroll-loops -fdump-tree-optimized" } */
#include "../../gcc.target/riscv/memcpy-local-constant.h"
/* { dg-final { scan-tree-dump-not "&value" "optimized" } } */
/* { dg-final { scan-assembler-not {\taddi\tsp,sp,} } } */
/* { dg-final { scan-assembler-times {\tsb\t} 8 } } */
