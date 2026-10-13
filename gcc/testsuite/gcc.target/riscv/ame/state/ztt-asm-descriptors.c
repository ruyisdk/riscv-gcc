/* { dg-do compile } */
/* { dg-options "-O2 -g -fno-ipa-icf -ffat-lto-objects -fdump-rtl-ztt_md_reuse -mztt-profile=gcc-runtime-u32-m32-a16" } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
#include "ztt-asm-descriptors.h"
/* { dg-final { scan-assembler-times {madd\.ew\t} 9 } } */
/* { dg-final { scan-assembler-times {madd\.ew\.x\t} 2 } } */
/* { dg-final { scan-rtl-dump {Reuse Md for typed store} "ztt_md_reuse" } } */
