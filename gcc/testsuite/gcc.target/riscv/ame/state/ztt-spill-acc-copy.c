/* { dg-do compile } */
/* { dg-options "-O2 -g -fno-ipa-icf -ffat-lto-objects -fdump-rtl-ztt_md_reuse -mztt-profile=gcc-runtime-u8-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#include "ztt-spill-acc-copy.h"
/* { dg-final { scan-rtl-dump-times "Drop interleaved raw reload" 335 "ztt_md_reuse" } } */
/* { dg-final { scan-rtl-dump-times "Drop dead private spill" 288 "ztt_md_reuse" { target rv32 } } } */
/* { dg-final { scan-rtl-dump-times "Drop dead private spill" 296 "ztt_md_reuse" { target rv64 } } } */
/* { dg-final { scan-rtl-dump-times "Remove unused AME workspace" 19 "ztt_md_reuse" } } */
/* { dg-final { scan-rtl-dump-times "Drop dead scalar private spill" 3 "ztt_md_reuse" } } */
/* { dg-final { scan-rtl-dump "Drop ACC copy scale" "ztt_md_reuse" } } */
/* { dg-final { scan-assembler-times {\tsub\tsp,sp,} 5 } } */
/* { dg-final { scan-assembler-times {\tmmulacc\.2d\t} 6 } } */
/* { dg-final { scan-assembler-times {\tmmulaccneg\.2d\t} 2 } } */
/* { dg-final { scan-assembler {\tagettyp\t} } } */
