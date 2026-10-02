/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m32-a16" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m32-a16" { target rv64 } } */
#include "ztt-exponent-family-body.h"
/* { dg-final { scan-assembler-times {\tmldexp\.ew\.x\t} 5 } } */
/* { dg-final { scan-assembler-times {\tmldexpacc\.ew\.x\t} 5 } } */
/* { dg-final { scan-assembler-not {call[ \t]+__riscv_ztt_|amestype} } } */
