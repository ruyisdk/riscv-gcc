/* { dg-do compile } */
/* { dg-options "-O0 -g -march=rv32gc_ztt0p6 -mabi=ilp32d -mztt-profile=gcc-runtime-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O0 -g -march=rv64gc_ztt0p6 -mabi=lp64d -mztt-profile=gcc-runtime-u8-m16-a4" { target rv64 } } */

#include "../../../../gcc.target/riscv/ame/runtime-n/ztt-runtime-n-codegen.c"

/* { dg-final { scan-assembler "mss\\.1r" } } */
/* { dg-final { scan-assembler "csrr\ts11,amenlen" } } */
