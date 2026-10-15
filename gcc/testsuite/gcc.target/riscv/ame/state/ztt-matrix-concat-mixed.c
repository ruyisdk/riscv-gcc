/* { dg-do compile } */
/* { dg-options "-O2 -fdump-rtl-expand -mztt-profile=gcc-runtime-u8-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#define BC_HALF 1x2
#define BC_WHOLE 1x4
#define BC_OTHER i16_rnu
#define BC_OTHER_CARRIER __INT16_TYPE__
#include "ztt-matrix-concat.h"
/* { dg-final { scan-rtl-dump-times "Use concat inputs for elementwise" 12 "expand" } } */
