/* integer bitwise XOR.  */
/* { dg-do compile } */
/* { dg-options "-O0 -fno-ipa-icf  -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m32-a16" { target rv32 } } */
/* { dg-options "-O0 -fno-ipa-icf  -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m32-a16" { target rv64 } } */
/* { dg-additional-options "-ffat-lto-objects" { target { lto } } } */
#include "../../../../../gcc.target/riscv/ame/matrix/bitwise/ztt-bitwise-xor-body.h"
/* { dg-final { scan-assembler-times {mxor\.ew\t} 328 } } */
/* { dg-final { scan-assembler-not {madd\.ew\t} } } */
