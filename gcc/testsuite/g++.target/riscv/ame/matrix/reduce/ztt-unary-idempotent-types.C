/* { dg-do compile } */
/* { dg-options "-O2 -mztt-profile=gcc-runtime-u8-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#include "../../../../../gcc.target/riscv/ame/matrix/reduce/ztt-unary-idempotent-types.h"
/* { dg-final { scan-assembler-times {mabs\.ew\t} 3 } } */
