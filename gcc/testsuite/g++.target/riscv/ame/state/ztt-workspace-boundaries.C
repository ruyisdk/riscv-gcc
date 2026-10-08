/* { dg-do compile } */
/* { dg-options "-O2 -g -fno-ipa-icf -fdump-rtl-ztt_md_reuse -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m32-a16" { target rv32 } } */
/* { dg-options "-O2 -g -fno-ipa-icf -fdump-rtl-ztt_md_reuse -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m32-a16" { target rv64 } } */
#define WORKSPACE_BOUNDARIES
#include "../../../../gcc.target/riscv/ame/state/ztt-workspace-body.h"
/* { dg-final { scan-rtl-dump-not "Remove unused AME workspace" "ztt_md_reuse" } } */
