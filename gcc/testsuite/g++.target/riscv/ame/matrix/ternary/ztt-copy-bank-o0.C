/* { dg-do compile } */
/* { dg-options "-O0 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a16" { target rv32 } } */
/* { dg-options "-O0 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a16" { target rv64 } } */
#include "../../../../../gcc.target/riscv/ame/matrix/ternary/ztt-copy-bank-source.h"
/* { dg-final { scan-assembler-times {\tmmulacc\.ew\t} 5 } } */
/* { dg-final { scan-assembler-times {\tmmulsub\.ew\t} 1 } } */
