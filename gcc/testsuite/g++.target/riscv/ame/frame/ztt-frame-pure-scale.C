/* { dg-do compile } */
/* { dg-options "-O2 -g -fcompare-debug -mztt-profile=gcc-runtime-u8-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#include "../../../../gcc.target/riscv/ame/frame/ztt-frame-pure-scale.h"
/* { dg-final { scan-assembler-not {li\s+[a-z][a-z0-9]*,0\n} } } */
/* { dg-final { scan-assembler {sub\s+sp,sp,} } } */
/* { dg-final { scan-assembler-times {mss\.rm\t} 1 } } */
/* { dg-final { scan-assembler {\.cfi_def_cfa 8, 0} } } */
