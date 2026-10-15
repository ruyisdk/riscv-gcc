/* { dg-do compile } */
/* { dg-options "-O2 -fdump-rtl-expand -mztt-profile=gcc-runtime-u32-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#define MZ_TYPE i8_rnu
#define MZ_CARRIER __INT8_TYPE__
#define MZ_COUNT 16
#include "ztt-m2a-zero.h"
/* { dg-final { scan-rtl-dump-times "Forward zero M to ACC" 2 "expand" } } */
