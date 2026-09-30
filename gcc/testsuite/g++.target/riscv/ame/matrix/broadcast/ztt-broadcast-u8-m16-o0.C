/* integer broadcast.  */
/* { dg-do compile } */
/* { dg-options "-O0 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O0 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv64 } } */
#include "../../../../../gcc.target/riscv/ame/matrix/broadcast/ztt-broadcast-body.h"
/* { dg-final { scan-assembler-times {\tmbcast\.m\.x\t} 53 } } */
/* { dg-final { scan-assembler-not {amestype|\tmbcast\.f\t} } } */
