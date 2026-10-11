/* { dg-do compile } */
/* { dg-options "-g -fcompare-debug -fno-ipa-icf -mztt-profile=gcc-runtime-u32-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#include "../ztt-scalar-type.h"
/* { dg-final { scan-assembler-times {\tcsrw\tamestype,} 26 { target { no-opts "-O0" } } } } */
/* { dg-final { scan-assembler-times {\tcsrw\tamestype,} 36 { target { any-opts "-O0" } } } } */
/* { dg-final { scan-assembler-not {\tcsrw\tamestype,zero} } } */
/* { dg-final { scan-assembler-not {\t(call|tail)\t__riscv_ztt_} } } */
