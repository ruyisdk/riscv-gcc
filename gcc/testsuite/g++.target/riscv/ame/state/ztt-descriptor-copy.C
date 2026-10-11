/* { dg-do compile } */
/* { dg-options "-O2 -g -fcompare-debug -fdump-rtl-ztt_md_reuse -mztt-profile=gcc-runtime-u32-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#include "../../../../gcc.target/riscv/ame/state/ztt-descriptor-copy.h"
/* { dg-final { scan-rtl-dump-times "Reuse Md for typed store" 3 "ztt_md_reuse" } } */
/* { dg-final { scan-assembler-times {\tmsettyp\t} 7 } } */
/* { dg-final { scan-assembler-times {\tmmulacc\.ew\t} 1 } } */
/* { dg-final { scan-assembler-times {\tmss\.rm\t} 4 } } */
