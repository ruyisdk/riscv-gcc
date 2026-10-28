/* { dg-do compile } */
/* { dg-options "-O2 -g -fno-ipa-icf -ffat-lto-objects -fdump-rtl-ztt_state -mztt-profile=gcc-runtime-u8-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#include "ztt-gather-shared.h"
/* { dg-final { scan-rtl-dump-times {UNSPECV_ZTT_STATE_GATHER_REUSE_BOTH} 9 "ztt_state" } } */
/* { dg-final { scan-assembler {mcolgather\.ew\s+m([0-9]+),m\1,m\1} } } */
/* { dg-final { scan-assembler {mrowgather\.ew\s+m([0-9]+),m\1,m\1} } } */
/* { dg-final { scan-assembler-times {mcolgather\.ew} 8 } } */
/* { dg-final { scan-assembler-times {mrowgather\.ew} 3 } } */
