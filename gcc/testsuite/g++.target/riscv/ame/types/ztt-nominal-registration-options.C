/* AME/Ztt v0.2.5 nominal Scalar registration; draft/provisional.  */
/* { dg-do compile } */
/* { dg-options "-O2 -fdump-tree-gimple -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -fdump-tree-gimple -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv64 } } */
#pragma GCC push_options
#pragma GCC optimize ("O1")
#include <riscv_ztt.h>
int inside_pragma (int x) { return x + 1; }
#pragma GCC pop_options
int outside_pragma (int x) { return x + 1; }
/* { dg-final { scan-tree-dump-times {optimize \("O1"\)} 1 "gimple" } } */
