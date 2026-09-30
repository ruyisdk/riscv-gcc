/* { dg-do compile } */
/* { dg-options "-march=rv32im_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv32 } } */
/* { dg-options "-march=rv64im_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv64 } } */
/* { dg-error "runtime-N AME/Ztt profile requires integer multiplication and the 'zicsr' ISA extension" "" { target *-*-* } 0 } */
int unavailable;
