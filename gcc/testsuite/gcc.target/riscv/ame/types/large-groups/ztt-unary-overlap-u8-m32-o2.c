/* { dg-do assemble } */
/* { dg-options "-O2 -mztt-profile=gcc-runtime-u8-m32-a16 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-options "-O2 -mztt-profile=gcc-runtime-u8-m32-a16 -march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#define TEST_UDS 8
#define TEST_M 32
#include "ztt-unary-overlap.h"
