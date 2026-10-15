/* { dg-do compile } */
/* { dg-options "-ffat-lto-objects -O0 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a16" { target rv32 } } */
/* { dg-options "-ffat-lto-objects -O0 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a16" { target rv64 } } */
#include "ztt-copy-bank-invalid.h"
/* { dg-error "ternary operation requires 24 simultaneously allocated M registers.*profile provides 16" "" { target *-*-* } 0 } */
