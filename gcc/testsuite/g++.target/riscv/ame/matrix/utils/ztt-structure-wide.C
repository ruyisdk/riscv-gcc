/* { dg-do compile } */
/* { dg-options "-O2 -fdump-tree-optimized -mztt-profile=gcc-runtime-u8-m32-a16" } */
/* { dg-additional-options "-ffat-lto-objects" } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target { rv64 } } } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target { rv32 } } } */
#define SF_TYPE i128_rnu
#define SF_CARRIER __riscv_ztt_i128_storage_t
#define SF_HALF 1x1
#define SF_PAIR 1x2
#define SF_COLUMN 2x1
#include "../../../../../gcc.target/riscv/ame/matrix/utils/ztt-structure-fold-body.h"
/* The concatenation occupies all 32 M registers.  */
/* { dg-final { scan-tree-dump-times "mextract_" 2 "optimized" } } */
/* { dg-final { scan-tree-dump-times "__riscv_ztt_mconcat_m_" 4 "optimized" } } */
