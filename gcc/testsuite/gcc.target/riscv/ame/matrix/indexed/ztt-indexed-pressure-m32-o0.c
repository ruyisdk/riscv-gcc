/* basic-square indexed API.  */
/* { dg-do compile } */
/* { dg-options "-O0 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m32-a4" { target rv32 } } */
/* { dg-options "-O0 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m32-a4" { target rv64 } } */
#include "ztt-indexed-pressure-body.h"
/* { dg-final { scan-assembler-times {\tmcolgather\.ew\t} 1 } } */
/* { dg-final { scan-assembler-times {\tmrowgather\.ew\t} 1 } } */
/* { dg-final { scan-assembler-times {\tmcolscatadd\.ew\t} 1 } } */
/* { dg-final { scan-assembler-times {\tmrowscatadd\.ew\t} 1 } } */
/* { dg-final { scan-assembler-times {\tmcolscatmax\.ew\t} 1 } } */
/* { dg-final { scan-assembler-times {\tmrowscatmax\.ew\t} 1 } } */
/* { dg-final { scan-assembler {\tmss\.1r\t} } } */
/* { dg-final { scan-assembler {\tmls\.1r\t} } } */
