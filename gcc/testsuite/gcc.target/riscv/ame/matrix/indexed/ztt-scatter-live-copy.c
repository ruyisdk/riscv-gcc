/* { dg-do compile } */
/* { dg-options "-O2 -g -fno-ipa-icf -ffat-lto-objects -fdump-rtl-ztt_state -mztt-profile=gcc-runtime-u8-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#include "ztt-scatter-live-copy.h"
/* { dg-final { scan-rtl-dump-times {UNSPECV_ZTT_STATE_COPY} 5 "ztt_state" } } */
/* { dg-final { scan-assembler-times {mmov\.m\.m} 5 } } */
/* { dg-final { scan-assembler-times {mcolscatadd\.ew} 6 } } */
/* { dg-final { scan-assembler-times {mrowscatadd\.ew} 3 } } */
