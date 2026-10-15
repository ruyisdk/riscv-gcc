/* { dg-do compile } */
/* { dg-options "-O2 --param ggc-min-expand=0 --param ggc-min-heapsize=0 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a1" { target rv32 } } */
/* { dg-options "-O2 --param ggc-min-expand=0 --param ggc-min-heapsize=0 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a1" { target rv64 } } */
#include "../../../../gcc.target/riscv/ame/typed/ztt-nominal-pages.h"
/* { dg-final { scan-assembler-times {mbcast\.m\.x} 16 } } */
/* { dg-final { scan-assembler-not {call[ \t]+__riscv_ztt_} } } */
