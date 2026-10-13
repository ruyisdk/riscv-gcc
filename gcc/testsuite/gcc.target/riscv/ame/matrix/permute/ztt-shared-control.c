/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -ffat-lto-objects -fdump-rtl-ztt_md_reuse -mztt-profile=gcc-runtime-u32-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#include "ztt-shared-control.h"
/* { dg-final { scan-rtl-dump {Narrow rowcol control definition} "ztt_md_reuse" { target rv64 } } } */
/* { dg-final { scan-assembler-times {mrowbcast\.ew\.x} 13 } } */
/* { dg-final { scan-assembler-times {mcolbcast\.ew\.x} 11 } } */
