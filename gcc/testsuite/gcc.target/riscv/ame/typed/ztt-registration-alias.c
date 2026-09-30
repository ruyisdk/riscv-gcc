/* { dg-do compile } */
/* { dg-options "-std=gnu11 -O2 -march=rv32gc_ztt0p6 -mabi=ilp32d -mztt-profile=gcc-runtime-u32-m32-a16" { target rv32 } } */
/* { dg-options "-std=gnu11 -O2 -march=rv64gc_ztt0p6 -mabi=lp64d -mztt-profile=gcc-runtime-u32-m32-a16" { target rv64 } } */
#include "ztt-registration-alias-body.h"
/* { dg-final { scan-assembler {madd\.ew\.x} } } */
/* { dg-final { scan-assembler {mzero\.2d\.m} } } */
/* { dg-final { scan-assembler-not {call[ \t]+__riscv_ztt_} } } */
