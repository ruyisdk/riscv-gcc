/* { dg-do compile } */
/* { dg-options "-O2 -g -dp -fno-ipa-icf -fdump-rtl-ztt_md_reuse -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m32-a16" { target rv32 } } */
/* { dg-options "-O2 -g -dp -fno-ipa-icf -fdump-rtl-ztt_md_reuse -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m32-a16" { target rv64 } } */
#include "ztt-mmul-prepared-body.h"
/* { dg-final { scan-rtl-dump-not {Reuse Md at insn [0-9]+: sources 1} "ztt_md_reuse" } } */
/* { dg-final { scan-rtl-dump-not {Reuse Md at insn [0-9]+: sources 2} "ztt_md_reuse" } } */
/* { dg-final { scan-rtl-dump-times {Reuse Md at insn [0-9]+: sources 3} 8 "ztt_md_reuse" } } */
/* { dg-final { scan-rtl-dump-not {Drop unused Md descriptor at insn [0-9]+} "ztt_md_reuse" } } */
/* { dg-final { scan-assembler-times { l=4\]  ztt_acc_mmul_prepared_} 8 } } */
/* { dg-final { scan-assembler-not { l=72\]  ztt_acc_mmul_} } } */
/* { dg-final { scan-assembler-not { l=140\]  ztt_acc_mmul_} } } */
/* { dg-final { scan-rtl-dump "DCE: Deleting insn" "ztt_md_reuse" } } */
