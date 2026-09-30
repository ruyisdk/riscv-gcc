/* { dg-do compile } */
/* { dg-options "-march=rv32gc -mabi=ilp32d" { target rv32 } } */
/* { dg-options "-march=rv64gc -mabi=lp64d" { target rv64 } } */

#pragma riscv intrinsic "ztt" /* { dg-error "requires the .*ztt0p6.* ISA extension" } */
