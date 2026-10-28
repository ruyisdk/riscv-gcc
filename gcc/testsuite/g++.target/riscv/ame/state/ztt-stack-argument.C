/* { dg-do compile } */
/* { dg-options "-O2 -g -std=gnu++17 -fno-tree-vectorize -fno-ipa-icf -mztt-profile=gcc-runtime-u32-m16-a4 -fdump-rtl-ztt_md_reuse" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#include "../../../../gcc.target/riscv/ame/state/ztt-stack-argument.h"
/* { dg-final { scan-rtl-dump-not "Reuse scalar stack value" "ztt_md_reuse" } } */
