/* integer maximum.  */
/* { dg-do compile } */
/* { dg-options "-O0 -fno-ipa-icf  -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u16-m32-a16" { target rv32 } } */
/* { dg-options "-O0 -fno-ipa-icf  -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u16-m32-a16" { target rv64 } } */
/* { dg-additional-options "-ffat-lto-objects" { target { lto } } } */
#include "ztt-minmax-max-body.h"
/* { dg-final { scan-assembler-times {mmax\.ew\t} 256 } } */
/* { dg-final { scan-assembler-not {madd\.ew\t} } } */
