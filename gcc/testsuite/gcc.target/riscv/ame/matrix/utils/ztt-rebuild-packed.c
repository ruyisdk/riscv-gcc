/* { dg-do compile } */
/* { dg-options "-O2 -fdump-tree-optimized -mztt-profile=gcc-runtime-u128-m32-a16" } */
/* { dg-additional-options "-ffat-lto-objects" } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target { rv64 } } } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target { rv32 } } } */
#define RB_TYPE i32_rnu
#define RB_CARRIER int32_t
#define RB_HALF 1x4
#define RB_PAIR 1x8
#include "ztt-rebuild-body.h"
/* { dg-final { scan-tree-dump-times "__riscv_ztt_mconcat_m_" 8 "optimized" } } */
