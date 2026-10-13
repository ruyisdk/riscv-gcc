/* { dg-do compile } */
/* { dg-options "-O2 -ffat-lto-objects -fno-ipa-icf -mztt-profile=gcc-runtime-u16-m16-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
/* { dg-error "requires 24 simultaneously allocated M registers for sources and an independent destination; profile provides 16" "" { target *-*-* } 0 } */
#define VOLATILE_INPUT
#include "ztt-scatter-input-invalid.h"
