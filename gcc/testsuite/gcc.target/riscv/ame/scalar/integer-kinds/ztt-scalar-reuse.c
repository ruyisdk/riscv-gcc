/* { dg-do compile } */
/* { dg-options "-O2 -g -fno-ipa-icf -ffat-lto-objects -mztt-profile=gcc-runtime-u8-m16-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#include "ztt-scalar-reuse.h"
/* { dg-final { scan-assembler-times {madd\.ew\.x} 3 } } */
/* { dg-final { scan-assembler-times {msub\.ew\.x} 2 } } */
/* { dg-final { scan-assembler-times {mmul\.ew\.x} 2 } } */
/* { dg-final { scan-assembler-times {msll\.ew\.x} 1 } } */
