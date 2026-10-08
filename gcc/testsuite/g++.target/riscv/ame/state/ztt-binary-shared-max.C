/* { dg-do compile } */
/* { dg-options "-O2 -g -dp -fno-ipa-icf -fdump-rtl-ztt_md_reuse -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m32-a16" { target rv32 } } */
/* { dg-options "-O2 -g -dp -fno-ipa-icf -fdump-rtl-ztt_md_reuse -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m32-a16" { target rv64 } } */
#include "../../../../gcc.target/riscv/ame/state/ztt-binary-shared-max.h"
/* { dg-final { scan-rtl-dump-times {Reuse Md for binary at insn [0-9]+: sources 2} 4 "ztt_md_reuse" } } */
/* { dg-final { scan-rtl-dump-times {Reuse Md for binary at insn [0-9]+: sources 3} 8 "ztt_md_reuse" } } */
