/* { dg-do compile } */
/* { dg-options "-O2 -fnon-call-exceptions -fdump-rtl-ztt_md_reuse -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m32-a16" { target rv32 } } */
/* { dg-options "-O2 -fnon-call-exceptions -fdump-rtl-ztt_md_reuse -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m32-a16" { target rv64 } } */
#define RS_ONLY_MUL
#define RS_TYPE i32_rnu
#define RS_ELEMENT __INT32_TYPE__
#include "ztt-reload-shared.h"
/* { dg-final { scan-assembler-times {\tmmul\.ew\t} 1 } } */
/* { dg-final { scan-rtl-dump-not "Prepare Md before private reload" "ztt_md_reuse" } } */
