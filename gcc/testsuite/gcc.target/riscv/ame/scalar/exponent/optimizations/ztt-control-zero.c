/* { dg-do compile } */
/* { dg-options "-g -fcompare-debug -fno-ipa-icf -mztt-profile=gcc-runtime-u8-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#include "../ztt-control-zero.h"
/* { dg-final { scan-assembler-times {ms(ll|rl|ra)\.ew\.x\tm[0-9]+,zero,m[0-9]+} 6 } } */
/* { dg-final { scan-assembler-times {mldexp\.ew\.x\tm[0-9]+,zero,m[0-9]+} 6 } } */
/* { dg-final { scan-assembler-times {mldexpacc\.ew\.x\tm[0-9]+,zero,m[0-9]+} 5 } } */
/* { dg-final { scan-assembler-times {madd\.ew\.x\tm[0-9]+,zero,} 1 { target { no-opts "-O0" } } } } */
/* { dg-final { scan-assembler-not {madd\.ew\.x\tm[0-9]+,zero,} { target { any-opts "-O0" } } } } */
/* { dg-final { scan-assembler-not {\t(call|tail)\t__riscv_ztt_} } } */
