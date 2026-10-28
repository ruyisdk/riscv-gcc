/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -ffat-lto-objects -mztt-profile=gcc-runtime-u8-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#include "ztt-orthogonal-bcast.h"
/* { dg-final { scan-assembler-times {mrowgather\.ew} 2 } } */
/* { dg-final { scan-assembler-times {mcolgather\.ew} 4 } } */
/* { dg-final { scan-assembler-times {mrowbcast\.ew\.x} 13 } } */
/* { dg-final { scan-assembler-times {mcolbcast\.ew\.x} 11 } } */
