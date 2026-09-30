/* integer subtraction.  */
/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf  -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a1" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf  -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a1" { target rv64 } } */
/* { dg-additional-options "-ffat-lto-objects" { target { lto } } } */
#include "ztt-sub-body.h"
/* { dg-final { scan-assembler-times {msub\.ew\t} 152 } } */
/* { dg-final { scan-assembler-not {madd\.ew\t} } } */
