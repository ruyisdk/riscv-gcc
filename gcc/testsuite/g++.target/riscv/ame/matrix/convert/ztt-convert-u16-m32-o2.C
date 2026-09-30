/* mconv.ew.  */
/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u16-m32-a4" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u16-m32-a4" { target rv64 } } */
#include "../../../../../gcc.target/riscv/ame/matrix/convert/ztt-convert-body.h"
/* { dg-final { scan-assembler-times {\tmconv\.ew\t} 15 } } */
/* { dg-final { scan-assembler-not {amestype|\tmconv\.ew\.x\t} } } */
