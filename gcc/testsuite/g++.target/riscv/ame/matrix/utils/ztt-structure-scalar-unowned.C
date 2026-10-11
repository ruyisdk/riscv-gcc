/* { dg-do compile } */
/* { dg-options "-O2 -ffat-lto-objects -mztt-profile=gcc-runtime-u32-m32-a16 -fdump-tree-optimized -fdump-rtl-ztt_regions" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#include "../../../../../gcc.target/riscv/ame/matrix/utils/ztt-structure-scalar-ownership.h"
/* { dg-error "ownership changes.*require ownership-region support" "" { target *-*-* } 0 } */
/* { dg-final { scan-rtl-dump {Unproved Ztt access:} "ztt_regions" } } */
/* { dg-final { scan-tree-dump-not "__riscv_ztt_mextract_" "optimized" } } */
/* { dg-final { scan-tree-dump-times "__riscv_ztt_mconcat_m_" 1 "optimized" } } */
