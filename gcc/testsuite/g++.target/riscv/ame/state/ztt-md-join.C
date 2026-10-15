/* { dg-do compile } */
/* { dg-options "-O2 -g -dp -fno-ipa-icf -fno-unroll-loops -fno-peel-loops -fdump-rtl-ztt_md_reuse -mztt-profile=gcc-runtime-u8-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#include "../../../../gcc.target/riscv/ame/state/ztt-md-join.h"
/* { dg-final { scan-rtl-dump "Intersect Md at join block" "ztt_md_reuse" } } */
/* { dg-final { scan-assembler {madd\.ew} } } */
/* { dg-final { scan-assembler {msub\.ew} } } */
/* { dg-final { scan-assembler {mss\.rm} } } */
