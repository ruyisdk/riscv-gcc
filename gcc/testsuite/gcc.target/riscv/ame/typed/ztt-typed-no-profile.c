/* { dg-do compile } */
/* { dg-options "-march=rv32gc_ztt0p6 -mabi=ilp32d" { target rv32 } } */
/* { dg-options "-march=rv64gc_ztt0p6 -mabi=lp64d" { target rv64 } } */

#pragma riscv intrinsic "ztt" /* { dg-error "requires .*-mztt-profile=gcc-p0-n128-u8-m16-a4.*" } */
