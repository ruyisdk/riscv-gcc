/* { dg-do compile } */
/* { dg-options "-O2 -fcompare-debug -fno-ipa-icf -fdump-rtl-ztt_md_reuse -mztt-profile=gcc-runtime-u8-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#include "ztt-exponent-tc.h"
/* { dg-final { scan-assembler-times {mldexpacc\.ew\.x\t} 16 } } */
/* { dg-final { scan-assembler-times {csrw\tamestype,} 8 } } */
/* { dg-final { scan-rtl-dump-times {\(const_int 0 \[0\]\)\n\s+(?:\(reg:[^\n]+\)\n\s+)?\(const_int 4 \[0x4\]\)} 16 "ztt_md_reuse" } } */
