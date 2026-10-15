/* { dg-do compile } */
/* { dg-options "-O2 -mztt-profile=gcc-runtime-u32-m16-a4" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#include "ztt-scalar-args.h"
/* { dg-final { scan-assembler-times {\tmadd\.ew\.x\t} 6 } } */
/* { dg-final { scan-assembler-times {\tmmulacc\.ew\.x\t} 6 } } */
/* { dg-final { scan-assembler-not {call[ \t]+__riscv_ztt_} } } */
