/* Complete large packed ACC groups.  */
/* { dg-do assemble } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u128-m16-a16" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u128-m16-a16" { target rv64 } } */
#define TEST_BITS 16
#define TEST_K 16
#include "../packed/ztt-acc-packed-body.h"
