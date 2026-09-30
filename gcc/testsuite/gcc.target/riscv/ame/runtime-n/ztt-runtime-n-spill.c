/* { dg-do compile } */
/* { dg-options "-O0 -g -fstack-clash-protection -march=rv32gc_ztt0p6 -mabi=ilp32d -mztt-profile=gcc-runtime-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O0 -g -fstack-clash-protection -march=rv64gc_ztt0p6 -mabi=lp64d -mztt-profile=gcc-runtime-u8-m16-a4" { target rv64 } } */

#include "../typed/ztt-typed-o0-spill.c"

/* { dg-final { scan-assembler "mss\\.1r" } } */
/* { dg-final { scan-assembler "mls\\.1r" } } */
/* { dg-final { scan-assembler "csrr\ts11,amenlen" } } */
/* { dg-final { scan-assembler "sub\tsp,sp," } } */
/* { dg-final { scan-assembler-not "vlenb" } } */
/* { dg-final { scan-assembler "\\.cfi_def_cfa 8, 0" } } */
/* { dg-final { scan-assembler "\\.cfi_def_cfa 2, \[0-9\]+" } } */
