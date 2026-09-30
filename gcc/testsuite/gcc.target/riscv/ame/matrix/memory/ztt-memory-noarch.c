/* { dg-do compile } */
/* { dg-options "-march=rv32im_zicsr -mabi=ilp32" { target rv32 } } */
/* { dg-options "-march=rv64im_zicsr -mabi=lp64" { target rv64 } } */

#pragma riscv intrinsic "ztt" /* { dg-error "requires the .*ztt0p6.* ISA extension" } */
