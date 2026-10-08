/* { dg-do compile } */
/* { dg-options "-O2 -fdump-tree-optimized -mztt-profile=gcc-runtime-u32-m32-a16" } */
/* { dg-additional-options "-ffat-lto-objects" } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target { rv64 } } } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target { rv32 } } } */
#define WT_RAW 1
#include "ztt-witness-body.h"
/* { dg-error "functions using AME/Ztt typed values cannot mix L0 selector builtins" "" { target *-*-* } 0 } */
/* { dg-final { scan-tree-dump-times "__riscv_ztt_mcolunzip_ew_" 11 "optimized" } } */
