/* { dg-do compile } */
/* { dg-options "-O2 -fdump-rtl-ztt_md_reuse -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u16-m32-a16" { target rv32 } } */
/* { dg-options "-O2 -fdump-rtl-ztt_md_reuse -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u16-m32-a16" { target rv64 } } */
#define RS_ONLY_MUL
#define RS_TYPE f32_rne
#define RS_ELEMENT float
#include "ztt-reload-shared.h"
/* { dg-final { scan-assembler-times {\tmmul\.ew\t} 1 } } */
/* { dg-final { scan-rtl-dump-times "Prepare Md before private reload" 1 "ztt_md_reuse" } } */
