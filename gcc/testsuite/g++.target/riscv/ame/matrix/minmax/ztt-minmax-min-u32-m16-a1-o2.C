/* integer minimum.  */
/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf  -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m16-a1" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf  -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m16-a1" { target rv64 } } */
/* { dg-additional-options "-ffat-lto-objects" { target { lto } } } */
#include "../../../../../gcc.target/riscv/ame/matrix/minmax/ztt-minmax-min-body.h"
/* { dg-final { scan-assembler-times {mmin\.ew\t} 328 } } */
/* { dg-final { scan-assembler-not {madd\.ew\t} } } */
