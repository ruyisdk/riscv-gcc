/* { dg-do assemble } */
/* { dg-options "-O2 -march=rv32gc_ztt -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -march=rv64gc_ztt -mabi=lp64 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv64 } } */

#include "../../../../gcc.target/riscv/ame/base/ztt-builtins-formats.h"
