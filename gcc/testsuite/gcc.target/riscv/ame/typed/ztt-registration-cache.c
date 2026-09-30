/* registration.  */
/* { dg-do compile } */
/* { dg-options "-std=gnu11 -O2 -fno-ipa-icf --param ggc-min-expand=0 --param ggc-min-heapsize=0 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv32 } } */
/* { dg-options "-std=gnu11 -O2 -fno-ipa-icf --param ggc-min-expand=0 --param ggc-min-heapsize=0 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv64 } } */
#include "ztt-registration-body.h"
/* { dg-final { scan-assembler-times {\tmbcast\.m\.x\t} 49 } } */
/* { dg-final { scan-assembler-not {amestype|__builtin_riscv_ztt} } } */
