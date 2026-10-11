/* { dg-do compile } */
/* { dg-options "-O2 -g -dp -fno-ipa-icf -fno-unroll-loops -fno-peel-loops -fdump-rtl-ztt_md_reuse -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -g -dp -fno-ipa-icf -fno-unroll-loops -fno-peel-loops -fdump-rtl-ztt_md_reuse -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv64 } } */
#include "ztt-md-branch.h"
/* { dg-final { scan-rtl-dump "Restore Md on branch edge" "ztt_md_reuse" } } */
/* { dg-final { scan-assembler {msub\.ew} } } */
/* { dg-final { scan-assembler {mcolbcast\.ew\.x} } } */
