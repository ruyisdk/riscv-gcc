/* integer arithmetic.  */
/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv64 } } */
#include "../../../../../gcc.target/riscv/ame/matrix/arithmetic/ztt-arith-accepted.h"
/* { dg-final { scan-assembler-times {\tmsub\.ew\t} 4 } } */
/* { dg-final { scan-assembler-times {\tmadd\.ew\t} 2 } } */
