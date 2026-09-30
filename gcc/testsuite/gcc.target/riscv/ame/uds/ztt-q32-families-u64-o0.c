/* Q32.  */
/* { dg-do compile } */
/* { dg-options "-O0 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u64-m16-a4" { target rv32 } } */
/* { dg-options "-O0 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u64-m16-a4" { target rv64 } } */
#include "ztt-q32-families-body.h"
/* { dg-final { scan-assembler-times {\tmadd\.ew\t} 80 } } */
/* { dg-final { scan-assembler-times {\tmsub\.ew\t} 80 } } */
/* { dg-final { scan-assembler-times {\tmmin\.ew\t} 80 } } */
/* { dg-final { scan-assembler-times {\tmmax\.ew\t} 80 } } */
/* { dg-final { scan-assembler-times {\tmand\.ew\t} 80 } } */
/* { dg-final { scan-assembler-times {\tmandnot\.ew\t} 80 } } */
/* { dg-final { scan-assembler-times {\tmor\.ew\t} 80 } } */
/* { dg-final { scan-assembler-times {\tmornot\.ew\t} 80 } } */
/* { dg-final { scan-assembler-times {\tmxor\.ew\t} 80 } } */
/* { dg-final { scan-assembler-not {amestype} } } */
