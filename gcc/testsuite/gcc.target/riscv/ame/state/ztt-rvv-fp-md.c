/* { dg-do compile } */
/* { dg-options "-O2 -g -fno-ipa-icf -mztt-profile=gcc-runtime-u8-m32-a16" } */
/* { dg-additional-options "-march=rv32gcv_ztt0p6 -mabi=ilp32d" { target rv32 } } */
/* { dg-additional-options "-march=rv64gcv_ztt0p6 -mabi=lp64d" { target rv64 } } */
#include "ztt-rvv-fp-md.h"
/* { dg-final { scan-assembler-times {msettyp\t} 10 } } */
/* { dg-final { scan-assembler-times {mss\.1r\t} 12 } } */
/* { dg-final { scan-assembler-times {mls\.rm\t} 8 } } */
/* { dg-final { scan-assembler-times {mss\.rm\t} 16 } } */
/* { dg-final { scan-assembler-times {vfadd\.vf\t} 4 } } */
/* { dg-final { scan-assembler-times {vfmul\.vf\t} 1 } } */
/* { dg-final { scan-assembler-times {vfmin\.vf\t} 1 } } */
/* { dg-final { scan-assembler-times {vfcvt\.x\.f\.v\t} 1 } } */
