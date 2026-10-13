/* { dg-do compile } */
/* { dg-options "-O2 -g -dp -fno-ipa-icf -ffat-lto-objects -mztt-profile=gcc-runtime-u8-m16-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#include "ztt-memory-load-md.h"
/* { dg-final { scan-assembler-times {\tmls\.cm\t} 7 } } */
/* { dg-final { scan-assembler-times {\tmls\.st\t} 7 } } */
/* { dg-final { scan-assembler-times {\tmls\.tst\t} 7 } } */
/* { dg-final { scan-assembler-times {l=4\] +ztt_state_memory_load_} 3 } } */
