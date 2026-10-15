/* { dg-do compile } */
/* { dg-options "-O2 -g -ffat-lto-objects -fdump-tree-optimized -fdump-rtl-ztt_regions -mztt-profile=gcc-runtime-u8-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#include "../../../../../gcc.target/riscv/ame/matrix/bitwise/ztt-andnot-zero-unowned.c"
/* { dg-error "ownership changes.*require ownership-region support" "" { target *-*-* } 0 } */
/* { dg-final { scan-rtl-dump {Unproved Ztt access:} "ztt_regions" } } */
/* { dg-final { scan-tree-dump {__riscv_ztt_mzero_m_i32_rnu_1x1 \(\)} "optimized" } } */
