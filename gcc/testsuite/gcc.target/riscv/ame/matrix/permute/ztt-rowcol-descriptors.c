/* { dg-do compile } */
/* { dg-options "-O2 -g -fcompare-debug -fno-ipa-icf -fdump-rtl-ztt_md_reuse -mztt-profile=gcc-runtime-u32-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#include "ztt-rowcol-descriptors.h"
/* { dg-final { scan-rtl-dump "Reuse descriptors after workspace cleanup" "ztt_md_reuse" } } */
/* { dg-final { scan-assembler-times {\tm(row|col)(bcast|shift)\.ew\.x\t} 29 } } */
/* { dg-final { scan-assembler-times {\tmadd\.ew\t} 14 } } */
