/* { dg-do compile } */
/* { dg-options "-O2 -dp -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m32-a16" { target rv32 } } */
/* { dg-options "-O2 -dp -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m32-a16" { target rv64 } } */
#include "../../../../../gcc.target/riscv/ame/acc/matmul/ztt-acc-prep-wide.h"
/* Reuse prepared sources for single, continuous and packed ACC groups.  */
/* { dg-final { scan-assembler-times { l=8\]  ztt_acc_from_m_} 2 } } */
/* { dg-final { scan-assembler-times { l=16\]  ztt_acc_from_m_} 1 } } */
/* { dg-final { scan-assembler-times { l=12\]  ztt_acc_from_m_} 1 } } */
