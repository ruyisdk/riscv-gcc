/* { dg-do compile } */
/* { dg-options "-ffat-lto-objects -O0 -mztt-profile=gcc-runtime-u8-m16-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
/* { dg-error "requires 32 simultaneously allocated M registers for distinct sources; profile provides 16" "" { target *-*-* } 0 } */
#include "../../../../../gcc.target/riscv/ame/matrix/indexed/ztt-gather-input-invalid.h"
