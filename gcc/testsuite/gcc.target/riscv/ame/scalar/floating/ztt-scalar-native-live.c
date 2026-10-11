/* { dg-do compile } */
/* { dg-options "-O2 -mztt-profile=gcc-runtime-u32-m32-a16" } */
/* { dg-additional-options "-march=rv64gc_ztt0p6 -mabi=lp64d" { target rv64 } } */
/* { dg-additional-options "-march=rv32gc_ztt0p6 -mabi=ilp32d" { target rv32 } } */

#include "ztt-scalar-native-live.h"

/* { dg-final { scan-assembler-times {madd\.ew\.x} 1 } } */
/* { dg-final { scan-assembler-times {csrw\tamestype} 1 } } */
/* { dg-final { scan-assembler-not {\tsd\t[at][0-9]+,} } } */
