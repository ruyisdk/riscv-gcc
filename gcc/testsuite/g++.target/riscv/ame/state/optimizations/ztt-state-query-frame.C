/* { dg-do compile } */
/* { dg-options "-g -std=gnu++17 -march=rv32gcv_ztt0p6 -mabi=ilp32d -mztt-profile=gcc-runtime-u32-m16-a4 -fdump-rtl-ztt_regions -fdump-rtl-ztt_verify_regions" { target rv32 } } */
/* { dg-options "-g -std=gnu++17 -march=rv64gcv_ztt0p6 -mabi=lp64d -mztt-profile=gcc-runtime-u32-m16-a4 -fdump-rtl-ztt_regions -fdump-rtl-ztt_verify_regions" { target rv64 } } */
#define QUERY_REGION
#include "../../../../../gcc.target/riscv/ame/state/ztt-state-region-frame.h"
/* { dg-final { scan-rtl-dump {Ztt owned edge:} "ztt_regions" } } */
/* { dg-final { scan-rtl-dump-not {Ztt caller-owned entry contract} "ztt_regions" } } */
/* { dg-final { scan-rtl-dump-not {Unproved Ztt access:} "ztt_verify_regions" } } */
/* { dg-final { scan-assembler {vs1r\.v\s+v1,} } } */
/* { dg-final { scan-assembler {\.cfi_restore 97} } } */
/* { dg-final { scan-assembler {\.cfi_offset 1,} } } */
