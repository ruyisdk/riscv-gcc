/* { dg-do compile } */
/* { dg-options "-std=gnu++17 -O2 --param ggc-min-expand=0 --param ggc-min-heapsize=0 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a1" { target rv32 } } */
/* { dg-options "-std=gnu++17 -O2 --param ggc-min-expand=0 --param ggc-min-heapsize=0 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a1" { target rv64 } } */
#include "../../../../gcc.target/riscv/ame/typed/ztt-registration-attributes-body.h"
/* { dg-final { scan-assembler-times {\tmmul\.ew\t} 1 } } */
/* { dg-final { scan-assembler-not {__builtin_riscv_ztt} } } */
