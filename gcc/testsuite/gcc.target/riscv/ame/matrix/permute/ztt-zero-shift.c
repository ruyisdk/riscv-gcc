/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -mztt-profile=gcc-runtime-u32-m32-a16" } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
#include "ztt-zero-shift.h"
/* { dg-final { scan-assembler-times {\tmcolshift\.ew\.x\t} 3 } } */
/* { dg-final { scan-assembler-times {\tmrowshift\.ew\.x\t} 3 } } */
/* { dg-final { scan-assembler-times {\tmcolbcast\.ew\.x\t} 3 } } */
/* { dg-final { scan-assembler-times {\tmrowbcast\.ew\.x\t} 3 } } */
