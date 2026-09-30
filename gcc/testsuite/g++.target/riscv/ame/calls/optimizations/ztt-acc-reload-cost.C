/* { dg-do compile } */
/* { dg-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u64-m32-a16" { target rv32 } } */
/* { dg-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u64-m32-a16" { target rv64 } } */
#include "../../../../../gcc.target/riscv/ame/calls/ztt-acc-reload-cost.h"
/* { dg-final { scan-assembler-times {mmulacc\.2d\s+} 1 } } */
/* { dg-final { scan-assembler-times {mmulbtaccneg\.2d\s+} 1 } } */
