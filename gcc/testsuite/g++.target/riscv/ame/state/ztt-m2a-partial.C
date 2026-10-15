/* { dg-do compile } */
/* { dg-options "-O2 -g -dp -fno-ipa-icf -ffat-lto-objects -mztt-profile=gcc-runtime-u32-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#include "../../../../gcc.target/riscv/ame/state/ztt-m2a-partial.h"
/* { dg-final { scan-assembler-times {l=28\] +ztt_acc_from_m_zttar1x2_[sd]i} 2 } } */
