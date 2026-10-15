/* { dg-do compile } */
/* { dg-options "-O2 -g -fno-ipa-icf -mztt-profile=gcc-runtime-u8-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#include "ztt-andnot-combine.h"
/* { dg-final { scan-assembler-times {mandnot\.ew\t} 13 } } */
/* { dg-final { scan-assembler-times {mand\.ew\t} 2 } } */
/* { dg-final { scan-assembler-times {mor\.ew\t} 6 } } */
/* { dg-final { scan-assembler-times {mls\.rm\t} 32 } } */
/* { dg-final { scan-assembler-times {mss\.rm\t} 49 } } */
