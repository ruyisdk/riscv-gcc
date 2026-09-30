/* distinct in/out M objects.  */
/* { dg-do compile } */
/* { dg-options "-O0 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m32-a4" { target rv32 } } */
/* { dg-options "-O0 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m32-a4" { target rv64 } } */
#include "../../../../../gcc.target/riscv/ame/matrix/zip/ztt-zip-pressure-body.h"
/* { dg-final { scan-assembler-times {\tmcolzip\.ew\t} 1 } } */
/* { dg-final { scan-assembler-times {\tmrowzip\.ew\t} 1 } } */
/* { dg-final { scan-assembler-times {\tmcolunzip\.ew\t} 1 } } */
/* { dg-final { scan-assembler-times {\tmrowunzip\.ew\t} 1 } } */
