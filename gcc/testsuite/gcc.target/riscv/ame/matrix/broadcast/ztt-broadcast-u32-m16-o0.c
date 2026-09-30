/* integer broadcast.  */
/* { dg-do compile } */
/* { dg-options "-O0 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv32 } } */
/* { dg-options "-O0 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv64 } } */
#include "ztt-broadcast-body.h"
/* { dg-final { scan-assembler-times {\tmbcast\.m\.x\t} 123 } } */
/* { dg-final { scan-assembler-not {amestype|\tmbcast\.f\t} } } */
