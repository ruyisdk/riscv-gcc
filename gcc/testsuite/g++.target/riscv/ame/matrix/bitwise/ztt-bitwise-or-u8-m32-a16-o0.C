/* integer bitwise OR.  */
/* { dg-do compile } */
/* { dg-options "-O0 -fno-ipa-icf  -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m32-a16" { target rv32 } } */
/* { dg-options "-O0 -fno-ipa-icf  -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m32-a16" { target rv64 } } */
/* { dg-additional-options "-ffat-lto-objects" { target { lto } } } */
#include "../../../../../gcc.target/riscv/ame/matrix/bitwise/ztt-bitwise-or-body.h"
/* { dg-final { scan-assembler-times {mor\.ew\t} 152 } } */
/* { dg-final { scan-assembler-not {madd\.ew\t} } } */
