/* { dg-do compile } */
/* { dg-options "-O2 -march=rv64im -mabi=lp64" { target rv64 } } */
/* { dg-options "-O2 -march=rv32im -mabi=ilp32" { target rv32 } } */

#include "../../gcc.target/riscv/order-pow2-shared.h"

/* { dg-final { scan-assembler-times {\msltu\M} 7 } } */
/* { dg-final { scan-assembler-not {\msrli\M} } } */
