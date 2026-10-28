/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -mztt-profile=gcc-runtime-u32-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#include "../../../../../gcc.target/riscv/ame/matrix/indexed/ztt-matrix-exponent-layout-types.h"
/* { dg-final { scan-assembler-times {mrowgather\.ew\s} 4 } } */
/* { dg-final { scan-assembler-times {mldexp\.ew\s} 4 } } */
/* { dg-final { scan-assembler-times {mrdexp\.ew\s} 1 } } */
