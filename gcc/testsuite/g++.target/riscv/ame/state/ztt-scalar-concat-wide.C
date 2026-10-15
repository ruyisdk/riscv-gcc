/* { dg-do compile } */
/* { dg-options "-O2 -fdump-rtl-expand -mztt-profile=gcc-runtime-u8-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#define SC_HALF 1x2
#define SC_WHOLE 1x4
#include "../../../../gcc.target/riscv/ame/state/ztt-scalar-concat.h"
/* { dg-final { scan-rtl-dump-times "Use concat inputs for scalar" 15 "expand" } } */
