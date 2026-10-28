/* { dg-do compile } */
/* { dg-options "-O2 -g -fno-ipa-icf -fdump-rtl-ztt_md_reuse -mztt-profile=gcc-runtime-u32-m16-a4" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#include "ztt-md-loop.h"
/* { dg-final { scan-rtl-dump-times "Clean dead AME scale after liveness update" 2 "ztt_md_reuse" } } */
/* { dg-final { scan-assembler {csrr\s+s11,amenlen} } } */
/* { dg-final { scan-assembler {ebreak} } } */
