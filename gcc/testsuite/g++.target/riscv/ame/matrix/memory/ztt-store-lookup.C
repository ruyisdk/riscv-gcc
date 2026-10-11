/* { dg-do compile } */
/* { dg-options "-fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m32-a4" { target rv32 } } */
/* { dg-options "-fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m32-a4" { target rv64 } } */
#include "../../../../../gcc.target/riscv/ame/matrix/memory/ztt-store-lookup-body.h"
/* { dg-final { scan-assembler {\tmss\.rm\t} } } */
/* { dg-final { scan-assembler {\tmss\.cm\t} } } */
/* { dg-final { scan-assembler {\tmss\.st\t} } } */
/* { dg-final { scan-assembler {\tmss\.tst\t} } } */
