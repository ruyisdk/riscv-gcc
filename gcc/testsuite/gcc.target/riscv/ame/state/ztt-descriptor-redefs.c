/* { dg-do compile } */
/* { dg-options "-O2 -g -fcompare-debug -fno-ipa-icf -fdump-rtl-ztt_md_reuse -mztt-profile=gcc-runtime-u32-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#include "ztt-descriptor-redefs.h"
/* { dg-final { scan-rtl-dump "Drop repeated descriptor definition" "ztt_md_reuse" } } */
/* { dg-final { scan-assembler-times {\tm(add|sub|min|max|and|andnot|or|ornot|xor)\.ew\t} 45 } } */
