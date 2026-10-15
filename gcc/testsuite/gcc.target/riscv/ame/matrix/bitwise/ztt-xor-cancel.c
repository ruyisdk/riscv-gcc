/* { dg-do compile } */
/* { dg-options "-O2 -g -fno-ipa-icf -mztt-profile=gcc-runtime-u8-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#include "ztt-xor-cancel.h"
/* { dg-final { scan-assembler-times {mxor\.ew\t} 11 } } */
/* { dg-final { scan-assembler-times {mand\.ew\t} 1 } } */
/* { dg-final { scan-assembler-times {mls\.rm\t} 26 } } */
/* { dg-final { scan-assembler-times {mss\.rm\t} 39 } } */
