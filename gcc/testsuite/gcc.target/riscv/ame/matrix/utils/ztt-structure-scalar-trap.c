/* { dg-do compile } */
/* { dg-options "-O2 -ftrapv -ffat-lto-objects -fdump-tree-optimized -mztt-profile=gcc-runtime-u32-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#include "ztt-structure-scalar.h"
/* { dg-final { scan-tree-dump-times "__riscv_ztt_mextract_" 9 "optimized" } } */
/* { dg-final { scan-tree-dump-not "__riscv_ztt_mrowunzip_" "optimized" } } */
