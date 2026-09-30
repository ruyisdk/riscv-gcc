/* { dg-do compile } */
/* { dg-options "-std=gnu11 -march=rv32gc_ztt0p6 -mabi=ilp32d -mztt-profile=gcc-runtime-u8-m16-a4 -fdump-rtl-ztt_regions -fdump-rtl-ztt_verify_regions" { target rv32 } } */
/* { dg-options "-std=gnu11 -march=rv64gc_ztt0p6 -mabi=lp64d -mztt-profile=gcc-runtime-u8-m16-a4 -fdump-rtl-ztt_regions -fdump-rtl-ztt_verify_regions" { target rv64 } } */
#define QUERY_CASE 2
#include "../ztt-state-query.h"
/* { dg-final { scan-assembler-not {amenlen|msettyp|asettyp|mld|mls|mst|mss|ame.acquire|ame.release} } } */
/* { dg-final { scan-assembler-not {s11} } } */
