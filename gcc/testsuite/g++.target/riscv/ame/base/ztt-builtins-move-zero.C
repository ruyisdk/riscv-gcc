/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv32gc_ztt -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv64gc_ztt -mabi=lp64 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv64 } } */

#include "../../../../gcc.target/riscv/ame/base/ztt-builtins-move-zero.h"

/* { dg-final { scan-assembler-times {\tm[a-z0-9.]+\tm15,zero,[ast][0-9]+} 10 } } */
/* { dg-final { scan-assembler-times {\tm[a-z0-9.]+\tm15,[ast][0-9]+,zero} 6 } } */
/* { dg-final { scan-assembler-times {\tm[a-z0-9.]+\tm15,zero,zero} 5 } } */
/* { dg-final { scan-assembler-times {\tmmove[0-9]+\.x\.m\t[ast][0-9]+,m15,zero} 8 } } */
/* { dg-final { scan-assembler-not {\tm[a-z0-9.]+\t[^ \n]*,0(,|\n)} } } */
