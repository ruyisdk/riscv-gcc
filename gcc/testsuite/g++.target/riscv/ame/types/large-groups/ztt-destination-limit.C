/* { dg-do compile } */
/* { dg-options "-fno-lto -mztt-profile=gcc-runtime-u8-m16-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#include "../../../../../gcc.target/riscv/ame/types/large-groups/ztt-destination-limit.h"
/* { dg-error "requires 24 simultaneously allocated M registers for sources and an independent destination; profile provides 16" "" { target *-*-* } 0 } */
