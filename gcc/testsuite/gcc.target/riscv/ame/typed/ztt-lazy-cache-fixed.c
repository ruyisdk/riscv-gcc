/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-p0-n128-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-p0-n128-u8-m16-a4" { target rv64 } } */
#define ZTT_LAZY_NAME lazy_first
#include "ztt-lazy-cache-body.h"
#undef ZTT_LAZY_NAME
#define ZTT_LAZY_NAME lazy_again
#include "ztt-lazy-cache-body.h"
/* { dg-final { scan-assembler-times {\tmconv\.ew\t} 32 } } */
/* { dg-final { scan-assembler-times {\tmmul\.ew\t} 32 } } */
/* { dg-final { scan-assembler-times {\tmadd\.ew\.x\t} 32 } } */
