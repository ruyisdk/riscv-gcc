/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m32-a16" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m32-a16" { target rv64 } } */
#include "../../../../../gcc.target/riscv/ame/matrix/construct/ztt-index-range.h"
/* { dg-final { scan-assembler-times {csrr[^\n]*amenlen} 42 { target { rv32 } } } } */
/* { dg-final { scan-assembler-times {csrr[^\n]*amenlen} 50 { target { rv64 } } } } */
/* { dg-final { scan-assembler-times {\tmrowid\.ew\t} 26 } } */
/* { dg-final { scan-assembler-times {\tmcolid\.ew\t} 8 } } */
