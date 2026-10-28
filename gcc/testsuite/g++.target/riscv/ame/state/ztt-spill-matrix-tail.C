/* { dg-do compile } */
/* { dg-options "-O2 -g -ffat-lto-objects -fdump-rtl-ztt_md_reuse -mztt-profile=gcc-runtime-u32-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#include "../../../../gcc.target/riscv/ame/state/ztt-spill-matrix-tail.h"
/* { dg-final { scan-rtl-dump-times "Drop dead private spill" 2 "ztt_md_reuse" } } */
/* { dg-final { scan-assembler-not {\tmss\.1r\t} } } */
/* { dg-final { scan-assembler-times {\tmcolscatadd\.ew\t} 1 } } */
/* { dg-final { scan-assembler-times {\tmss\.rm\t} 2 } } */
