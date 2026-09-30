/* { dg-do compile } */
/* { dg-options "-march=rv32gc -mabi=ilp32d -mztt-profile=gcc-p0-n128-u8-m16-a4" { target rv32 } } */
/* { dg-options "-march=rv64gc -mabi=lp64d -mztt-profile=gcc-p0-n128-u8-m16-a4" { target rv64 } } */
/* { dg-error "requires the .*ztt0p6.* ISA extension" "" { target *-*-* } 0 } */
