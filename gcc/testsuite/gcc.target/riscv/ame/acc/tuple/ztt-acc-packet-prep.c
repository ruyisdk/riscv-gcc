/* { dg-do compile } */
/* { dg-options "-O2 -dp -fno-ipa-icf -fdump-rtl-ztt_md_reuse -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m32-a16" { target rv32 } } */
/* { dg-options "-O2 -dp -fno-ipa-icf -fdump-rtl-ztt_md_reuse -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m32-a16" { target rv64 } } */
#include "ztt-acc-packet-prep.h"
/* { dg-final { scan-rtl-dump-times "Reuse Md for ACC move" 11 "ztt_md_reuse" } } */
/* { dg-final { scan-assembler-times "ztt_acc_from_m_prepared_" 11 } } */
