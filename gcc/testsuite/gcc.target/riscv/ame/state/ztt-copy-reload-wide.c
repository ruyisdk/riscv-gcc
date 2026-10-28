/* { dg-do compile } */
/* { dg-options "-O2 -g -fno-ipa-icf -fdump-rtl-ztt_md_reuse -mztt-profile=gcc-runtime-u8-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#include "ztt-copy-reload.h"
/* { dg-final { scan-rtl-dump-times "Prepare Md before copy reload" 6 "ztt_md_reuse" } } */
/* { dg-final { scan-assembler-times {mmulacc\.ew\s} 6 } } */
/* { dg-final { scan-assembler-times {mmul(?:add|sub|accneg)\.ew\s} 3 } } */
/* { dg-final { scan-assembler-times {mldexpacc\.ew\.x\s} 1 } } */
