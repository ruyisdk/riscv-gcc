/* { dg-do compile } */
/* { dg-options "-O2 -fdump-rtl-expand -mztt-profile=gcc-runtime-u16-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#define MC_HALF 1
#define MC_WHOLE 2
#define MC_TYPE u128_rnu
#define MC_CARRIER __riscv_ztt_u128_storage_t
#include "ztt-m2a-concat.h"
/* { dg-final { scan-rtl-dump-times "Use concat inputs for M-to-ACC" 8 "expand" } } */
