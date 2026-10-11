/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -ffat-lto-objects -mztt-profile=gcc-runtime-u32-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#include "ztt-same-convert.h"
/* { dg-final { scan-assembler-times {\tmconv\.ew\t} 1 } } */
