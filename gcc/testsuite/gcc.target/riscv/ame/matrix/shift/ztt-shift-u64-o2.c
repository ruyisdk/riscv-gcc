/* mixed shifts.  */
/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u64-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u64-m16-a4" { target rv64 } } */
#include "ztt-shift-u64-body.h"
/* { dg-final { scan-assembler-times {\tmsll\.ew\t} 130 } } */
/* { dg-final { scan-assembler-times {\tmsrl\.ew\t} 130 } } */
/* { dg-final { scan-assembler-times {\tmsra\.ew\t} 130 } } */
/* { dg-final { scan-assembler-times {\tmsll\.ew\.x\t} 62 } } */
/* { dg-final { scan-assembler-times {\tmsrl\.ew\.x\t} 62 } } */
/* { dg-final { scan-assembler-times {\tmsra\.ew\.x\t} 62 } } */
/* { dg-final { scan-assembler-not {amestype} } } */
