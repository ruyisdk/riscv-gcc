/* data-scalar arithmetic.  */
/* { dg-do compile } */
/* { dg-options "-O0 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u64-m16-a4" { target rv32 } } */
/* { dg-options "-O0 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u64-m16-a4" { target rv64 } } */
#include "../../../../../gcc.target/riscv/ame/matrix/scalar-arithmetic/ztt-scalar-arith-body.h"
/* { dg-final { scan-assembler-times {\tmadd\.ew\.x\t} 36 } } */
/* { dg-final { scan-assembler-times {\tmsub\.ew\.x\t} 36 } } */
/* { dg-final { scan-assembler-times {\tmabsdiff\.ew\.x\t} 36 } } */
/* { dg-final { scan-assembler-times {\tmhdiff\.ew\.x\t} 36 } } */
/* { dg-final { scan-assembler-times {\tmmean\.ew\.x\t} 36 } } */
/* { dg-final { scan-assembler-times {\tmmul\.ew\.x\t} 36 } } */
/* { dg-final { scan-assembler-times {\tmmulneg\.ew\.x\t} 36 } } */
/* { dg-final { scan-assembler-times {\tmmin\.ew\.x\t} 56 } } */
/* { dg-final { scan-assembler-times {\tmmax\.ew\.x\t} 56 } } */
/* { dg-final { scan-assembler-times {\tcsrw\tamestype,} 364 } } */
/* { dg-final { scan-assembler-not {\tmconv\.ew\t} } } */
