/* { dg-do compile } */
/* { dg-options "-O2 -g -fno-ipa-icf -fdump-rtl-ztt_md_reuse -mztt-profile=gcc-runtime-u32-m16-a4" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#include "ztt-spill-return.h"
#include "ztt-workspace-exits.h"
/* { dg-final { scan-rtl-dump-times {Remove unused AME workspace: [0-9]+ \* scale, insns [0-9]+ and [0-9]+ and [0-9]+} 1 "ztt_md_reuse" } } */
/* { dg-final { scan-rtl-dump-times "Compact scalar-spill AME workspace" 2 "ztt_md_reuse" } } */
