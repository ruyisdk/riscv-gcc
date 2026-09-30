/* runtime-N resource profiles.  */
/* { dg-do link } */
/* { dg-options "-O2 -flto=1 -nostdlib -Wl,--export-dynamic -Wl,-e,resource_pressure -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a1" { target rv32 } } */
/* { dg-options "-O2 -flto=1 -nostdlib -Wl,--export-dynamic -Wl,-e,resource_pressure -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a1" { target rv64 } } */
#define EXPECT_M 16
#define EXPECT_ACC 1
#include "ztt-resources-body.h"
