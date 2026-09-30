/* Q32.  */
/* { dg-do compile } */
/* { dg-options "-O0 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u128-m16-a4" { target rv32 } } */
/* { dg-options "-O0 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u128-m16-a4" { target rv64 } } */
#include "ztt-q32-shift-body.h"
/* { dg-final { scan-assembler-times {\tmsll\.ew\t} 36 } } */
/* { dg-final { scan-assembler-times {\tmsll\.ew\.x\t} 20 } } */
/* { dg-final { scan-assembler-times {\tmsrl\.ew\t} 36 } } */
/* { dg-final { scan-assembler-times {\tmsrl\.ew\.x\t} 20 } } */
/* { dg-final { scan-assembler-times {\tmsra\.ew\t} 36 } } */
/* { dg-final { scan-assembler-times {\tmsra\.ew\.x\t} 20 } } */
/* { dg-final { scan-assembler-not {amestype} } } */
