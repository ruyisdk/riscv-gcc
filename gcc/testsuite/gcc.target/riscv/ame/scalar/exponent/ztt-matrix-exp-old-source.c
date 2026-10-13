/* { dg-do compile } */
/* { dg-options "-O2 -g -fno-ipa-icf -ffat-lto-objects -mztt-profile=gcc-runtime-u8-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#define CT_EXP
#include "../../matrix/ternary/ztt-control-old-source.h"
/* { dg-final { scan-assembler-times {mldexpacc\.ew\s} 8 } } */
/* { dg-final { scan-assembler-times {mrdexpacc\.ew\s} 2 } } */
/* { dg-final { scan-assembler {mldexpacc\.ew\s+m([0-9]+),m\1,m\1} } } */
