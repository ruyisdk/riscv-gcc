/* single-M
   i8 integer rounding-mode subset.  */
/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -fdump-rtl-ztt_state -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-p0-n128-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -fdump-rtl-ztt_state -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-p0-n128-u8-m16-a4" { target rv64 } } */

#include "ztt-irm-mixed.h"

/* { dg-final { scan-rtl-dump "UNSPECV_ZTT_STATE_STORE" "ztt_state" } } */
/* { dg-final { scan-assembler-not "mmov\\.m\\.m" } } */
/* { dg-final { scan-assembler "mss\\.1r" } } */
/* { dg-final { scan-assembler "mls\\.1r" } } */
/* { dg-final { scan-rtl-dump "UNSPECV_ZTT_STATE_ADD" "ztt_state" } } */
/* { dg-final { scan-assembler-not {\tm[a-z0-9.]+\t[^\n]*\mm(1[6-9]|2[0-9]|3[01])\M} } } */
