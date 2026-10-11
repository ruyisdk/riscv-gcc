/* Identical-source mul preparation.  */
/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv64 } } */
#include "../../../../../gcc.target/riscv/ame/matrix/mul/ztt-shared-source-body.h"
/* { dg-final { scan-assembler-times {\tmmul\.ew\t} 4 } } */
/* { dg-final { scan-assembler-times {\tmsettyp\t} 9 } } */
/* { dg-final { scan-assembler-not {\tmss\.1r\t} } } */
/* { dg-final { scan-assembler-not {\tmls\.1r\t} } } */
/* { dg-final { scan-assembler-times {\tmls\.rm\t} 5 } } */
/* { dg-final { scan-assembler-times {\tmss\.rm\t} 9 } } */
