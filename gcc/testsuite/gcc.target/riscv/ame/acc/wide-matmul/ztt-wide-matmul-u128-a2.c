/* Compile/assemble checks, not numerical execution evidence.  */
/* { dg-do assemble } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u128-m16-a2" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u128-m16-a2" { target rv64 } } */
#include "ztt-wide-matmul-body.h"
RUN(low_resources, u64_rdn, 2, i64_rnu, u128_rne, 2)
