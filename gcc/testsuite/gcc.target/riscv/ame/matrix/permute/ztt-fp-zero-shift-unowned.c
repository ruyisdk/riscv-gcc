/* { dg-do compile } */
/* { dg-options "-O2 -mztt-profile=gcc-runtime-u32-m32-a16 -fdump-rtl-ztt_regions" } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
#define ZTT_SHIFT_CASE 1
#define ZTT_SHIFT_FLOAT 1
#include "ztt-zero-shift-ownership.h"
/* { dg-error "ownership changes.*require ownership-region support" "" { target *-*-* } 0 } */
/* { dg-final { scan-rtl-dump {Unproved Ztt access:} "ztt_regions" } } */
