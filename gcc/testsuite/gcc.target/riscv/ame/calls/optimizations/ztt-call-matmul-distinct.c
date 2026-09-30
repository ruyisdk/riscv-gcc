/* { dg-do compile } */
/* { dg-options "-g -std=gnu99 -march=rv32gc_ztt0p6 -mabi=ilp32d -mztt-profile=gcc-runtime-u8-m32-a1" { target rv32 } } */
/* { dg-options "-g -std=gnu99 -march=rv64gc_ztt0p6 -mabi=lp64d -mztt-profile=gcc-runtime-u8-m32-a1" { target rv64 } } */
#include "../ztt-call-matmul-distinct.h"
/* { dg-final { scan-assembler-times {mmulacc\.2d\s+acc0,(?:m0,m16|m16,m0)} 2 } } */
