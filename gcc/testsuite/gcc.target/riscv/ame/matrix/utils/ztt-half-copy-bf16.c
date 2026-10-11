/* { dg-do compile } */
/* { dg-options "-O2 -fdump-tree-optimized -mztt-profile=gcc-runtime-u8-m32-a16" } */
/* { dg-additional-options "-ffat-lto-objects" } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target { rv64 } } } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target { rv32 } } } */
#define HC_TYPE bf16_rne
#define HC_CARRIER __bf16
#include "ztt-half-copy-body.h"
/* { dg-final { scan-tree-dump-times "__riscv_ztt_mconcat_m_" 13 "optimized" } } */
