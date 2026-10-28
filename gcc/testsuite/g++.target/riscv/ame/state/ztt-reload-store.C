/* { dg-do compile } */
/* { dg-options "-O2 -g -fno-ipa-icf -fdump-rtl-ztt_md_reuse -mztt-profile=gcc-runtime-u8-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#include "../../../../gcc.target/riscv/ame/state/ztt-reload-store.h"
/* { dg-final { scan-rtl-dump-times "Prepare Md before store reload" 5 "ztt_md_reuse" } } */
/* { dg-final { scan-assembler-times {\tmss\.rm\t} 5 } } */
/* { dg-final { scan-assembler-times {\tmss\.cm\t} 1 } } */
/* { dg-final { scan-assembler-times {\tmss\.st\t} 1 } } */
/* { dg-final { scan-assembler-times {\tmss\.tst\t} 1 } } */
