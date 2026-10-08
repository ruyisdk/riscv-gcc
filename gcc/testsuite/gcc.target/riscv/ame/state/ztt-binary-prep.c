/* { dg-do compile } */
/* { dg-options "-O2 -g -dp -fno-ipa-icf -fdump-rtl-ztt_md_reuse -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m32-a16" { target rv32 } } */
/* { dg-options "-O2 -g -dp -fno-ipa-icf -fdump-rtl-ztt_md_reuse -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m32-a16" { target rv64 } } */
#include "ztt-binary-prep-body.h"
/* { dg-final { scan-rtl-dump {Reuse Md for binary at insn [0-9]+: sources 1} "ztt_md_reuse" } } */
/* { dg-final { scan-rtl-dump {Reuse Md for binary at insn [0-9]+: sources 2} "ztt_md_reuse" } } */
/* { dg-final { scan-rtl-dump {Reuse Md for binary at insn [0-9]+: sources 3} "ztt_md_reuse" } } */
/* { dg-final { scan-assembler { l=8\]  ztt_state_sub_prepared_} } } */
