/* Complete packed ACC copies.  */
/* { dg-do assemble } */
/* { dg-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u64-m32-a16" { target rv32 } } */
/* { dg-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u64-m32-a16" { target rv64 } } */
#define TEST_BITS 16
#define TEST_K 4
#include "../ztt-acc-packed-body.h"
