/* { dg-do compile } */
/* { dg-options "-O2 -fdump-rtl-expand -mztt-profile=gcc-runtime-u8-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#define MZ_TYPE i32_rnu
#define MZ_CARRIER __INT32_TYPE__
#define MZ_COUNT 4
#include "ztt-m2a-zero.h"
/* { dg-final { scan-rtl-dump-times "Forward zero M to ACC" 2 "expand" } } */
