/* { dg-do compile } */
/* { dg-options "-O2 -g -fno-ipa-icf -fno-tree-vectorize -fdump-rtl-ztt_md_reuse -mztt-profile=gcc-runtime-u32-m16-a4" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#include "ztt-scalar-zero-store.h"
#include "ztt-scalar-zero-tiles.h"
/* { dg-final { scan-rtl-dump-times "Use x0 for scalar store" 2 "ztt_md_reuse" } } */
/* { dg-final { scan-rtl-dump-times "Use x0 for scalar store at insn .* across predecessor" 1 "ztt_md_reuse" } } */
