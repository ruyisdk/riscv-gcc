/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -ffat-lto-objects -fdump-rtl-ztt_md_reuse -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m32-a16" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -ffat-lto-objects -fdump-rtl-ztt_md_reuse -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m32-a16" { target rv64 } } */
#include "../types/large-groups/ztt-wide-copy.h"
/* { dg-final { scan-rtl-dump {Drop interleaved raw reload} "ztt_md_reuse" } } */
/* { dg-final { scan-assembler-times {\tmadd\.ew\t} 3 } } */
/* { dg-final { scan-assembler-times {\tmmul\.ew\t} 1 } } */
/* { dg-final { scan-assembler-times {\tmldexpacc\.ew\.x\t} 3 } } */
