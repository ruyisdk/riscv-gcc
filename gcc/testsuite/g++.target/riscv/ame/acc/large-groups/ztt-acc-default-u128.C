/* { dg-do compile } */
/* { dg-options "-std=gnu++17 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u128-m32-a16" { target rv32 } } */
/* { dg-options "-std=gnu++17 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u128-m32-a16" { target rv64 } } */
#include "../../../../../gcc.target/riscv/ame/acc/large-groups/ztt-acc-default.h"
/* { dg-final { scan-assembler-not {\t(call|tail)\t__riscv_ztt_} } } */
