/* { dg-do compile } */
/* { dg-options "-O2 -g -fno-ipa-icf -ffat-lto-objects -fdump-rtl-ztt_md_reuse -mztt-profile=gcc-runtime-u8-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#include "ztt-spill-construct-tail.h"
/* { dg-final { scan-rtl-dump-times "Drop dead private spill" 256 "ztt_md_reuse" { target rv32 } } } */
/* { dg-final { scan-rtl-dump-times "Drop dead private spill" 232 "ztt_md_reuse" { target rv64 } } } */
/* { dg-final { scan-rtl-dump-times "Remove unused AME workspace" 17 "ztt_md_reuse" { target rv32 } } } */
/* { dg-final { scan-rtl-dump-times "Remove unused AME workspace" 15 "ztt_md_reuse" { target rv64 } } } */
/* { dg-final { scan-assembler-times {\tmbcast\.m\.x\t} 1 } } */
/* { dg-final { scan-assembler-times {\tmrowid\.ew\t} 1 } } */
/* { dg-final { scan-assembler-times {\tmcolid\.ew\t} 1 } } */
