/* { dg-do compile } */
/* { dg-options "-O2 -g -fno-ipa-icf -fdump-rtl-ztt_md_reuse -mztt-profile=gcc-runtime-u32-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#define AR_TYPE i8_rnu
#define AR_ELEMENT __INT8_TYPE__
#define AR_K 8
#include "ztt-reload-acc.h"
/* { dg-final { scan-rtl-dump "Prepare Md before ACC reload .*packet 1" "ztt_md_reuse" } } */
/* { dg-final { scan-assembler {\tasettyp\tacc7,} } } */
