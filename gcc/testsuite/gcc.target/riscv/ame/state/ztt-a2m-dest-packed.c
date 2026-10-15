/* { dg-do compile } */
/* { dg-options "-O2 -g -dp -fno-ipa-icf -ffat-lto-objects -fdump-rtl-ztt_md_reuse -mztt-profile=gcc-runtime-u32-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#define AD_TYPE i8_rnu
#define AD_ALT i8_rod
#define AD_CARRIER signed char
#define AD_SHAPE 1x8
#define AD_ACC accx8
#include "ztt-a2m-dest.h"
/* { dg-final { scan-rtl-dump-times "Reuse Md for ACC-to-M" 4 "ztt_md_reuse" } } */
/* { dg-final { scan-assembler-times {l=8\] +ztt_acc_to_m_zttap4x8_[sd]i} 4 } } */
