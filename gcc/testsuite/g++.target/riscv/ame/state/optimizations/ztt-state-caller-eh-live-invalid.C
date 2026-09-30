/* { dg-do compile } */
/* { dg-options "-std=gnu++17 -fexceptions -march=rv32gc_ztt0p6 -mabi=ilp32d -mztt-profile=gcc-runtime-u8-m16-a4" { target rv32 } } */
/* { dg-options "-std=gnu++17 -fexceptions -march=rv64gc_ztt0p6 -mabi=lp64d -mztt-profile=gcc-runtime-u8-m16-a4" { target rv64 } } */
#define EH_UNGUARDED
#include "../ztt-state-caller-eh-live.h"
/* { dg-error "caller-owned function cannot prove ownership" "" { target *-*-* } 0 } */
