/* { dg-do compile } */
/* { dg-options "-O2 -g -fdump-rtl-ztt_md_reuse -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -g -fdump-rtl-ztt_md_reuse -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv64 } } */
#include "ztt-stack-call.h"
/* { dg-final { scan-rtl-dump "Rebase AME stack address" "ztt_md_reuse" } } */
/* { dg-final { scan-assembler "call\tstack_limit" } } */
/* { dg-final { scan-assembler "jalr\t" } } */
