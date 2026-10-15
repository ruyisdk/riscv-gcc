/* { dg-do compile } */
/* { dg-options "-O2 -ffat-lto-objects -fdump-tree-optimized -fdump-rtl-ztt_regions -mztt-profile=gcc-runtime-u8-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#include "../../../../../gcc.target/riscv/ame/matrix/indexed/ztt-gather-widen-unowned.c"
/* { dg-error "ownership changes.*require ownership-region support" "" { target *-*-* } 0 } */
/* { dg-final { scan-rtl-dump {Unproved Ztt access:} "ztt_regions" } } */
/* { dg-final { scan-tree-dump-times {__riscv_ztt_mcolid_ew_i8_rnu_sat_1x1 \(\)} 1 "optimized" } } */
/* { dg-final { scan-tree-dump-times {__builtin_riscv_ztt_convert_[0-9]+ \(} 1 "optimized" } } */
