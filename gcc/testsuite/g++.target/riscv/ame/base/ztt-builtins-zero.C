/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32gc_ztt -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -march=rv64gc_ztt -mabi=lp64 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv64 } } */

#include "../../../../gcc.target/riscv/ame/base/ztt-builtins-zero.h"

/* { dg-final { scan-assembler-times {\tm[a-z0-9.]+\tm15,zero,m0} 34 } } */
/* { dg-final { scan-assembler-times {\tmadd\.ew\.x\tm15,[ast][0-9]+,m0} 2 } } */
/* { dg-final { scan-assembler-not {\tm[a-z0-9.]+\tm15,0,m0} } } */
