/* { dg-do compile } */
/* { dg-options "-O2 -dp -fno-ipa-icf -fdump-rtl-ztt_md_reuse -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m32-a16" { target rv32 } } */
/* { dg-options "-O2 -dp -fno-ipa-icf -fdump-rtl-ztt_md_reuse -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m32-a16" { target rv64 } } */
#include "../../../../../gcc.target/riscv/ame/acc/matmul/ztt-md-reuse-body.h"
/* { dg-final { scan-rtl-dump-times "Reuse Md at insn .*: sources 3" 1 "ztt_md_reuse" } } */
/* { dg-final { scan-assembler-times { l=4\]  ztt_acc_mmul_} 1 } } */
/* { dg-final { scan-assembler-times { l=28\]  ztt_acc_mmul_} 3 } } */
