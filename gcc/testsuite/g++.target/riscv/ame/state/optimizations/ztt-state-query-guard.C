/* { dg-do compile } */
/* { dg-options "-std=gnu++17 -march=rv32gc_ztt0p6 -mabi=ilp32d -mztt-profile=gcc-runtime-u8-m16-a4 -fdump-rtl-ztt_regions -fdump-rtl-ztt_verify_regions" { target rv32 } } */
/* { dg-options "-std=gnu++17 -march=rv64gc_ztt0p6 -mabi=lp64d -mztt-profile=gcc-runtime-u8-m16-a4 -fdump-rtl-ztt_regions -fdump-rtl-ztt_verify_regions" { target rv64 } } */
#define QUERY_CASE 0
#include "../../../../../gcc.target/riscv/ame/state/ztt-state-query.h"
/* { dg-final { scan-rtl-dump {Ztt owned edge:} "ztt_regions" } } */
/* { dg-final { scan-rtl-dump-not {Ztt caller-owned entry contract} "ztt_regions" } } */
/* { dg-final { scan-rtl-dump-not {Unproved Ztt access:} "ztt_verify_regions" } } */
