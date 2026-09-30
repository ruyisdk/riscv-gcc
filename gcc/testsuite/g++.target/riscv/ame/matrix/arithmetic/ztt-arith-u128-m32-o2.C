/* integer arithmetic.  */
/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u128-m32-a4" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u128-m32-a4" { target rv64 } } */
#include "../../../../../gcc.target/riscv/ame/matrix/arithmetic/ztt-arith-body.h"
/* { dg-final { scan-assembler-times {\tmadd\.ew\t} 27 } } */
/* { dg-final { scan-assembler-times {\tmsub\.ew\t} 27 } } */
/* { dg-final { scan-assembler-times {\tmabsdiff\.ew\t} 27 } } */
/* { dg-final { scan-assembler-times {\tmhdiff\.ew\t} 27 } } */
/* { dg-final { scan-assembler-times {\tmmean\.ew\t} 27 } } */
/* { dg-final { scan-assembler-times {\tmmulneg\.ew\t} 27 } } */
/* { dg-final { scan-assembler-not {\tmconv\.ew\t|amestype|\.ew\.x\t} } } */
