/* { dg-do compile } */
/* { dg-options "-O0 -ffat-lto-objects -fno-ipa-icf -mztt-profile=gcc-runtime-u8-m16-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#include "../../../../../gcc.target/riscv/ame/matrix/indexed/ztt-gather-input.h"
/* { dg-final { scan-assembler-times {mcolgather\.ew} 4 } } */
/* { dg-final { scan-assembler-times {mrowgather\.ew} 3 } } */
