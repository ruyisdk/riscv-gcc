/* { dg-do compile } */
/* { dg-options "-std=gnu++17 -march=rv32gc_ztt0p6 -mabi=ilp32d -mztt-profile=gcc-runtime-u8-m16-a4 -fdump-rtl-ztt_regions -fdump-rtl-ztt_verify_regions" { target rv32 } } */
/* { dg-options "-std=gnu++17 -march=rv64gc_ztt0p6 -mabi=lp64d -mztt-profile=gcc-runtime-u8-m16-a4 -fdump-rtl-ztt_regions -fdump-rtl-ztt_verify_regions" { target rv64 } } */
#define CASE 3
#include "../../../../../gcc.target/riscv/ame/state/ztt-state-region-invalid.h"
/* { dg-error "ownership changes.*require ownership-region support" "" { target *-*-* } 0 } */
/* { dg-final { scan-rtl-dump {Unproved Ztt access:} "ztt_regions" } } */
