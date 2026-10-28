/* { dg-do compile } */
/* { dg-options "-O2 -g -fno-ipa-icf -fdump-rtl-expand -mztt-profile=gcc-runtime-u32-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#define AC_TYPE u32_rod_sat
#define AC_ELEMENT __UINT32_TYPE__
#define AC_SHAPE 1x2
#include "ztt-sub-self.h"
/* { dg-final { scan-rtl-dump-times "Zero identical integer tuple inputs" 4 "expand" } } */
/* { dg-final { scan-assembler-times {msub\.ew\t} 14 } } */
