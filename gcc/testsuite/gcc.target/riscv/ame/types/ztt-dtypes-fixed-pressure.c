/* integer
   1x1 types with UDS=8.  Wider elements own a complete 2/4-M group.  */
/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-p0-n128-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-p0-n128-u8-m16-a4" { target rv64 } } */
#include "ztt-dtypes-pressure.h"
/* { dg-final { scan-assembler "msettyp" } } */
/* { dg-final { scan-assembler "mss.1r" } } */
/* { dg-final { scan-assembler "mls.1r" } } */
/* { dg-final { scan-assembler-not "mmov.m.m" } } */
