/* { dg-do compile } */
/* { dg-options "-O2 -g -fno-ipa-icf -ffat-lto-objects -mztt-profile=gcc-runtime-u8-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#define LG_TYPE i32_rnu_sat
#define LG_ELEMENT __INT32_TYPE__
#include "ztt-select-layout.h"
/* { dg-final { scan-assembler-times {m(?:row|col)gather\.ew\s} 9 } } */
/* { dg-final { scan-assembler-times {mcmovge\.ew\s} 5 } } */
/* { dg-final { scan-assembler-times {mmean\.ew\s} 7 } } */
