/* mmul.ew.  */
/* { dg-do compile } */
/* { dg-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m32-a4" { target rv32 } } */
/* { dg-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m32-a4" { target rv64 } } */
#include "../../../../../../gcc.target/riscv/ame/matrix/mul/ztt-mmul-pressure-body.h"
/* { dg-final { scan-assembler-times {\tmmul\.ew\t} 9 } } */
/* { dg-final { scan-assembler {\tmss\.1r\t} } } */
/* { dg-final { scan-assembler {\tmls\.1r\t} } } */
