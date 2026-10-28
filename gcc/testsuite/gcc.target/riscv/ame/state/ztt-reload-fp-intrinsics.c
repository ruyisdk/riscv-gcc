/* { dg-do compile } */
/* { dg-options "-O2 -g -fno-math-errno -fno-ipa-icf -fno-pic -mcmodel=medany -fdump-rtl-ztt_md_reuse -mztt-profile=gcc-runtime-u8-m32-a16" } */
/* { dg-additional-options "-march=rv32imafd_zicsr_ztt0p6 -mabi=ilp32d" { target rv32 } } */
/* { dg-additional-options "-march=rv64imafd_zicsr_ztt0p6 -mabi=lp64d" { target rv64 } } */
#include "ztt-reload-fp-intrinsics.h"
/* { dg-final { scan-rtl-dump-times "Prepare Md before private reload" 4 "ztt_md_reuse" { target rv32 } } } */
/* { dg-final { scan-rtl-dump-times "Prepare Md before private reload" 5 "ztt_md_reuse" { target rv64 } } } */
/* { dg-final { scan-assembler-times {\tmmulacc\.ew\.x\t} 4 } } */
/* { dg-final { scan-assembler-times {\tfmin\.d\t} 1 } } */
/* { dg-final { scan-assembler-times {\tfmax\.d\t} 1 } } */
/* { dg-final { scan-assembler-times {\tfsgnj\.d\t} 1 } } */
/* { dg-final { scan-assembler-times {\tfcvt\.[wl]\.d [^\n]*,dyn} 1 } } */
