/* basic-square indexed API.  */
/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv64 } } */
#include "../../../../../gcc.target/riscv/ame/matrix/indexed/ztt-indexed-body.h"
/* { dg-final { scan-assembler-times {\tmcolgather\.ew\t} 5 } } */
/* { dg-final { scan-assembler-times {\tmrowgather\.ew\t} 5 } } */
/* { dg-final { scan-assembler-times {\tmcolscatadd\.ew\t} 5 } } */
/* { dg-final { scan-assembler-times {\tmrowscatadd\.ew\t} 5 } } */
/* { dg-final { scan-assembler-times {\tmcolscatmax\.ew\t} 5 } } */
/* { dg-final { scan-assembler-times {\tmrowscatmax\.ew\t} 5 } } */
/* { dg-final { scan-assembler-not {amestype|\tmconv\.ew\t} } } */
