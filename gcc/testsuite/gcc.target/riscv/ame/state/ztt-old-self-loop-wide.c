/* { dg-do compile } */
/* { dg-options "-O2 -g -fno-ipa-icf -fdump-rtl-ztt_state -mztt-profile=gcc-runtime-u8-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#include "ztt-old-self-loop.h"
/* { dg-final { scan-rtl-dump-not "UNSPECV_ZTT_STATE_COPY" "ztt_state" } } */
/* { dg-final { scan-assembler-times {\tmmulacc\.ew\t} 1 } } */
/* { dg-final { scan-assembler-times {\tmmuladd\.ew\.x\t} 1 } } */
/* { dg-final { scan-assembler-times {\tmcolscatadd\.ew\t} 1 } } */
