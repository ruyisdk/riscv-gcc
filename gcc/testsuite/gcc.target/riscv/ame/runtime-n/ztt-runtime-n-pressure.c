/* { dg-do compile } */
/* { dg-options "-O2 -g -march=rv32gc_ztt0p6 -mabi=ilp32d -mztt-profile=gcc-runtime-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -g -march=rv64gc_ztt0p6 -mabi=lp64d -mztt-profile=gcc-runtime-u8-m16-a4" { target rv64 } } */

#include "../typed/ztt-typed-pressure.c"

/* { dg-final { scan-assembler-times "msettyp\tm\[0-9\]+," 16 } } */
/* { dg-final { scan-assembler "mss\\.1r" } } */
/* { dg-final { scan-assembler "mls\\.1r" } } */
/* { dg-final { scan-assembler-not "msettyp\tm(1\[6-9\]|2\[0-9\]|3\[01\])," } } */
/* { dg-final { scan-assembler "csrr\ts11,amenlen" } } */
