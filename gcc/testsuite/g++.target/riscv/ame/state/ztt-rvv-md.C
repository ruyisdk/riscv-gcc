/* { dg-do compile } */
/* { dg-options "-O2 -g -fno-ipa-icf -mztt-profile=gcc-runtime-u8-m32-a16" } */
/* { dg-additional-options "-march=rv32gcv_ztt0p6 -mabi=ilp32d" { target rv32 } } */
/* { dg-additional-options "-march=rv64gcv_ztt0p6 -mabi=lp64d" { target rv64 } } */
#include "../../../../gcc.target/riscv/ame/state/ztt-rvv-md.h"
/* { dg-final { scan-assembler-times {msettyp\t} 10 } } */
/* { dg-final { scan-assembler-times {mss\.1r\t} 12 } } */
/* { dg-final { scan-assembler-times {mls\.rm\t} 8 } } */
/* { dg-final { scan-assembler-times {mss\.rm\t} 16 } } */
/* { dg-final { scan-assembler-times {vadd\.vv\t} 3 } } */
/* { dg-final { scan-assembler-times {vmul\.vv\t} 1 } } */
/* { dg-final { scan-assembler-times {vsaddu\.vv\t} 1 } } */
/* { dg-final { scan-assembler-times {vredsum\.vs\t} 1 } } */
