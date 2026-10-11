/* { dg-do compile } */
/* { dg-options "-O2 -mztt-profile=gcc-runtime-u32-m32-a16" } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */

#include "../../../../../gcc.target/riscv/ame/matrix/permute/ztt-rowcol-control.h"

/* { dg-final { scan-assembler-times {m(row|col)bcast\.ew\.x} 4 } } */
/* { dg-final { scan-assembler-not {\ts[rl]li\t[^\n]*,32} } } */
