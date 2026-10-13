/* { dg-do compile } */
/* { dg-options "-O2 -g -fno-ipa-icf -ffat-lto-objects -mztt-profile=gcc-runtime-u8-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#define MX_KIND 1
#define MX_TYPE f32_rne
#define MX_CARRIER float
#define MY_TYPE i32_rnu
#define MY_CARRIER __INT32_TYPE__
#include "ztt-mixed-old-source.h"
/* { dg-final { scan-assembler-times {mldexpacc\.ew\s} 8 } } */
/* { dg-final { scan-assembler-times {mrdexpacc\.ew\s} 2 } } */
/* { dg-final { scan-assembler {mldexpacc\.ew\s+m([0-9]+),m\1,m[0-9]+} } } */
