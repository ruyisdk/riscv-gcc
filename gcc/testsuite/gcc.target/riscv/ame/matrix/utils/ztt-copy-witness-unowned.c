/* { dg-do compile } */
/* { dg-options "-O2 -fdump-tree-optimized -mztt-profile=gcc-runtime-u32-m32-a16 -fdump-rtl-ztt_regions" } */
/* { dg-additional-options "-ffat-lto-objects" } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target { rv64 } } } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target { rv32 } } } */
#include "ztt-copy-witness-ownership.h"
/* { dg-error "ownership changes.*require ownership-region support" "" { target *-*-* } 0 } */
/* { dg-final { scan-rtl-dump {Unproved Ztt access:} "ztt_regions" } } */
/* { dg-final { scan-tree-dump "__riscv_ztt_mcopy_m2m_" "optimized" } } */
/* { dg-final { scan-tree-dump "__riscv_ztt_mcolzip_ew_" "optimized" } } */
