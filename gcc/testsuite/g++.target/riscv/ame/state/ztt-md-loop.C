/* { dg-do compile } */
/* { dg-options "-O2 -g -fno-ipa-icf -fdump-rtl-ztt_md_reuse -mztt-profile=gcc-runtime-u32-m16-a4" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#include "../../../../gcc.target/riscv/ame/state/ztt-md-loop.h"
/* { dg-final { scan-rtl-dump "Intersect Md on self loop block" "ztt_md_reuse" } } */
/* { dg-final { scan-assembler {madd\.ew} } } */
/* { dg-final { scan-assembler {mmax\.ew} } } */
