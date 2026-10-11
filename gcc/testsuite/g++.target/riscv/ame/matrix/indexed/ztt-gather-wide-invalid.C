/* { dg-do compile } */
/* { dg-options "-O2 -ffat-lto-objects -mztt-profile=gcc-runtime-u8-m16-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#include "../../../../../gcc.target/riscv/ame/matrix/indexed/ztt-gather-wide-invalid.c"
/* { dg-error "Ztt gather operation requires 17 simultaneously allocated M registers for distinct sources; profile provides 16" "" { target *-*-* } 0 } */
