/* UDS32, i32/RNU only.  */
/* { dg-do compile } */
/* { dg-options "-O0 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m16-a1" { target rv32 } } */
/* { dg-options "-O0 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m16-a1" { target rv64 } } */
#include "ztt-acc-body.h"
/* { dg-final { scan-assembler "mmulacc.2d" } } */
/* { dg-final { scan-assembler "mmov.m.a" } } */
/* { dg-final { scan-assembler "mmov.a.m" } } */
/* { dg-final { scan-assembler "mzero.2d.acc" } } */
