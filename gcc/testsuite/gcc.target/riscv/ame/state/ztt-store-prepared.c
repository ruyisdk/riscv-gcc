/* { dg-do compile } */
/* { dg-options "-O2 -g -dp -fno-ipa-icf -fdump-rtl-ztt_md_reuse -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m32-a16" { target rv32 } } */
/* { dg-options "-O2 -g -dp -fno-ipa-icf -fdump-rtl-ztt_md_reuse -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m32-a16" { target rv64 } } */
#include "ztt-store-prepared-body.h"
/* { dg-final { scan-rtl-dump-times "Reuse Md for typed store" 7 "ztt_md_reuse" } } */
/* { dg-final { scan-assembler-times { l=4\]  ztt_state_store_prepared_} 4 } } */
/* { dg-final { scan-assembler-times { l=4\]  ztt_state_memory_store_prepared_} 3 } } */
/* { dg-final { scan-assembler-times { l=72\]  ztt_group_state_store_} 3 } } */
