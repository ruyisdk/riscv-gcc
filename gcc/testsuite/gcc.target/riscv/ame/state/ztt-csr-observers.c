/* { dg-do compile } */
/* { dg-options "-O2 -fdump-rtl-ztt_md_reuse -mztt-profile=gcc-runtime-u32-m32-a16" } */
/* { dg-additional-options "-ffat-lto-objects" } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target { rv64 } } } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target { rv32 } } } */
#include "ztt-csr-observers.h"
/* { dg-final { scan-rtl-dump-times "Reuse Md for typed store" 10 "ztt_md_reuse" } } */
/* { dg-final { scan-assembler-times {csrr[ \t]+[^\n]*amefflags} 9 } } */
