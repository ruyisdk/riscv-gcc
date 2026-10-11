/* { dg-do compile } */
/* { dg-options "-O2 -g -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m32-a16 -fdump-rtl-ztt_md_reuse" { target { rv64 } } } */
/* { dg-options "-O2 -g -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m32-a16 -fdump-rtl-ztt_md_reuse" { target { rv32 } } } */

#include "../../../../gcc.target/riscv/ame/state/ztt-scalar-descriptors.h"

/* { dg-final { scan-rtl-dump-times "Reuse typed descriptors at insn \[0-9\]+: 0x1\[048c\]" 4 "ztt_md_reuse" } } */
/* { dg-final { scan-assembler-times {\tcsrw\tamestype,} 29 } } */
