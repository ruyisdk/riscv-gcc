/* { dg-do compile } */
/* { dg-options "-O2 -mztt-profile=gcc-runtime-u32-m32-a16" } */
/* { dg-additional-options "-march=rv64gc_zfhmin_zfbfmin_ztt0p6 -mabi=lp64d" { target rv64 } } */
/* { dg-additional-options "-march=rv32gc_zfhmin_zfbfmin_ztt0p6 -mabi=ilp32d" { target rv32 } } */

#include "../../../../../gcc.target/riscv/ame/scalar/floating/ztt-scalar-native-ternary.h"

/* { dg-final { scan-assembler-times {mmulacc\.ew\.x} 9 } } */
/* { dg-final { scan-assembler-times {csrw\tamestype} 9 } } */
