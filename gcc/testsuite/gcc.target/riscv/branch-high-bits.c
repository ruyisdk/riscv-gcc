/* { dg-do compile } */
/* { dg-options "-O2 -std=gnu11 -fdump-rtl-combine -march=rv64im -mabi=lp64" { target rv64 } } */
/* { dg-options "-O2 -std=gnu11 -fdump-rtl-combine -march=rv32im -mabi=ilp32" { target rv32 } } */

#include "branch-high-bits.h"

/* { dg-final { scan-rtl-dump "branch_on_high_bits" "combine" } } */
/* { dg-final { scan-assembler-times {\msrli\M[^\n]*,62} 2 { target rv64 } } } */
/* { dg-final { scan-assembler-times {\msrli\M[^\n]*,30} 2 { target rv32 } } } */
/* { dg-final { scan-assembler-times {\msltu\M} 3 } } */
