/* { dg-do compile } */
/* { dg-options "-O2 -fdump-rtl-expand -mztt-profile=gcc-runtime-u16-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#define ZC_TYPE u128_rnu
#define ZC_CARRIER __riscv_ztt_u128_storage_t
#define ZC_COUNT 2
#include "ztt-zero-chain.h"
/* { dg-final { scan-rtl-dump-times "Forward zero M to ACC" 12 "expand" } } */
/* { dg-final { scan-rtl-dump-times "Forward zero ACC to M" 12 "expand" } } */
