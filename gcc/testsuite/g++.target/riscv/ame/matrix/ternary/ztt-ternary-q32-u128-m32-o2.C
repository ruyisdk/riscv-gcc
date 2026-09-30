/* old-destination arithmetic.  */
/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u128-m32-a4" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u128-m32-a4" { target rv64 } } */
#define TEST_Q32 1
#include "../../../../../gcc.target/riscv/ame/matrix/ternary/ztt-ternary-body.h"
/* { dg-final { scan-assembler {\tmmulacc\.ew\t} } } */
/* { dg-final { scan-assembler {\tmmulaccneg\.ew\t} } } */
/* { dg-final { scan-assembler {\tmmuladd\.ew\t} } } */
/* { dg-final { scan-assembler {\tmmulsub\.ew\t} } } */
/* { dg-final { scan-assembler-not {amestype|\tmmul[a-z]*\.ew\.x\t} } } */
