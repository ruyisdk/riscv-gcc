/* mmul.ew.  */
/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -flto -ffat-lto-objects -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -flto -ffat-lto-objects -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv64 } } */
/* { dg-require-effective-target lto } */
#include "ztt-mmul-body.h"
/* { dg-final { scan-assembler-times {\tmmul\.ew\t} 19 } } */
