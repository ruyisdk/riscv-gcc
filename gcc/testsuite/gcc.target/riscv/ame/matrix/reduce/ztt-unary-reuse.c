/* { dg-do compile } */
/* { dg-options "-O2 -g -fno-ipa-icf -ffat-lto-objects -fdump-rtl-ztt_state -mztt-profile=gcc-runtime-u8-m16-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#include "ztt-unary-reuse.h"
/* { dg-final { scan-assembler-times {mabs\.ew} 4 } } */
/* { dg-final { scan-assembler-times {mreducemax\.(?:row|col)} 2 } } */
/* { dg-final { scan-assembler-times {mprefixmax\.(?:row|col)} 2 } } */
/* { dg-final { scan-assembler-times {mrowbcast\.ew\.x} 2 } } */
/* { dg-final { scan-assembler-times {mcolbcast\.ew\.x} 1 } } */
/* { dg-final { scan-assembler-times {m(?:row|col)shift\.ew\.x} 2 } } */
/* { dg-final { scan-rtl-dump-times "UNSPECV_ZTT_STATE_STRUCTURAL_REUSE" 6 "ztt_state" } } */
/* { dg-final { scan-rtl-dump-times "UNSPECV_ZTT_STATE_ROWCOL_REUSE" 4 "ztt_state" } } */
