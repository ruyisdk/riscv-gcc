/* { dg-do compile } */
/* { dg-options "-O2 -dp -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m32-a16" { target rv32 } } */
/* { dg-options "-O2 -dp -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m32-a16" { target rv64 } } */
#include "ztt-acc-prep-wide.h"
/* Single-ACC wide sources are prepared; the other groups stay intact.  */
/* { dg-final { scan-assembler-times { l=8\]  ztt_acc_from_m_} 2 } } */
/* { dg-final { scan-assembler-times { l=56\]  ztt_acc_from_m_} 1 } } */
/* { dg-final { scan-assembler-times { l=24\]  ztt_acc_from_m_} 1 } } */
