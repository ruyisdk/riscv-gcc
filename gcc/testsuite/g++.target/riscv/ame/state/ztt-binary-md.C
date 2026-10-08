/* { dg-do compile } */
/* { dg-options "-O2 -g -dp -fno-ipa-icf -fdump-rtl-ztt_md_reuse -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m32-a16" { target rv32 } } */
/* { dg-options "-O2 -g -dp -fno-ipa-icf -fdump-rtl-ztt_md_reuse -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m32-a16" { target rv64 } } */
#include "../../../../gcc.target/riscv/ame/state/ztt-binary-md-body.h"
/* { dg-final { scan-rtl-dump-times "Reuse Md for typed store" 50 "ztt_md_reuse" } } */
/* { dg-final { scan-rtl-dump-times "Reuse Md for ACC move" 1 "ztt_md_reuse" } } */
/* { dg-final { scan-assembler-times { l=4\]  ztt_state_store_prepared_} 50 } } */
/* { dg-final { scan-assembler-times { l=16\]  ztt_state_store_} 7 } } */
