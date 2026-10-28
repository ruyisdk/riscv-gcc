/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -mztt-profile=gcc-runtime-u32-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#define AC_TYPE i32_rnu
#define AC_ELEMENT __INT32_TYPE__
#define AC_SHAPE 1x1
#include "ztt-max-zero.h"
/* { dg-final { scan-assembler-times {mmax\.ew\t} 11 } } */
