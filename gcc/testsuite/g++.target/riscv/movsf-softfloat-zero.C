/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im -mabi=ilp32" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im -mabi=lp64" { target rv64 } } */
#include "../../gcc.target/riscv/movsf-softfloat-zero.h"
/* { dg-final { scan-assembler-times {\tsw\tzero,} 4 { target rv32 } } } */
/* { dg-final { scan-assembler-times {\tsw\tzero,} 2 { target rv64 } } } */
/* { dg-final { scan-assembler-times {\tsd\tzero,} 1 { target rv64 } } } */
/* { dg-final { scan-assembler-not {\tli\t[a-z0-9]+,0\n} } } */
