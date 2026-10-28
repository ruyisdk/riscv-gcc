/* { dg-do compile } */
/* { dg-options "-O2 -g -fno-ipa-icf -fdump-rtl-ztt_md_reuse -mztt-profile=gcc-runtime-u8-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#include "ztt-reload-unary.h"
/* { dg-final { scan-rtl-dump-times "Prepare Md before unary reload" 6 "ztt_md_reuse" } } */
/* { dg-final { scan-assembler-times {\tmabs\.ew\t} 5 } } */
/* { dg-final { scan-assembler-times {\tmconv\.ew\t} 2 } } */
/* { dg-final { scan-assembler-times {\tmreducemax\.row\t} 1 } } */
/* { dg-final { scan-assembler-times {\tmprefixmax\.col\t} 1 } } */
