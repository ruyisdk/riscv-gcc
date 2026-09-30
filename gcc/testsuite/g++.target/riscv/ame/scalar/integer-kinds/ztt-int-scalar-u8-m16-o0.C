/* Compile/assemble checks, not numerical execution evidence.  */
/* { dg-do assemble } */
/* { dg-options "-O0 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O0 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv64 } } */
#define TEST_UDS 8
#include "../../../../../gcc.target/riscv/ame/scalar/integer-kinds/ztt-int-scalar-body.h"
