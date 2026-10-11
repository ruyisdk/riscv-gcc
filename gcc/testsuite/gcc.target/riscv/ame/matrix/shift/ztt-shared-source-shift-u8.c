/* Identical-source shift preparation.  */
/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv64 } } */
#define O3_SHIFT
#include "../mul/ztt-shared-source-body.h"
/* { dg-final { scan-assembler-times {\tmsll\.ew\t} 4 } } */
/* { dg-final { scan-assembler-times {\tmsrl\.ew\t} 4 } } */
/* { dg-final { scan-assembler-times {\tmsra\.ew\t} 4 } } */
/* { dg-final { scan-assembler-times {\tmsll\.ew\.x\t} 1 } } */
/* { dg-final { scan-assembler-times {\tmsettyp\t} 29 } } */
/* { dg-final { scan-assembler-not {\tmss\.1r\t} } } */
/* { dg-final { scan-assembler-not {\tmls\.1r\t} } } */
/* { dg-final { scan-assembler-times {\tmls\.rm\t} 16 } } */
/* { dg-final { scan-assembler-times {\tmss\.rm\t} 29 } } */
