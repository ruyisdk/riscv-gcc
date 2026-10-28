/* { dg-do compile } */
/* { dg-options "-O2 -g -fno-ipa-icf -ffat-lto-objects -fdump-rtl-ztt_state -mztt-profile=gcc-runtime-u8-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#include "ztt-ternary-shared.h"
/* { dg-final { scan-rtl-dump-times {UNSPECV_ZTT_STATE_TERNARY_REUSE_LEFT} 5 "ztt_state" } } */
/* { dg-final { scan-assembler-times {mmulacc\.ew\s} 5 } } */
/* { dg-final { scan-assembler-times {mmulacc\.ew\s+m([0-9]+),m\1,m\1} 2 } } */
/* { dg-final { scan-assembler-times {mmuladd\.ew\s+m([0-9]+),m\1,m\1} 1 } } */
/* { dg-final { scan-assembler-times {mmulsub\.ew\s+m([0-9]+),m\1,m\1} 1 } } */
