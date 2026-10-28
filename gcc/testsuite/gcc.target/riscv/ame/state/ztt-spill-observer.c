/* { dg-do compile } */
/* { dg-options "-O2 -g -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m32-a16 -fdump-rtl-ztt_md_reuse" { target rv32 } } */
/* { dg-options "-O2 -g -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m32-a16 -fdump-rtl-ztt_md_reuse" { target rv64 } } */
#include "ztt-spill-observer.h"
/* { dg-final { scan-rtl-dump-times "Drop dead private spill" 16 "ztt_md_reuse" } } */
/* { dg-final { scan-assembler-times {\tmrowscatadd\.ew\t} 13 } } */
/* { dg-final { scan-assembler {\tfence\trw,rw} } } */
