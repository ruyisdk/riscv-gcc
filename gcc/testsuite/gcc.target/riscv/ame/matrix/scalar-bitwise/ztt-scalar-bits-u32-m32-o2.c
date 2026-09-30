/* scalar bitwise.  */
/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m32-a4" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m32-a4" { target rv64 } } */
#include "ztt-scalar-bits-body.h"
/* { dg-final { scan-assembler-times {\tmand\.ew\.x\t} 56 } } */
/* { dg-final { scan-assembler-times {\tmandnot\.ew\.x\t} 56 } } */
/* { dg-final { scan-assembler-times {\tmor\.ew\.x\t} 56 } } */
/* { dg-final { scan-assembler-times {\tmornot\.ew\.x\t} 56 } } */
/* { dg-final { scan-assembler-times {\tmxor\.ew\.x\t} 56 } } */
/* { dg-final { scan-assembler-times {\tcsrw\tamestype,} 280 } } */
/* { dg-final { scan-assembler-not {\tmconv\.ew\t} } } */
