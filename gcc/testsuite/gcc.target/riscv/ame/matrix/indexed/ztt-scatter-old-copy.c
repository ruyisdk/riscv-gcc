/* { dg-do compile } */
/* { dg-options "-O2 -g -fno-ipa-icf -ffat-lto-objects -mztt-profile=gcc-runtime-u8-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#include "ztt-scatter-old-copy.h"
/* { dg-final { scan-assembler-times {\tmmov\.m\.m\t} 10 } } */
/* { dg-final { scan-assembler-times {\tmcolscatadd\.ew\t} 7 } } */
/* { dg-final { scan-assembler-times {\tmrowscatadd\.ew\t} 3 } } */
/* { dg-final { scan-assembler-times {\tmcolscatmax\.ew\t} 2 } } */
/* { dg-final { scan-assembler-times {\tmrowscatmax\.ew\t} 2 } } */
/* { dg-final { scan-assembler-times {\tmadd\.ew\t} 12 } } */
