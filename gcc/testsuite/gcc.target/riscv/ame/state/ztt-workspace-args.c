/* { dg-do compile } */
/* { dg-options "-O2 -g -fno-ipa-icf -ffat-lto-objects -fdump-rtl-ztt_md_reuse -mztt-profile=gcc-runtime-u8-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#include "ztt-workspace-args.h"
/* { dg-final { scan-rtl-dump-times "Remove unused AME workspace" 15 "ztt_md_reuse" } } */
/* { dg-final { scan-assembler-times {\tsub\tsp,sp,} 6 } } */
/* { dg-final { scan-assembler-times {\tlb\t[^\n]*0\(s0\)} 1 } } */
/* { dg-final { scan-assembler-times {\tlbu\t[^\n]*0\(s0\)} 1 } } */
