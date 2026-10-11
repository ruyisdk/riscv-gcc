/* { dg-do compile } */
/* { dg-options "-O2 -ffat-lto-objects -mztt-profile=gcc-runtime-u32-m32-a16 -fdump-tree-optimized -fdump-rtl-ztt_regions" } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
#define CP_ONE(X) __riscv_ztt_mcopy_m2m_i32_rnu_1x2 (X)
#define CP_COPY(X) CP_ONE (CP_ONE (CP_ONE (CP_ONE (X))))
#include "ztt-copy-project-ownership.h"
/* { dg-error "ownership changes.*require ownership-region support" "" { target *-*-* } 0 } */
/* { dg-final { scan-rtl-dump {Unproved Ztt access:} "ztt_regions" } } */
/* { dg-final { scan-tree-dump-not "__riscv_ztt_mextract_" "optimized" } } */
/* { dg-final { scan-tree-dump-times "__riscv_ztt_mcopy_m2m_" 4 "optimized" } } */
