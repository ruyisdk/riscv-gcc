/* { dg-do compile } */
/* { dg-options "-g -fcompare-debug -fno-ipa-icf -mztt-profile=gcc-runtime-u8-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#include "../ztt-data-zero.h"
/* { dg-final { scan-assembler-times {\tm[a-z0-9]+\.ew\.x\tm[0-9]+,zero,m[0-9]+} 36 { target { no-opts "-O0" } } } } */
/* { dg-final { scan-assembler-not {\tm[a-z0-9]+\.ew\.x\tm[0-9]+,zero,m[0-9]+} { target { any-opts "-O0" } } } } */
/* { dg-final { scan-assembler-times {\tcsrw\tamestype,} 92 } } */
/* { dg-final { scan-assembler-times {\tmmul(acc|accneg|add|sub)\.ew\.x\t} 13 } } */
/* { dg-final { scan-assembler-not {\t(call|tail)\t__riscv_ztt_} } } */
