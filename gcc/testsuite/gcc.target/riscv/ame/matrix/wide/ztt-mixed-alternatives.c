/* { dg-do compile } */
/* { dg-options "-O2 -g -fno-ipa-icf -ffat-lto-objects -fdump-rtl-ztt_state -mztt-profile=gcc-runtime-u8-m16-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#include "ztt-mixed-alternatives.h"
/* { dg-final { scan-assembler-times {madd\.ew} 6 } } */
/* { dg-final { scan-assembler-times {msub\.ew} 6 } } */
/* { dg-final { scan-assembler-times {mmul\.ew} 3 } } */
/* { dg-final { scan-rtl-dump "UNSPECV_ZTT_STATE_ELEMENTWISE_M_REUSE_LEFT" "ztt_state" } } */
/* { dg-final { scan-rtl-dump "UNSPECV_ZTT_STATE_ELEMENTWISE_M_REUSE_RIGHT" "ztt_state" } } */
