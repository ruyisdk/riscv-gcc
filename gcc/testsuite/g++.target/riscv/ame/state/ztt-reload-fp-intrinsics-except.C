/* { dg-do compile } */
/* { dg-options "-O2 -g -fnon-call-exceptions -fno-math-errno -fno-ipa-icf -fno-pic -mcmodel=medany -fdump-rtl-ztt_md_reuse -mztt-profile=gcc-runtime-u8-m32-a16" } */
/* { dg-additional-options "-march=rv32imafd_zicsr_ztt0p6 -mabi=ilp32d" { target rv32 } } */
/* { dg-additional-options "-march=rv64imafd_zicsr_ztt0p6 -mabi=lp64d" { target rv64 } } */
#include "../../../../gcc.target/riscv/ame/state/ztt-reload-fp-intrinsics.h"
/* { dg-final { scan-rtl-dump-not "Prepare Md before private reload" "ztt_md_reuse" } } */
/* { dg-final { scan-assembler-times {\tmmulacc\.ew\.x\t} 4 } } */
