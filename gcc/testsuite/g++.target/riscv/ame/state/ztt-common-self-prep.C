/* { dg-do compile } */
/* { dg-options "-O2 -fcompare-debug -fno-ipa-icf -fdump-rtl-ztt_md_reuse -mztt-profile=gcc-runtime-u8-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#include "../../../../gcc.target/riscv/ame/state/ztt-common-self-prep.h"
/* { dg-final { scan-assembler-times {mldexpacc\.ew\.x\t} 8 } } */
/* { dg-final { scan-rtl-dump-times {Reuse Md for common preparation at insn [0-9]+: 2} 2 "ztt_md_reuse" } } */
