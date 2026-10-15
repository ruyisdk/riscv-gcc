/* { dg-do compile } */
/* { dg-options "-O2 -g -dp -fno-ipa-icf -ffat-lto-objects -mztt-profile=gcc-runtime-u32-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#define DP_TYPE i8_rnu
#define DP_CARRIER signed char
#define DP_UNIT 1x4
#define DP_WHOLE 1x8
#define DP_ACC accx8
#include "../../../../gcc.target/riscv/ame/state/ztt-a2m-partial.h"
/* { dg-final { scan-assembler-times {l=12\] +ztt_acc_to_m_zttap4x8_[sd]i} 1 } } */
