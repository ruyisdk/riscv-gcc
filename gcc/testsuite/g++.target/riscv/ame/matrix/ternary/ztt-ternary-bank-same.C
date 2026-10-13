/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a16" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a16" { target rv64 } } */
#define BK_TYPE i64_rnu
#define BK_CARRIER __INT64_TYPE__
#define BY_TYPE i64_rnu
#define BY_CARRIER __INT64_TYPE__
#include "../../../../../gcc.target/riscv/ame/matrix/ternary/ztt-ternary-bank-source.h"
/* { dg-final { scan-assembler-times {\tmmulacc\.ew\t} 5 } } */
/* { dg-final { scan-assembler-times {\tmmulsub\.ew\t} 1 } } */
