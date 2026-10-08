/* { dg-do compile } */
/* { dg-options "-O2 -fdump-tree-optimized -mztt-profile=gcc-runtime-u32-m32-a16" } */
/* { dg-additional-options "-ffat-lto-objects" } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target { rv64 } } } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target { rv32 } } } */
#define HC_PAIR 2x1
#define HC_HALF 1x1
#include "../../../../../gcc.target/riscv/ame/matrix/utils/ztt-half-copy-body.h"
/* { dg-final { scan-tree-dump-times "__riscv_ztt_mconcat_m_" 16 "optimized" } } */
