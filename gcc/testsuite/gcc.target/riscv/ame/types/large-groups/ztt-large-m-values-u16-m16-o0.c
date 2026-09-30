/* { dg-do assemble } */
/* { dg-options "-O0 -mztt-profile=gcc-runtime-u16-m16-a16 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-options "-O0 -mztt-profile=gcc-runtime-u16-m16-a16 -march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#define TEST_UDS 16
#define TEST_M 16
#include "ztt-large-m-values.h"
