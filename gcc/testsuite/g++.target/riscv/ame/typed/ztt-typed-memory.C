/* local v0.2.3 contract.  */
/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32gc_ztt0p6 -mabi=ilp32d -mztt-profile=gcc-p0-n128-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -march=rv64gc_ztt0p6 -mabi=lp64d -mztt-profile=gcc-p0-n128-u8-m16-a4" { target rv64 } } */

#include "../../../../gcc.target/riscv/ame/typed/ztt-typed-memory.c"

/* { dg-final { scan-assembler-times "mls\\.rm" 3 } } */
/* { dg-final { scan-assembler-times "mss\\.rm" 3 } } */
