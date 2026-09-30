/* { dg-do compile } */
/* { dg-options "-std=gnu11 -march=rv32gc_ztt0p6 -mabi=ilp32d -mztt-profile=gcc-runtime-u8-m16-a4" { target rv32 } } */
/* { dg-options "-std=gnu11 -march=rv64gc_ztt0p6 -mabi=lp64d -mztt-profile=gcc-runtime-u8-m16-a4" { target rv64 } } */
#define CONSTANT_CASE 2
#include "../ztt-state-region-constant-invalid.h"
/* { dg-error "require ownership-region support" "" { target *-*-* } 0 } */
