/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -mztt-profile=gcc-runtime-u32-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#include "ztt-binary-layout-ops.h"
/* { dg-final { scan-assembler-times {mrowgather\.ew\s} 2 } } */
/* { dg-final { scan-assembler-times {mrowbcast\.ew\.x\s} 14 } } */
/* { dg-final { scan-assembler-times {madd\.ew\s} 2 } } */
/* { dg-final { scan-assembler-times {mmax\.ew\s} 1 } } */
/* { dg-final { scan-assembler-times {mand\.ew\s} 1 } } */
/* { dg-final { scan-assembler-times {mor\.ew\s} 1 } } */
/* { dg-final { scan-assembler-times {mandnot\.ew\s} 1 } } */
/* { dg-final { scan-assembler-times {mmulneg\.ew\s} 1 } } */
