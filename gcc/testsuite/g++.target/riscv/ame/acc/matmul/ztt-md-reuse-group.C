/* { dg-do compile } */
/* { dg-options "-O2 -dp -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m32-a16" { target rv32 } } */
/* { dg-options "-O2 -dp -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m32-a16" { target rv64 } } */
#include "../../../../../gcc.target/riscv/ame/acc/matmul/ztt-acc-shared-source-body.h"
/* { dg-final { scan-assembler-times { l=4\]  ztt_acc_mmul_} 18 } } */
/* { dg-final { scan-assembler-times { l=72\]  ztt_acc_mmul_} 6 } } */
