/* { dg-do assemble } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m16-a4 -fdump-rtl-expand" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m16-a4 -fdump-rtl-expand" { target rv64 } } */
#include "../../../../gcc.target/riscv/ame/state/ztt-concat-packed.h"
/* { dg-final { scan-rtl-dump-times "Form packed conversion source directly" 1 "expand" } } */
