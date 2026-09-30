/* Q32.  */
/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u128-m32-a4" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u128-m32-a4" { target rv64 } } */
#include "ztt-q32-utils-body.h"
/* { dg-final { scan-assembler {\tmls\.rm\t} } } */
/* { dg-final { scan-assembler {\tmss\.rm\t} } } */
/* { dg-final { scan-assembler-not {amestype} } } */
