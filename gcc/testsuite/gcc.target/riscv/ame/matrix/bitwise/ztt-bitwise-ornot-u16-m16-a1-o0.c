/* integer bitwise ORNOT.  */
/* { dg-do compile } */
/* { dg-options "-O0 -fno-ipa-icf  -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u16-m16-a1" { target rv32 } } */
/* { dg-options "-O0 -fno-ipa-icf  -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u16-m16-a1" { target rv64 } } */
/* { dg-additional-options "-ffat-lto-objects" { target { lto } } } */
#include "ztt-bitwise-ornot-body.h"
/* { dg-final { scan-assembler-times {mornot\.ew\t} 256 } } */
/* { dg-final { scan-assembler-not {madd\.ew\t} } } */
