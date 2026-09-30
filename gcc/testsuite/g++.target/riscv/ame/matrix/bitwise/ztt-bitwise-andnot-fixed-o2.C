/* integer bitwise ANDNOT.  */
/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf  -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-p0-n128-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf  -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-p0-n128-u8-m16-a4" { target rv64 } } */
/* { dg-additional-options "-ffat-lto-objects" { target { lto } } } */
#include "../../../../../gcc.target/riscv/ame/matrix/bitwise/ztt-bitwise-andnot-body.h"
/* { dg-final { scan-assembler-times {mandnot\.ew\t} 24 } } */
