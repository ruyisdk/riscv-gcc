/* { dg-do compile } */
/* { dg-options "-O0 -ffat-lto-objects -fno-ipa-icf -mztt-profile=gcc-runtime-u16-m16-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#include "../../../../../gcc.target/riscv/ame/matrix/indexed/ztt-scatter-old.h"
/* { dg-final { scan-assembler-times {mcolscatadd\.ew} 3 } } */
/* { dg-final { scan-assembler-times {mrowscatadd\.ew} 2 } } */
/* { dg-final { scan-assembler-times {mcolscatmax\.ew} 1 } } */
/* { dg-final { scan-assembler-times {mrowscatmax\.ew} 2 } } */
