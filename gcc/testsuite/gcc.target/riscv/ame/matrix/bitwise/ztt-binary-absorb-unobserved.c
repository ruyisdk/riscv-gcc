/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -ffat-lto-objects -mztt-profile=gcc-runtime-u8-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#define BR_OBSERVE 0
#include "ztt-binary-absorb.h"
/* { dg-final { scan-assembler-times {mmin\.ew\t} 14 } } */
/* { dg-final { scan-assembler-times {mmax\.ew\t} 15 } } */
/* { dg-final { scan-assembler-times {mand\.ew\t} 5 } } */
/* { dg-final { scan-assembler-times {mor\.ew\t} 5 } } */
/* { dg-final { scan-assembler-times {mls\.rm\t} 40 } } */
/* { dg-final { scan-assembler-times {mss\.rm\t} 20 } } */
