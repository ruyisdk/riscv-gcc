/* { dg-do compile } */
/* { dg-options "-O2 -g -fno-ipa-icf -mztt-profile=gcc-runtime-u32-m32-a16 -fdump-rtl-ztt_md_reuse" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
/* { dg-final { scan-assembler-times {\tmconv\.ew\s} 6 } } */
/* { dg-final { scan-assembler-times {\tmmul\.ew\s} 2 } } */
/* { dg-final { scan-assembler-times {\tmmulacc\.ew\s} 1 } } */
/* { dg-final { scan-rtl-dump "Prepare Md before unary reload" "ztt_md_reuse" } } */
#include "ztt-reload-packets.h"
