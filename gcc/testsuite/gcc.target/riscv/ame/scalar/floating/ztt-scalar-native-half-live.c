/* { dg-do compile } */
/* { dg-options "-O2 -mztt-profile=gcc-runtime-u32-m32-a16" } */
/* { dg-additional-options "-march=rv64gc_zfhmin_zfbfmin_ztt0p6 -mabi=lp64d" { target rv64 } } */
/* { dg-additional-options "-march=rv32gc_zfhmin_zfbfmin_ztt0p6 -mabi=ilp32d" { target rv32 } } */

#include "ztt-scalar-native-half-live.h"

/* { dg-final { scan-assembler-times {madd\.ew\.x} 2 } } */
/* { dg-final { scan-assembler-times {csrw\tamestype} 2 } } */
/* { dg-final { scan-assembler-not {\ts[wd]\t[at][0-9]+,} } } */
