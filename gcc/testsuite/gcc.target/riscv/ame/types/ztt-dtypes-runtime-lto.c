/* integer
   1x1 types with UDS=8.  Wider elements own a complete 2/4-M group.  */
/* { dg-do compile } */
/* { dg-options "-O2 -flto -ffat-lto-objects -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -flto -ffat-lto-objects -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv64 } } */
#define TEST_RUNTIME 1
#include "ztt-dtypes-single.h"
