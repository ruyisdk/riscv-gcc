/* { dg-do compile } */
/* { dg-options "-O2 -mztt-profile=gcc-runtime-u32-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#include "../../../../../gcc.target/riscv/ame/matrix/mul/ztt-mul-zero-unowned.h"
/* { dg-error "ownership" "" { target *-*-* } 0 } */
