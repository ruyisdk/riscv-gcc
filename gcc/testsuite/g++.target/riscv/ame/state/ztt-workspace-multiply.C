/* { dg-do compile } */
/* { dg-options "-O2 -g -fno-ipa-icf -fdump-rtl-ztt_md_reuse -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -g -fno-ipa-icf -fdump-rtl-ztt_md_reuse -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv64 } } */
#include "../../../../gcc.target/riscv/ame/matrix/mul/ztt-shared-source-body.h"
/* { dg-final { scan-rtl-dump-times "Remove unused AME workspace: 48" 1 "ztt_md_reuse" } } */
/* { dg-final { scan-rtl-dump-times "Remove unused AME workspace: 80" 1 "ztt_md_reuse" } } */
/* { dg-final { scan-assembler-not {\tsub\tsp,sp,} } } */
/* { dg-final { scan-assembler-times {\tmmul\.ew\t} 4 } } */
/* { dg-final { scan-assembler-times {\tmls\.rm\t} 5 } } */
/* { dg-final { scan-assembler-times {\tmss\.rm\t} 9 } } */
