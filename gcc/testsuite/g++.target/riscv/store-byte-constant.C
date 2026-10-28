/* { dg-do compile } */
/* { dg-options "-O2 -mstrict-align -mstringop-strategy=scalar" } */

#include "../../gcc.target/riscv/store-byte-constant.h"

/* { dg-final { scan-assembler-not {\t(lbu|lhu|lw|lwu|ld|sh|sw|sd)\t} } } */
/* { dg-final { scan-assembler-not {\taddi\tsp,sp,} } } */
/* { dg-final { scan-assembler-times {\tsb\t} 12 { target rv32 } } } */
/* { dg-final { scan-assembler-times {\tsb\t} 20 { target rv64 } } } */
