/* { dg-do compile } */
/* { dg-options "-O2 -std=gnu11 -fno-tree-vectorize -fno-tree-loop-distribute-patterns -fdump-rtl-combine -march=rv64im -mabi=lp64" { target rv64 } } */
/* { dg-options "-O2 -std=gnu11 -fno-tree-vectorize -fno-tree-loop-distribute-patterns -fdump-rtl-combine -march=rv32im -mabi=ilp32" { target rv32 } } */

#include "branch-low-bit.h"

/* { dg-final { scan-rtl-dump "branch_on_low_bit" "combine" } } */
/* { dg-final { scan-assembler-not {\msrli\M} } } */
/* { dg-final { scan-assembler-times {\mandi\M} 5 } } */
