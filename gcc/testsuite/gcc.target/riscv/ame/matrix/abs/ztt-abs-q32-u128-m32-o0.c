/* mabs.ew.  */
/* { dg-do compile } */
/* { dg-options "-O0 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u128-m32-a4" { target rv32 } } */
/* { dg-options "-O0 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u128-m32-a4" { target rv64 } } */
#define TEST_Q32
#include "ztt-abs-body.h"
/* { dg-final { scan-assembler-times {\tmabs\.ew\t} 10 } } */
/* { dg-final { scan-assembler-not {amestype|\tmabs\.ew\.x\t} } } */
