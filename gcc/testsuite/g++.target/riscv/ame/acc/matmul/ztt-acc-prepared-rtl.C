/* { dg-do compile } */
/* { dg-options "-O2 -g -dp -fno-ipa-icf -fdump-rtl-ztt_md_reuse -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m32-a16" { target rv32 } } */
/* { dg-options "-O2 -g -dp -fno-ipa-icf -fdump-rtl-ztt_md_reuse -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m32-a16" { target rv64 } } */
#include "../../../../../gcc.target/riscv/ame/acc/matmul/ztt-acc-prep-body.h"
/* { dg-final { scan-rtl-dump-times "Reuse Md for ACC move" 1 "ztt_md_reuse" } } */
/* { dg-final { scan-rtl-dump "DCE: Deleting insn" "ztt_md_reuse" } } */
/* { dg-final { scan-assembler-times { l=8\]  ztt_acc_from_m_prepared_} 1 } } */
/* { dg-final { scan-assembler-times { l=76\]  ztt_acc_from_m_zttar4_} 3 } } */
