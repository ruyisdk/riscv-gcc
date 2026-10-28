/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -ffat-lto-objects -fdump-rtl-ztt_md_reuse -march=rv32imafd_zicsr_ztt0p6 -mabi=ilp32d -mztt-profile=gcc-runtime-u8-m32-a16" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -ffat-lto-objects -fdump-rtl-ztt_md_reuse -march=rv64imafd_zicsr_ztt0p6 -mabi=lp64d -mztt-profile=gcc-runtime-u8-m32-a16" { target rv64 } } */
#include "ztt-spill-fp-tail.h"
/* { dg-final { scan-rtl-dump {Drop dead private spill} "ztt_md_reuse" } } */
/* { dg-final { scan-rtl-dump-times {Drop interleaved raw reload} 56 "ztt_md_reuse" } } */
/* { dg-final { scan-assembler-times {\tfmin\.s\t} 3 } } */
/* { dg-final { scan-assembler-times {\tfmax\.s\t} 1 } } */
/* { dg-final { scan-assembler-times {\tmrowscatadd\.ew\t} 7 } } */
