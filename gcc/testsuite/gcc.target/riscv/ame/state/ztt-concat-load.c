/* { dg-do assemble } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m16-a4 -fdump-rtl-expand" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m16-a4 -fdump-rtl-expand" { target rv64 } } */
#include "ztt-concat-load.h"
/* { dg-final { scan-rtl-dump-times "Use concat inputs for elementwise" 4 "expand" } } */
