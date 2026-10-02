/* { dg-do compile } */
/* { dg-options "-O2 -dp -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m32-a16" { target rv32 } } */
/* { dg-options "-O2 -dp -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m32-a16" { target rv64 } } */
/* Isolate reuse within a single composite from the later basic-block pass.  */
/* { dg-additional-options "-fdisable-rtl-ztt_md_reuse" } */
/* { dg-prune-output "note: disable pass rtl-ztt_md_reuse" } */
#include "ztt-acc-shared-source-body.h"
/* { dg-final { scan-assembler-times { l=16\]  ztt_acc_mmul_} 12 } } */
/* { dg-final { scan-assembler-times { l=28\]  ztt_acc_mmul_} 12 } } */
